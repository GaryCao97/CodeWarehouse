
//这是2个线程模拟卖火车票的小程序
#include <windows.h>
#include <iostream>
using namespace std;

DWORD WINAPI Fun1Proc(LPVOID lpParameter);//thread data
DWORD WINAPI Fun2Proc(LPVOID lpParameter);//thread data
DWORD WINAPI Fun3Proc(LPVOID lpParameter);//thread data

int index = 0;
int tickets = 10;
HANDLE hMutex;
void main()
{
	HANDLE hThread1;
	HANDLE hThread2;
	HANDLE hThread3;
	//创建线程

	hThread1 = CreateThread(NULL, 0, Fun1Proc, NULL, 0, NULL);
	hThread2 = CreateThread(NULL, 0, Fun2Proc, NULL, 0, NULL);
	hThread3 = CreateThread(NULL, 0, Fun3Proc, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);

	//创建互斥对象
	hMutex = CreateMutex(NULL, TRUE, L"tickets");
	if (hMutex)
	{
		if (ERROR_ALREADY_EXISTS == GetLastError())
		{
			cout << "only one instance can run!" << endl;
			return;
		}
	}
	WaitForSingleObject(hMutex, INFINITE);
	ReleaseMutex(hMutex);
	ReleaseMutex(hMutex);
	ReleaseMutex(hMutex);

	Sleep(4000);
}
//线程1的入口函数
DWORD WINAPI Fun1Proc(LPVOID lpParameter)//thread data
{
	while (true)
	{
		ReleaseMutex(hMutex);
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
		{
			Sleep(1);
			cout << "thread1 sell ticket :" << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);
	}

	return 0;
}
//线程2的入口函数
DWORD WINAPI Fun2Proc(LPVOID lpParameter)//thread data
{
	while (true)
	{
		ReleaseMutex(hMutex);
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
		{
			Sleep(1);
			cout << "thread2 sell ticket :" << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);
	}

	return 0;
}
//线程3的入口函数
DWORD WINAPI Fun3Proc(LPVOID lpParameter)//thread data
{
	while (true)
	{
		ReleaseMutex(hMutex);
		WaitForSingleObject(hMutex, INFINITE);
		if (tickets>0)
		{
			Sleep(1);
			cout << "thread3 sell ticket :" << tickets-- << endl;
		}
		else
			break;
		ReleaseMutex(hMutex);
	}

	return 0;
}
