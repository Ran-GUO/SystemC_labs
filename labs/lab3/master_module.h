#ifndef MASTER_MODULE_H
#define MASTER_MODULE_H

#include <systemc.h>
#include "tlm_master_bus_if.h"

#define MAX_SIZE 100000

SC_MODULE(MasterModule)
{

	protected:
	// Data Members
	//int mem[MAX_SIZE];
	unsigned int addr;
	int data;
	// Sub-modules

	public:
		
	// Port Declaration
	sc_port<tlm_master_bus_if> bus;
	// Channel Members

	// Constructor
	SC_CTOR(MasterModule)
	{
		addr=0x33;
		SC_THREAD(boot_thread);
		SC_THREAD(isr0_thread);
		SC_THREAD(isr1_thread);
	}

	// Processes
	void boot_thread();
	void isr0_thread();
	void isr1_thread();

	// Helper Functions
};

#endif