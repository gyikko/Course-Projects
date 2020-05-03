/**
 * @file observer.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_OBSERVABLE_H_
#define SRC_OBSERVABLE_H_
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include "src/data_structs.h"
#include "src/observer.h"

/**
 * @brief
 *This class is the base class of Bus
 * It helps to user to observe the bus rides on route
 */
class IObservable {
 private:
    std::vector<IObserver*> observer_;
 public:
    void  RegisterObserver(IObserver * observer);  // Add observer to vector
    void ClearObservers();  // delete the observers
    void NotifyObservers(BusData * info);  // Upddate the observer results
};
#endif  // SRC_OBSERVABLE_H_
