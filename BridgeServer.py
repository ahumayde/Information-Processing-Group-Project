import socket
import time
import requests
import threading

URL = "https://httpbin.org/post"
port = 10000 
payload = { 'x' : 0, 'y' : 0, 'z' : 0}

def connect():
    wsocket =  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    wsocket.bind(('0.0.0.0', port))
    wsocket.listen(1)
    print("Intialize socket server, listen port: {}".format(port))
    print("Waiting for connection")
    csocket, address = wsocket.accept() 
    print('Connection: ', address)
    return csocket

def process(variable ,data):
    global payload
    payload[variable] += 2*int(data)

def recvMsg(csocket):
    while True:
        data = csocket.recv(1024).decode()
        if len(data) != 0:
            print("Data Received: ", data)
            process('x',data)

def postReq():
    while True:
        r = requests.post(URL, payload)
        r_dict = r.json()
        print(r_dict['data'], r_dict['form'])

def __main__():
    csocket = connect()

    thread1 = threading.Thread(target=recvMsg, args=(csocket,))
    thread2 = threading.Thread(target=postReq)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

if __name__ == '__main__':
    __main__()
