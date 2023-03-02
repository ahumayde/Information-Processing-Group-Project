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

@app.route('/ahmad')
def ahmad():
    return '<p>Ahmads a bitch</p>'

@app.route('/left')
def left():
    print("pressed") #debug
    keyboard.send('left')
    return "left pressed"

# @app.route('/data', methods=['GET', 'POST'])
# def get_data():
#         data = request.data
#         print(data)   #(str(data).split('&'))
#         # x = json.loads(data)
#         return f'<p>{str(data)}</p>'

app.run(host='localhost', port=8080, debug=True)