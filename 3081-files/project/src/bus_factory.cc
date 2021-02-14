/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <random>
#include "src/bus_factory.h"

Bus * BusFactory::GenerateBus(std::string name, Route * out, Route * in,
                             int busType, double speed) {
    if (busType == 1) {
        return new SmallBus(name, out, in, speed);
    } else if (busType == 2) {
        return new RegularBus(name, out, in, speed);
    }
    return new LargeBus(name, out, in, speed);
}
