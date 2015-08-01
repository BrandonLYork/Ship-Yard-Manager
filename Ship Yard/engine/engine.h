#include "globals.h"
#include "..\graphics\graphics.h"
#include "clock.h"

enum e_game_state {
	eGS_START,
	eGS_RUN,
	eGS_STOP
};

class _engine
{
private:
	// For later expansion possibly
	
	HINSTANCE		m_hInstance, m_hPrevInstance;
	LPSTR			m_lpCmdLine;
	int				m_nCmdShow;
	WNDCLASSEX		m_wCex;
	HWND OpenWindow(const char* cszWindowName, int nCmdShow);

	_graphics * _g;

	_engine() {
		_g = _graphics::ins();
	};

public:
	HWND			m_hWnd;
	MSG				m_uMsg;

	bool			m_forceQuit;
	//Graphics		graphics;
	//SoundEngine		sound;
	//DInput			input;
	//DrawlistHandler dlHandler;
	//GameHandler		game;
	e_game_state	m_gameState;

	//stopWatch		m_throttle;	//Throttle Code
	_clock			m_clock;

	

	// Singleton of engine class // Only allows on instance of the engine to ever be created or used.
	inline static _engine* ins() { static _engine e; return &e; }
	e_return_response init(HINSTANCE, HINSTANCE, LPSTR, int);
	WNDCLASSEX & getwindows_class() { return m_wCex; }
	e_return_response open_window();
	e_return_response work();
	e_return_response cleanUp();

	WPARAM getWParams() {
		return m_uMsg.wParam;
	}
	LPARAM getLParams() {
		return m_uMsg.lParam;
	}
	HWND const get_wnd() const {
		return m_hWnd;
	}
	
	bool run_game() {
		if (m_forceQuit) return false;
		return m_gameState != eGS_STOP;
	}

	e_return_response end_game() { m_gameState = eGS_STOP; return R_SUCCESS; }
	e_return_response force_stop_game() { m_forceQuit = true; return R_SUCCESS; }
	

	//void Init(HINSTANCE hInstance,							// to be called once at the beginning of the program
	//	HINSTANCE hPrevInstance,
	//	LPSTR lpCmdLine,
	//	int nCmdShow);
	//void Work();											// to be called once per frame
	//void Release();											// to be called at the end


	//WPARAM getWParam() { return m_uMsg.wParam; }
} typedef Engine;