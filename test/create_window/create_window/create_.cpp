#include <windows.h> 
#include <tchar.h> 
 
//�������� ������� ��������� 
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM); 
 
TCHAR szClassWindow[] = TEXT("��������� ����������");  /* ��� ������ ���� */ 
 
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, 
int nCmdShow) 
{ 
  HWND hWnd; 
  MSG lpMsg; 
  WNDCLASSEX wcl; 
 
  /* 1. ����������� ������ ����  */ 
 
  wcl.cbSize = sizeof (wcl);  // ������ ��������� WNDCLASSEX  
  // ������������ �� ����, ���� ������� ������ �� �����������  
  // ��� �� ��������� 
  wcl.style = CS_HREDRAW | CS_VREDRAW; // CS(Class Style) - ����� ������  
  // ���� 
  wcl.lpfnWndProc = WindowProc; // ����� ������� ��������� 
  wcl.cbClsExtra = 0;  // ������������ Windows  
  wcl.cbWndExtra  = 0;   // ������������ Windows  
  wcl.hInstance = hInst;  // ���������� ������� ���������� 
 
  // �������� ����������� ������ 
  wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
 
  // �������� ������������ ������� 
  wcl.hCursor = LoadCursor(NULL, IDC_ARROW); 
   
   // ���������� ���� ����� ������     
  wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);   
  wcl.lpszMenuName = NULL;  //���������� �� �������� ���� 
  wcl.lpszClassName = szClassWindow;  //��� ������ ���� 
  wcl.hIconSm = NULL; // ���������� ��������� ������ 
   
  /*  2. ����������� ������ ����  */ 
 
  if (!RegisterClassEx(&wcl)) 
    return 0; // ��� ��������� ����������� - ����� 
 
  /*  3. �������� ����  */ 
 
  // ��������� ���� �  ���������� hWnd ������������� ���������� ���� 
  hWnd = CreateWindowEx( 
    0,    // ����������� ����� ����  szClassWindow,  // ��� ������ ���� 
    TEXT("������  Windows ����������"), // ��������� ���� 
    WS_OVERLAPPEDWINDOW,  // ����� ���� 
    /* ���������, �����, ����������� ������ �������, ��������� ����, 
        ������ ������������ � ���������� ����  */ 
    CW_USEDEFAULT,  // �-���������� ������ �������� ���� ���� 
    CW_USEDEFAULT,  // y-���������� ������ �������� ���� ���� 
    CW_USEDEFAULT,  // ������ ���� 
    CW_USEDEFAULT,  // ������ ���� 
    NULL,     // ���������� ������������� ���� 
    NULL,     // ���������� ���� ���� 
    hInst,    // ������������� ����������, ���������� ���� 
    NULL);    // ��������� �� ������� ������ ���������� 
   
  /* 4. ����������� ���� */ 
 
  ShowWindow(hWnd, nCmdShow); 
  UpdateWindow(hWnd);  // ����������� ���� 
 
  /* 5. ������ ����� ��������� ���������  */ 
 
  // ��������� ���������� ��������� �� ������� ��������� 
  while(GetMessage(&lpMsg, NULL, 0, 0))  
  { 
    TranslateMessage(&lpMsg);  // ���������� ��������� 
    DispatchMessage(&lpMsg);  // ��������������� ��������� 
  } 
  return lpMsg.wParam; 
}   
 
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam,   
          LPARAM lParam) 
{ 
  switch(uMessage) 
  { 
    case WM_DESTROY:  // ��������� � ���������� ��������� 
      PostQuitMessage(0);  // ������� ��������� WM_QUIT 
      break; 
    default: 
    // ��� ���������, ������� �� �������������� � ������ �������  
    // ������� ������������ ������� Windows �� ��������� �� ��������� 
      return DefWindowProc(hWnd, uMessage, wParam, lParam); 
  } 
  return 0; 
} 