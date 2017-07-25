#include <iostream>
#include "rotary_encoder.h"

int main(){
	rotary_encoder r1(0,7);
//	rotary_encoder r2(3,2);
//	rotary_encoder r3(22,21);
	for(;;){
//		for(int i = 0; i<10; i++){
			r1.update();
//			r2.update(100);
//			r3.update(100);
//		}
//		std::cout << r1.get_position() << "\t" << r2.get_position() << "\t" << r3.get_position() << std::endl;
		std::cout << r1.get_position() << std::endl;
	}
//	std::cout << "start..." << std::endl;
//	pulsein(21,-1);

	return 0;
}
