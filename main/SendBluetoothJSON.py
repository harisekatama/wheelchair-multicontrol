import bluetooth
import json
import time
import datetime
import random

esp32_address = "C0:49:EF:E7:BD:EA"

def sendData(arah):
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((esp32_address, 1))
    
    date = datetime.datetime.now()
    
    data = {"arah": arah}
    json_data = json.dumps(data)
    
    sock.send(json_data.encode())
    
    print(f"{date} -> {data}")
    sock.close()

i = 0

while True:
    if i < 35:
        arah = random.choice('ABCDE')
        sendData(arah)
        i = i + 1
        time.sleep(1)
    else:
        break
