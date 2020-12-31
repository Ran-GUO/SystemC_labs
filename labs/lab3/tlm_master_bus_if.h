#ifndef TLM_MASTER_BUS_IF_H
#define TLM_MASTER_BUS_IF_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>

class tlm_master_bus_if: virtual public sc_interface{
public:
    virtual void writeToSlave(unsigned int addr_, int data_) = 0;
	virtual int readToSlave(unsigned int addr_) = 0;
	virtual const sc_event& irq0Event() const = 0;
	virtual const sc_event& irq1Event() const = 0;
};

#endif