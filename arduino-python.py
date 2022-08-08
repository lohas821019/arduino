# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 15:39:44 2022

@author: Jason
"""
import serial
import time
import numpy as np

COM_PORT = 'COM4'
baudRate = 9600
ser = serial.Serial(COM_PORT, baudRate, timeout=0.5)


choice = input('請輸入模式 0 ~ 16\n').lower()

if choice == 'q':
    ser.close()

elif (int(choice) < 17):
    # print(int(choice))
    choice = np.array(choice).tobytes()
    ser.write(choice)            # 訊息必須是位元組類型
    ser.flush()
    time.sleep(0.5)

while ser.in_waiting:
    mcu_feedback = ser.readline()
    mcu_feedback = mcu_feedback.decode("utf-8") # 接收回應訊息並解碼
    mcu_feedback = mcu_feedback.strip()
    print('控制板回應：', mcu_feedback)
    time.sleep(0.1)

# while ser.in_waiting:
#     sys.stdout.write(ser.readline())
#     sys.stdout.flush()


