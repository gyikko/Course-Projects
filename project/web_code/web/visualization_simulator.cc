/**
 * @file passenger_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "web_code/web/visualization_simulator.h"
#include "src/bus.h"
#include "src/observable.h"
#include "src/bus_factory.h"
#include "src/route.h"
#include "src/file_manager.h"
#include "src/file_writer.h"
#include "src/util.h"

int GenerateRandom() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
    int rand_int = dist1(rng);

    return rand_int;
}

VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
                                               ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
                                   const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);
        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

void VisualizationSimulator::Update() {
    if (pause == false) {
        simulationTimeElapsed_++;

        std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
        std::cout << "~~~~~~~~~~" << std::endl;

        std::cout << "~~~~~~~~~~ Generating new busses if needed ";
        std::cout << "~~~~~~~~~~" << std::endl;

        // Check if we need to generate new busses
        for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
            // Check if we need to make a new bus
            if (0 >= timeSinceLastBus_[i]) {
                Route * outbound = prototypeRoutes_[2 * i];
                Route * inbound = prototypeRoutes_[2 * i + 1];
                int busType = GenerateRandom();

                BusFactory bus;
                busses_.push_back(bus.GenerateBus(std::to_string(busId),
                                outbound->Clone(), inbound->Clone(), busType, 1));
                busId++;
                timeSinceLastBus_[i] = busStartTimings_[i];
            } else {
                timeSinceLastBus_[i]--;
            }
        }
    
        std::cout << "~~~~~~~~~ Updating busses ";
        std::cout << "~~~~~~~~~" << std::endl;

        std::ostringstream bus_data_oss;
        if(simulationTimeElapsed_ == numTimeSteps_){
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
                busses_[i] -> Report(bus_data_oss);
                std::vector<std::string> bus_data = Util::processOutput(bus_data_oss);
                FileWriter fw = FileWriterManager::GetInstance();
                fw.Write(bus_stats_file_name, bus_data);

                // bus_data_oss.flush();
                bus_data_oss.str("");

        }
        }
        // Update busses
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
            busses_[i]->Update();

            if (busses_[i]->IsTripComplete()) {
                webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
                busses_[i] -> Report(bus_data_oss);
                std::vector<std::string> bus_data = Util::processOutput(bus_data_oss);
                FileWriter fw = FileWriterManager::GetInstance();
                fw.Write(bus_stats_file_name, bus_data);

                // bus_data_oss.flush();
                bus_data_oss.str("");
                busses_.erase(busses_.begin() + i);
                continue;
            }
            webInterface_->UpdateBus(busses_[i]->GetBusData());

            busses_[i]->Report(std::cout);
        }
    }
    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
}

void VisualizationSimulator::Pause() {
    pause = !pause;
}

void VisualizationSimulator::ClearListeners() {
    for (size_t i = 0; i < busses_.size(); i++) {
        busses_[i]->ClearObservers();
    }
}

void VisualizationSimulator::AddListener(std::string id, IObserver *observer) {
    for (size_t i = 0; i < busses_.size(); i++) {
        busses_[i]->RegisterObserver(observer);
    }
}