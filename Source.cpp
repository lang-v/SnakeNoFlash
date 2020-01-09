#include<iostream>
#include<string>
#include"Snake.h"
#include<Windows.h>

using namespace std;
int main()
{
	//HANDLE fd = GetStdHandle(STD_OUTPUT_HANDLE);//Windows api隐藏光标,,,,,没出坑
	//CONSOLE_CURSOR_INFO cinfo;
	//cinfo.bVisible = false;
	//cinfo.dwSize = 1;
	cout << "选择难度\n1）Easy\n2) Justsoso\n3) trouble\n";
	int speed = 400;
	int i = 1;
	cin >> i;
	system("cls");
	switch (i)
	{
	case 1:speed = 250; break;
	case 2:speed = 200; break;
	case 3:speed = 100; break;
	case 4:speed = 50; break;
	default:
		cout << "Warning!\n";
		main();
		break;
	}
	Snake use;
	use.SnakeBady();
	use.randfood();
	int value = 3;
	char p = cin.get();
	char temp;
	temp = p;
	while (value != 0)	//监测键盘输入
	{
		if (value == 5)
		{
			system("cls");
			main();
		}
		if (!_kbhit())
			value = use.judge(p,speed);
		else
		{
			p = _getch();
			value = use.judge(p,speed);
		}
	}
	if ((MessageBox(NULL, TEXT("GameOver!"), TEXT("Notice!"), MB_YESNO)) == 7)
		main();
}
