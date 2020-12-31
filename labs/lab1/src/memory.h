#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>

template<int ADDR_SIZE, int WORD_SIZE, int MEM_SIZE>
SC_MODULE(RTL_memory){
    sc_in<bool> clk;
    sc_in<bool> enable;
    sc_in<bool> rd_we;
    sc_in<sc_uint<ADDR_SIZE>> addr;
    sc_in<sc_lv<WORD_SIZE>> data_in;
    sc_out<sc_lv<WORD_SIZE>> data_out;

    sc_lv<WORD_SIZE> memory[MEM_SIZE];
    sc_lv<WORD_SIZE> data;

    //SC_HAS_PROCESS(RTL_memory);

    SC_CTOR(RTL_memory):    
        clk("clk"),
        enable("enable"),
        rd_we("rd_we"),
        addr("addr"),
        data_in("data_in"), 
        data_out("data_out"){
        //memory("memory") 
        SC_THREAD(RTL_memory_THREAD); 
           
    }
    
    
    void RTL_memory_THREAD(){
        while(true){
            std::cout<<sc_time_stamp()<<": start rtl memory thread"<<std::endl;
            wait(clk->negedge_event());
            
            if(enable->read()==true){
                if(rd_we->read()==false){ //read
                    data=memory[addr->read()];
                    data_out->write(data);
                    std::cout<< sc_time_stamp() << " : finish read from memory "<<data_out->read()<< std::endl;

                }
                else{//write
                    data=data_in->read();
                    memory[addr->read()]=data;
                    std::cout<< sc_time_stamp() << " : finish write to memory "<< memory[addr->read()]<< std::endl;
                }
         }
            else{
                 std::cout<<"don't enable"<<std::endl;
            }         
         }
    }


};


#endif