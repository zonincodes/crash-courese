#include <cstdio>
#include <stdexcept>
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
    AutoBrake(const T &publish) : publish { publish} {}
    void observe(const SpeedUpdate& cd) {}
    void observe(const CarDetected& cd) {}

    void set_collision_threshold_s(double x){
        set_collision_threshold_s = x;
    }

    double get_speed_mps() const {
        return speed_mps;
    }

    private:
        const T& publish;
        double collision_threshold_s;
        double speed_mps;
};

const void assert_that(bool statement, const char* message)
{
    if(!statement) throw std::runtime_error{message};
}

int main() {
    ServiceBus bus;

    AutoBrake auto_brake{[&bus] (const auto& cmd){bus.publish(cmd);}};
    // while(true)
    // {
    //     auto_brake.observe(SpeedUpdate{10L});
    //     auto_brake.observe(CarDetected{250L, 25L});
    // }

    assert_that(1 + 2 > 2, "Something is profoundly wrong wit the universe.");
    assert_that(24 == 42, "This assertion will generate an exception");
}