#include <time.h>
#include <string>
#include <windows.h>


using namespace std;

#define ADDPOPUPMENU(hmenu, string) \
		HMENU hSubMenu = CreatePopupMenu(); \
		AppendMenu (hmenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, string);

#define ADDMENUITEM(hmenu, ID, string) \
		AppendMenu(hSubMenu, MF_STRING, ID, string);

enum
{
	ID_FILE_EXIT,
	ID_FILE_MSG,
	ID_SHOW_NUMBER
};

const char *clsName = "WinAPI";
string title = "Mini Paint 0.01";
bool running = true;

void CreateMainMenu(HWND hWnd)
{
	HMENU hMenu = CreateMenu();

	ADDPOPUPMENU(hMenu, "&File");
	ADDMENUITEM(hMenu, ID_FILE_EXIT, "&Exit");
	ADDMENUITEM(hMenu, ID_FILE_MSG, "&Show message");
	ADDMENUITEM(hMenu, ID_SHOW_NUMBER, "&Show random number");

	SetMenu(hWnd, hMenu);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CLOSE:
			DestroyWindow(hWnd);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			running = false;
			return 0;

		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case ID_FILE_EXIT:
					PostQuitMessage(0);
					running = false;
					break;

				case ID_FILE_MSG:
					MessageBox(hWnd, "Hello!", "Message", MB_ICONINFORMATION);
					break;

				case ID_SHOW_NUMBER:
					srand(time(NULL));
					int LuckyNumber = rand()%100;
					char *text_boxa = new char[10];
					itoa(LuckyNumber, text_boxa, 10);
					MessageBox(hWnd, (LPCSTR)text_boxa, "Losowa Liczba", MB_OK);
					break;
			}

		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpszCmdLinem, int nMode)
{	
	WNDCLASSEX Okno1;
	ZeroMemory(&Okno1, sizeof(WNDCLASSEX));
	MSG 	   msg;
	HWND hWnd;

	Okno1.cbSize 			= sizeof(WNDCLASSEX);
	Okno1.style  			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	Okno1.lpfnWndProc       = (WNDPROC)WndProc; 
	Okno1.cbClsExtra        = 0;  
	Okno1.cbWndExtra		= 0;
	Okno1.hIcon             = LoadIcon(NULL, IDI_APPLICATION);
	Okno1.hCursor           = LoadCursor(NULL, IDC_ARROW); 
	Okno1.hbrBackground     = (HBRUSH) COLOR_WINDOW; 
	Okno1.lpszMenuName      = NULL;     
	Okno1.lpszClassName     = clsName;      
	Okno1.hInstance         = hInstance;   
	Okno1.hIconSm           = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&Okno1))																	// rejestracja klasy okna!!!!
	{																								// WAŻNE !!!!!
		MessageBox(NULL, "Window Class Registration Error!", "Error", MB_OK);
		return 0;
	}

	if (!(hWnd = CreateWindowEx(WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,									// styl okna
							   clsName,																// wskaźnik do nazwy klasy
							   title.c_str(),														// wskażnik do tytułu okna
							   WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,				// styl tworzonego okna
							   CW_USEDEFAULT, CW_USEDEFAULT,										// pozycja X, Y okna
							   460, 340,															// rozmiar okna
							   NULL,																// handle to nadrzędnego okna (parent)
							   NULL,																// handle do Menu okna
							   hInstance,															// 
							   NULL)))																// lParam
	{
		MessageBox(NULL, "Window Class Registration Error!", "Error", MB_OK);
		return 0;
	}

	CreateMainMenu(hWnd);

	ShowWindow(hWnd, SW_SHOW);

	while(running)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}


