/**
 * @file observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include "src/data_structs.h"

/**
 * @brief
 * IObserver is a class to Notify the bus data. IObservable
 * is used to build a set of vector contains IObserver. It
 * then can register observers so that when the simulator
 * runs, when the busses are generated, they can be added
 * into observer and notify the results.
 */
class IObserver {
 public:
    void Notify(BusData *info);  // Notify the bus information
};
#endif  // SRC_OBSERVER_H_
