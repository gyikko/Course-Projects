/**
 * @file passenger_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <vector>
#include <random>
#include "src/bus_factory.h"
​
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
int rand_int = dist1(rng);

if (rand_int == 1){ // small bus

} else if (rand_int == 2) { // regular bus

} else { // large bus

}