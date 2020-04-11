/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

#include "src/observer.h"
#include "src/data_structs.h"
#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"

using namespace std;

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/**
 * @brief
 * As the description mentioned above, Bus Factory was created to generate different types of buses. So,
 * in this class, I implimented three different buses categorized by capacity of the bus, small, regular,
 * and large. Small bus will have 30 maximum capacity, regular is assigned with 60 capacity while large
 * can load 90 passengers maximum. The three class all inherited from their parent class, Bus.
 * Also, they all have on public class, Report, to tell people which type of bus is generated when the
 * simulator is running.
 */
class Bus : public IObservable {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  bool IsTripComplete();
  bool LoadPassenger(Passenger *);  // returning revenue delta
  bool Move();
  void Update();
  virtual void Report(std::ostream&);

  // Vis Getters
  void UpdateBusData();
  BusData GetBusData() const;
  std::string GetName() const { return name_; }
  Stop * GetNextStop() const { return next_stop_; }
  size_t GetNumPassengers() const { return passengers_.size(); }
  int GetCapacity() const { return passenger_max_capacity_; }

  // Built for observer
  void RegisterObserver(IObserver *bus_observer);
  void ClearObservers();
  void NotifyObservers(BusData *info);
  void Notify(BusData *info);

 private:
  // Observer for bus
  vector<IObserver *> observer_;
  
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete

  // Vis data for bus
  BusData bus_data_;
};

/**
 * @brief
 * A Small Bus product, bus size is 30 maximum capacity.
 */
class SmallBus : public Bus {
 public:
    SmallBus(std::string name, Route * out, Route * in, double speed = 1)
     :Bus(name, out, in, 30, speed) {}
    void Report(std::ostream&) override;
};
/**
 * @brief
 * A Small Bus product, bus size is 60 maximum capacity
 */
class RegularBus : public Bus {
 public:
    RegularBus(std::string name, Route * out, Route * in, double speed = 1)
     :Bus(name, out, in, 60, speed) {}
    void Report(std::ostream&) override;
};
/**
 * @brief
 * A Small Bus product, bus size is 90 maximum capacity
 */
class LargeBus : public Bus {
 public:
    LargeBus(std::string name, Route * out, Route * in, double speed = 1)
     :Bus(name, out, in, 90, speed) {}
    void Report(std::ostream&) override;
};
#endif  // SRC_BUS_H_
