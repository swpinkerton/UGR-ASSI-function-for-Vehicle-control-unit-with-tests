//
// Created by Scott on 28/11/2022.
//

#include "Function.h"

// test function
int function(int bps){
    if(bps==0){
        return 1;
    }else{
        return 0;
    }
}

//Outputs follow the figure from rule T14.11.1
//State         |   light response      |   int value
//AS off        |   off                 |   0
//AS Ready      |   yellow continuous   |   1
//AS Driving    |   yellow flashing     |   2
//AS Emergency  |   blue continuous     |   3
//AS Finished   |   blue flashing       |   4

int ASSI(int ESB_active, int mission_finished, int vehicle_standstill, int R2D, int mission_selected, int ASMS, int ASB,int TS, int brakes_engaged){
    if (ESB_active){
        if (mission_finished && vehicle_standstill){
            return 4;
        }else{
            return 3;
        }
    }else{
        if(mission_selected && ASMS && ASB && TS){
            if(R2D){
                return 2;
            }else{
                if(brakes_engaged){
                    return 1;
                }else{
                    return 0;
                }
            }
        }else{
            return 0;
        }
    }
}



