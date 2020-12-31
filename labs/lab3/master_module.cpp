#include "master_module.h"

void MasterModule::boot_thread(){
    wait(5, SC_NS);
    cout<<sc_time_stamp()<<" : master : boot "<<endl;
}

void MasterModule::isr0_thread(){
    int value = 1 ;
    while(true){
        wait(bus->irq0Event());
        cout<<" master isr0_thread "<<endl;
        value = value + 1;
        addr=addr+1;
        if(addr>MAX_SIZE)addr=0;
        bus->writeToSlave(addr,value);
        cout<<sc_time_stamp()<<" : master : adress:"<< addr <<" write : " << value <<endl;
       
    }
}

void MasterModule::isr1_thread(){
    int value;
    while(true){
        wait(bus->irq1Event());
        cout<<"master isr1_thread "<<endl;
        value = bus->readToSlave(addr);
        cout<<sc_time_stamp()<<" : master : adress:" << addr <<" read : " << value <<endl;


    }
}
