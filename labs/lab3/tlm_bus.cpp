#include "tlm_bus.h"

void TLMBus::writeToSlave(unsigned int addr_, int data_){
    
    mux.lock();
    rwToSlaveEv.notify();
    rw = false;
    data = data_;
    addr = addr_;
    wait(ackToMasterEv); 
    mux.unlock();
}
int TLMBus::readToSlave(unsigned int addr_){
    
    mux.lock();  
    rwToSlaveEv.notify();
    rw = true;
    addr = addr_;  
    wait(sendDataToMasterEv);
    mux.unlock();
    return data;
}
const sc_event& TLMBus::irq0Event() const{
    return irq0;
}
const sc_event& TLMBus::irq1Event() const{
    return irq1;
}

void TLMBus::sendDataToMaster(int data_){
    data = data_;
    sendDataToMasterEv.notify();
}
void TLMBus::sendAckToMaster(){
    ackToMasterEv.notify();
}
const sc_event& TLMBus::rwEvent() const{
    return rwToSlaveEv;
}
bool TLMBus::isRead() const{
    return rw;
}
int TLMBus::getData() const{
    return data;
}

unsigned int TLMBus::getAddress() const{
    return addr;
}
void TLMBus::irq0Notify(){
    irq0.notify();
}
void TLMBus::irq1Notify(){
    irq1.notify();
}