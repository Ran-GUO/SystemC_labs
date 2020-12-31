#ifndef _DF_DISPLAY_H_
#define _DF_DISPLAY_H_

#include <iostream>
#include <systemc.h>
#include <cstdlib>

SC_MODULE(DF_Display)
{
	sc_fifo_in<double> result;
	int N;
	
	SC_HAS_PROCESS(DF_Display);
	
	DF_Display(sc_module_name name,int n):
		sc_module(name),N(n){
		SC_THREAD(DF_Display_thread);
		}

	void DF_Display_thread();

	/*SC_CTOR(DF_Adder){
		SC_THREAD(DF_Adder_thread);
	};*/
};

#endif	
	
	

