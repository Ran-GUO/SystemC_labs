#ifndef _DF_ADDER_H_
#define _DF_ADDER_H_

#include <iostream>
#include <systemc.h>
#include <cstdlib>

SC_MODULE(DF_Adder)
{
	sc_fifo_in<double> feed_back;
	sc_fifo_in<double> const_value;
	sc_fifo_out<double> added_value;
	
	SC_HAS_PROCESS(DF_Adder);
	
	DF_Adder(sc_module_name name):
		sc_module(name){
		SC_THREAD(DF_Adder_thread);
		}

	void DF_Adder_thread();

	/*SC_CTOR(DF_Adder){
		SC_THREAD(DF_Adder_thread);
	};*/
};

#endif	
	
	

