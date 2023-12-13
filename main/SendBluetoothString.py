import bluetooth
import random

def sendData(data):
    target_address = "C0:49:EF:E7:BD:EA"  # Replace with the Bluetooth MAC address of your ESP32

    port = 1  # RFCOMM port
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((target_address, port))

    sock.send(data)

    sock.close()

# Example usage
i = 0
while True:
    if i < 35:
        date = datetime.datetime.now()
        data = random.choice('ABCDE')
        print(f"{date} -> Arah : {data}")
        sendData(data)
        i = i + 1
    else :
        print("Done")
        break
