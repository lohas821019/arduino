# -*- coding: utf-8 -*-
"""
Created on Mon Mar 28 15:39:44 2022

@author: Jason
"""
import serial
import time

COM_PORT = 'COM3'
baudRate = 9600
ser = serial.Serial(COM_PORT, baudRate, timeout=0.5)

try:
    while True:
        # 接收用戶的輸入值並轉成小寫
        choice = input('按1、按2、按e關閉程式  ').lower()

        if choice == '1':
            
            print('傳送1指令')
            ser.write(b'0')  # 訊息必須是位元組類型
            time.sleep(0.5)
            
        elif choice == '2':
            print('傳送2指令')
            ser.write(b'1')
            time.sleep(0.5)
            
        elif choice == 'e':
            ser.close()
            sys.exit()
        else:
            print('錯誤…')

        while ser.in_waiting:
            mcu_feedback = ser.readline().decode()  # 接收回應訊息並解碼
            print('控制板回應：', mcu_feedback)
            
except KeyboardInterrupt:
    ser.close()
    print('再見！')
