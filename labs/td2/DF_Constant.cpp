#include "DF_Constant.h"
//#include "helper_fct.h"

void DF_Constant::DF_Constant_thread(void){
	while(true){
	wait(1,SC_MS);
	const_value->write(cte);
	std::cout<<sc_time_stamp()<<":const_value: send value "<<cte<<std::endl;	
	}
}

void DF_Constant::print_debug(std::string s, int value){
	std::cout<<sc_time_stamp()<<" : "<<s<<value<<std::endl;
}

void DF_Constant::print_debug(std::string s){
	std::cout<<sc_time_stamp()<<" : "<<s<<std::endl;
}
