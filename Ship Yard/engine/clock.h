#ifndef _clock_h_
#define _clock_h_

#include "globals.h"
#include <time.h>

class _clock//No init is needed
{
private:
	time_t _last_tick;
	time_t _tick;
	float _step;	//In Milliseconds
	float _accumulated_tick;
public:
	_clock()
	{
		_last_tick = clock();
		_tick = clock();
	};

	void init(float interval)	//How fast it updates
	{
		_step = interval;
	}

	uint32_t get_delta() {
		return (uint32_t)clock() - _last_tick;
	}

	bool timed_update() {
		return (_tick - _last_tick > _step);
	}
	
	void update()
	{
		_tick = clock();
		_last_tick = _tick;
	}

};



#endif