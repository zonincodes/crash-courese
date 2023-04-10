#include <cstdio>

struct SpeedUpdate
{
    double velocity_mps;
};

struct CarDetected
{
    double distance_m;
    double velocity_mps;
};

struct BrakeCommand{
    double time_to_collision_s;
};


struct ServiceBus
{
    void publish(const BrakeCommand&);
};


template <typename T>
struct AutoBrake
{
    AutoBrake(const T &publish);
    void observe(const SpeedUpdate&);
    void observe(const CarDetected&);

    private:
        const T& publish;
};

int main() {
    ServiceBus bus;

    AutoBrake auto_brake{[&bus] (const auto& cmd){bus.publish(cmd);}};
    while(true)
    {
        auto_brake.observe(SpeedUpdate{10L});
        auto_brake.observe(CarDetected{250L, 25L});
    }
}