#include "tx_unit.h"

void TxUnit::TxUnit_THREAD(){
 
    int count=0;
    while(true){
        wait();
        if(reset->read()){
            count = 0;
            reg="00000000";
            buf="00000000";
            txd->write(1);
            reg_empty->write(true);
            buf_empty->write(true);

        }
        else{
            if(load->read()){ //clk->pos && load, load data in buf
                buf=data_in.read();
                buf_empty->write(false);
            }


            if(enable->read()){ 
                if(count==0 ){  //first bit :start
                    if(!buf_empty->read()){
                        txd->write(false); //start
                        reg=buf;
                        reg_empty->write(false);
                        buf_empty->write(true);
                        cout<<"start for transmission...  reg : "<<reg.to_uint()<<endl;
                        ++count;
                    }   
                    else{    
                        txd->write(true);
                        reg_empty->write(true);             
                    }
                }
                else if(count>=1 && count<=8){
                    txd->write(reg.to_uint() & 1);
                    reg = reg>>1;
                    cout<<txd->read();                   
                    ++count;
                }
                else if(count==9){
                    txd->write(true); //stop
                    reg_empty->write(true);
                    count=0;
                    cout<<txd->read()<<endl;
                }
                else{
                    cout<<"count error"<<endl;
                    return;
                }

            }

        }
    }
}