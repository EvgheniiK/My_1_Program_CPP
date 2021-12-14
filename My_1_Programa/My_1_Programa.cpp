// My_1_Programa.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "My_1_Programa.h"
#include <windows.h>
#include <commctrl.h>
#include <tchar.h>

#define MAX_LOADSTRING 100
HINSTANCE hInst;
int x; int y;

char buf[100];
char buf2[100];



// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	UNREFERENCED_PARAMETER(lParam);

	HDC hdc, hCompatibleDC;
	PAINTSTRUCT ps;
	HANDLE hbitmap, holdbitmap, hImg;
	RECT rect;
	BITMAP bitmap;

	static HBITMAP hBitmap, hOldBitmap;
	static BITMAP bm;
	static HDC hMemDC;


	static WCHAR szHello[MAX_LOADSTRING];
	static int xt = 100, yt = 100;

	RECT cr, cr2;//область прямоугольника


	static TCHAR usa[] = _T("     Это СШП      ");
	static TCHAR russia[] = _T("  Это Россия      ");
	static TCHAR default1[] = _T("                           ");
	static TCHAR lpDesktop55[] = _T("E:\\win256_3.bmp");



	switch (message)
	{

	case WM_CREATE:


		break;


	case WM_MOUSEMOVE:

		x = LOWORD(lParam);
		y = HIWORD(lParam);


		_itoa_s(x, buf, 10);
		_itoa_s(y, buf2, 10);

		InvalidateRect(hDlg, NULL, FALSE);//перерисовка

		break;


	case WM_PAINT:
	{

		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		GetClientRect(hDlg, &cr);



		const COLORREF rgbRed = 0xeaeaea;
		if (x > 220 && x < 400 && y>400 && y < 500)
		{
			SetBkColor(hdc, rgbRed);
			DrawText(hdc, usa, -1, &cr, DT_CENTER | DT_INTERNAL | DT_NOCLIP);
		}



		if (x > 700 && x < 1200 && y>100 && y < 400)
		{
			SetBkColor(hdc, rgbRed);
			DrawText(hdc, russia, -1, &cr, DT_CENTER);

		}

		if (x > 80 && x < 160 && y>250 && y < 340)
		{
			SetBkColor(hdc, rgbRed);
			DrawText(hdc, usa, -1, &cr, DT_CENTER);

		}
		else { InvalidateRect(hDlg, NULL, 0); }

		SetBkColor(hdc, rgbRed);
		TextOutA(hdc, 0, 0, buf, strlen(buf));
		TextOutA(hdc, 0, 20, buf2, strlen(buf2));

		EndPaint(hDlg, &ps);


	}
	break;

	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), 0, About);

}





