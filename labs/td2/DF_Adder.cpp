#include "DF_Adder.h"


void DF_Adder::DF_Adder_thread(void){
	while(true){
		//read 2 FIFO input
		
		std::cout<<sc_time_stamp()<<": DF_Adder : wait for reading const_value. "<<std::endl;
		double v1 = const_value->read();
		std::cout<<sc_time_stamp()<<": DF_Adder : wait for reading feedback_value. "<<std::endl;
		double v2 = feed_back->read();
		
		
		wait(100, SC_NS);
		std::cout<<sc_time_stamp()<<": DF_Adder : result = "<< v1+v2<<std::endl;
		added_value->write(v1+v2);
	}
		
}

