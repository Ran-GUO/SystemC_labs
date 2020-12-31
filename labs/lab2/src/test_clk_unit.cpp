#include "clk_unit.h"
#include "benches.h"

void test_clk_unit(){

    sc_signal<bool> reset, en_tx, en_rx;
	sc_clock clk("clk",25,SC_NS);
	
	ClkUnit ClkUnit_inst("ClkUnit");
		ClkUnit_inst.sys_clk(clk);
		ClkUnit_inst.reset(reset);
		ClkUnit_inst.en_tx(en_tx);
		ClkUnit_inst.en_rx(en_rx);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave_clkunit");
	sc_write_comment(tf, "Clk Unit Simulation ...");
    sc_trace(tf,clk, "clk");  // .signal()
	sc_trace(tf,reset,"reset");
	sc_trace(tf,en_tx,"en_tx");
	sc_trace(tf,en_rx,"en_rx");

	/* Elaboration step */
	cout << sc_time_stamp() << ": ELABORATION" <<endl;

	/* Simulation step */
	cout << sc_time_stamp() << ": START SIMULATION" <<endl;

	sc_start(200,SC_US);

	/* End of Simulation */
	cout << sc_time_stamp() << ": END OF SIMULATION" << endl; ;

    sc_close_vcd_trace_file(tf);
}