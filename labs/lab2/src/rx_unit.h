#ifndef RX_UNIT_H
#define RX_UNIT_H

#include <iostream>
#include <systemc.h>
#include <cstdlib>

SC_MODULE(RxUnit){
  sc_in<bool> sys_clk;
  sc_in<bool> reset;
  sc_in<bool> enable;
  sc_in<bool> read;
  sc_in<bool> rxd;

  sc_out<sc_lv<8>> data_out;
  sc_out<bool> frame_err;
  sc_out<bool> output_err;
  sc_out<bool> data_rdy;

  sc_lv<8> shift_reg="00000000";



  SC_CTOR(RxUnit): sys_clk("sys_clk"), reset("reset"), enable("enable"),
    read("read"), rxd("rxd"), data_out("data_out"),
    frame_err("frame_err"), output_err("output_err"),
    data_rdy("data_rdy"){

      SC_THREAD(RxUnit_THREAD);
      sensitive << sys_clk.pos();

      cout << sc_time_stamp() << " : RxUnit is instantiated!" << endl;

    }

  void RxUnit_THREAD();
};

#endif