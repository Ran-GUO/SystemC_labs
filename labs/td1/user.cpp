#include "user.h"

void user::user_thread(void){

	std::cout<< sc_time_stamp() << " : test du compteur "<< std::endl;
	period->write(10);
	data_in->write(3);
	reset->write(false);
	up_down->write(false);
	load->write(false);
	wait(5,SC_NS);
	
	//reset
	std::cout<< sc_time_stamp() << " : reset"<< std::endl;
	reset->write(true);
	wait(15,SC_NS);
	
	//Decompte
	std::cout<< sc_time_stamp() << " : decompte"<< std::endl;
	reset->write(false);
	wait(15,SC_NS);
	
	//load
	std::cout<< sc_time_stamp() << " : load"<< std::endl;
	load->write(true);
	wait(15,SC_NS);
	load->write(false);
	
	//decompte
	std::cout<< sc_time_stamp() << " : decompte"<< std::endl;
	up_down->write(false);
	wait(60,SC_NS);
	
	//compte
	std::cout<< sc_time_stamp() << " : compte"<< std::endl;
	up_down->write(true);
	wait(60,SC_NS);
	
	
}

