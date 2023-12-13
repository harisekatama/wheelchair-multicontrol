import bluetooth
import random
import datetime
import socket

host = "192.168.4.1"
port = 80

def sendData(data):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host,port))
        date = datetime.datetime.now()
        s.send(data.encode('utf-8'))
        print(f"{date} -> Arah : {data}")
        s.close()
    
i = 0
while True:
    if i < 35:
        data = random.choice('ABCDE')
        sendData(data)
        i = i + 1
    else :
        #print("Done")
        break
