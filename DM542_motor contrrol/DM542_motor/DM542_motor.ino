
char incomingChr = 0;   // 存放讀到的資料

int pulPin = 10;  //pulse/clock/脈波
int dirPin = 11;  // 方向
int enblPin = 12;  //制能或是使用
int x;
int y;
int z;
String cc ;
int re = 9;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // 以 9600 的齙率啟用 UART 串列傳輸

  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enblPin, OUTPUT);

  digitalWrite(pulPin, LOW);
  //  digitalWrite(enblPin, LOW);
  //  digitalWrite(dirPin,  HIGH);

  digitalWrite(enblPin, LOW);
  //  delay(100);
  //  digitalWrite(enblPin, LOW);
}

void loop() {

  String s = "";
  // 當有資料進來時才傳送資料出去
  if (Serial.available() > 0) {
    // 讀取收到的資料

    String c = Serial.readString();
    //    Serial.println(c);

    cc = c.substring(2, 7);
    x = cc.toInt();
    // 回傳收到的內容
    motor_control(c[0], c[1], x);
    Serial.println('9');
  }
  delay(1000)
  motor_control(1,0,0)

}


int motor_control(char y, char z , int x ) {

  if (y == '0') {
    digitalWrite(enblPin, LOW);
  }
  if (y == '1') {
    digitalWrite(enblPin, HIGH);
  }
  if (z == '0') {
    digitalWrite(dirPin, LOW);
    steptimes(x);
    delay(1);
  }
  if (z == '1') {
    digitalWrite(dirPin, HIGH);
    steptimes(x);
    delay(1);
  }


}

void  steptimes( int x ) {

  for (int counter = 0; counter <= x; counter++) {
    digitalWrite(pulPin, HIGH);
    //    delay(0.5);
    delayMicroseconds(50);
    digitalWrite(pulPin, LOW);
    //    delay(0.5);
    delayMicroseconds(50);

    //    delay(1);
    delayMicroseconds(200);
    //    Serial.println(counter);
    //原本是100 100 1000
  }

}
