#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#define N 100
using namespace std;
struct student
{
	char name[20];
	char number[20];
	int score[5];
	double aver_score;
}stud[N];
struct user
{
	char username[20];
	char password[20];
}use[N];
int student_num,user_num = 0;
int user_order;
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
void Open()
{
	FILE *fp1,*fp2;
	if ((fp1 = fopen("score.dat","rb")) == 0)
	{
		cout << "File can not open!";
		exit(0);
	}
	for(student_num = 0;student_num < N;student_num++)
	{
		if (feof(fp1))
			break;
		fread(&stud[student_num],sizeof(struct student),1,fp1);
	}
	student_num--;
	if ((fp2 = fopen("register.txt","r")) == 0)
	{
		cout << "File can not open!";
		exit(0);
	}
	for(user_num = 0;user_num < N;user_num++)
	{
		if (feof(fp2))
			break;
		fread(&use[user_num],sizeof(struct user),1,fp2);
	}
	user_num--;
	fclose(fp1);
	fclose(fp2);
	fp1 = fp2 = 0;
}
void Save()
{
	FILE *fp1,*fp2;
	int i;
	if ((fp1 = fopen("score.dat","wb")) == 0)
	{
		cout << "File can not open!";
		exit(0);
	}
	for(i = 0;i < student_num;i++)
	{
		fwrite(&stud[i],sizeof(struct student),1,fp1);
		if (feof(fp1))
			break;
	}
	if ((fp2 = fopen("register.txt","w")) == 0)
	{
		cout << "File can not open!";
		exit(0);
	}
	for(i = 0;i < user_num;i++)
	{
		fwrite(&use[i],sizeof(struct user),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	fp1 = fp2 = 0;
}
int Beginning()
{
	int choosen;
start:
	system("cls");
	cout << endl;
	R();
	cout<<"     请选择你要进行过的工作："<<endl<<endl
		<<"     注册······1"<<endl
		<<"     登录······2"<<endl
		<<endl
		<<"     请输入：";
	cin >> choosen;
	if (choosen > 2 || choosen < 1)
	{
		cout << "     选择有误，重新选择！" << endl;
		goto start;
	}
	return choosen;
}
void Register()
{
	char user[20] , password[20];
	system("cls");
	cout<< "     注册界面" << endl;
	R();
	cout<< "     请注册！"<< endl;
	cout<< "     用户名：";
	scanf("%s",&user);
	cout<< "     密  码：";
	scanf("%s",&password);
	for (int i = 0;i < 20;i++)
	{
		use[user_num].username[i] = user[i];
		use[user_num].password[i] = password[i];
	}
	user_num++;
}
void Load()
{
	char user[20] , password[20];
	int times = 0;
start:
	system("cls");
	if (times == 0)cout << "     登陆界面" << endl;
	else cout << "     对不起，用户名或密码错误，请重新输入！"<<endl;
	R();
	cout << "     请登录！"<< endl;
	cout << "     用户名：";
	scanf("%s",&user);
	cout << "     密  码：";
	scanf("%s",&password);
	int i;
	for (i = 0;i < user_num;i++)
	{
		if (strcmp(user,use[i].username) != 0 || strcmp(password,use[i].password) != 0)
			continue;
		else 
		{
			user_order = i;
			break;
		}
	}
	if (i == user_num && times !=2)
	{
		times++;
		goto start;
	}
	else if(i == user_num && times == 2)
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
	cout << "     系统主页" << endl;
	R();
	cout<<"     请选择你要进行过的工作："<<endl<<endl
		<<"     录入成绩······1"<<endl
		<<"     删除成绩······2"<<endl
		<<"     展示成绩······3"<<endl
		<<"     排列成绩······4"<<endl
		<<"     查询成绩······5"<<endl
		<<"     修改密码······6"<<endl
		<<"     注销账号······7"<<endl
		<<"     退出系统······8"<<endl
		<<endl
		<<"     请输入：";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     选择有误，重新选择！" << endl;
		goto start;
	}
	return choosen;
}
void Input()
{
	system("cls");
	cout << "     录入成绩" << endl;
	R();
	int i = student_num;
	cout << "     请输入学生个数 ：" ;
	cin >> student_num;
	student_num += i;
	system("cls");
	for (;i < student_num;i++)
	{
		R();
		cout << "     请输入第" << i+1 << "个学生的信息" << endl;
		cout << "     姓名  ";scanf("%s",&stud[i].name);
		cout << "     学号  ";scanf("%s",&stud[i].number);
		for (int x = 0;x < 4;x++)
		{
			cout << "     学科" << x+1 << " ";
			cin >> stud[i].score[x];
		}
		system("cls");
	}
}
void Output()
{
	system("cls");
	cout << "     展示成绩" << endl;
	R();
	cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
	for (int i = 0;i < student_num;i++)
	{
		stud[i].score[4] = 0;
		stud[i].aver_score = 0;
		cout << setiosflags(ios::left);
		cout<< "     " << setw(6) << i+1
			<< setw(7) << stud[i].name;
		cout<<setw(11) << stud[i].number;
		for (int x = 0;x < 4;x++)
		{
			cout << setw(6) << stud[i].score[x];
			stud[i].score[4] += stud[i].score[x];
			stud[i].aver_score += stud[i].score[x] / 4.0;
		}
		cout << setw(6) << stud[i].score[4] << setprecision(3) << setw(6) << stud[i].aver_score;
		cout << endl;
	}
	cout << endl << "     ";
	system("pause");
}
void Delete()
{
start:
	system("cls");
	cout << "     删除成绩" << endl;
	R();
	cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
	for (int i = 0;i < student_num;i++)
	{
		stud[i].score[4] = 0;
		cout << setiosflags(ios::left);
		cout<< "     " << setw(6) << i+1
			<< setw(7) << stud[i].name;
		cout<<setw(11) << stud[i].number;
		for (int x = 0;x < 4;x++)
		{
			cout << setw(6) << stud[i].score[x];
			stud[i].score[4] += stud[i].score[x];
			stud[i].aver_score += stud[i].score[x] / 4.0;
		}
		cout << setw(6) << stud[i].score[4] << setprecision(3) << setw(6) << stud[i].aver_score;
		cout << endl;
	}
	cout << endl;
	cout << "     请选择需要删除的序号：" ;
	int order;
	cin >> order;
	for (int i = order-1;i < student_num-1;i++)
	{
		for (int n = 0;n < 20;n++)
		{
			stud[i].name[n] = stud[i+1].name[n];
			stud[i].number[n] = stud[i+1].number[n];
		}
		for (int n = 0;n < 6;n++)
			stud[i].score[n] = stud[i+1].score[n];
	}
	student_num--;
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
	cout<< "     成绩排序" << endl;
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
			for (int n = 0;n < student_num;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (strcmp(stud[n].name,stud[m].name) <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = stud[n].name[x];
							temp_number[x] = stud[n].number[x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = stud[n].score[x];
						temp_aver = stud[n].aver_score;
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								stud[i].name[x] = stud[i-1].name[x];
								stud[i].number[x] = stud[i-1].number[x];
							}
							for(int x = 0;x < 5;x++)
								stud[i].score[x] = stud[i-1].score[x];
							stud[i].aver_score = stud[i-1].aver_score;
						}
						for(int x = 0;x < 20;x++)
						{
							stud[n].name[x] = temp_name[x];
							stud[m].number[x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							stud[m].score[x] = temp_score[x];
						stud[m].aver_score = temp_aver;
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
			for (int n = 0;n < student_num;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (strcmp(stud[n].number,stud[m].number) <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = stud[n].name[x];
							temp_number[x] = stud[n].number[x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = stud[n].score[x];
						temp_aver = stud[n].aver_score;
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								stud[i].name[x] = stud[i-1].name[x];
								stud[i].number[x] = stud[i-1].number[x];
							}
							for(int x = 0;x < 5;x++)
								stud[i].score[x] = stud[i-1].score[x];
							stud[i].aver_score = stud[i-1].aver_score;
						}
						for(int x = 0;x < 20;x++)
						{
							stud[n].name[x] = temp_name[x];
							stud[m].number[x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							stud[m].score[x] = temp_score[x];
						stud[m].aver_score = temp_aver;
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
			for (int n = 0;n < student_num;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (stud[n].aver_score - stud[m].aver_score <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = stud[n].name[x];
							temp_number[x] = stud[n].number[x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = stud[n].score[x];
						temp_aver = stud[n].aver_score;
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								stud[i].name[x] = stud[i-1].name[x];
								stud[i].number[x] = stud[i-1].number[x];
							}
							for(int x = 0;x < 5;x++)
								stud[i].score[x] = stud[i-1].score[x];
							stud[i].aver_score = stud[i-1].aver_score;
						}
						for(int x = 0;x < 20;x++)
						{
							stud[n].name[x] = temp_name[x];
							stud[m].number[x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							stud[m].score[x] = temp_score[x];
						stud[m].aver_score = temp_aver;
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
			for (int n = 0;n < student_num;n++)
			{
				for (int m = 0;m < n;m++)
				{
					if (stud[n].score[choosen] - stud[m].score[choosen] <= 0)
					{
						for(int x = 0;x < 20;x++)
						{
							temp_name[x] = stud[n].name[x];
							temp_number[x] = stud[n].number[x];
						}
						for(int x = 0;x < 5;x++)
							temp_score[x] = stud[n].score[x];
						temp_aver = stud[n].aver_score;
						for (int i = n;i > m;i--)
						{
							for(int x = 0;x < 20;x++)
							{
								stud[i].name[x] = stud[i-1].name[x];
								stud[i].number[x] = stud[i-1].number[x];
							}
							for(int x = 0;x < 5;x++)
								stud[i].score[x] = stud[i-1].score[x];
							stud[i].aver_score = stud[i-1].aver_score;
						}
						for(int x = 0;x < 20;x++)
						{
							stud[n].name[x] = temp_name[x];
							stud[m].number[x] = temp_number[x] ;
						}
						for(int x = 0;x < 5;x++)
							stud[m].score[x] = temp_score[x];
						stud[m].aver_score = temp_aver;
						break;
					}
				}
			}
		}
	}
	Output();
}
void Search()
{
	int choosen;
start:
	system("cls");
	cout << "     查找成绩" << endl;
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
	int i,flags = 0;
	if (choosen == 1)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
		for (i = 0;i < student_num;i++)
		{
			if (strcmp(search,stud[i].name) == 0)
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << stud[i].name;
				cout<<setw(11) << stud[i].number;
				for (int x = 0;x < 5;x++)
					cout << setw(6) << stud[i].score[x];
				cout << setprecision(3) << setw(6) << stud[i].aver_score;
				cout << endl;
				flags = 1;
			}
		}
		if (i == student_num && flags == 0)
			cout << "     查无结果！";
		cout << endl;
	}
	else if (choosen == 2)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
		for (i = 0;i < student_num;i++)
		{
			if (strcmp(search,stud[i].number) == 0)
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << stud[i].name;
				cout<<setw(11) << stud[i].number;
				for (int x = 0;x < 5;x++)
					cout << setw(6) << stud[i].score[x];
				cout << setprecision(3) << setw(6) << stud[i].aver_score;
				cout << endl;
				flags = 1;
			}
		}
		if (i == student_num && flags == 0)
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
		for (i = 0;i < student_num;i++)
		{
			if (search == stud[i].score[choosen])
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << stud[i].name;
				cout<<setw(11) << stud[i].number;
				for (int x = 0;x < 5;x++)
					cout << setw(6) << stud[i].score[x];
				cout << setprecision(3) << setw(6) << stud[i].aver_score;
				cout << endl;
				flags = 1;
			}
		}
		if (i == student_num && flags == 0)
			cout << "     查无结果！";
		cout << endl;
	}
	else
	{
		int search;
		cin >> search;
		system("cls");
		cout << "     序号  姓名   学号       学科1 学科2 学科3 学科4 总分  平均分" << endl;
		for (i = 0;i < student_num;i++)
		{
			if (search == stud[i].aver_score)
			{
				cout << setiosflags(ios::left);
				cout<< "     " << setw(6) << i+1
					<< setw(7) << stud[i].name;
				cout<<setw(11) << stud[i].number;
				for (int x = 0;x < 5;x++)
					cout << setw(6) << stud[i].score[x];
				cout << setprecision(3) << setw(6) << stud[i].aver_score;
				cout << endl;
				flags = 1;
			}
		}
		if (i == student_num && flags == 0)
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
void Change()
{
	char password[20],c_password[20];
start:
	system("cls");
	cout << "     修改密码（密码最多9位）" << endl;
	R();
	cout << "     原密码：";
	scanf("%s",&password);
	cout << "     新密码：";
	scanf("%s",&c_password);
	if (strcmp(password,use[user_order].password) == 0)
		for (int m = 0;m < 10;m++)
			use[user_order].password[m] = c_password[m];
	else 
	{
		cout << "     你输入的密码错误！重新输入！" ;
		goto start;
	}
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
	Open();
start:
	switch(Beginning())
	{
	case 1:Register();
	case 2:Load();break;
	}
chose:
	system("cls");
	switch(Chose())
	{
		case 1 : Input();break;
		case 2 : Delete();break;
		case 3 : Output();break;
		case 4 : Sort();break;
		case 5 : Search();break;
		case 6 : Change();break;
		case 7 : goto start;
		case 8 : goto end;
	}
	goto chose;
end:
	Save();
	End();
	cout << "     ";
	system("pause");
	return 0;
}