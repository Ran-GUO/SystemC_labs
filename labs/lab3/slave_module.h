#ifndef SLAVE_MODULE_H
#define SLAVE_MODULE_H

#include <systemc.h>
#include "tlm_slave_bus_if.h"
#define MAX_SIZE 100000

SC_MODULE(SlaveModule)
{

protected:
	// Data Members
	int mem[MAX_SIZE];
	unsigned int addr;
	sc_uint<8> data;
	// Sub-modules

public: 
	// Port Declaration
	sc_port<tlm_slave_bus_if> bus;
	// Channel Members
	// Constructor
	SC_HAS_PROCESS(SlaveModule);
	SlaveModule(sc_module_name inst_name)
		: sc_module(inst_name) {

		SC_THREAD(main_thread);
		SC_THREAD(interrupt_thread);
	}
	
	/*~SlaveModule() {
		delete[] mem;
	}*/

	// Processes
	void main_thread();
	void interrupt_thread();

	// Helper Functions
	void write(unsigned int addr_, sc_uint<8> data_);
	void read(unsigned int addr_, sc_uint<8>& data_);
};

#endif