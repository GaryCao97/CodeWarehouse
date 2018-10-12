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
		<<"     *                   ��   ӭ   ʹ   ��                  *"<<endl
		<<"     *                        190506��                      *"<<endl
		<<"     *             ѧ  ��  ��  ��  ��  ��  ϵ  ͳ           *"<<endl
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
	cout<<"     ��ѡ����Ҫ���й��Ĺ�����"<<endl<<endl
		<<"     ע�ᡤ����������1"<<endl
		<<"     ��¼������������2"<<endl
		<<endl
		<<"     �����룺";
	cin >> choosen;
	if (choosen > 2 || choosen < 1)
	{
		cout << "     ѡ����������ѡ��" << endl;
		goto start;
	}
	return choosen;
}
void Register()
{
	char user[20] , password[20];
	system("cls");
	cout<< "     ע�����" << endl;
	R();
	cout<< "     ��ע�ᣡ"<< endl;
	cout<< "     �û�����";
	scanf("%s",&user);
	cout<< "     ��  �룺";
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
	if (times == 0)cout << "     ��½����" << endl;
	else cout << "     �Բ����û���������������������룡"<<endl;
	R();
	cout << "     ���¼��"<< endl;
	cout << "     �û�����";
	scanf("%s",&user);
	cout << "     ��  �룺";
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
	cout << "     ϵͳ��ҳ" << endl;
	R();
	cout<<"     ��ѡ����Ҫ���й��Ĺ�����"<<endl<<endl
		<<"     ¼��ɼ�������������1"<<endl
		<<"     ɾ���ɼ�������������2"<<endl
		<<"     չʾ�ɼ�������������3"<<endl
		<<"     ���гɼ�������������4"<<endl
		<<"     ��ѯ�ɼ�������������5"<<endl
		<<"     �޸����롤����������6"<<endl
		<<"     ע���˺š�����������7"<<endl
		<<"     �˳�ϵͳ������������8"<<endl
		<<endl
		<<"     �����룺";
	cin >> choosen;
	if (choosen > 8 || choosen < 1)
	{
		cout << "     ѡ����������ѡ��" << endl;
		goto start;
	}
	return choosen;
}
void Input()
{
	system("cls");
	cout << "     ¼��ɼ�" << endl;
	R();
	int i = student_num;
	cout << "     ������ѧ������ ��" ;
	cin >> student_num;
	student_num += i;
	system("cls");
	for (;i < student_num;i++)
	{
		R();
		cout << "     �������" << i+1 << "��ѧ������Ϣ" << endl;
		cout << "     ����  ";scanf("%s",&stud[i].name);
		cout << "     ѧ��  ";scanf("%s",&stud[i].number);
		for (int x = 0;x < 4;x++)
		{
			cout << "     ѧ��" << x+1 << " ";
			cin >> stud[i].score[x];
		}
		system("cls");
	}
}
void Output()
{
	system("cls");
	cout << "     չʾ�ɼ�" << endl;
	R();
	cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
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
	cout << "     ɾ���ɼ�" << endl;
	R();
	cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
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
	cout << "     ��ѡ����Ҫɾ������ţ�" ;
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
	cout<< "     �ɼ�����" << endl;
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
	cout << "     ���ҳɼ�" << endl;
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
	int i,flags = 0;
	if (choosen == 1)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
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
			cout << "     ���޽����";
		cout << endl;
	}
	else if (choosen == 2)
	{
		char search[20];
		scanf("%s",&search);
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
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
			cout << "     ���޽����";
		cout << endl;
	}
	else
	{
		int search;
		cin >> search;
		system("cls");
		cout << "     ���  ����   ѧ��       ѧ��1 ѧ��2 ѧ��3 ѧ��4 �ܷ�  ƽ����" << endl;
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
void Change()
{
	char password[20],c_password[20];
start:
	system("cls");
	cout << "     �޸����루�������9λ��" << endl;
	R();
	cout << "     ԭ���룺";
	scanf("%s",&password);
	cout << "     �����룺";
	scanf("%s",&c_password);
	if (strcmp(password,use[user_order].password) == 0)
		for (int m = 0;m < 10;m++)
			use[user_order].password[m] = c_password[m];
	else 
	{
		cout << "     ���������������������룡" ;
		goto start;
	}
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