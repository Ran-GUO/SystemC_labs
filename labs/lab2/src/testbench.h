
#ifndef TESTBENCH_H
#define TESTBENCH_H


#include "tx_unit.h"
#include "rx_unit.h"
#include "clk_unit.h"
#include "mini_uart.h"



SC_MODULE(TestBench){

    sc_out<bool> sys_clk;
    sc_out<bool> reset;
    sc_out_resolved ce,rd,wr;
    //sc_out<bool> rd;
    //sc_out<bool> wr;
    sc_out_rv<2> addr;
    sc_in_rv<8> data_in;
    //sc_inout<bool> rxd_txd; 

    //sc_signal<bool> txd;
    sc_out_rv<8> data_out;
    sc_in<bool> irq_rx;
    sc_in<bool> irq_tx;

    //sc_clock clk("clk",25,SC_NS);
    //MiniUart  mini_uart_inst;
    char *message;
    unsigned int cpt;

    sc_time CLK_PERIOD;
    sc_clock clock;
    sc_mutex bus_mutex;

   // ClkUnit ClkUnit_inst;
    //TxUnit  TxUnit_inst;
    //RxUnit  RxUnit_inst;

    SC_CTOR(TestBench) : clock("Clock",sc_time(25,SC_NS)){
    //sys_clk("sys_clk"), reset("reset"), ce("ce"),rd("rd"), wr("wr"),
    //addr("addr"), data_in("data_in"), rxd_txd("rxd_txd"),
    //data_out("data_out"),irq_rx("irq_rx"), irq_tx("irq_tx"){//,mini_uart_inst("mini_uart_inst"){

        //ce = false;
        //wr = false;
        //rd = false;
        CLK_PERIOD=sc_time(25,SC_NS);
        cpt=0;
        ce.initialize(SC_LOGIC_Z);
        rd.initialize(SC_LOGIC_Z);
        wr.initialize(SC_LOGIC_Z);
        addr.initialize("00");
        data_out.initialize("ZZZZZZZZ");

/*
        mini_uart_inst.sys_clk(sys_clk);
        mini_uart_inst.reset(reset);
        mini_uart_inst.ce(ce);
        mini_uart_inst.rd(rd);
        mini_uart_inst.wr(wr);
        mini_uart_inst.addr(addr);
        mini_uart_inst.data_in(data_in);
        mini_uart_inst.rxd(rxd_txd);
        mini_uart_inst.txd(rxd_txd);
        mini_uart_inst.data_out(data_out);
        mini_uart_inst.irq_rx(irq_rx);
        mini_uart_inst.irq_tx(irq_tx); 
    */   
       // mini_uart_inst.ClkUnit_inst(ClkUnit_inst);
       // mini_uart_inst.TxUnit_inst(TxUnit_inst);
       // mini_uart_inst.RxUnit_inst(RxUnit_inst);     
	
        SC_METHOD(sysclk_method);
        sensitive<<clock.default_event();
        SC_THREAD(start_thread);
        SC_THREAD(tx_interrupt_thread);
        //sensitive<<sys_clk.pos();
        SC_THREAD(rx_interrupt_thread);
	}
    
    void sysclk_method();
	void tx_interrupt_thread();
	void rx_interrupt_thread();
    void start_thread();

    void resetTest();
    void write(sc_lv<2> Addr, sc_uint<8> Data);
    void read(sc_lv<2> Addr, sc_uint<8> &Data);
};

#endif