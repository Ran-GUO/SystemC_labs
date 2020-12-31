#include "slave_module.h"

void SlaveModule::write(unsigned int addr_, sc_uint<8> data_){
    mem[addr_] = data_;
    bus->sendAckToMaster();
    
}
void SlaveModule::read(unsigned int addr_, sc_uint<8>& data_){
    data_= mem[addr_];
    bus-> sendDataToMaster(data_);
}

void SlaveModule::main_thread(){
    while(true){
        wait(bus->rwEvent());
        addr = bus->getAddress();
        if(bus->isRead()){
            cout<<"Slave- Read"<<endl;
            cout<<"----  adresse: "<< addr <<" data: "<<data<<endl;           
            read(addr,data);
        }
        else{
             cout<<"Slave- write"<<endl;
            cout<<"----  adresse:"<< addr <<"  data: "<<data<<endl;
            data = bus->getData();
            write(addr,data);
        }
    }
}

void SlaveModule::interrupt_thread(){
    while(true){
        bus->irq0Notify();
        wait(15,SC_NS);
        bus->irq1Notify();
        wait(1,SC_US);

    }
}