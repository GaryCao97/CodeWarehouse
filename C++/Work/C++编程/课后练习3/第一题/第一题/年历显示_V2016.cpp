#include"head_V2016.h"
void register_function();
void function_one();
void function_two();
void function_three();
void end_function();
void couts(int hour, int minute, int second);
int main()  //�����溯�� 
{
	conceal(1, 0); //��겻�ɼ�
	string output1 = "   �� �� �� ʾ ϵ ͳ    ", output2 = "�� ӭ �� �� �� ��", output3 = "V 2016  ";
	for (m = 0; m <= 18; m++)
	{
		if (m == 7 || m == 9 || m == 10 || m == 12 || m == 14){ position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(58, m); cout << "*"; Sleep(second_time_interval); }
		else if (m == 3 || m == 18)                    { position_cursor(00, m); for (i = 1; i <= 80; i++)  { cout << "-";        Sleep(second_time_interval); } }
		else if (m == 6 || m == 15)                    { position_cursor(17, m); for (i = 1; i <= 42; i++)  { cout << "*";        Sleep(second_time_interval); } }
		else if (m == 8)                           { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(27, m); for (i = 0; i <= 23; i++) { cout << output1[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
		else if (m == 11)                          { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(30, m); for (i = 0; i <= 16; i++) { cout << output2[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
		else if (m == 13)                          { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(50, m); for (i = 0; i <= 07; i++) { cout << output3[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
	}
	Sleep(main_time_interval);    //�ӳٵȴ�main_time_interval������������ͬ�� 
	register_function();
	/*��������������� ����������ο��˽��ͣ�

	0 2 4 6 8 ...		                                          ...80
	1
	2
	3---------------------------------------------------------------
	4
	5
	6         ******************************************
	7         *                                        *
	8         *           �� �� �� ʾ ϵ ͳ            *
	9         *                                        *
	10        *                                        *
	11   	  *           �� ӭ �� �� �� ��            *
	12        *                                        *
	13        *                               V 2016   *
	14        *                                        *
	15        ******************************************
	16
	17
	18 -------------------------------------------------------------
	.
	.
	.

	����ͼʾ��Ӧ��ÿ��������£�ÿһ�еĴ����Ӧ����ĵ��У�

	0
	1
	2
	3  n+=3; position_cursor(0,n); for(i=1;i<=80;i++) {cout<<"-"; Sleep(second_time_interval);}
	4
	5
	6  n+=3; position_cursor(17,n); for(i=1;i<=42;i++) cout<<"*";
	7  n++ ; position_cursor(17,n); cout<<"*"; position_cursor(58,n); cout<<"*";
	8  n++ ; position_cursor(17,n); cout<<"*"; position_cursor(27,n); for(i=0;i<=23;i++) {cout<<output1[i];Sleep(second_time_interval);} position_cursor(58,n); cout<<"*";
	9
	10 n++ ; position_cursor(17,n); cout<<"*"; position_cursor(58,n); cout<<"*";
	11 n++ ; position_cursor(17,n); cout<<"*"; position_cursor(30,n); for(i=0;i<=16;i++) {cout<<output2[i];Sleep(second_time_interval);} position_cursor(58,n); cout<<"*";
	12 n++ ; position_cursor(17,n); cout<<"*"; position_cursor(58,n); cout<<"*";
	13 n++ ; position_cursor(17,n); cout<<"*"; position_cursor(51,n); for(i=0;i<=07;i++) {cout<<output3[i];Sleep(second_time_interval);} position_cursor(58,n); cout<<"*";
	14 n++ ; position_cursor(17,n); cout<<"*"; position_cursor(58,n); cout<<"*";
	15 n++ ; position_cursor(17,n); for(i=1;i<=42;i++) cout<<"*";
	16
	17
	18 n+=2; position_cursor(0,n);for(i=1;i<=80;i++) {cout<<"-"; Sleep(second_time_interval);}
	Sleep(3000);*/
}
void register_function()  //���˵����� 
{
	//int number;
	system("cls");
	cout << "������ʾ" << endl
		<< "��ѡ����:" << endl
		<< "��1������һ�����,���ʱ����Ļ����ʾ���������.�ٶ�����������1940~2040��֮��;" << endl
		<< "��2����������,������µ�������" << endl
		<< "��3������������,�������컹�ж�����,���ڼ�,�Ƿ��ǹ�������;" << endl
		<< "��4���˳�ϵͳ" << endl;
	Sleep(500);
	number = _getch();
	switch (number)
	{
	case '1':function_one(); break;
	case '2':function_two(); break;
	case '3':function_three(); break;
	case '4':end_function(); break;
	default:register_function();
	}
}
void function_one()    //����һ����������������� 
{
	//int year,days,month,month_days,i,j,k,m;
	int H;
	cout << "����������Ҫ��ѯ����������ݣ�"; conceal(10, 1);  //���ɼ�
	cin >> year;
loop:
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		m = 5; H = n = 1;
		conceal(1, 0);
		if (year<year0 || year>year1)        //�ж����������Ƿ��ڳ�ʼ�ο���ݺͽ����ο���ݵķ�Χ�ڣ���1940~2040��Χ�ڣ������ڣ��򷵻����˵��������������������� 
		{
			system("cls"); register_function();
		}
		else
		{
			system("cls"); /*for(k=0;k<23;k++) cout<<" ";*/ position_cursor(m, 0); cout << setfill(' ') << year << "��������" << endl;
		}
		days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0);
		days = days % 7 + 1;
		for (month = 1; month <= 12; month++)
		{
			//for(k=0;k<23;k++)	cout<<" ";   �ɰ汾���������ո���������������λ����Ҫ�������е�position(x,y)�ƶ����λ�õ�Ч��һ�£�����ͬ �� 
			position_cursor(m, n);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			cout << setw(2) << month << "��:" << endl; n++;
			//for(k=0;k<23;k++)	cout<<" ";
			position_cursor(m, n);
			for (k = 0; k<28; k++) { cout << weekdays[k]; Sleep(string_time_interval); }   //���  Sun Mon Tue Wed Thu Fri Sat 
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<endl;  ���еȼ���m++ ,position_cursor(3,m);����ͬ�� 
			n++;
			//for(k=0;k<23;k++)	cout<<" ";
			position_cursor(m, n);
			for (i = 1, j = 1; j <= lmonth(month, year);)     //ѭ�����뵱������ 
			{
				if (i <= days&&days != 7){ cout << setw(4) << " "; i++; Sleep(number_time_interval); }       //�жϵ������յ������ٸ��������ж���λ�ã�����Ӧ����ո� 
				else{ cout << setw(4) << j; j++; Sleep(number_time_interval); }
				k = j - 1;
				if ((i + j - 2) % 7 == 0 && k != lmonth(month, year))  //ÿ�����߸����֣���һ���а����ո����ڣ�����һ�� 
				{/*cout<<endl;*/ n++;/*for(k=0;k<23;k++)	cout<<" ";*/position_cursor(m, n);
				}
			}
			days = (i + j - 2) % 7;
			Sleep(third_time_interval);
			if (month % 2 == 0){ m = 5, H = n = month / 2 * 10; }
			else { m += P, n = H; }
		}
		cout << endl << endl << "- - - - - - - - - - - - - - - -" << endl
			<< "1) --------��һ��������" << endl
			<< "2) --------��һ��������" << endl
			<< "3) --------�������˵�;" << endl
			<< "4) --------�˳�ϵͳ;" << endl;
	circle:
		{
			conceal(1, 1);
			number = _getch(); //�����Ժ�������ȡһ���ַ���������ʾ����Ļ�ϣ�����س���ͷ�ļ���conio.h ����ͬ�� 
			switch (number)
			{
			case '1': year--; system("cls"); goto loop; break;
			case '2': year++; system("cls"); goto loop; break;
			case '3':register_function(); break;
			case '4':end_function(); break;
			default:goto circle;
			}
		}
	}
}
void function_two()    //���ܶ�������������굱�µ����� 
{
	//int year,days,month,month_days,i,j,k;
	cout << "����������Ҫ��ѯ�����������£�"; conceal(1, 1);
	cin >> year >> month;
	Sleep(third_time_interval);
loop:
	{
		conceal(1, 0);
		sum_month_days = m = 0; system("cls");   //ÿ�ν���loop������ʹsum_month_days��ʼ��Ϊ0������ѭ�����õ�ʱ����δ��ʼ��Ϊ0����ɵĺ�����������۽����һ�� 
		if (year<year0 || year>year1 || month<1 || month>12)   //�ж���ݡ��·��Ƿ����Ҫ�� 
			register_function();
		days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0) + monthl(month, year);   //������������ڵ�1940.04.01�������� 
		days = days % 7 + 1;             //��������������������жϼ�������ڵĵ������յ����� 
		/*cout<<endl<<endl;*/ m += 2;
		//for(k=0;k<23;k++) cout<<" ";
		position_cursor(22, m);
		cout << setfill(' ') << setw(4) << year << "��" << month << "������:" << endl; m++;
		//for(k=0;k<23;k++)	cout<<" ";
		position_cursor(22, m);
		for (k = 0; k<28; k++){ cout << weekdays[k]; Sleep(15); }  //���  Sun Mon Tue Wed Thu Fri Sat
		/*cout<<endl;*/ m++;
		//for(k=0;k<23;k++)	cout<<" ";
		position_cursor(22, m);
		for (i = 1, j = 1; j <= lmonth(month, year);)       //ѭ�����뵱�¸��� 
		{
			if (i <= days&&days != 7)                    //���ݵ������յ�����ȷ����λ���Լ���Ӧ���е�����ո������������ʽҪ�� 
			{
				cout << setw(4) << " "; i++; Sleep(50);
			}
			else
			{
				cout << setw(4) << j; j++; Sleep(50);
			}
			k = j - 1;
			if ((i + j - 2) % 7 == 0 && k != lmonth(month, year)) //ÿ�����߸����֣���һ���а����ո����ڣ�����һ�� 
			{/*cout<<endl;*/ m++;/*for(k=0;k<23;k++)	cout<<" ";*/position_cursor(22, m);
			}
		}
		Sleep(500);
		/*cout<<endl<<endl<<endl;*/m += 3; position_cursor(0, m);
		cout << "- - - - - - - - - - - - - - - -" << endl
			<< "1) --------�ϸ�������;" << endl
			<< "2) --------�¸�������;" << endl
			<< "3) --------�������˵�;" << endl
			<< "4) --------�˳�ϵͳ;" << endl;
	circle:
		{
			number = _getch();
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			/*InitializeCriticalSection(&cs);//��ʼ���ٽ���
			EnterCriticalSection(&cs);//�����ٽ���
			//��������
			MyMoney*=10;//���з���MyMoney�����ĳ�����Ҫ����дEnter.. Leave...
			LeaveCriticalSection(&cs);//�뿪�ٽ���
			DeleteCriticalSection(&cs);//ɾ���ٽ���*/
			switch (number)
			{
			case '1'://system("cls"); 
				if (--month>0)
				{
					start_delete();
					//_endthreadex(0);
					goto loop;
				}
				//���ݵ��µ��·ݿ����Ƿ���ݽ�λ���⣬�統����1�£�ѡ���ϸ���������ʱ�������2016��1���·ݱ�Ϊ 12
				else
				{
					--year; month = 12;
					start_delete();
					//_endthreadex(0);
					goto loop;
				}; break;
			case '2'://system("cls");
				if (++month<13)
				{
					start_delete();
					//_endthreadex(0);
					goto loop;            //���ݵ��µ��·ݿ����Ƿ���ݽ�λ���� 
				}
				else
				{
					++year; month = 1;
					start_delete();
					//_endthreadex(0);
					goto loop;
				}; break;
			case '3':register_function(); break;
			case '4':end_function(); break;
			default:goto circle;
			}
		}
	}
}
void function_three()  //������������������������������յ�ʱ���ͼ��뵱�յ����ڣ��Լ��Ƿ�Ϊ�������� 
{
	string week_day;
	int days1, days2, day, year_temp, month_temp, day_temp, hour, minute, second;
	sum_month_days = 0; //δʹͷ�ļ��е�monthl()�����ٴε���ʱ�˱�����ʼΪ0 
	cout << "����������Ҫ��ѯ�������������գ�"; conceal(1, 1);
	cin >> year >> month >> day;
	year_temp = year, month_temp = month, day_temp = day;
	system("cls");
	if (year<year0 || year>year1 || month<1 || month>12 || day<1 || day>lmonth(month, year)) { system("cls"); function_three(); }  //�ж���ݡ��·��Ƿ����Ҫ�� 
	SYSTEMTIME sys;
	GetLocalTime(&sys);   //��ȡ�������� 
	switch (sys.wDayOfWeek)
	{
	case 1:week_day = "һ"; break;
	case 2:week_day = "��"; break;
	case 3:week_day = "��"; break;
	case 4:week_day = "��"; break;
	case 5:week_day = "��"; break;
	case 6:week_day = "��"; break;
	case 0:week_day = "��"; break;
	}
	position_cursor(18, 9);
	cout << "��ǰʱ�䣺" << sys.wYear << "." << setfill('0') << setw(2) << sys.wMonth << "." << setw(2) << sys.wDay << " "
		<< setw(2) << sys.wHour << ":" << setw(2) << sys.wMinute << ":" << setw(2) << sys.wSecond << " ����" << week_day.c_str();//��ȡ������ϵͳʱ�� 
	hour = sys.wHour, minute = sys.wMinute, second = sys.wSecond;
	if (year>sys.wYear)
	{
		year = year + sys.wYear; sys.wYear = year - sys.wYear; year = year - sys.wYear;
		month = month + sys.wMonth; sys.wMonth = month - sys.wMonth; month = month - sys.wMonth;
		day = day + sys.wDay; sys.wDay = day - sys.wDay; day = day - sys.wDay;
	}
	//���ݼ�������ںͱ��������ڿ����Ƿ񽻻�����ݣ������������ݴ��ڱ�������ݣ��ͽ�������֤year<sys.wYear 
	days1 = monthl(month, year) + day;      //����year��Ӧ������ �������һ��������� 
	sum_month_days = 0; //δʹͷ�ļ��е�monthl()�����ٴε���ʱ�˱�����ʼΪ0 
	days2 = 366 * lyear(sys.wYear, year) + 365 * (sys.wYear - lyear(sys.wYear, year) - year) + monthl(sys.wMonth, sys.wYear) + sys.wDay; //����sys.wYear����Ӧ�����ڵ�year����Ԫ��һ�յ������� 
	days1 = (int)fabs((double)(days2 - days1));   //�������ȡ����ֵ 
	sum_month_days = 0; //δʹͷ�ļ��е�monthl()�����ٴε���ʱ�˱�����ʼΪ0
	days2 = 366 * lyear(year_temp, year0) + 365 * (year_temp - lyear(year_temp, year0) - year0) + monthl(month_temp, year_temp) + day_temp;  //���¼���year_temp��Ӧ�����ڵ�1940.01.01�������� �����ж������� 
	switch (days2 % 7)
	{
	case 1:week_day = "һ"; break;
	case 2:week_day = "��"; break;
	case 3:week_day = "��"; break;
	case 4:week_day = "��"; break;
	case 5:week_day = "��"; break;
	case 6:week_day = "��"; break;
	case 0:week_day = "��"; break;
	}
	conceal(1, 0);
	position_cursor(18, 11);
	cout << year_temp << "��" << month_temp << "��" << day_temp << "�վ��" << days1 << "��,����" << week_day.c_str() << " ";
	festival(year_temp, month_temp, day_temp);
	position_cursor(1, 20);
	cout << endl << "- - - - - - - - - - - - - - - -" << endl
		<< "1) --------���¼���;" << endl
		<< "2) --------�������˵�;" << endl
		<< "3) --------�˳�ϵͳ;" << endl;
	couts(hour, minute, second);
	/*circle:
	{
	number=_getch();
	switch(number)
	{
	case '1':
	system("cls");
	function_three();break;
	case '2':
	system("cls");
	register_function();break;
	case '3':
	system("cls");
	end_function();break;
	default:goto circle;
	}
	}*/
}
void end_function()   //�������溯�� 
{
	//int i;
	conceal(10, 0);//��겻�ɼ� 
	string cout1 = "  �� �� �� �� �� �� �� ��", cout2 = "    �� �� �� ǿ 5 1 8   ", cout3 = "--------------------------";
	system("cls");
	Sleep(2000);
	for (i = y0; i <= y0 + 6; i++)
	{
		position_cursor(x0, i);
		if (i == y0 || i == y0 + 6) cout << "-------------------------" << endl;
		else if (i == y0 + 2)        cout << "    �� л �� �� ʹ ��    ";
		else if (i == (y0 + 4))      cout << "          �� ��          ";
	}
	Sleep(3000);
	position_cursor(x0, y0 + 2); cout << "                         " << endl;
	position_cursor(x0, y0 + 4); cout << "                         " << endl;
	position_cursor(x0, y0 + 3); for (i = 0; i<25; i++) { cout << cout1[i]; Sleep(30); }
	Sleep(2000);
	position_cursor(x0, y0 + 3); for (i = 0; i<24; i++) { cout << cout2[i]; Sleep(10); }
	Sleep(1000);
	for (k = 0; k <= 0; k++)   //��������cout2�ַ���������� 
	{
		position_cursor(x0, y0 + 3); for (i = 0; i<24; i++){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);/*system("color F");*/cout << cout2[i]; Sleep(2); }
		position_cursor(x0, y0 + 3); for (i = 0; i<24; i++){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);/*system("color 7");*/cout << cout2[i]; Sleep(2); }
	}
	Sleep(main_time_interval);
	position_cursor(1, 20);
	exit(0); //�������������� 
}
//�����������ļ�ʱ���ж���תͬ������غ��� 
unsigned int  __stdcall ScanInputThread(void *arg)   //�����������ĸ��������̺߳��� 
{
	while (1)
	{
		int i = _getch();
		if (i == '1' || i == '2' || i == '3')
		{
			EnterCriticalSection(&CS);
			switch (i)
			{
			case '1':
				system("cls");
				function_three();
				break;
			case '2':
				system("cls");
				register_function();
				break;
			case '3':
				system("cls");
				end_function();
				break;
			}
		}
		else
			LeaveCriticalSection(&CS);
		Sleep(100);
	}
}
void couts(int hour, int minute, int second)   //�����������ĸ�����ʱ�̺߳��� 
{
	conceal(10, 0);
	InitializeCriticalSection(&CS); //��ʼ���ٽ�����Դ
	_beginthreadex(NULL, 0, ScanInputThread, NULL, 0, NULL);//�����߳� 
	while (1)    //����ѭ�� 
	{
		EnterCriticalSection(&CS);  //�����ٽ���
		second++;
		if (second == 60)
		{
			minute += second / 60;                //������� 
			second %= 60;
			if (minute == 60)
			{
				minute %= 60;
				hour += minute / 60;               //������� 
			}
		}
		position_cursor(39, 9);
		cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
		LeaveCriticalSection(&CS); //�뿪�ٽ���
		wait(1);   //Ч����Sleep(1000);��ͬ	
	}
}
