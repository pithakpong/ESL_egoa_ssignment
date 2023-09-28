import requests
import time
import random
import time
import serial
serial_port = 'COM4'
baud_rate = 115200
node_red_url = "http://127.0.0.1:1880/sensor-data"
def generate_sensor_data(sensor1=0,sensor2=0):
    sensor1_value = time.time()
    sensor2_value = sensor1
    sensor3_value = sensor2
    return {
        "sensor1": sensor1_value,
        "sensor2": sensor2_value,
        "sensor3": sensor3_value,
    }
ser = serial.Serial(serial_port, baud_rate)
while True:
    data = ser.readline().decode('utf-8').strip()

    data = data.split(' ')
    print(data)
    if (len(data) == 3):
        sensor_data = generate_sensor_data(data[0],data[1])
    try:
        # data = ser.readline().decode('utf-8').strip()
        # data = data.split(' ')
        if (len(data)):
            # print(data)
            for i in data : 
                print(i,end=' ')
            print(len(data))
        response = requests.post(node_red_url, json=sensor_data, timeout=1)
        if response.status_code == 200:
            # print("Sensor data sent successfully to Node-RED.")
            pass
        else:
            # print("Error sending sensor data to Node-RED. Status Code:", response.status_code)
            pass
    except Exception as e:
        # print("Error:", e)
        pass
    time.sleep(1)
