/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
  Stop *stop;

  virtual void TearDown() {
    delete stop;
    stop = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(StopTests, Constructor) {
    stop = new Stop(5, 44, -93);
    EXPECT_EQ(stop->GetLongitude(), 44);
    EXPECT_EQ(stop->GetLatitude(), -93);
    EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
}