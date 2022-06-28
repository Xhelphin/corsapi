#!/usr/bin/env python3
import serial
from flask import Flask, render_template
import os

"""
ser.write(''.encode('utf-8'))
"""

app = Flask(__name__)

@app.route('/')
def index():
	return render_template('index.html')

@app.route('/<val>')
def changefunction(val):
	val = str(val)
	ser.write(val.encode('utf-8'))
	return render_template('change.html')

if __name__ == "__main__":
	if os.geteuid() != 0:
		print("This script must be run as root.")
		exit(255)
	ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
	ser.reset_input_buffer()
	app.run(debug=True, host='0.0.0.0', port=int(80))
