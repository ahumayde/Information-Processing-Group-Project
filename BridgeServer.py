import socket
import time
import requests
import threading
import random
import json 

URL = "http://172.20.10.7:8080"
port = 10000
payload = { "right" : 0, "left" : 0, "drop" : 0, "store" : 0}

upper_bound_y =  30
lower_bound_y = -30
hold_time = 500000000 # in nanoseconds (0.5s)

right_held = False
left_held  = False
store_held = False
drop_held  = False

def connect():
    wsocket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    wsocket.bind(('0.0.0.0', port))
    wsocket.listen(1)
    print("Intialize socket server, listen port: {}".format(port))
    print("Waiting for connection")
    csocket, address = wsocket.accept() 
    print("Connection: ", address)
    return csocket

# Later use x for left and right, with buttons for rotate
def process(x, y, b):
    # Right
    if b == 1:
        r = requests.get(URL+"/right") # Get
        # payload["right"] = 1         # Post
        # payload["left"]  = 0         # Post
    # Left
    elif b == 2:
        r = requests.get(URL+"/left")  # Get
        # payload["right"] = 0         # Post
        # payload["left"]  = 1         # Post
    # Store
    while store_held:
        # payload["store"] = 0         # Post
        store_held = y < lower_bound_y
        if time.time_ns() - start_store >= hold_time:
            store_held = False
    if y < lower_bound_y:
        start_store = time.time_ns()
        store_held = True
        r = requests.get(URL+"/store") # Get
        # payload["drop"]  = 0         # Post
        # payload["store"] = 1         # Post
    # Drop
    while drop_held:
        # payload["drop"]  = 0         # Post
        drop_held = y > upper_bound_y 
        if time.time_ns - start_drop >= hold_time:
            drop_held = False 
    if y > upper_bound_y:
        start_drop = time.time_ns()
        drop_held = True
        r = requests.get(URL+"/drop")  # Get
        print("get sent")              # Get
        # payload["drop"]  = 1         # Post
        # payload["store"] = 0         # Post
        # print("post sent")           # Post
    # print("x:", x, " y:",y," b:",b)
    # print(payload)
    # time.sleep(1)


def recieve_message(csocket):
    while True:
        msg = csocket.recv(1024).decode()
        x = int(msg.split(",")[1])
        y = int(msg.split(",")[2])
        b = int(msg.split(",")[3])
        process(x, y, b)


def post_request():
    while True:
        r = requests.post((URL+"/data"), data=payload, headers={"heldent-Type" : "application/json"})
        # print("post request sent:",r.text)
        #time.sleep(0.25)


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
