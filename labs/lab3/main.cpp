#include <systemc.h>
#include "testbench.h"
int sc_main(int argc, char* argv[]) {

	/* Elaboration step */
	cout << sc_time_stamp() << ": ELABORATION" <<endl;



	/* Simulation step */
	cout << sc_time_stamp() << ": START SIMULATION" <<endl;
	Testbench test_inst("test");
	

	sc_start(100,SC_US);

	/* End of Simulation */
	cout << sc_time_stamp() << ": END OF SIMULATION" << endl; ;
				
	return 0;
}


