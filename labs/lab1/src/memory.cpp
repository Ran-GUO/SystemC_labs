#include "memory.h"

/*
template<int ADDR_SIZE, int WORD_SIZE, int MEM_SIZE>
void RTL_memory<ADDR_SIZE,WORD_SIZE,MEM_SIZE>::RTL_memory_THREAD(void){
     while(true){
         std::cout<<sc_time_stamp<<"start rtl memory thread"<<std::endl;
         wait(clk->negedge_event());

         if(enable->read()==true){
             if(rd_we->read()==false){ //read
                 data=memory[addr->read()];
                 data_out=data->write();
             }
             else{//write
                 data=data_in->read();
                 memory[addr->read()]=data;
             }
         }
         else{
             std::cout<<"don't enable"<<std::endl;
         }         
     }
 }
 */