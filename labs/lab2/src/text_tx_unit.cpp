#include "tx_unit.h"
#include "clk_unit.h"
#include "benches.h"

void test_tx_unit(){

    sc_signal<bool> reset, en_tx, en_rx,load,reg_empty,buf_empty,txd;
	sc_clock clk("clk",25,SC_NS);
    sc_signal<sc_lv<8>> data_in;
	
	ClkUnit ClkUnit_inst("ClkUnit");
		ClkUnit_inst.sys_clk(clk);
		ClkUnit_inst.reset(reset);
		ClkUnit_inst.en_tx(en_tx);
		ClkUnit_inst.en_rx(en_rx);

    TxUnit TxUnit_inst("TxUnit");
		TxUnit_inst.sys_clk(clk);
		TxUnit_inst.reset(reset);
		TxUnit_inst.enable(en_tx);
		TxUnit_inst.load(load);
		TxUnit_inst.data_in(data_in);
		TxUnit_inst.reg_empty(reg_empty);
		TxUnit_inst.buf_empty(buf_empty);
		TxUnit_inst.txd(txd);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave_Txunit");
	sc_write_comment(tf, "Clk Unit Simulation ...");
    
    sc_trace(tf,clk, "clk");  // .signal()
	sc_trace(tf,reset,"reset");
	sc_trace(tf,en_tx,"en_tx");
	sc_trace(tf,en_rx,"en_rx");
    sc_trace(tf,load,"load");
	sc_trace(tf,data_in,"data_in");
	sc_trace(tf,reg_empty,"reg_empty");
	sc_trace(tf,buf_empty,"buf_empty");
	sc_trace(tf,txd,"txd");

	/* Elaboration step */
	cout << sc_time_stamp() << ": ELABORATION" <<endl;

	/* Simulation step */
	cout << sc_time_stamp() << ": START SIMULATION" <<endl;

    // Reset
	cout << "----------------Reset----------------" << endl;
	load.write(false);
	reset.write(true);
	sc_start(100,SC_NS);
	reset.write(false);
	sc_start(300,SC_NS);

	// Load and send
	cout << "----------------Load and send Txd---------------" << endl;
	data_in.write(0x69); //01101001 -> 10010110
	load.write(true);
	sc_start(25,SC_NS);
	load.write(false);
	sc_start(1,SC_MS);

	cout << "----------------Load and send Txd---------------" << endl;
	data_in.write(0x70); //11110000 -> 00001111
	load.write(true);
	sc_start(25,SC_NS);
	load.write(false);
	sc_start(1,SC_MS);

    cout << "----------------Load and send Txd---------------" << endl;
    data_in.write(0x0B); //00001011 -> 11010000
	load.write(true);
	sc_start(25,SC_NS);
	load.write(false);
	sc_start(3,SC_MS);
	

	/* End of Simulation */
	cout << sc_time_stamp() << ": END OF SIMULATION" << endl; ;

    sc_close_vcd_trace_file(tf);
}