/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <vector>
#include <random>
#include "src/bus.h"

class BusFactory {
  public:
    Bus * GenerateBus(std::string name, Route * out, Route * in,
                             int busType, double speed = 1);
};
#endif  // SRC_BUS_FACTORY_H_