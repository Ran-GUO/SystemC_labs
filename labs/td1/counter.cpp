#include "counter.h"

void counter::counter_thread(void){

	while(true){
	std::cout<< sc_time_stamp() << " :counter_Q ="<< Q->read()<<std::endl;
	//on attend la period avant la prochaine operation
	wait(period->read(),SC_NS,reset->posedge_event());

	//si reset
	if(reset->read()==true){
		Q->write(0);
	}
	//declenchement period ns
	//si chargement d une valeur : Q prend la valeur de data_in
	else if(load->read()==true){
		Q->write(data_in->read());
	}	
	//sinon on compte ou decompte
	else{
		//on regard si compte ou decompte
		if(up_down->read()==true){
			//on compte
			Q->write((Q->read()+1)%10);
		}
		else{
			//on decompte
			Q->write(Q->read()==0 ? 9 : Q->read()-1);
		}
	}
	std::cout<< sc_time_stamp() << " :counter_Q ="<< Q->read()<<std::endl;
	}
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
