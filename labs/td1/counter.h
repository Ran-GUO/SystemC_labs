#ifndef _COUNTER_H_
#define _COUNTER_H_

#include <iostream>
#include <systemc.h>

SC_MODULE(counter)
{
	sc_in<double> period;
	sc_in<bool> reset;
	sc_in<bool> up_down;
	sc_in<bool> load;
	sc_in<int> data_in;
	sc_out<int> Q;
	SC_CTOR(counter) : period("period"), reset("reset"), up_down("up_down"), load("load"), data_in("data_in"), Q("Q"){
	SC_THREAD(counter_thread);
	};
	
	void counter_thread(void);
};
#endif	
	
	

