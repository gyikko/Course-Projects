#ifndef BUS_WEB_OBSERVER_H_
#define BUS_WEB_OBSERVER_H_

#include "src/bus.h"
#include "src/observer.h"
#include "my_web_server_session.h"
#include 

/**
 * @brief
 * This is in charge of connecting the observer with
 * front end
 */
class BusWebObserver : public IObserver{
  private:
    MyWebServerSession *session;
}
#endif  // BUS_WEB_OBSERVER_H