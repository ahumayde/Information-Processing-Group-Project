import keyboard
import json
import time
from flask import Flask, render_template, request
from flask_cors import CORS

app = Flask(__name__)
CORS(app)

@app.route('/')
def index():
    return render_template('index.html')

# @app.route('/ahmad')
# def ahmad():
#     return '<p>Ahmads a bitch</p>'

# @app.route('/left')
# def left():
#     print("pressed") #debug
#     keyboard.send('left')
#     return "left pressed"

@app.route('/data', methods=['GET', 'POST'])
def get_data():
        data = request.data.decode()
        data_pairs = data.split('&')
             
        values = {}
        for pair in data_pairs:
            key, value = pair.split("=")
            values[key] = int(value)

        print(values)
    
        if values['store']:
            keyboard.send('up')

        if values['drop']:
            keyboard.send('down')
        
        if values['left']:
            keyboard.send('left')

        if values['right']:
            keyboard.send('right')
     
        return f'<p>{str(data)}</p>'

app.run(host='172.20.10.11', port=8080, debug=True)
