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

    double get_collision_threshold_s(){
        return collision_threshold_s;
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
//  requirement initial speed is zero
void initial_speed_is_xero(){
    AutoBrake auto_brake{[](const BrakeCommand&){}};
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not equal 0");
}

// requiremnt: Default Collision Threshold is Five
void initial_seinstivity_is_five()
{
    AutoBrake auto_brake{[](const BrakeCommand&){}};
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "sensitivity is not 5");
}


// test harness
void run_test(void(*unit_test)(), const char* name){
    try{
        unit_test();
        printf("[+] Test %s successful.\n", name);
    } catch (const std::exception &e){
        printf("[-] Test failure in %s. %s.\n", name, e.what());
    }
}

int main() {
    ServiceBus bus;

    AutoBrake auto_brake{[&bus] (const auto& cmd){bus.publish(cmd);}};
    // while(true)
    // {
    //     auto_brake.observe(SpeedUpdate{10L});
    //     auto_brake.observe(CarDetected{250L, 25L});
    // }

    // assert_that(1 + 2 > 2, "Something is profoundly wrong wit the universe.");
    // assert_that(24 == 42, "This assertion will generate an exception");

    run_test(initial_speed_is_xero, "initial speed is 0");
    run_test(initial_seinstivity_is_five, "initial sensitivity is 5");
}