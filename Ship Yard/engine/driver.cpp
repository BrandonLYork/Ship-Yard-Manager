#include <assert.h>
#include "globals.h"
#include "engine.h"

#include "..\yard\wiring.h"

int main(int argc, char* argv[]) {
	//_engine * _e;
	//_e = _engine::ins();
	// Currently not accepting commands from the command line

	// initialize game

	// run game loop

	// clean up

	printf("%d", ELECTRICAL);
	printf("%d", CONTROL);
	printf("%d", NETWORK);

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