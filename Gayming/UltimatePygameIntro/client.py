import requests as rq
import time
jsurl="http://172.20.10.11:8080"
while True:
    x = rq.get(jsurl)
    print(x.text)
    time.sleep(1)


