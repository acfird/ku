//2016.3.15
//石家庄铁道大学

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include <sstream>
using namespace std;

string fuhao(int v)
 {
    string c;
	int n;
	if (v)
		{
		n = (rand() % 100) % 4;
		if (n == 0) c = '+';
		else if (n == 1) c = '-';
		else if (n == 2) c = '*';
		else c = '/';
		return c;
		}
	else
		{
		n = (rand() % 20) % 2;
		if (n == 0) c = '+';
		else   c = '-';
		return c;
		}
	}
string suanshi(int v, int c, int y)   //生成算式
 {
   	int n1, n2;
	int shu = (rand() % (8) + 2);
	string str1, str2;
	string shi = "";
	int sui;
	ofstream fout;
	for (int i = 1; i <= shu; i++)
		{
		n1 = (rand() % (y)) + 1;
		str1 = to_string(n1);
		n2 = (rand() % (y)) + 1;
		str2 = to_string(n2);
		if (c)
			{
			sui = (rand() % (4)) + 1;
			switch (sui) 
			{
				case 1:
					{
						if (shi == "") 
						{ 
							shi = str1 + fuhao(v) + str2; 
						}
						else 
						{ 
							shi = str1 + fuhao(v) + shi; 
						}
						}
					break;
					case 2:
						{
							if (shi == "") 
							{ 
								shi = str2 + fuhao(v) + str1; 
							}
							else 
							{ 
								shi = shi + fuhao(v) + str1; 
							}
							}
						break;
						case 3:
							{
								if (shi == "") 
								{ 
									shi = "(" + str1 + fuhao(v) + str2 + ")"; 
								}
								else 
								{ 
									shi = "(" + str1 + fuhao(v) + shi + ")"; 
								}
								}
							break;
							case 4:
								{
									if (shi == "") 
									{ 
										shi = "(" + str2 + fuhao(v) + str1 + ")"; 
									}
									else 
									{ 
										shi = "(" + shi + fuhao(v) + str1 + ")"; 
									}
									}
								break;
								
			}
			}
		else
			 {
			sui = (rand() % (2)) + 1;
			switch (sui) 
			{
				case 1:
					{
						if (shi == "") 
						{ 
							shi = str1 + fuhao(v) + str2; 
						}
						else 
						{ 
							shi = str1 + fuhao(v) + shi; 
						}
						}
					break;
					case 2:
						{
							if (shi == "") 
							{ 
								shi = str2 + fuhao(v) + str1; 
							}
							else 
							{ 
								shi = shi + fuhao(v) + str1; 
							}
							}
						break;
						
			}
			}
		}
	return  shi + "=";
	}
void main()
 {
	int v, kuohao, fanwei;
	int c;
	int wenjian;
	ofstream fl;
	cout << "请输入一共有多少个算式：" << endl;
	cin >> c;
	cout << "是否输出到文件：(1:是， 0：否)" << endl;
	cin >> wenjian;
	cout << "有无除法：（1：有，0：无）" << endl;
	cin >> v;
	cout << "是否有括号：（1：有，0：无）" << endl;
	cin >> kuohao;
	cout << "请输入数值的范围：" << endl;
	cout << "1-";
	cin >> fanwei;	
	cout << endl;
	if (wenjian)
		 {
		fl.open("file.txt");
		fl << "道四则运算题如下：" << endl;
		for (int i = 0; i < c; i++)
		 {
			fl << suanshi(v, kuohao, fanwei) << endl;
			cout << suanshi(v, kuohao, fanwei) << endl;
			}
		}
	else
		 {
		for (int i = 0; i < c; i++)
		 {
			cout << suanshi(v, kuohao, fanwei) << endl;
		 }
		}
	}