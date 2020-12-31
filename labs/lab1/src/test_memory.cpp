#include "test_memory.h"

/*
template<int ADDR_SIZE, int WORD_SIZE, int MEM_SIZE>
void test_memory<ADDR_SIZE,WORD_SIZE,MEM_SIZE>::test_memory_THREAD(void){
    std::cout<< sc_time_stamp() << " : test du memory "<< std::endl;
    enable->write(false);
    rd_we->write(false);
    addr->write("0x77");
    data_in->write("00110011");
    wait(7,SC_NS);

    //write
    std::cout<< sc_time_stamp() << " : write to memory "<< std::endl;
    enable->write(true);
    rd_we->write(true);
    addr->write("0x77");
    data_in->write("00110011");
    wait(15,SC_NS);

    //read
    std::cout<< sc_time_stamp() << " : read from memory "<< std::endl;
    enable->write(true);
    rd_we->write(false);
    addr->write("0x77");
    wait(8,SC_NS);

    //write
    std::cout<< sc_time_stamp() << " : write to memory "<< std::endl;
    enable->write(true);
    rd_we->write(true);
    addr->write("0x77");
    data_in->write("11110000");
    wait(7,SC_NS);



}
*/
 