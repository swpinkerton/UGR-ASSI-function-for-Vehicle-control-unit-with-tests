//
// Created by Scott on 28/11/2022.
//
#include "gtest/gtest.h"
#include "Function.h"

//Outputs follow the figure from rule T14.11.1
//State         |   light response      |   int value
//AS off        |   off                 |   0
//AS Ready      |   yellow continuous   |   1
//AS Driving    |   yellow flashing     |   2
//AS Emergency  |   blue continuous     |   3
//AS Finished   |   blue flashing       |   4

// Added randomization of non required inputs to test every case

TEST(UGRTestSuite, TestsWork){
    EXPECT_TRUE(true);
}

TEST(UGRTestSuite, TestsWork2){
    int input = 0;
    EXPECT_EQ(1,function(input));
}

TEST(UGRTestSuite,ASOff1_mission) {
    int ESB_active = 0;
    int mission_finished = 0;
    int vehicle_standstill = rand()%2;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = rand()%2;
    int ASB = rand()%2;
    int TS = rand()%2;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(0, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASOff1_ASMS) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = 0;
    int ASB = rand()%2;
    int TS = rand()%2;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(0, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASOff1_ASB) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = rand()%2;
    int ASB = 0;
    int TS = rand()%2;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(0, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASOff1_TS) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = rand()%2;
    int ASB = rand()%2;
    int TS = 0;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(0, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASOff2) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = 0;
    int mission_selected = 1;
    int ASMS = 1;
    int ASB = 1;
    int TS = 1;
    int brakes_engaged = 0;
    EXPECT_EQ(0, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASReady) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = 0;
    int mission_selected = 1;
    int ASMS = 1;
    int ASB = 1;
    int TS = 1;
    int brakes_engaged = 1;
    EXPECT_EQ(1, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASDriving) {
    int ESB_active = 0;
    int mission_finished = rand()%2;
    int vehicle_standstill = rand()%2;
    int R2D = 1;
    int mission_selected = 1;
    int ASMS = 1;
    int ASB = 1;
    int TS = 1;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(2, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASEmergancy) {
    int ESB_active = 1;
    int mission_finished = 0;
    int vehicle_standstill = 1;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = rand()%2;
    int ASB = rand()%2;
    int TS = rand()%2;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(3, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}

TEST(UGRTestSuite,ASFinished) {
    int ESB_active = 1;
    int mission_finished = 1;
    int vehicle_standstill = 1;
    int R2D = rand()%2;
    int mission_selected = rand()%2;
    int ASMS = rand()%2;
    int ASB = rand()%2;
    int TS = rand()%2;
    int brakes_engaged = rand()%2;
    EXPECT_EQ(4, ASSI(ESB_active, mission_finished, vehicle_standstill, R2D, mission_selected, ASMS, ASB, TS,brakes_engaged));
}