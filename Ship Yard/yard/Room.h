#ifndef _ROOM_H_
#define _ROOM_H_

#include <stdio.h>

enum e_room_direction {
	RmConn_UP,
	RmConn_Down,
	RmConn_Left,
	RmConn_Right,
	RmConn_Front,
	RmConn_Back
};

enum e_room_type {
	Rm_Default
};

class _room_ {
private:
	_room_ * _room_connections[6];

	// Wiring * _wire_connections[6];

	// Piping * _pipe_connections[6];

	int _PipeLimit;
	int _PipeTypeLimit;
	int _WireLimit;
	int _WireTypeLimit;

	e_room_type _my_type;

public:
	_room_() {

	}
	
	void add_door(_room_ * conn, int dir) {
		_room_connections[dir] = conn;
	}

	void print_room() {
		switch (_my_type) {
		case Rm_Default:
		default:
			printf("X");
			break;
		}
	}
} typedef Room;

#endif