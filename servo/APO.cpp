#include "APO.h"
#include "Arduino.h"

//bool APO::attach(Servo PINA, Servo PINB)
//{
//    _PINA = PINA;
//    _PINB = PINB;
//}
void APO::write(int degreesA, int degreesB)
{
    _PINA.write(degreesA);
    _PINB.write(degreesB);
}
void APO::writeMicroseconds(int degreesA, int degreesB)
{
    _PINA.writeMicroseconds(degreesA);
    _PINB.writeMicroseconds(degreesB);
}
int APO::read()
{
    _PINA.read();
    _PINB.read();
}
int APO::readMicroseconds()
{
    _PINA.readMicroseconds();
    _PINB.readMicroseconds();
}
/*void Forward(int Apwm, int Bpwm)
{
    _PINA.write(Apwm);
    _PINB.write(Bpwm);
}
void Reverse(int Apwm, int Bpwm)
{

}
*/
