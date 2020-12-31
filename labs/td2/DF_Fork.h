#ifndef _DF_FORK_H_
#define _DF_FORK_H_

#include <iostream>
#include <systemc.h>
#include <cstdlib>

SC_MODULE(DF_Fork)
{
	sc_fifo_out<double> feed_back;
	sc_fifo_out<double> result;
	sc_fifo_in<double> added_value;
	
	SC_HAS_PROCESS(DF_Fork);
	
	DF_Fork(sc_module_name name):
		sc_module(name){
		SC_THREAD(DF_Fork_thread);
		}

	void DF_Fork_thread();

	/*SC_CTOR(DF_Adder){
		SC_THREAD(DF_Adder_thread);
	};*/
};

#endif	
	
	

