#include "rotary_encoder.h"

rotary_encoder::rotary_encoder(int pin_a2, int pin_b2){
	wiringPiSetup();

	pin_a = pin_a2;
	pin_b = pin_b2;

//	pinMode(pin_a, INPUT);
	pinMode(pin_b, INPUT);

//	pullUpDnControl (pin_a, PUD_DOWN);
	pullUpDnControl (pin_b, PUD_DOWN);

	position = 0;
}

void rotary_encoder::set_position(int input){
	position = input;
}

int rotary_encoder::get_position(){
	return position;
}

void rotary_encoder::update(){
	for(;;){
		if(pulsein(pin_a,-1,0) > 0){
			if(digitalRead(pin_b)){
				position--;
			}else{
				position++;
			}
			pulsein(pin_b,-1);
		}
	delay(15);
	}
}

int pulsein(int pin, long maxtime, int change_from){
	int last_state; 	
	if(change_from < 0){
		last_state = digitalRead(pin);
	}else{
		last_state = change_from;	
	}
	long time = 0;
	for(;;){
//		usleep(1);
		time++;
		if(digitalRead(pin) != last_state){
			return time;
		}
		if(maxtime > 0){
			if(time > maxtime){
				return -1;
			}
		}
	}
	return -1;
}

