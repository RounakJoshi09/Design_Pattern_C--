#include <bits/stdc++.h>
using namespace std;
class BusState {
    public:
        virtual void pickUp(Bus &bus, int num) {}
        virtual int dropOff(Bus &bus) {}
};

class PickUpState : public BusState {
    public:
        void pickUp(Bus &bus, int num) {
            bus.passengers += num;
        }
};

class DropOffState : public BusState {
    public:
        int dropOff(Bus &bus,int passenger) {
            int num = bus.passengers;
            bus.passengers = num-passenger;
            return num;
        }
};

class Bus {
    public:
        int id;
        int capacity;
        int passengers;
        BusState *state;

        Bus(int id, int capacity) : id(id), capacity(capacity), passengers(0) {
            state = new PickUpState();
        }

        void setState(BusState *state) {
            this->state = state;
        }

        void pickUp(int num) {
            state->pickUp(*this, num);
        }

        int dropOff() {
            return state->dropOff(*this);
        }
};

class Stop {
    public:
        int id;
        int passengers;

        Stop(int id, int passengers) : id(id), passengers(passengers) {}

        void addPassengers(int num) {
            passengers += num;
        }

        int getPassengers(int capacity) {
            int num = std::min(passengers, capacity);
            passengers = num;  
            return num;
        }
};

class Simulation {
    public:
        vector<Bus> buses;
        vector<Stop> stops;

        Simulation(int numBuses, int busCapacity, int numStops, int stopPassengers) {
            for (int i = 0; i < numBuses; i++) {
                buses.push_back(Bus(i, busCapacity));
            }
            for (int i = 0; i < numStops; i++) {
                stops.push_back(Stop(i, stopPassengers));
            }
        }

        void run() {
            for (auto &bus : buses) {
                for (auto &stop : stops) {
                    int num = stop.getPassengers(bus.capacity - bus.passengers);
                    bus.pickUp(num);
                }
                int num = bus.dropOff();
                stops.back().addPassengers(num);
                bus.setState(new DropOffState());
            }
        }
};
