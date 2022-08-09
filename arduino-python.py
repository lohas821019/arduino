# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 15:39:44 2022

@author: Jason
"""
import serial
import time
import numpy as np
import sys

COM_PORT = 'COM4'
baudRate = 9600
ser = serial.Serial(COM_PORT, baudRate, timeout=0.5)

while 1:
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
    

#%% 等待回傳直回傳
'''
https://stackoverflow.com/questions/13017840/using-pyserial-is-it-possible-to-wait-for-data

'''
import serial
import time
import numpy as np

COM_PORT = 'COM4'
baudRate = 9600
ser = serial.Serial(COM_PORT, baudRate, timeout=0.5)
while 1:
  choice = input('請輸入模式 0 ~ 16\n').lower()
  choice = np.array(choice).tobytes()
  ser.write(choice)
  
  tdata = ser.read()           # Wait forever for anything
  time.sleep(1)              # Sleep (or inWaiting() doesn't give the correct value)
  data_left = ser.inWaiting()  # Get the number of characters ready to be read
  tdata += ser.read(data_left)
  print(tdata)
