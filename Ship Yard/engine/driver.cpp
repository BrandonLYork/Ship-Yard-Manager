#include <assert.h>
#include "globals.h"
#include "engine.h"

#include "..\yard\wiring.h"
#include "..\yard\dock.h"

//int main(int argc, char* argv[]) {
//	//_engine * _e;
//	//_e = _engine::ins();
//	// Currently not accepting commands from the command line
//
//	// initialize game
//
//	// run game loop
//
//	// clean up
//	_dock_ d;
//	d.start_new_ship(3, 3, 3);
//	// d.print_dock(0);
//
//	COORD home;
//	home.X = 0;
//	home.Y = 2;
//	
//	do {
//		int ch = getchar();
//		// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), home);
//		printf("\n%i : %c\n", ch, ch);
//	} while (true);
//
//	d.print_sub_dock(0, 0, 0, 1);
//
//	printf("%d", ELECTRICAL);
//	printf("%d", CONTROL);
//	printf("%d", NETWORK);
//
//	printf("Press any key to continue...");
//	getchar();
//	return R_SUCCESS;
//}

_engine * _e;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	_e = _engine::ins();

	_e->init(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	//	// Currently not accepting commands from the command line
	//
	//	// initialize game
	//
	//	// run game loop
	//
	//	// clean up
	//	_dock_ d;
	//	d.start_new_ship(3, 3, 3);
	//	// d.print_dock(0);
	//
	//	COORD home;
	//	home.X = 0;
	//	home.Y = 2;
	//	
	//	do {
	//		int ch = getchar();
	//		// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), home);
	//		printf("\n%i : %c\n", ch, ch);
	//	} while (true);
	//
	//	d.print_sub_dock(0, 0, 0, 1);
	//
	//	printf("%d", ELECTRICAL);
	//	printf("%d", CONTROL);
	//	printf("%d", NETWORK);
	//
	//	printf("Press any key to continue...");
	//	getchar();
	//	return R_SUCCESS;

	/*Engine* engine = Engine::Ins();

	while (!engine->toQuit)
		engine->Work();

	engine->Release(); */

	MSG msg;


	while (PeekMessage(&_e->m_uMsg, _e->m_hWnd, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)_e->getWParams();
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, World!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application specific layout section.

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, _e->getWParams(), _e->getWParams());
		break;
	}

	return 0;
}