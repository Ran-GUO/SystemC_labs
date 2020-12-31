#ifndef CLK_UNIT_H
#define CLK_UNIT_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>

#define CYC_TX 40000000/9600
#define CYC_RX 40000000/153600

SC_MODULE(ClkUnit){
    sc_in<bool> sys_clk;
    sc_in<bool> reset;
    sc_out<bool> en_tx;
    sc_out<bool> en_rx;
 
    //sc_clock clk("clk",25,SC_NS);
    //SC_HAS_PROCESS(ClkUnit);
    int count_tx=0;    
    int count_rx=0;

    const int cyc_tx = CYC_TX;
    const int cyc_rx = CYC_RX;

    SC_CTOR(ClkUnit):    
        sys_clk("sys_clk"),
        reset("reset"),
        en_tx("en_tx"),
        en_rx("en_rx"){ 

        SC_THREAD(ClkUnit_THREAD); 
        sensitive << sys_clk.pos();
    }

    void ClkUnit_THREAD();

};

#endif