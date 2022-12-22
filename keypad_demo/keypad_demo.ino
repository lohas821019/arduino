
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '/'},
  {' ', '0', 'C', '='}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

// Created instances
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

boolean firstNumState = true;
String firstNum = "";
String secondNum = "";
float result = 0.0;
char operatr = ' ';

void setup() {
 Serial.begin(9600);//設置串口波特率爲9600
 clr();
}

void loop() {
  char newKey = myKeypad.getKey();
  if (newKey != NO_KEY && (newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0')) {
    if (firstNumState == true) {
      firstNum = newKey;
      Serial.print(firstNum);
    }
    else {
      secondNum = newKey;
      Serial.print(secondNum);
    }
  }
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == ' ' || newKey == '/')) {
    if (firstNumState == true) {
      operatr = newKey;
      firstNumState = false;
      Serial.print(operatr);
    }
  }
  if (newKey != NO_KEY && newKey == '=') {
    if (operatr == '+') {
      result = firstNum.toFloat() + secondNum.toFloat();
    }
    if (operatr == '-') {
      result = firstNum.toFloat() - secondNum.toFloat();
    }
    if (operatr == '*') {
      result = firstNum.toFloat() * secondNum.toFloat();
    }
    if (operatr == '/') {
      result = firstNum.toFloat() / secondNum.toFloat();
    }
    Serial.print("=");
    Serial.println(result);
    firstNumState = true;
  }
  if (newKey != NO_KEY && newKey == 'C') {
    clr();
  }
}
void clr() {
  firstNum = "";
  secondNum = "";
  result = 0;
  operatr = ' ';
}