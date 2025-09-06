# server.py

import socket
import time
from wlm import *

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65525  # Port to listen on (non-privileged ports are > 1023)

def server(freq):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            #print(f"Connected by {addr}")
            while True:
                data = conn.recv(1024)
                if not data:
                    break                
                conn.sendall(freq)
                
wlmeter = WavelengthMeter()    

while True:
    f = wlmeter.frequences
    s = str(f)
    b = s.encode()
    try:
        server(b)
    except: 
        print('OSError')
        time.sleep(1)
        server(b)
