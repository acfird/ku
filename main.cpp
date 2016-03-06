﻿// 2016.3.3 支持真分数, 100以内的四则运算
//张江鹏
#include<iostream>
using namespace std;
//生成一个整数随机数
int f()
{
	int a;
	a = rand();
	a = a % 100;
	return a;
}

void main()
{
	int s1, s2, p, z = 30;
	for (int i = 0; i<z; i++)
	{
		s1 = f();
		s2 = f();
		p = f();

		//生成一个运算符
		if (p % 4 == 0)
		{
			if ((s1 + s2) >= 100)
			{
				z += 1;
				continue;
			}
			else
				cout << s1 << "+" << s2 << "=" << endl;
		}
		if (p % 4 == 1)
		{
			cout << s1 << "-" << s2 << "=" << endl;
		}
		if (p % 4 == 2)
		{
			if ((s1*s2) >= 100)
			{
				z += 1;
				continue;
			}
			else
				cout << s1 << "*" << s2 << "=" << endl;
		}
		if (p % 4 == 3)
		{
			if ((s1>s2) || (s2 == 0))
			{
				z += 1;
				continue;
			}
			else
				cout << s1 << "/" << s2 << "=" << endl;
		}
	}
}