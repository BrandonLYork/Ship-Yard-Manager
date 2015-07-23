#include "engine.h"
#include "globals.h"

e_return_response Engine::init() {
	return R_SUCCESS;
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