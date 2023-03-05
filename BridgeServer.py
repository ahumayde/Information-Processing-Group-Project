import socket
import requests
import threading
# import json 

URL = "http://172.20.10.11:8080"
port = 10000
payload = { "right" : 0, "left" : 0, "drop" : 0, "store" : 0}
UpperBoundY =  20
LowerBoundY = -20

def connect():
    wsocket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    wsocket.bind(('0.0.0.0', port))
    wsocket.listen(1)
    print("Intialize socket server, listen port: {}".format(port))
    print("Waiting for connection")
    csocket, address = wsocket.accept() 
    print("Connection: ", address)
    return csocket

def process(x, y, b):
    if b == 1:
        # Post
        payload["right"] = 1
        payload["left"]  = 0
        # Get
        # r = requests.get(URL+"/right")
    elif b == 2:
        # Post
        payload["right"] = 0
        payload["left"]  = 1
        # Get
        # r = requests.get(URL+"/left")
    else: # Post
        payload["right"] = 0
        payload["left"]  = 0
    if y > UpperBoundY:
        # Post
        payload["drop"]  = 1
        payload["store"] = 0
        # Get
        # r = requests.get(URL+"/drop")
    elif y < LowerBoundY:
        # Post
        payload["drop"]  = 0
        payload["store"] = 1
        # Get
        # r = requests.get(URL+"/store")
    else: # Post
        payload["drop"]  = 0
        payload["store"] = 0

    print("x:", x, " y:",y," b:",b)
    print(payload)
    

def recieve_message(csocket):
    while True:
        msg = csocket.recv(1024).decode()
        x = int(msg.split(",")[1])
        y = int(msg.split(",")[2])
        b = int(msg.split(",")[3])
        process(x, y, b)


def post_request():
    while True:
        r = requests.post((URL+"/data"), data=payload, headers={"Content-Type" : "application/json"})
        #r_dict = r.json()
        print(r.text) #_dict['data'], r_dict['form'])

def main():
    # Connect to TCP Client
    csocket = connect()

    # Get Requests
    # recieve_message(csocket)        

    # Post Requests with threading
    thread1 = threading.Thread(target=recieve_message, args=(csocket,))
    thread2 = threading.Thread(target=post_request)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

if __name__ == '__main__':
    main()
