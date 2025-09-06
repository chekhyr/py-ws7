# echo-client.py

import socket
import time 
HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65525  # The port used by the server

def recive_data():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.sendall(b"get freq")
        data = s.recv(1024)
        #print(f"Received {data!r}")
    return data

while True:
    time.sleep(2e-2)
    try:
        message = recive_data()
        print(message)
    except:
        time.sleep(1)
        print('Error occured')
        message = recive_data()
        print(message)
          
