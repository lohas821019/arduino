# Arduino

Using Arduino to control motor

- 目前無法使用APO.h (APO.h/APO.cpp 的attach部分看起來有問題)
- 也可省略使用APO.h，於switch部分改成下方寫法

```arduino
void moto(byte DIR, int PWMA, int PWMB)
{
   switch (DIR)
	{
	case 0:
		RCL.write(70);
		RCR.write(70);
	case 1:
		RCL.write(0);
		RCR.write(30);
	}
}
```