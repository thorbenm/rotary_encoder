#include <iostream>
#include "rotary_encoder.h"

rotary_encoder r1(0,7);
rotary_encoder r2(3,2);
rotary_encoder r3(22,21);

void t1_function(){
	r1.update();
}

void t2_function(){
	r2.update();
}

void t3_function(){
	r3.update();
}

int prev_position[] = {1,0,0};

int main(){
	std::cout << "start.." << std::endl;
	std::thread t1 (t1_function);
	std::thread t2 (t2_function);
	std::thread t3 (t3_function);
	for(;;){
		if(r1.get_position() != prev_position[0] ||
		   r2.get_position() != prev_position[1] ||
		   r3.get_position() != prev_position[2]){
			std::cout << r1.get_position() << "\t"
				  << r2.get_position() << "\t"
				  << r3.get_position() << std::endl;
			prev_position[0] = r1.get_position();
			prev_position[1] = r2.get_position();
			prev_position[2] = r3.get_position();
		}
	}

	return 0;
}
