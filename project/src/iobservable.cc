/**
 * @file iobservable.cc
 *
 * @copyright Jingyi Jin, All rights reserved.
 */
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>

#include "src/observable.h"
#include "src/data_structs.h"


void IObservable::RegisterObserver(IObserver* observer) {
    // add the observer into the observer list
    observer_.push_back(observer);
}

void IObservable::ClearObservers() {
    // clear the observer list
    observer_.erase(observer_.begin(), observer_.end());
}

void IObservable::NotifyObservers(BusData * info) {
    for (std::vector<IObserver*>::const_iterator iter = observer_.begin();
        iter != observer_.end(); ++iter) {
            if (*iter != 0) {
                //(*iter) -> Notify(info);
        }
    }
}
