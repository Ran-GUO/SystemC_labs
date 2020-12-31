#include "DF_Fork.h"


void DF_Fork::DF_Fork_thread(void){
	while(true){
		double val= added_value->read();
		wait(10,SC_NS);
		
		result->write(val);
		feed_back->write(val);
		std::cout<<sc_time_stamp()<<"Fork : feedback : "<<val<<std::endl;
	}
		
}

