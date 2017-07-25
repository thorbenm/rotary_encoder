#pragma once

#include <wiringPi.h>
#include <unistd.h>

class rotary_encoder{
public:
	rotary_encoder(int pin_a, int pin_b);
	void set_position(int input = 0);
	int update(int maxtime = -1);
	int get_position();

private:
	int pin_a;
	int pin_b;
	int position;
	int a_state;
	int a_last_state;
}; 

int pulsein(int pin, long maxtime = -1, int change_from = -1);
