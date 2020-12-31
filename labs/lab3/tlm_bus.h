#ifndef TLM_BUS_H
#define TLM_BUS_H

#include "tlm_master_bus_if.h"
#include "tlm_slave_bus_if.h"


class TLMBus : public sc_prim_channel, public tlm_master_bus_if, public tlm_slave_bus_if
{
public:
	// Constructor
	explicit TLMBus() : sc_prim_channel(sc_gen_unique_name("TLMBus")){
		// do nothing
	}

	explicit TLMBus(sc_module_name nm) : sc_prim_channel(nm) {
		// do nothing
	}

	// tlm__master_bus_if
	void writeToSlave(unsigned int addr_, int data_) override;
	int readToSlave(unsigned int addr_) override;
	const sc_event& irq0Event() const override;
	const sc_event& irq1Event() const override;

	// tlm__slave_bus_if
	void sendDataToMaster(int data_) override;
	void sendAckToMaster() override;
	const sc_event& rwEvent() const override;
	bool isRead() const override;
	int getData() const override;
	unsigned int getAddress() const override;
	void irq0Notify() override;
	void irq1Notify() override;

private:
	// Variables
	//int mem[MAX];
	unsigned int addr;
	int data;
	bool rw;
	sc_event irq0, irq1;
	sc_event rwToSlaveEv,ackToMasterEv,sendDataToMasterEv;
	sc_mutex mux;
	
	// Copy constructor so compiler won't create one
	TLMBus( const TLMBus& );
};

#endif

