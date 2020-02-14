/**
 * @file main.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <string>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of useful information.
 *
 * Functions for passengers to set their travel information.
 */
class Passenger {  // : public Reporter {
 public:
  explicit Passenger(int = -1, std::string = "Nobody");
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  /**
  * @brief Generation of a stop id set by passenger.
  *
  * This function will be used to get the stop id of passenger's destination.
  */
  int GetDestination() const;
  void Report() const;
 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
