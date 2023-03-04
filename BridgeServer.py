import socket
import time
import requests
import threading
import json 

URL = "http://172.20.10.11:8080/data"
port = 10000
payload = { "right" : 0, "left" : 0, "drop" : 0, "store" : 0}

def connect():
    wsocket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    wsocket.bind(('0.0.0.0', port))
    wsocket.listen(1)
    print("Intialize socket server, listen port: {}".format(port))
    print("Waiting for connection")
    csocket, address = wsocket.accept() 
    print("Connection: ", address)
    return csocket

# def process(variable ,data):
#     global payload
#     payload[variable] = 2*int(data)

# def recvMsg(csocket):
#     while True:
#         data = csocket.recv(1024).decode()
#         if len(data) != 0:
#             print("Data Received: ", data)
#             process("x",data)

# def postReq():
#     while True:
#         print("trying post")
#         r = requests.post(URL, data=payload)
#         # r_dict = r.json()
#         # print(r_dict['data'], r_dict['form'])
#         print("successfull post")

def main():
    global payload
    csocket = connect()

    while True:
        msg = csocket.recv(1024).decode()
        # payload["x"] = msg
        x = int(msg.split(",")[1])
        y = int(msg.split(",")[2])
        b = int(msg.split(",")[3])

        if b == 1:
            payload["right"] = 1
            payload["left"]  = 0
        elif b == 2:
            payload["right"] = 0
            payload["left"]  = 1
        else:
            payload["right"] = 0
            payload["left"]  = 0
        if y > 10:
            payload["drop"]  = 1
            payload["store"] = 0
        elif y < -10:
            payload["drop"]  = 0
            payload["store"] = 1
        else:
            payload["drop"]  = 0
            payload["store"] = 0    

        print("x:", x, " y:",y," b:",b)
        print(payload)
        
        r = requests.post(URL, data=payload, headers={"Content-Type" : "application/json"})
        print(r.text)   #_dict['data'], r_dict['form'])
        print("successfull post")

        # if len(data) != 0:
        #     print("Data Received: ", data)
        #     process('x',data)
        # print("trying post")
        # r_dict = jsonify(payload)
        # r = urllib3.req
        # r = requests.get(URL)

    # thread1 = threading.Thread(target=recvMsg, args=(csocket,))
    # thread2 = threading.Thread(target=postReq)

    # thread1.start()
    # thread2.start()

    # thread1.join()
    # thread2.join()

if __name__ == '__main__':
    main()
