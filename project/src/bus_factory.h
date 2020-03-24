/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <vector>
#include <random>
#include <string>
#include "src/bus.h"

/**
 * @brief
 * To make the project more releastic, I implemented a new class, Bus Factory, which can generate different
 * kinds of buses. So far, the needs for different buses types are just reporting different capacity. So,
 * here I used concreate factory method for bus factory. The class basically just generate the bus and use
 * an int parameter to define the type of the buses. When the parameter is set to one, small bus will be
 * generated, regular size will be generated when 2 is assigned to the parameter and leaves value 3 for
 * having large size bus. The value will be assigned randomly to make sure all kinds of buses will
 * appear on the simulator. The process will be applied in visualization_simulator.
 */
class BusFactory {
 public:
    Bus * GenerateBus(std::string name, Route * out, Route * in,
                             int busType, double speed = 1);
};
#endif  // SRC_BUS_FACTORY_H_
