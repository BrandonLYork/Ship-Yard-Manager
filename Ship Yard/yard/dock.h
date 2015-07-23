#ifndef _DOCK_H_
#define _DOCK_H_

#include "..\engine\globals.h"
#include "Room.h"

class _dock_ {
	Room ***_room;
	short _height, _width, _depth;

	_dock_() {
		_height = _width = _depth = 1;
		//_room = NULL;
	}

	void start_new_ship() {
		
		_room = new Room**[_width]();
		for(int i = 0;i < _width;i++) {
			_room[i] = new Room*[_depth]();
			for (int j = 0; j < _depth; j++) {
				_room[i][j] = new Room[_height]();
			}
		}
	}
} typedef Dock;

#endif