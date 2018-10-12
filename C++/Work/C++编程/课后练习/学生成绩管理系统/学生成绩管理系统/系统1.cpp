#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

int score[100][5];
double aver_score[100];
char name[100][20],number[100][20];
int student;

void R()
{
	cout<<endl;
	cout<<"     ********************************************************"<<endl
		<<"     *                                                      *"<<endl
		<<"     *                   ��   ӭ   ʹ   ��                  *"<<endl
		<<"     *                        190506��                      *"<<endl
		<<"     *             ѧ  ��  ��  ��  ��  ��  ϵ  ͳ           *"<<endl
		<<"     *                                                      *"<<endl
		<<"     ********************************************************"<<endl;
	cout<<endl;
}

void Loading()
{
	char user[10] , password[10];
	char r_user[10] = "190506" , r_password[10] = "190506";
	int times = 0;
start:
	if (times == 0)cout << endl;
	R();
	cout << "     ���¼��"<< endl;
	cout << "     �û�����";
	gets(user);
	cout << "     ��  �룺";
	gets(password);
	if ((strcmp(user,r_user) != 0 || strcmp(password,r_password) != 0) && times !=3)
	{
		times++;
		system("cls");
		cout << "     �Բ����û���������������������룡"<<endl;
		goto start;
	}
	else if(times == 3)
	{
		cout << "     ��Ĵ���������࣬��Ȼ����ԣ�" << endl;
		cout << "     ";
		system("pause");
		system("cls");
		times = 0;
		goto start;
	}
	else 
	{
		cout << "     ��½�ɹ���" << endl;
		cout << "     ";
		system("pause");
	}
}

int Chose()
{
	int choosen;
start:
	system("cls");
	R();
	cout<<"     ��ѡ����Ҫ���й��Ĺ�����"<<endl<<endl
		<<"     ¼��ɼ�������������1"<<endl
		<<"     ɾ���ɼ�������������2"<<endl
		<<"     չʾ�ɼ�������������3"<<endl
		<<"     ���гɼ�������������4"<<endl
		<<"     ��ѯ�ɼ�������������5"<<endl
		<<"     �˳�ϵͳ������������6"<<endl
		<<endl
		<<"     �����룺";
	cin >> choosen;
	if (choosen > 6 || choosen < 1)
	{
		cout << "     ѡ����������ѡ��" << endl;
		goto start;
	}
	return choosen;
}

void Input()
{
	system("cls");
	R();
	cout << "     ������ѧ������ ��" ;
	cin >> student;
	system("cls");
	for (int i = 0;i < student;i++)
	{
		R();
		cout << "     �������" << i+1 << "��ѧ������Ϣ" << endl;
		cout << "     ����  ";scanf("%s",&name[i]);
		cout << "     ѧ��  ";scanf("%s",&number[i]);
		for (int x = 0;x < 4;x++)
		{
			cout << "     ѧ��" << x+1 << " ";
			cin >> score[i][x];
		}
		system("cls");
	}
}

void Output()
{
	system("cls");
	R();
	cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
	for (int i = 0;i < student;i++)
	{
		score[i][4] = 0;
		cout << setiosflags(ios::left);
		cout<< "     " << setw(6) << i+1
			<< setw(7) << name[i];
		cout<<setw(11) << number[i];
		for (int x = 0;x < 4;x++)
		{
			cout << setw(6) << score[i][x];
			score[i][4] += score[i][x];
			aver_score[i] += score[i][x] / 4.0;
		}
		cout << setw(6) << score[i][4] << setprecision(3) << setw(6) << aver_score[i];
		cout << endl;
	}
	cout << endl << "     ";
	system("pause");
}

void Delete()
{
start:
	system("cls");
	R();
	cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
	for (int i = 0;i < student;i++)
	{
		score[i][4] = 0;
		cout << setiosflags(ios::left);
		cout<< "     " << setw(6) << i+1
			<< setw(7) << name[i];
		cout<<setw(11) << number[i];
		for (int x = 0;x < 4;x++)
		{
			cout << setw(6) << score[i][x];
			score[i][4] += score[i][x];
			aver_score[i] += score[i][x] / 4.0;
		}
		cout << setw(6) << score[i][4] << setprecision(3) << setw(6) << aver_score[i];
		cout << endl;
	}
	cout << endl;
	cout << "     ��ѡ����Ҫɾ������ţ�" ;
	int order;
	cin >> order;
	for (int i = order-1;i < student-1;i++)
	{
		for (int n = 0;n < 20;n++)
		{
			name[i][n] = name[i+1][n];
			number[i][n] = number [i+1][n];
		}
		for (int n = 0;n < 6;n++)
			score[i][n] = score[i+1][n];
	}
	student--;
	cout << "     �Ƿ����ɾ��(Y/y or N/n)��";
	char choice;
	do
	{
		cin >> choice;
		if (choice == 89 || choice == 121)goto start;
		else if (choice == 78 || choice == 110)break;
		else cout << "     ��������������������룺";
	}while(1);
}

void Sort()
{
	int choosen;
start:
	system("cls");
	R();
	cout<<"     ��ѡ����������ʽ��" << endl << endl
		<<"     ���������򡤡�����������1"<<endl
		<<"     ��ѧ�����򡤡�����������2"<<endl
		<<"     ��ѧ��1���� ������������3"<<endl
		<<"     ��ѧ��2���� ������������4"<<endl
		<<"     ��ѧ��3���� ������������5"<<endl
		<<"     ��ѧ��4���� ������������6"<<endl
		<<"     ���ܷ����򡤡�����������7"<<endl
		<<"     ��ƽ�������򡤡���������8"<<endl
		<<endl
		<<"     �����룺";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     ѡ����������ѡ��" << endl;
		goto start;
	}
	switch(choosen)
	{
	case 1:
		{
			int temp_score[5];
			char temp_name[20],temp_number[20];
			double temp_aver;
			for (int n = 0;n < student;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (strcmp(name[n],name[m]) <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = name[n][x];
							temp_number[x] = number[n][x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = score[n][x];
						temp_aver = aver_score[n];
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								name[i][x] = name[i-1][x];
								number[i][x] = number[i-1][x];
							}
							for(int x = 0;x < 5;x++)
								score[i][x] = score[i-1][x];
							aver_score[i] = aver_score[i-1];
						}
						for(int x = 0;x < 20;x++)
						{
							name[m][x] = temp_name[x];
							number[m][x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							score[m][x] = temp_score[x];
						aver_score[m] = temp_aver;
						break;
					}
				}
			}
		}break;
	case 2:
		{
			int temp_score[5];
			char temp_name[20],temp_number[20];
			double temp_aver;
			for (int n = 0;n < student;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (strcmp(number[n],number[m]) <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = name[n][x];
							temp_number[x] = number[n][x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = score[n][x];
						temp_aver = aver_score[n];
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								name[i][x] = name[i-1][x];
								number[i][x] = number[i-1][x];
							}
							for(int x = 0;x < 5;x++)
								score[i][x] = score[i-1][x];
							aver_score[i] = aver_score[i-1];
						}
						for(int x = 0;x < 20;x++)
						{
							name[m][x] = temp_name[x];
							number[m][x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							score[m][x] = temp_score[x];
						aver_score[m] = temp_aver;
						break;
					}
				}
			}
		}break;
	case 8:
		{
			int temp_score[5];
			char temp_name[20],temp_number[20];
			double temp_aver;
			for (int n = 0;n < student;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (aver_score[n] - aver_score[m] <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = name[n][x];
							temp_number[x] = number[n][x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = score[n][x];
						temp_aver = aver_score[n];
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								name[i][x] = name[i-1][x];
								number[i][x] = number[i-1][x];
							}
							for(int x = 0;x < 5;x++)
								score[i][x] = score[i-1][x];
							aver_score[i] = aver_score[i-1];
						}
						for(int x = 0;x < 20;x++)
						{
							name[m][x] = temp_name[x];
							number[m][x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							score[m][x] = temp_score[x];
						aver_score[m] = temp_aver;
						break;
					}
				}
			}
		}break;
	default:
		{
			choosen -= 3;
			int temp_score[5];
			char temp_name[20],temp_number[20];
			double temp_aver;
			for (int n = 0;n < student;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (score[n][choosen] - score[m][choosen] <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = name[n][x];
							temp_number[x] = number[n][x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = score[n][x];
						temp_aver = aver_score[n];
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								name[i][x] = name[i-1][x];
								number[i][x] = number[i-1][x];
							}
							for(int x = 0;x < 5;x++)
								score[i][x] = score[i-1][x];
							aver_score[i] = aver_score[i-1];
						}
						for(int x = 0;x < 20;x++)
						{
							name[m][x] = temp_name[x];
							number[m][x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							score[m][x] = temp_score[x];
						aver_score[m] = temp_aver;
						break;
					}
				}
			}
		}
	}
}

void Search()
{
	int choosen;
start:
	system("cls");
	R();
	cout<<"     ��ѡ�����Ĳ��ҷ�ʽ��" << endl << endl
		<<"     ���������ҡ�������������1"<<endl
		<<"     ��ѧ�Ų��ҡ�������������2"<<endl
		<<"     ��ѧ��1���� ������������3"<<endl
		<<"     ��ѧ��2���� ������������4"<<endl
		<<"     ��ѧ��3���� ������������5"<<endl
		<<"     ��ѧ��4���� ������������6"<<endl
		<<"     ���ֲܷ��ҡ�������������7"<<endl
		<<"     ��ƽ���ֲ��ҡ�����������8"<<endl
		<<endl
		<<"     �����룺";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     ѡ����������ѡ��" << endl;
		goto start;
	}
	cout << "     ������������ݣ�" ;
	int i;
	if (choosen == 1)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
		for (i = 0;i < student;i++)
		{
			if (strcmp(search,name[i]) == 0)
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << name[i];
				cout<<setw(11) << number[i];
				for (int x = 0;x < 5;x++)
					cout << setw(6) << score[i][x];
				cout << setprecision(3) << setw(6) << aver_score[i];
				cout << endl;
			}
		}
		if (i == student && strcmp(search,name[i-1]) != 0)
			cout << "     ���޽����";
		cout << endl;
	}
	else if (choosen == 2)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
		for (i = 0;i < student;i++)
		{
			if (strcmp(search,number[i]) == 0)
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << name[i];
				cout<<setw(11) << number[i];
				for (int x = 0;x < 5;x++)
					cout << setw(6) << score[i][x];
				cout << setprecision(3) << setw(6) << aver_score[i];
				cout << endl;
			}
		}
		if (i == student && strcmp(search,number[i-1]) != 0)
			cout << "     ���޽����";
		cout << endl;
	}
	else if (choosen > 2 && choosen < 8)
	{
		choosen -= 3;
		int search;
		cin >> search;
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
		for (i = 0;i < student;i++)
		{
			if (search == score[i][choosen])
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << name[i];
				cout<<setw(11) << number[i];
				for (int x = 0;x < 5;x++)
					cout << setw(6) << score[i][x];
				cout << setprecision(3) << setw(6) << aver_score[i];
				cout << endl;
			}
		}
		if (i == student && search != score[i-1][choosen])
			cout << "     ���޽����";
		cout << endl;
	}
	else
	{
		int search;
		cin >> search;
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
		for (i = 0;i < student;i++)
		{
			if (search == aver_score[i])
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << name[i];
				cout<<setw(11) << number[i];
				for (int x = 0;x < 5;x++)
					cout << setw(6) << score[i][x];
				cout << setprecision(3) << setw(6) << aver_score[i];
				cout << endl;
			}
		}
		if (i == student && search != aver_score[i-1])
			cout << "     ���޽����";
		cout << endl;
	}
	cout << "     �Ƿ��������(Y/y or N/n)��";
	char choice;
	do
	{
		cin >> choice;
		if (choice == 89 || choice == 121)goto start;
		else if (choice == 78 || choice == 110)break;
		else cout << "     ��������������������룺";
	}while(1);
}

void End()
{
	system("cls");
	cout<<endl;
	cout<<"     ********************************************************"<<endl
		<<"     *                                                      *"<<endl
		<<"     *                       190506��                       *"<<endl
		<<"     *                    ѧ���ɼ�����ϵͳ                  *"<<endl
		<<"     *                     ��л����ʹ��                     *"<<endl
		<<"     *                ���๦�ܾ����ڴ����°汾              *"<<endl
		<<"     *                                                      *"<<endl
		<<"     ********************************************************"<<endl;
	cout<<endl;
}

int main()
{
	Loading();
chose:
	system("cls");
	switch(Chose())
	{
		case 1 : Input();break;
		case 2 : Delete();break;
		case 3 : Output();break;
		case 4 : Sort();break;
		case 5 : Search();break;
		case 6 : goto end;
	}
	goto chose;
end:
	End();
	cout << "     ";
	system("pause");
	return 0;
}