#ifndef _DF_CONSTANT_H_
#define _DF_CONSTANT_H_

#include <iostream>
#include <systemc.h>
#include <cstdlib>

SC_MODULE(DF_Constant)
{
	sc_fifo_out<double> const_value;
	
	const double cte;
	SC_HAS_PROCESS(DF_Constant);
	
	DF_Constant(sc_module_name name,const double v):
		sc_module(name),cte(v){
		SC_THREAD(DF_Constant_thread);
		}

	void DF_Constant_thread();
	void print_debug(std::string s);
	void print_debug(std::string s, int value);

	//SC_CTOR(DF_Constant){
	//	SC_THREAD(DF_Constand_thread);
	//}
};
#endif	
	
	

