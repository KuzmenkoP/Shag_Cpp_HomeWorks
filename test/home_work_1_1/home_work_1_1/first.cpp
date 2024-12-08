
#include <iostream>
#include <Windows.h>
#include <tchar.h>
//#define _UNICOD
using namespace std;

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[]=TEXT("Каркасное приложение");


INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASSEX wc1;

	wc1.cbSize=sizeof(wc1);
	wc1.style=CS_HREDRAW|CS_VREDRAW;
	wc1.lpfnWndProc=WindowProc;
	wc1.cbClsExtra=0;
	wc1.cbWndExtra=0;
	wc1.hInstance=hInst;
	wc1.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	wc1.hCursor=LoadCursor(NULL, IDC_ARROW);
	wc1.hbrBackground=(HBRUSH) GetStockObject(WHITE_BRUSH);
	wc1.lpszMenuName=NULL;
	wc1.lpszClassName=szClassWindow;
	wc1.hIconSm=NULL;

	if(!RegisterClassEx(&wc1)) return 0;

	hWnd=CreateWindowEx(0,
						szClassWindow,
						TEXT("Виндовс приложение"),
						WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						CW_USEDEFAULT,
						NULL,
						NULL,
						hInst,
						NULL);

	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);


	while (GetMessage(&lpMsg, NULL,0,0))
	{
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return lpMsg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMessage,wParam,lParam);
	}
	return 0;
}