import requests as rq
import time
jsurl="http://127.0.0.1:5001"
while True:
    x = rq.get(jsurl)
    print(x.text)
    time.sleep(1)


