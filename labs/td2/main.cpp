#include "DF_Constant.h"
#include "DF_Adder.h"
#include "DF_Fork.h"
#include "DF_Display.h"

#include <iostream>
#include <systemc.h>

int sc_main(int argc, char* argv[]){
	sc_fifo<double> Const_value, Added_value, Feedback, Result;
	
	DF_Constant Df_constant("Df_constant",5 );
	Df_constant.const_value(Const_value);
	
	DF_Adder Df_adder("Df_adder");
	Df_adder.feed_back(Feedback);
	Df_adder.const_value(Const_value);
	Df_adder.added_value(Added_value);
	
	DF_Fork Df_fork("Df_fork");
	Df_fork.feed_back(Feedback);
	Df_fork.added_value(Added_value);
	Df_fork.result(Result);
	
	DF_Display Df_display("Df_display",6);
	Df_display.result(Result);
	
	
	std::cout<<sc_time_stamp()<<" : start simulation "<<std::endl;
	Feedback.write(0); //pas utiliser -> parce que c'est pas un pointeur
	sc_start(100,SC_MS);
	
	std::cout<<sc_time_stamp()<<" : end simulation "<<std::endl;

	return 0;
}



