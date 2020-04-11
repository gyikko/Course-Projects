#ifndef SRC_OBSERVER_H_
#define SRC_OBSERVER_H_
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include "src/data_structs.h"

class IObserver {
  public:
    void Notify(BusData *info);
};

class IObservable {
  private: 
    std::vector<IObserver *> observer_;
  public:
    void RegisterObserver(IObserver * observer);
    void ClearObservers();
    void NotifyObservers (BusData * info);
};
#endif