#include "counter.h"
#include "user.h"
#include <iostream>
#include <systemc.h>

int sc_main(int argc, char* argv[]){
	sc_signal<bool> reset, up_down, load;
	sc_signal<int> data_in, Q;
	sc_signal<double> fil_period;
	
	counter counter_inst("counter_inst");
	counter_inst.period(fil_period);
	counter_inst.reset(reset);
	counter_inst.up_down(up_down);
	counter_inst.load(load);
	counter_inst.data_in(data_in);
	counter_inst.Q(Q);
	
	user user_inst("test_counter_inst");
	user_inst.period(fil_period);
	user_inst.reset(reset);
	user_inst.up_down(up_down);
	user_inst.load(load);
	user_inst.data_in(data_in);
	
	std::cout<<"start_simulation ..."<<std::endl;
	sc_start(400,SC_NS);
	std::cout<<sc_time_stamp<<": stop sim"<<std::endl;
	
	
}

/*
int sc_main(int argc, char* argv[])
{
	
	sc_clock clk1("clk1", 10, SC_MS);  // Period = 10 ms
	sc_signal<bool> rst;
	counter my_counter("counter1");
		my_counter.reset(rst);
		my_counter.clk(clk1);
	rst .write(true);
	sc_start(1, SC_MS);
	rst= false;
	sc_start(100, SC_MS);
	rst = true;sc_start(12, SC_MS);
	rst = false;
	sc_start(30, SC_MS);
	return0;
}*/
