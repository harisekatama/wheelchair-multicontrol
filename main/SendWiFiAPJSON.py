import bluetooth
import random
import datetime
import socket

host = "192.168.4.1"
port = 80

def sendData(arah):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((host,port))
        date = datetime.datetime.now()
        
        data = {"arah": arah}
        jsonString = json.dumps(data)
        s.send(jsonString.encode('utf-8'))
        print(f"{date} -> {data}")
        s.close()
    
i = 0
while True:
    if i < 35:
        arah = random.choice('ABCDE')
        sendData(arah)
        i = i + 1
        time.sleep(1.5)
    else :
        #print("Done")
        break
