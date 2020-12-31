#ifndef TLM_SLAVE_BUS_IF_H
#define TLM_SLAVE_BUS_IF_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>

class tlm_slave_bus_if : virtual public sc_interface{
public:
    virtual void sendDataToMaster(int data_) = 0;
	virtual void sendAckToMaster() = 0;
	virtual const sc_event& rwEvent() const = 0;
	virtual bool isRead() const = 0;
	virtual int getData() const = 0;
	virtual unsigned int getAddress() const = 0;
	virtual void irq0Notify() = 0;
	virtual void irq1Notify() = 0;
};

#endif