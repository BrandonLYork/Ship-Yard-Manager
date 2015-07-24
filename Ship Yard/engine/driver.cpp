#include <assert.h>
#include "globals.h"
#include "engine.h"

#include "..\yard\wiring.h"
#include "..\yard\dock.h"

int main(int argc, char* argv[]) {
	//_engine * _e;
	//_e = _engine::ins();
	// Currently not accepting commands from the command line

	// initialize game

	// run game loop

	// clean up
	_dock_ d;
	d.start_new_ship(3, 3, 3);
	d.print_dock(0);

	printf("%d", ELECTRICAL);
	printf("%d", CONTROL);
	printf("%d", NETWORK);

	printf("Press any key to continue...");
	getchar();
	return R_SUCCESS;
}



//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//	/*Engine* engine = Engine::Ins();
//
//	engine->Init(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
//
//	while (!engine->toQuit)
//		engine->Work();
//
//	engine->Release();
//
//	return engine->getWParam();*/
//}