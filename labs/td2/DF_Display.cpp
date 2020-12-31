#include "DF_Display.h"


void DF_Display::DF_Display_thread(void){
	//while(true){
		for (int i=1;i<N;i++){
		double res=result->read();
		std::cout<<sc_time_stamp()<<" : result display : "<<res<<std::endl;
		}
	std::cout<<sc_time_stamp()<<" : ================stop display ============== "<<std::endl;
	//}
		
}

