#include "rx_unit.h"


void RxUnit::RxUnit_THREAD(){
    bool ready=false;
    int count=0; //0-16 cyc_rx
    int count_bit=0; //0-8 cyc_tx

    while(true){
        wait();

        if(reset->read()){
            output_err->write(false);
            frame_err->write(false);
            data_rdy->write(false);
            data_out->write("00000000");
        }
        else{
            if(read->read()){ 
                output_err->write(false);
                frame_err->write(false);
                data_rdy->write(false);
                //ready=true;
            }


            if(enable->read()  ){ 
                if(count_bit==0){  //first bit :start
                    if(!rxd->read()){
                        shift_reg="00000000";                                            
                       
                        ++count;                  
                        if(count==16){
                            count_bit++;
                            count=0;
                        }
                    }                   

                }
                else if(count_bit>=1 && count_bit<=8){
                    ++count;
                    if(count==8){
                        shift_reg = shift_reg >> 1;
                        shift_reg = shift_reg | ((uint8_t)rxd->read() )<< 7;  
                    }
                    if(count==16){
                        count_bit++;
                        count=0;
                    }                                      
                }
                else if(count_bit==9){
                    count++;
                    if(count==8){
                        if(rxd->read()==0) frame_err->write(true);
                        else frame_err->write(false);

                        if(data_rdy->read()){
                            output_err->write(true);
                            data_rdy->write(false);
                        }
                        else 
                            data_rdy->write(rxd->read());

                        data_out->write(shift_reg);                        
                        cout<<"data_out : "<<shift_reg<<endl;
                        count_bit=0;
                        count=0;
                     //   ready=false;
                    }
                }
                
                else{
                    cout<<"count error"<<endl;
                    return;
                }

            }

        }
    }
}