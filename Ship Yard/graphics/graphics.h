#ifndef _graphics_h_
#define _graphics_h_

#define _run_console_

#include <stdio.h>

class _graphics {
private:
public:
	inline static _graphics* ins() { static _graphics g; return &g; }

#ifdef _run_console_
private:

public:
	

	void draw_string(char* str) {
		printf("[system] : %s", str);
	}
	void debug_string(char* str) {
		printf("[debug] : %s", str);
	}
#endif
};

#endif