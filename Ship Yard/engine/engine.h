#include "globals.h"
#include "..\graphics\graphics.h"
#include "clock.h"

class _engine
{
private:

	// For later expansion possibly
	/*HWND		m_hWnd;
	MSG			m_uMsg;
	HINSTANCE	m_hInstance, m_hPrevInstance;
	LPSTR		m_lpCmdLine;
	int			m_nCmdShow;
	HWND OpenWindow(const char* cszWindowName, int nCmdShow);*/

	_graphics * _g;

	_engine() {
		_g = _graphics::ins();
	};

public:

	bool			m_forceQuit;
	//Graphics		graphics;
	//SoundEngine		sound;
	//DInput			input;
	//DrawlistHandler dlHandler;
	//GameHandler		game;
	int				m_gameState;

	//stopWatch		m_throttle;	//Throttle Code
	_clock			m_clock;

	

	// Singleton of engine class // Only allows on instance of the engine to ever be created or used.
	inline static _engine* ins() { static _engine e; return &e; }
	e_return_response init();
	e_return_response work();
	e_return_response cleanUp();

	

	//void Init(HINSTANCE hInstance,							// to be called once at the beginning of the program
	//	HINSTANCE hPrevInstance,
	//	LPSTR lpCmdLine,
	//	int nCmdShow);
	//void Work();											// to be called once per frame
	//void Release();											// to be called at the end


	//WPARAM getWParam() { return m_uMsg.wParam; }
} typedef Engine;