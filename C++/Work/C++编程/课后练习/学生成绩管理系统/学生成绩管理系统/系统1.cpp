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
		<<"     *                   欢   迎   使   用                  *"<<endl
		<<"     *                        190506版                      *"<<endl
		<<"     *             学  生  成  绩  管  理  系  统           *"<<endl
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
	cout << "     请登录！"<< endl;
	cout << "     用户名：";
	gets(user);
	cout << "     密  码：";
	gets(password);
	if ((strcmp(user,r_user) != 0 || strcmp(password,r_password) != 0) && times !=3)
	{
		times++;
		system("cls");
		cout << "     对不起，用户名或密码错误，请重新输入！"<<endl;
		goto start;
	}
	else if(times == 3)
	{
		cout << "     你的错误次数过多，请等会再试！" << endl;
		cout << "     ";
		system("pause");
		system("cls");
		times = 0;
		goto start;
	}
	else 
	{
		cout << "     登陆成功！" << endl;
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
	cout<<"     请选择你要进行过的工作："<<endl<<endl
		<<"     录入成绩······1"<<endl
		<<"     删除成绩······2"<<endl
		<<"     展示成绩······3"<<endl
		<<"     排列成绩······4"<<endl
		<<"     查询成绩······5"<<endl
		<<"     退出系统······6"<<endl
		<<endl
		<<"     请输入：";
	cin >> choosen;
	if (choosen > 6 || choosen < 1)
	{
		cout << "     选择有误，重新选择！" << endl;
		goto start;
	}
	return choosen;
}

void Input()
{
	system("cls");
	R();
	cout << "     请输入学生个数 ：" ;
	cin >> student;
	system("cls");
	for (int i = 0;i < student;i++)
	{
		R();
		cout << "     请输入第" << i+1 << "个学生的信息" << endl;
		cout << "     姓名  ";scanf("%s",&name[i]);
		cout << "     学号  ";scanf("%s",&number[i]);
		for (int x = 0;x < 4;x++)
		{
			cout << "     学科" << x+1 << " ";
			cin >> score[i][x];
		}
		system("cls");
	}
}

void Output()
{
	system("cls");
	R();
	cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
	cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
	cout << "     请选择需要删除的序号：" ;
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
	cout << "     是否继续删除(Y/y or N/n)：";
	char choice;
	do
	{
		cin >> choice;
		if (choice == 89 || choice == 121)goto start;
		else if (choice == 78 || choice == 110)break;
		else cout << "     你的输入有误，请重新输入：";
	}while(1);
}

void Sort()
{
	int choosen;
start:
	system("cls");
	R();
	cout<<"     请选择您的排序方式：" << endl << endl
		<<"     按姓名排序·······1"<<endl
		<<"     按学号排序·······2"<<endl
		<<"     按学科1排序 ······3"<<endl
		<<"     按学科2排序 ······4"<<endl
		<<"     按学科3排序 ······5"<<endl
		<<"     按学科4排序 ······6"<<endl
		<<"     按总分排序·······7"<<endl
		<<"     按平均分排序······8"<<endl
		<<endl
		<<"     请输入：";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     选择有误，重新选择！" << endl;
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
	cout<<"     请选择您的查找方式：" << endl << endl
		<<"     按姓名查找·······1"<<endl
		<<"     按学号查找·······2"<<endl
		<<"     按学科1查找 ······3"<<endl
		<<"     按学科2查找 ······4"<<endl
		<<"     按学科3查找 ······5"<<endl
		<<"     按学科4查找 ······6"<<endl
		<<"     按总分查找·······7"<<endl
		<<"     按平均分查找······8"<<endl
		<<endl
		<<"     请输入：";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     选择有误，重新选择！" << endl;
		goto start;
	}
	cout << "     请输入查找内容：" ;
	int i;
	if (choosen == 1)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
			cout << "     查无结果！";
		cout << endl;
	}
	else if (choosen == 2)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
			cout << "     查无结果！";
		cout << endl;
	}
	else if (choosen > 2 && choosen < 8)
	{
		choosen -= 3;
		int search;
		cin >> search;
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
			cout << "     查无结果！";
		cout << endl;
	}
	else
	{
		int search;
		cin >> search;
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
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
			cout << "     查无结果！";
		cout << endl;
	}
	cout << "     是否继续查找(Y/y or N/n)：";
	char choice;
	do
	{
		cin >> choice;
		if (choice == 89 || choice == 121)goto start;
		else if (choice == 78 || choice == 110)break;
		else cout << "     你的输入有误，请重新输入：";
	}while(1);
}

void End()
{
	system("cls");
	cout<<endl;
	cout<<"     ********************************************************"<<endl
		<<"     *                                                      *"<<endl
		<<"     *                       190506版                       *"<<endl
		<<"     *                    学生成绩管理系统                  *"<<endl
		<<"     *                     感谢您的使用                     *"<<endl
		<<"     *                更多功能敬请期待最新版本              *"<<endl
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