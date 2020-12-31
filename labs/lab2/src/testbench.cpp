
#include "testbench.h"

void TestBench::sysclk_method()
{
	sys_clk->write(clock.read());  // .signal()
}

void TestBench::start_thread(){
	cpt=0;
	message = (char *) "Bonjour  \n";
	resetTest();
	wait(125,SC_NS);
	
	cout<<"start: write 0"<<endl;
	write(0x00,'0');
	
}

void TestBench::tx_interrupt_thread()
{
	while (true)
	{
		wait(irq_tx->posedge_event());
		cout << "TX Interrupt at time : " << sc_time_stamp() << endl;
	
		if(cpt < sizeof(message)){			
			
			cout<<"write " <<message[cpt]<<endl;
			write(0x00,message[cpt]);
			cpt++;
		}
	}
}

void TestBench::rx_interrupt_thread()
{	
	
	sc_uint<8> value;
	while (true)
	{
		wait(irq_rx->posedge_event());
		cout << "RX Interrupt at time : " << sc_time_stamp() << endl;
		read(0x00,value);
		cout<< "read " << char(value) <<endl;
	}

}

void TestBench::resetTest(void)
{
	bus_mutex.lock();
    cout << sc_time_stamp() << " : ------------------reset---------------- " << endl;

	reset = true;
	wait( 25 * 20, SC_NS);
	reset =false;

    ce -> write(SC_LOGIC_0);
	wr -> write(SC_LOGIC_0);
	rd -> write(SC_LOGIC_0);
	addr = "00";
	data_out ->write("ZZZZZZZZ");

	ce -> write(SC_LOGIC_Z);
	wr -> write(SC_LOGIC_Z);
	rd -> write(SC_LOGIC_Z);
	bus_mutex.unlock();
}

void TestBench::read(sc_lv<2> Addr, sc_uint<8>& Data)
{
	bus_mutex.lock();
    cout << sc_time_stamp() << " : ------------------read---------------- " << endl;
    cout << "data_in = "<< Data << endl;
	ce -> write(SC_LOGIC_1);
	//wr -> write(SC_LOGIC_0);
	//rd -> write(SC_LOGIC_0);
	addr = Addr;	
	//wait(25, SC_NS);

	rd -> write(SC_LOGIC_1);
	wait(25, SC_NS);

	Data = data_in->read();
	ce -> write(SC_LOGIC_0);
	rd -> write(SC_LOGIC_0);
	wait(25, SC_NS);

	ce -> write(SC_LOGIC_Z);
	wr -> write(SC_LOGIC_Z);
	rd -> write(SC_LOGIC_Z);
	bus_mutex.unlock();

}

void TestBench::write(sc_lv<2> Addr, sc_uint<8> Data)
{
	bus_mutex.lock();
	cout << sc_time_stamp() << " : ------------------write---------------- " << endl;
    cout << "data_in = "<< Data << endl;

	//wait(25,SC_NS);
	//wr -> write(SC_LOGIC_0);
	//wait(50,SC_NS);

    ce -> write(SC_LOGIC_1);
	//rd -> write(SC_LOGIC_0);
   // wait(25, SC_NS);

	addr->write(Addr);
	//data_out->write("ZZZZZZZZ");
	wait(25, SC_NS);
	
	wr -> write(SC_LOGIC_1);
	data_out->write(Data);
	wait(75, SC_NS);

	ce -> write(SC_LOGIC_0);
	wr -> write(SC_LOGIC_0);
	data_out->write("ZZZZZZZZ");
	wait(25, SC_NS);

	ce -> write(SC_LOGIC_Z);
	wr -> write(SC_LOGIC_Z);
	rd -> write(SC_LOGIC_Z);
	bus_mutex.unlock();
}
