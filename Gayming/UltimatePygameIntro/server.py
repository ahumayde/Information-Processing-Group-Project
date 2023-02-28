from flask import Flask, render_template, request
import json

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/ahmad')
def ahmad():
    return '<p>Ahmads a bitch</p>'

@app.route('/left')
def left():
    #move left code
    return "left"


@app.route('/data', methods=['GET', 'POST'])
def get_data():
        data = request.data
        print(data)   #(str(data).split('&'))
        # x = json.loads(data)
        return f'<p>{str(data)}</p>'





app.run(host='192.168.67.238', port=5000, debug=True)