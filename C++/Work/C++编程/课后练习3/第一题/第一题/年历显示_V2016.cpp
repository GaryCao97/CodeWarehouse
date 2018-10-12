#include"head_V2016.h"
void register_function();
void function_one();
void function_two();
void function_three();
void end_function();
void couts(int hour, int minute, int second);
int main()  //主界面函数 
{
	conceal(1, 0); //光标不可见
	string output1 = "   年 历 显 示 系 统    ", output2 = "欢 迎 您 的 访 问", output3 = "V 2016  ";
	for (m = 0; m <= 18; m++)
	{
		if (m == 7 || m == 9 || m == 10 || m == 12 || m == 14){ position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(58, m); cout << "*"; Sleep(second_time_interval); }
		else if (m == 3 || m == 18)                    { position_cursor(00, m); for (i = 1; i <= 80; i++)  { cout << "-";        Sleep(second_time_interval); } }
		else if (m == 6 || m == 15)                    { position_cursor(17, m); for (i = 1; i <= 42; i++)  { cout << "*";        Sleep(second_time_interval); } }
		else if (m == 8)                           { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(27, m); for (i = 0; i <= 23; i++) { cout << output1[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
		else if (m == 11)                          { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(30, m); for (i = 0; i <= 16; i++) { cout << output2[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
		else if (m == 13)                          { position_cursor(17, m); cout << "*"; Sleep(1); position_cursor(50, m); for (i = 0; i <= 07; i++) { cout << output3[i]; Sleep(second_time_interval); } position_cursor(58, m); cout << "*"; Sleep(1); }
	}
	Sleep(main_time_interval);    //延迟等待main_time_interval毫秒数，【下同】 
	register_function();
	/*上述代码解释如下 （结束界面参考此解释）

	0 2 4 6 8 ...		                                          ...80
	1
	2
	3---------------------------------------------------------------
	4
	5
	6         ******************************************
	7         *                                        *
	8         *           年 历 显 示 系 统            *
	9         *                                        *
	10        *                                        *
	11   	  *           欢 迎 你 的 访 问            *
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

	上述图示对应的每行输出如下（每一行的代码对应输出的当行）

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
void register_function()  //主菜单函数 
{
	//int number;
	system("cls");
	cout << "年历显示" << endl
		<< "请选择功能:" << endl
		<< "（1）输入一个年份,输出时在屏幕上显示该年的日历.假定输入的年份在1940~2040年之间;" << endl
		<< "（2）输入年月,输出该月的日历；" << endl
		<< "（3）输入年月日,输出距今天还有多少天,星期几,是否是公历节日;" << endl
		<< "（4）退出系统" << endl;
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
void function_one()    //功能一函数：输出当年年历 
{
	//int year,days,month,month_days,i,j,k,m;
	int H;
	cout << "请输入您需要查询的日历的年份："; conceal(10, 1);  //光标可见
	cin >> year;
loop:
	{
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		m = 5; H = n = 1;
		conceal(1, 0);
		if (year<year0 || year>year1)        //判断输入的年份是否在初始参考年份和结束参考年份的范围内，即1940~2040范围内，若不在，则返回主菜单函数，否则进行年历输出 
		{
			system("cls"); register_function();
		}
		else
		{
			system("cls"); /*for(k=0;k<23;k++) cout<<" ";*/ position_cursor(m, 0); cout << setfill(' ') << year << "的日历：" << endl;
		}
		days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0);
		days = days % 7 + 1;
		for (month = 1; month <= 12; month++)
		{
			//for(k=0;k<23;k++)	cout<<" ";   旧版本代码的输出空格以满足输出界面的位置需要，与下列的position(x,y)移动光标位置的效果一致，【下同 】 
			position_cursor(m, n);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			cout << setw(2) << month << "月:" << endl; n++;
			//for(k=0;k<23;k++)	cout<<" ";
			position_cursor(m, n);
			for (k = 0; k<28; k++) { cout << weekdays[k]; Sleep(string_time_interval); }   //输出  Sun Mon Tue Wed Thu Fri Sat 
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<endl;  换行等价于m++ ,position_cursor(3,m);【下同】 
			n++;
			//for(k=0;k<23;k++)	cout<<" ";
			position_cursor(m, n);
			for (i = 1, j = 1; j <= lmonth(month, year);)     //循环输入当月天数 
			{
				if (i <= days&&days != 7){ cout << setw(4) << " "; i++; Sleep(number_time_interval); }       //判断当月首日的星期再根据条件判断其位置，并相应输出空格 
				else{ cout << setw(4) << j; j++; Sleep(number_time_interval); }
				k = j - 1;
				if ((i + j - 2) % 7 == 0 && k != lmonth(month, year))  //每输入七个数字（第一个行包括空格在内）换行一次 
				{/*cout<<endl;*/ n++;/*for(k=0;k<23;k++)	cout<<" ";*/position_cursor(m, n);
				}
			}
			days = (i + j - 2) % 7;
			Sleep(third_time_interval);
			if (month % 2 == 0){ m = 5, H = n = month / 2 * 10; }
			else { m += P, n = H; }
		}
		cout << endl << endl << "- - - - - - - - - - - - - - - -" << endl
			<< "1) --------上一年日历；" << endl
			<< "2) --------下一年日历；" << endl
			<< "3) --------返回主菜单;" << endl
			<< "4) --------退出系统;" << endl;
	circle:
		{
			conceal(1, 1);
			number = _getch(); //不回显函数，读取一个字符，但不显示在屏幕上，无须回车，头文件加conio.h 【下同】 
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
void function_two()    //功能二函数：输出当年当月的日历 
{
	//int year,days,month,month_days,i,j,k;
	cout << "请输入您需要查询的日历的年月："; conceal(1, 1);
	cin >> year >> month;
	Sleep(third_time_interval);
loop:
	{
		conceal(1, 0);
		sum_month_days = m = 0; system("cls");   //每次进入loop都必须使sum_month_days初始化为0，以免循环调用的时候其未初始化为0，造成的后续结果与理论结果不一致 
		if (year<year0 || year>year1 || month<1 || month>12)   //判断年份、月份是否符合要求 
			register_function();
		days = 366 * lyear(year, year0) + 365 * (year - lyear(year, year0) - year0) + monthl(month, year);   //计算输入的日期到1940.04.01的总天数 
		days = days % 7 + 1;             //根据上述计算的总天数判断键入的日期的当月首日的星期 
		/*cout<<endl<<endl;*/ m += 2;
		//for(k=0;k<23;k++) cout<<" ";
		position_cursor(22, m);
		cout << setfill(' ') << setw(4) << year << "年" << month << "月日历:" << endl; m++;
		//for(k=0;k<23;k++)	cout<<" ";
		position_cursor(22, m);
		for (k = 0; k<28; k++){ cout << weekdays[k]; Sleep(15); }  //输出  Sun Mon Tue Wed Thu Fri Sat
		/*cout<<endl;*/ m++;
		//for(k=0;k<23;k++)	cout<<" ";
		position_cursor(22, m);
		for (i = 1, j = 1; j <= lmonth(month, year);)       //循环输入当月各天 
		{
			if (i <= days&&days != 7)                    //根据当月首日的星期确定其位置以及相应首行的输出空格数，以满足格式要求 
			{
				cout << setw(4) << " "; i++; Sleep(50);
			}
			else
			{
				cout << setw(4) << j; j++; Sleep(50);
			}
			k = j - 1;
			if ((i + j - 2) % 7 == 0 && k != lmonth(month, year)) //每输入七个数字（第一个行包括空格在内）换行一次 
			{/*cout<<endl;*/ m++;/*for(k=0;k<23;k++)	cout<<" ";*/position_cursor(22, m);
			}
		}
		Sleep(500);
		/*cout<<endl<<endl<<endl;*/m += 3; position_cursor(0, m);
		cout << "- - - - - - - - - - - - - - - -" << endl
			<< "1) --------上个月日历;" << endl
			<< "2) --------下个月日历;" << endl
			<< "3) --------返回主菜单;" << endl
			<< "4) --------退出系统;" << endl;
	circle:
		{
			number = _getch();
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
			/*InitializeCriticalSection(&cs);//初始化临界区
			EnterCriticalSection(&cs);//进入临界区
			//操作数据
			MyMoney*=10;//所有访问MyMoney变量的程序都需要这样写Enter.. Leave...
			LeaveCriticalSection(&cs);//离开临界区
			DeleteCriticalSection(&cs);//删除临界区*/
			switch (number)
			{
			case '1'://system("cls"); 
				if (--month>0)
				{
					start_delete();
					//_endthreadex(0);
					goto loop;
				}
				//根据当月的月份考虑是否年份进位问题，如当月是1月，选择上个月日历的时候则年份2016减1，月份变为 12
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
					goto loop;            //根据当月的月份考虑是否年份进位问题 
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
void function_three()  //功能三函数：输出键入的年月日与今日的时间差和键入当日的星期，以及是否为公历节日 
{
	string week_day;
	int days1, days2, day, year_temp, month_temp, day_temp, hour, minute, second;
	sum_month_days = 0; //未使头文件中的monthl()函数再次调用时此变量初始为0 
	cout << "请输入您需要查询的日历的年月日："; conceal(1, 1);
	cin >> year >> month >> day;
	year_temp = year, month_temp = month, day_temp = day;
	system("cls");
	if (year<year0 || year>year1 || month<1 || month>12 || day<1 || day>lmonth(month, year)) { system("cls"); function_three(); }  //判断年份、月份是否符合要求 
	SYSTEMTIME sys;
	GetLocalTime(&sys);   //获取本机日期 
	switch (sys.wDayOfWeek)
	{
	case 1:week_day = "一"; break;
	case 2:week_day = "二"; break;
	case 3:week_day = "三"; break;
	case 4:week_day = "四"; break;
	case 5:week_day = "五"; break;
	case 6:week_day = "六"; break;
	case 0:week_day = "日"; break;
	}
	position_cursor(18, 9);
	cout << "当前时间：" << sys.wYear << "." << setfill('0') << setw(2) << sys.wMonth << "." << setw(2) << sys.wDay << " "
		<< setw(2) << sys.wHour << ":" << setw(2) << sys.wMinute << ":" << setw(2) << sys.wSecond << " 星期" << week_day.c_str();//获取本机的系统时间 
	hour = sys.wHour, minute = sys.wMinute, second = sys.wSecond;
	if (year>sys.wYear)
	{
		year = year + sys.wYear; sys.wYear = year - sys.wYear; year = year - sys.wYear;
		month = month + sys.wMonth; sys.wMonth = month - sys.wMonth; month = month - sys.wMonth;
		day = day + sys.wDay; sys.wDay = day - sys.wDay; day = day - sys.wDay;
	}
	//根据键入的日期和本机的日期考虑是否交换两年份，即若键入的年份大于本机的年份，就交换，保证year<sys.wYear 
	days1 = monthl(month, year) + day;      //计算year对应的日期 到当年第一天的总天数 
	sum_month_days = 0; //未使头文件中的monthl()函数再次调用时此变量初始为0 
	days2 = 366 * lyear(sys.wYear, year) + 365 * (sys.wYear - lyear(sys.wYear, year) - year) + monthl(sys.wMonth, sys.wYear) + sys.wDay; //计算sys.wYear所对应的日期到year当年元月一日的总天数 
	days1 = (int)fabs((double)(days2 - days1));   //两数相差取绝对值 
	sum_month_days = 0; //未使头文件中的monthl()函数再次调用时此变量初始为0
	days2 = 366 * lyear(year_temp, year0) + 365 * (year_temp - lyear(year_temp, year0) - year0) + monthl(month_temp, year_temp) + day_temp;  //重新计算year_temp对应的日期到1940.01.01的总天数 用以判断其星期 
	switch (days2 % 7)
	{
	case 1:week_day = "一"; break;
	case 2:week_day = "二"; break;
	case 3:week_day = "三"; break;
	case 4:week_day = "四"; break;
	case 5:week_day = "五"; break;
	case 6:week_day = "六"; break;
	case 0:week_day = "日"; break;
	}
	conceal(1, 0);
	position_cursor(18, 11);
	cout << year_temp << "年" << month_temp << "月" << day_temp << "日距今" << days1 << "天,星期" << week_day.c_str() << " ";
	festival(year_temp, month_temp, day_temp);
	position_cursor(1, 20);
	cout << endl << "- - - - - - - - - - - - - - - -" << endl
		<< "1) --------重新计算;" << endl
		<< "2) --------返回主菜单;" << endl
		<< "3) --------退出系统;" << endl;
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
void end_function()   //结束界面函数 
{
	//int i;
	conceal(10, 0);//光标不可见 
	string cout1 = "  我 到 底 错 哪 儿 了 ？", cout2 = "    地 表 最 强 5 1 8   ", cout3 = "--------------------------";
	system("cls");
	Sleep(2000);
	for (i = y0; i <= y0 + 6; i++)
	{
		position_cursor(x0, i);
		if (i == y0 || i == y0 + 6) cout << "-------------------------" << endl;
		else if (i == y0 + 2)        cout << "    感 谢 您 的 使 用    ";
		else if (i == (y0 + 4))      cout << "          再 见          ";
	}
	Sleep(3000);
	position_cursor(x0, y0 + 2); cout << "                         " << endl;
	position_cursor(x0, y0 + 4); cout << "                         " << endl;
	position_cursor(x0, y0 + 3); for (i = 0; i<25; i++) { cout << cout1[i]; Sleep(30); }
	Sleep(2000);
	position_cursor(x0, y0 + 3); for (i = 0; i<24; i++) { cout << cout2[i]; Sleep(10); }
	Sleep(1000);
	for (k = 0; k <= 0; k++)   //结束界面cout2字符串高亮输出 
	{
		position_cursor(x0, y0 + 3); for (i = 0; i<24; i++){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);/*system("color F");*/cout << cout2[i]; Sleep(2); }
		position_cursor(x0, y0 + 3); for (i = 0; i<24; i++){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 07);/*system("color 7");*/cout << cout2[i]; Sleep(2); }
	}
	Sleep(main_time_interval);
	position_cursor(1, 20);
	exit(0); //无条件结束程序 
}
//功能三函数的计时与判断跳转同步的相关函数 
unsigned int  __stdcall ScanInputThread(void *arg)   //功能三函数的附属键盘线程函数 
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
void couts(int hour, int minute, int second)   //功能三函数的附属计时线程函数 
{
	conceal(10, 0);
	InitializeCriticalSection(&CS); //初始化临界区资源
	_beginthreadex(NULL, 0, ScanInputThread, NULL, 0, NULL);//创建线程 
	while (1)    //永真循环 
	{
		EnterCriticalSection(&CS);  //进入临界区
		second++;
		if (second == 60)
		{
			minute += second / 60;                //输出分钟 
			second %= 60;
			if (minute == 60)
			{
				minute %= 60;
				hour += minute / 60;               //输出秒数 
			}
		}
		position_cursor(39, 9);
		cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
		LeaveCriticalSection(&CS); //离开临界区
		wait(1);   //效果与Sleep(1000);相同	
	}
}
