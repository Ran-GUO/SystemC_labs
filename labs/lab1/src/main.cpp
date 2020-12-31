#include <systemc.h>
#include"memory.h"
#include"test_memory.h"

#define ADDR_SIZE 4
#define WORD_SIZE 8
#define MEM_SIZE  16

int sc_main(int argc, char* argv[]) {

	

	
	

	test_memory<ADDR_SIZE,WORD_SIZE,MEM_SIZE> test_inst("test_inst");
	
/*

*/
	/* Simulation step */
	cout << sc_time_stamp() << ": START SIMULATION ..." <<endl;

	sc_start(100,SC_NS);

	/* End of Simulation */
	cout << sc_time_stamp() << ": END OF SIMULATION" << endl; ;
				
	return 0;
}


