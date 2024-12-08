#include <windows.h> 
#include <tchar.h> 
 
//прототип оконной процедуры 
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM); 
 
TCHAR szClassWindow[] = TEXT(" аркасное приложение");  /* »м€ класса окна */ 
 
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, 
int nCmdShow) 
{ 
  HWND hWnd; 
  MSG lpMsg; 
  WNDCLASSEX wcl; 
 
  /* 1. ќпределение класса окна  */ 
 
  wcl.cbSize = sizeof (wcl);  // размер структуры WNDCLASSEX  
  // ѕерерисовать всЄ окно, если изменЄн размер по горизонтали  
  // или по вертикали 
  wcl.style = CS_HREDRAW | CS_VREDRAW; // CS(Class Style) - стиль класса  
  // окна 
  wcl.lpfnWndProc = WindowProc; // адрес оконной процедуры 
  wcl.cbClsExtra = 0;  // используетс€ Windows  
  wcl.cbWndExtra  = 0;   // используетс€ Windows  
  wcl.hInstance = hInst;  // дескриптор данного приложени€ 
 
  // загрузка стандартной иконки 
  wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
 
  // загрузка стандартного курсора 
  wcl.hCursor = LoadCursor(NULL, IDC_ARROW); 
   
   // заполнение окна белым цветом     
  wcl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);   
  wcl.lpszMenuName = NULL;  //приложение не содержит меню 
  wcl.lpszClassName = szClassWindow;  //им€ класса окна 
  wcl.hIconSm = NULL; // отсутствие маленькой иконки 
   
  /*  2. –егистраци€ класса окна  */ 
 
  if (!RegisterClassEx(&wcl)) 
    return 0; // при неудачной регистрации - выход 
 
  /*  3. —оздание окна  */ 
 
  // создаетс€ окно и  переменной hWnd присваиваетс€ дескриптор окна 
  hWnd = CreateWindowEx( 
    0,    // расширенный стиль окна  szClassWindow,  // им€ класса окна 
    TEXT(" аркас  Windows приложени€"), // заголовок окна 
    WS_OVERLAPPEDWINDOW,  // стиль окна 
    /* «аголовок, рамка, позвол€юща€ мен€ть размеры, системное меню, 
        кнопки развЄртывани€ и свЄртывани€ окна  */ 
    CW_USEDEFAULT,  // х-координата левого верхнего угла окна 
    CW_USEDEFAULT,  // y-координата левого верхнего угла окна 
    CW_USEDEFAULT,  // ширина окна 
    CW_USEDEFAULT,  // высота окна 
    NULL,     // дескриптор родительского окна 
    NULL,     // дескриптор меню окна 
    hInst,    // идентификатор приложени€, создавшего окно 
    NULL);    // указатель на область данных приложени€ 
   
  /* 4. ќтображение окна */ 
 
  ShowWindow(hWnd, nCmdShow); 
  UpdateWindow(hWnd);  // перерисовка окна 
 
  /* 5. «апуск цикла обработки сообщений  */ 
 
  // получение очередного сообщени€ из очереди сообщений 
  while(GetMessage(&lpMsg, NULL, 0, 0))  
  { 
    TranslateMessage(&lpMsg);  // трансл€ци€ сообщени€ 
    DispatchMessage(&lpMsg);  // диспетчеризаци€ сообщений 
  } 
  return lpMsg.wParam; 
}   
 
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam,   
          LPARAM lParam) 
{ 
  switch(uMessage) 
  { 
    case WM_DESTROY:  // сообщение о завершении программы 
      PostQuitMessage(0);  // посылка сообщени€ WM_QUIT 
      break; 
    default: 
    // все сообщени€, которые не обрабатываютс€ в данной оконной  
    // функции направл€ютс€ обратно Windows на обработку по умолчанию 
      return DefWindowProc(hWnd, uMessage, wParam, lParam); 
  } 
  return 0; 
} 