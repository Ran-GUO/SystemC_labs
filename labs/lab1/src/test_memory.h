#ifndef TEST_MEMORY_H
#define TEST_MEMORY_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>
#include "memory.h"

template<int ADDR_SIZE, int WORD_SIZE, int MEM_SIZE>
SC_MODULE(test_memory){
    sc_clock clk;
    sc_signal<bool> enable,rd_we;
	sc_signal<sc_uint<ADDR_SIZE>> addr;
    sc_signal<sc_lv<WORD_SIZE>> data_in,data_out;
    sc_trace_file *tf;

    RTL_memory<ADDR_SIZE,WORD_SIZE,MEM_SIZE> mem_inst;
    
    /*sc_out<bool> clk;
    sc_out<bool> enable;
    sc_out<bool> rd_we;
    sc_out<sc_uint<ADDR_SIZE>> addr;
    sc_out<sc_lv<WORD_SIZE>> data_in;
    */
   //we use it when we dom't use SC_CTOR
    SC_HAS_PROCESS(test_memory); 


    test_memory(sc_module_name (n)): sc_module(n),mem_inst("mem_inst"){ 
        //clk=true;
        tf=sc_create_vcd_trace_file("wave");
        enable=false;
        rd_we=false;
        addr="0x77";
        

        mem_inst.clk(clk);
	    mem_inst.enable(enable);
	    mem_inst.rd_we(rd_we);
	    mem_inst.addr(addr);
	    mem_inst.data_in(data_in);
	    mem_inst.data_out(data_out);

        
        sc_write_comment(tf,"Simulation ...");
        sc_trace(tf, clk, "clk");
        sc_trace(tf, enable, "enable");
        sc_trace(tf, rd_we, "rd_we");
        sc_trace(tf, addr, "addr");
        sc_trace(tf, data_in, "data_in");
        sc_trace(tf, data_out, "data_out");
        //sc_trace(tf, , "data_out");
        
    
        SC_THREAD(test_memory_THREAD);
        //SC_THREAD(clk_THREAD);   
        }
/*
    void clk_THREAD(void){
        while(true){
            wait(5,SC_NS);
            clk=!clk;
        }
    }
*/
    void test_memory_THREAD(void){
    std::cout<< sc_time_stamp() << " : test du memory "<< std::endl;
    //clk=false;    
    enable=false;
    rd_we=false;
    addr="0x77";
    data_in="00110011";
    wait(7,SC_NS);

    //write
    std::cout<< sc_time_stamp() << " : write to memory "<< std::endl;
    enable=true;
    rd_we=true;
    addr="0x77";
    data_in="00110011";
    wait(15,SC_NS);

    //read
    std::cout<< sc_time_stamp() << " : read from memory "<< std::endl;
    enable=true;
    rd_we=false;
    addr="0x77";
    wait(8,SC_NS);

    //write
    std::cout<< sc_time_stamp() << " : wsrite to memory "<< std::endl;
    enable=true;
    rd_we=true;
    addr="0x77";
    data_in="11110000";
    wait(7,SC_NS);

     //read
    std::cout<< sc_time_stamp() << " : wread from memory  "<< std::endl;
    enable=true;
    rd_we=false;
    addr="0x77";
    //data_in="11001100";
    wait(7,SC_NS);

    //not enable
    std::cout<< sc_time_stamp() << " : not enable  "<< std::endl;
    enable=false;
    
    //write
    std::cout<< sc_time_stamp() << " : wsrite to memory "<< std::endl;
    rd_we=true;
    addr="0x77";
    data_in="11100000";
    wait(7,SC_NS);

     //read
    std::cout<< sc_time_stamp() << " : wread from memory  "<< std::endl;
    rd_we=false;
    addr="0x77";
    //data_in="11001100";
    wait(7,SC_NS);

    //write
    std::cout<< sc_time_stamp() << " : wsrite to memory "<< std::endl;
    rd_we=true;
    addr="0x66";
    data_in="11100001";
    wait(7,SC_NS);

    addr="0x66";
    enable=true;
    wait(7,SC_NS);
    rd_we=false;
    wait(100,SC_NS);
    sc_close_vcd_trace_file(tf);

    }
 
};

#endif