/* STUDENTS:  DO NOT EDIT THIS FILE.  INSTEAD, MODIFY YOUR OWN PROJECT
 * CODE TO FIT THE SPECIFICATION GIVEN BY THE TESTS IN THIS FILE.
 *
 * If you DO modify it, we overwrite it with a fresh version from our repo
 * when grading, so you can't use it to fudge the tests anyway.
 *
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;
    
  virtual void SetUp() {
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(PassengerTests, Constructor) {
  passenger = new Passenger();
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};


TEST_F(PassengerTests, NameCheck) {
  passenger1 = new Passenger(12, "John Doe");
  passenger2 = new Passenger(12, "Apple Bee");
  std::string expected_output1 = "Name: John Doe";
  std::string expected_output2 = "Name: Apple Bee";
  testing::internal::CaptureStdout();
  passenger1 -> Report(std::cout);
  std::string output1 = testing::internal::GetCapturedStdout();

  testing::internal::CaptureStdout();
  passenger2 -> Report(std::cout);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  int p1 = output1.find(expected_output1);
  int p2 = output2.find(expected_output2);
  EXPECT_GE(p1, 0);
  EXPECT_GE(p2, 0);
}


TEST_F(PassengerTests, IsOnCheck) {
  passenger = new Passenger(12, "John Doe");
  passenger -> GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
}


TEST_F(PassengerTests, TimeOnBus) {
  passenger = new Passenger(12, "John Doe");
  passenger -> GetOnBus();
  for (int i = 0; i < 5; i++)
    passenger -> Update();
  EXPECT_EQ(passenger->GetTotalWait(), 6);
}

TEST_F(PassengerTests, UpdateCheck) {
  passenger = new Passenger(12, "John Doe");
  passenger -> Update();
  EXPECT_EQ(passenger->GetTotalWait(), 1);
}


TEST_F(PassengerTests, DestinationCheck) {
  passenger = new Passenger(12, "John Doe");
  EXPECT_EQ(passenger->GetDestination(), 12);
}