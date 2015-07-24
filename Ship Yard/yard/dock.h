#ifndef _DOCK_H_
#define _DOCK_H_

#include <stdio.h>

#include "..\engine\globals.h"
#include "Room.h"

class _dock_ {
	Room ***_room;
	short _width, _height, _depth;

public:
	_dock_() {
		_height = _width = _depth = 1;
		//_room = NULL;
	}

	void start_new_ship(int w, int h, int d) {
		_width = w;
		_height = h;
		_depth = d;

		_room = new Room**[_width]();
		for(int i = 0;i < _width;i++) {
			_room[i] = new Room*[_depth]();
			for (int j = 0; j < _depth; j++) {
				_room[i][j] = new Room[_height]();
			}
		}
	}

	void print_dock(int h) {
		// Print across and then down
		// x - x - x - x
		// x - x ->
		// |
		// V

		for (int j = 0; j < _depth; j++) {
			for (int i = 0; i < _width; i++) {
				_room[i][j][h].print_room();
				if (i < _width - 1) 
					printf(" - ");
			}
			printf("\n");
			if (j < _depth - 1) {
				for (int i = 0; i < _width; i++) {
					printf("|   ");
				}
			}
			printf("\n");
		}
	}
} typedef Dock;

#endif