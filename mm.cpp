//2016.3.15
//ʯ��ׯ������ѧ

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
string suanshi(int v, int c, int y)   //������ʽ
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
	cout << "������һ���ж��ٸ���ʽ��" << endl;
	cin >> c;
	cout << "�Ƿ�������ļ���(1:�ǣ� 0����)" << endl;
	cin >> wenjian;
	cout << "���޳�������1���У�0���ޣ�" << endl;
	cin >> v;
	cout << "�Ƿ������ţ���1���У�0���ޣ�" << endl;
	cin >> kuohao;
	cout << "��������ֵ�ķ�Χ��" << endl;
	cout << "1-";
	cin >> fanwei;	
	cout << endl;
	if (wenjian)
		 {
		fl.open("file.txt");
		fl << "���������������£�" << endl;
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