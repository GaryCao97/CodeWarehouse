// WHello.cpp
#include<Windows.h>
//#include<stdio.h>
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LPCWSTR szAppName = L"WHello";
//������ں���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	HWND hWnd;
	MSG msg;
	WNDCLASS wndClass;
	//ע�ᴰ����
	if (!hPrevInstance) {
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc = WndProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = hInstance;
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndClass.lpszMenuName = NULL;
		wndClass.lpszClassName = szAppName;
		if (!RegisterClass(&wndClass))return FALSE;
	}
	//��������ʾ����
	hWnd = CreateWindow(szAppName, L"Hello Program", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	if (!hWnd)return FALSE;
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	//��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}
//��Ϣ����Ĵ��ڹ��̺���
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static LPCTSTR str = L"Hello, Welcome to Windows!";
	PAINTSTRUCT ps;
	HDC hDC;
	//int x, y;
	//wchar_t buf[20];
	switch (uMsg){
	case WM_PAINT://���ƿͻ���
		hDC = BeginPaint(hWnd, &ps);
		TextOut(hDC, 0, 0, str, (int)wcslen(str));
		EndPaint(hWnd, &ps);
		return 0;
	//case WM_LBUTTONUP:
	//	x = LOWORD(lParam);
	//	y = HIWORD(lParam);
	//	swprintf(buf, 20, L"Hello! (%d, %d)", x, y);
	//	hDC = GetDC(hWnd);
	//	TextOut(hDC, 0, 0, buf, (int)wcslen(buf));
	//	ReleaseDC(hWnd, hDC);
	//	return 0;
	case WM_DESTROY://�رմ��ںͳ���

		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}