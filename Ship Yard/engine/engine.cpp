#include <windows.h>
#include "engine.h"
#include "globals.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

e_return_response Engine::init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	/*MSG			m_uMsg;
	HINSTANCE	m_hInstance, m_hPrevInstance;
	LPSTR		m_lpCmdLine;
	int			m_nCmdShow;*/

	m_hInstance = hInstance;
	m_hPrevInstance = hPrevInstance;
	m_lpCmdLine = lpCmdLine;
	m_nCmdShow = nCmdShow;
	
	static TCHAR szWindowClass[] = ("Ship Yard");

	m_wCex.cbSize = sizeof(WNDCLASSEX);
	m_wCex.style = CS_HREDRAW | CS_VREDRAW;
	m_wCex.lpfnWndProc = WndProc;
	m_wCex.cbClsExtra = 0;
	m_wCex.cbWndExtra = 0;
	m_wCex.hInstance = hInstance;
	m_wCex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	m_wCex.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_wCex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_wCex.lpszMenuName = NULL;
	m_wCex.lpszClassName = szWindowClass;
	m_wCex.hIconSm = LoadIcon(m_wCex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return R_SUCCESS;
}

e_return_response Engine::open_window() {
	//static TCHAR szWindowClass[] = ("win32app");
	static TCHAR szTitle[] = ("Win32 Guided Tour Application");
	static TCHAR szClassTitle[] = ("Ship Yard");
	
	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	m_hWnd = CreateWindow(
		szClassTitle,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		m_hInstance,
		NULL
		);

	if (!m_hWnd)
	{
		MessageBox(NULL,
			("Call to CreateWindow failed!"),
			("Win32 Guided Tour"),
			NULL);

		return R_SUCCESS;
	}
}

e_return_response Engine::work() {

	if (m_clock.timed_update()) {
		//_g.draw_string("Test");
	}

	m_clock.update();
	return R_SUCCESS;
}

e_return_response Engine::cleanUp() {
	return R_SUCCESS;
}