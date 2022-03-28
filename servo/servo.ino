#include <Arduino.h>
#include <Servo.h>

#define RCLPin 25
#define RCRPin 26

Servo RCL;
Servo RCR;

int DIR;

void setup()
{
    Serial.begin(115200); //
//    RCL.attach(RCLPin,1,0,180,1000,2000);
//    RCR.attach(RCRPin,1,0,180,1000,2000);

    RCL.attach(RCLPin,1000,2000);
    RCR.attach(RCRPin,1000,2000);
    //https://www.arduino.cc/en/Reference/ServoAttach
    //servo.attach(pin, min, max)
}

void loop()
{
 moto(DIR);  
}

void moto(byte DIR)
{
    switch (DIR)
    {
    case 0:
        RCL.write(70);
        RCR.write(70);
        break;
    case 1:
        RCL.write(0);
        RCR.write(30);
        break;
    case 2:
        RCL.write(0);
        RCR.write(50);
        break;
    case 3:
        RCL.write(0);
        RCR.write(90);
        break;
    case 4:
        RCL.write(30);
        RCR.write(0);
        break;
    case 5:
        RCL.write(50);
        RCR.write(50);
        break;
    case 6:
        RCL.write(50);
        RCR.write(130);; // 往左自轉
        break;
    case 7:
        RCL.write(0);
        RCR.write(0);
        break;
    case 8:
        RCL.write(50);
        RCR.write(0);
        break;
    case 9:
        RCL.write(130);
        RCR.write(50);; // 往右自轉
        break;
    case 10:
        RCL.write(50);
        RCR.write(50);;
        break;
    case 11:
        RCL.write(0);
        RCR.write(0);;
        break;
    case 12:
        RCL.write(90);
        RCR.write(0);;
        break;
    case 13:
        RCL.write(0);
        RCR.write(0);;
        break;
    case 15:
        RCL.write(50);
        RCR.write(50);;
        break;
    case 16:
        RCL.write(130);
        RCR.write(130);; //後退
        break;
    }
}
