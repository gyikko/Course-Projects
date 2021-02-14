/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/stop.h"
#include "../src/passenger.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  Route *route;
  Stop *stp1;
  Stop *stp2;
  Stop **stops;
  double *distances;
  RandomPassengerGenerator *generator;
  list<double> db_lst;
  list<Stop *> stp_lst;

  virtual void SetUp() {
    stp1 = new Stop(1);
    stp2 = new Stop(2);
    stops = new Stop*[2];
    stops[0] = stp1;
    stops[1] = stp2;

    distances = new double[1];
    distances[0] = 5.5;
    db_lst.push_back(0.1);
    db_lst.push_back(0.2);
    stp_lst.push_back(stp1);
    stp_lst.push_back(stp2);
    generator = new RandomPassengerGenerator(db_lst, stp_lst);
    route = new Route("bus", stops, distances, 2, generator);
  }
  
  virtual void TearDown() {
    delete []distances;
    delete route;
    delete stp1;
    delete stp2;
    delete []stops;
    //delete generator;

    stp1 = NULL;
    stp2 = NULL;
    generator = NULL;
    route = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST_F(RouteTests, Constructor) {
  std::string expected_output = "Name: bus\nNum stops: 2";
  testing::internal::CaptureStdout();
  route -> Report(std::cout);
  std::string output = testing::internal::GetCapturedStdout();
  int p = output.find(expected_output);
  EXPECT_GE(p, 0);
  EXPECT_EQ(route -> GetName(), "bus");
  EXPECT_EQ(route -> GetDestinationStop(), stp1);
  EXPECT_GE(route -> GetTotalRouteDistance(), 5);
  EXPECT_GE(route -> GetNextStopDistance(), 0);
}

TEST_F(RouteTests, EndCheck) {
  EXPECT_EQ(route -> IsAtEnd(), false);
  route -> NextStop();
  EXPECT_EQ(route -> PrevStop(), stp1);
  route -> NextStop();
  EXPECT_EQ(route -> IsAtEnd(), true);
}