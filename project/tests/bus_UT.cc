/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/random_passenger_generator.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger_loader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:
  Bus *bus;
  /*-----------router1------------*/
  Route *route1;
  Stop *stp1;
  Stop *stp2;
  Stop **stops1;
  double *distances1;
  RandomPassengerGenerator *generator1;
  list<double> db_lst1;
  list<Stop *> stp_lst1;
  /*-----------router1------------*/
  Route *route2;
  Stop *stp3;
  Stop *stp4;
  Stop **stops2;
  double *distances2;
  RandomPassengerGenerator *generator2;
  list<double> db_lst2;
  list<Stop *> stp_lst2;
  /*----------passenger----------*/ 
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    /*-----------router1------------*/
    stp1 = new Stop(1);
    stp2 = new Stop(2);
    stops1 = new Stop*[2];
    stops1[0] = stp1;
    stops1[1] = stp2;
    distances1 = new double[1];
    distances1[0] = 1.5;
    db_lst1.push_back(0.1);
    db_lst1.push_back(0.2);
    stp_lst1.push_back(stp1);
    stp_lst1.push_back(stp2);
    generator1 = new RandomPassengerGenerator(db_lst1, stp_lst1);
    route1 = new Route("bus1", stops1, distances1, 1, generator1);
    /*-----------router2------------*/
    stp3 = new Stop(1);
    stp4 = new Stop(2);
    stops2 = new Stop*[2];
    stops2[0] = stp1;
    stops2[1] = stp2;
    distances2 = new double[1];
    distances2[0] = 2.5;
    db_lst2.push_back(0.3);
    db_lst2.push_back(0.4);
    stp_lst2.push_back(stp3);
    stp_lst2.push_back(stp4);
    generator2 = new RandomPassengerGenerator(db_lst2, stp_lst2);
    route2 = new Route("bus2", stops2, distances2, 2, generator2);
    /*----------passenger----------*/ 
    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
    passenger = new Passenger();
    bus = new Bus("test", route1, route2, 5, 5);
  }

  virtual void TearDown() {
    /*-----------router1------------*/
    delete []distances1;
    delete route1;
    delete stp1;
    delete stp2;
    delete []stops1;
    stp1 = NULL;
    stp2 = NULL;
    generator1 = NULL;
    route1 = NULL;
    /*-----------router2------------*/
    delete []distances2;
    delete route2;
    delete stp3;
    delete stp4;
    delete []stops2;
    stp3 = NULL;
    stp4 = NULL;
    generator2 = NULL;
    route2 = NULL;
    /*----------passenger----------*/ 
    delete pass_loader;
    delete pass_unloader;
    delete passenger;
    passenger = NULL;
    pass_loader = NULL;
    pass_unloader = NULL;

    delete bus;
    bus = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(BusTests, ConstrucCheck) {
  std::string expected_output = "Name: test";
  testing::internal::CaptureStdout();
  bus -> Report(std::cout);
  std::string output = testing::internal::GetCapturedStdout();
  int p = output.find(expected_output);
  EXPECT_GE(p, 0);

  EXPECT_EQ(bus->GetName(), "test");
  EXPECT_EQ(bus->GetCapacity(), 5);
}


TEST_F(BusTests, CompleteCheck) {
  EXPECT_EQ(bus -> IsTripComplete(), false);
  for (int i = 0; i < 5; i++) {
    bus -> Update();
  }
  EXPECT_EQ(bus -> IsTripComplete(), true);
}


TEST_F(BusTests, MoveCheck) {
  passenger = new Passenger(2, "P");
  EXPECT_EQ(bus -> Move(), false);
  for (int i = 0; i < 1; i++) {
    bus -> LoadPassenger(passenger);
    bus -> Update(); 
    //EXPECT_EQ(bus -> Move(), true);
  }
}


TEST_F(BusTests, LoadCheck) {
  for (int i = 0; i < 5; i++)
    bus -> LoadPassenger(passenger);
  EXPECT_EQ(bus->GetNumPassengers(), 5);
}