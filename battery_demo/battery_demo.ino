

float temp;  //創建一個浮點型變量temp作為存儲空間準備存放數據

void setup() {
  Serial.begin(9600);  //使用9600的波特率進行串口通訊
}

void loop() {

  int V1 = analogRead(A0);  //從A0口讀取電壓數據存入剛剛創建整數型變量V1，模擬口的電壓測量範圍為0-5V 返回的值為0-1024

  float vol = V1 * (5.0 / 1023.0);  //我們將 V1的值換算成實際電壓值存入浮點型變量 vol

  if (vol == temp) {  //這部分的判斷是用來過濾重複的數據，只有本次的電壓值和上次不一時才進行輸出

    temp = vol;  //比較完成後，將這次的值存入比對比用的變量temp

  } else {

    Serial.print(vol);  //串口輸出電壓值，並且不換行

    Serial.println(" V");  //串口輸出字符V，並且換行

    temp = vol;

    delay(1000);  //輸出完成後等待1秒鐘，用於控制數據的刷新速度。
  }
}

// 原文網址：https:  //kknews.cc/tech/l6nzzjz.html