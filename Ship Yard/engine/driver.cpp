#include <assert.h>
#include <time.h>

#include "globals.h"
#include "engine.h"

#include "..\yard\wiring.h"
#include "..\yard\dock.h"

// Global variables

// The main window class name.
static TCHAR szWindowClass[] = ("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = ("Win32 Guided Tour Application");

_engine * _e;

COORD viewport;

clock_t FPSTimer = clock();
clock_t drawTimer = clock();
RECT r;

int frames, framesSoFar, elapsed = 0;
int cycles, cyclesSoFar = 0;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	char buffer[128];	

	switch (message)
	{
	case WM_PAINT:
		sprintf_s(buffer, "Greetings, FPS[%d] Cycles[%d]", frames, cycles);
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, World!"
		// in the top left corner.
		DrawText(hdc, buffer, strlen(buffer), &r, DT_LEFT);
			//5, 5,
		
			//buffer, strlen(buffer));
		// End application-specific layout section.
		
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_RIGHT:
			r.right++;
			viewport.X += 1;
			break;
		case VK_LEFT:
			r.right--;
			viewport.X -= 1;
			if (viewport.X < 0) viewport.X = 0;
			break;
		case VK_UP:
			viewport.Y -= 1;
			if (viewport.Y < 0) viewport.Y = 0;
			break;
		case VK_DOWN:
			viewport.Y += 1;
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		_e->end_game();
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	_e = _engine::ins();
	_e->getwindows_class().lpfnWndProc = WndProc;
	_e->init(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	// ShowWindow(hWnd,	nCmdShow);
	// UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;

	r.top = 0;
	r.left = 0;
	r.right = 500;
	r.bottom = 32;
	frames = 0;
	framesSoFar = 0;

	do {
		while (PeekMessage(&msg, _e->get_wnd(), 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		
		//Count each time one cycle of processing is completed
		cyclesSoFar++;
		

		// Draw the screen no faster than 16.6ms
		if (clock() - drawTimer >= CLOCKS_PER_SEC / 60) {
			// RedrawWindow(_e->get_wnd(), 0, 0, RDW_ERASE);
			InvalidateRect(_e->get_wnd(), 0, true);
			// UpdateWindow(_e->get_wnd());

			// PrintWindow(_e->get_wnd(), 0, 0);

			framesSoFar++;
			drawTimer = clock();
		}

		// Update debug information
		if (clock() - FPSTimer >= CLOCKS_PER_SEC) {
			frames = framesSoFar;
			framesSoFar = 0;
			cycles = cyclesSoFar;
			cyclesSoFar = 0;
			elapsed = 0;
			FPSTimer = clock();
		}

		// Run the game until told to quit
		// _e->stop_game() will quit clean
		// _e->force_quit_game() will pull it out as fast as possible
	} while (_e->run_game());

	

	return (int)msg.wParam;
}