
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>

#include "web_interface.h"
#include "config_manager.h"

class Route;
class Bus;
class BusFactory;
class Stop;
/**
 * @brief
 * The pause functionality mainly rely on Update(). Because, when the simulator is paused, we want the
 * simulator to stop updating. So, by defining the status of pause button (clicked or not clicked),
 * Update() will make a decision to keep updating or pause the process. The similar logic also works
 * for resume functionality. If pause function is called, then un-pause it, or pause the function if
 * the pause function is not called.
 */
class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Update();
        void Pause();

    private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;
       
        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;

        int busId = 1000;
        bool pause = false;
};

#endif // VISUALIZATION_SIMULATOR_H_
