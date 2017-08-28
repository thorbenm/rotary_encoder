#pragma once

#include <wiringPi.h>
#include <unistd.h>
#include <thread>

class rotary_encoder{
public:
	rotary_encoder(int pin_a, int pin_b);
	void set_position(int input = 0);
	int get_position();
	void update();

private:
	int pin_a;
	int pin_b;
	int position;
}; 

int pulsein(int pin, long maxtime = -1, int change_from = -1);
