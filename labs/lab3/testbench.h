#ifndef TESTBENCH_H
#define TESTBENCH_H

#include "slave_module.h"
#include "master_module.h"
#include "tlm_bus.h"

SC_MODULE(Testbench){
    MasterModule master_inst;
    SlaveModule slave_inst;
    TLMBus tlm_bus;

    sc_trace_file *tf;

    SC_CTOR(Testbench):master_inst("master_inst"),slave_inst("slave_inst")
	{
        //master_inst.addr=master_inst.addr++;
		master_inst.bus(tlm_bus);
        slave_inst.bus(tlm_bus);

        tf = sc_create_vcd_trace_file("wave_MS");
	    sc_write_comment(tf, " Simulation ...");
    
        //sc_trace(tf,master_inst.data, "master.data");  
       // sc_trace(tf,slave_inst.data, "slave.data"); 
       // sc_trace(tf,tlm_bus.isRead(), "tlm_bus.rw");  

        //SC_THREAD(test_thread);
       // SC_THREAD(trace_thread);
        
	}

    void trace_thread(){
        wait(50,SC_US);
        sc_close_vcd_trace_file(tf);
    }

   /* void test_thread(){
        while(1){
            wait(1,SC_US);
            master_inst.addr++;
        }
    }*/
};

#endif