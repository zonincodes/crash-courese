#include <cstdio>
#include <stdexcept>
#include <cstdint>
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
    AutoBrake(const T &publish) : collision_threshold_s{5}, speed_mps{}, publish{publish} 
    {

    }

    void observe(const SpeedUpdate& cd) {
        speed_mps = cd.velocity_mps;
    }
    void observe(const CarDetected& cd) {
        const auto relative_velocity_mps = speed_mps - cd.velocity_mps;
        const auto time_to_collison_s = cd.distance_m / relative_velocity_mps;

        if(time_to_collison_s > 0 && 
            time_to_collison_s <= collision_threshold_s){
            publish(BrakeCommand{time_to_collison_s});
        }
    }

    void set_collision_threshold_s(double x){
        if(x < 1) throw std::runtime_error{"Collision less than 1."};
        collision_threshold_s = x;
    }

    double get_speed_mps() const {
        return speed_mps;
    }

    double get_collision_threshold_s() const {
        return collision_threshold_s;
    }

    private:
        double collision_threshold_s;
        double speed_mps;
        const T& publish;
};

void assert_that(bool statement, const char* message)
{
    if(!statement) throw std::runtime_error{message};
}
//  requirement initial speed is zero
void initial_speed_is_xero(){
    AutoBrake auto_brake{[](const BrakeCommand&){}};
    assert_that(auto_brake.get_speed_mps() == 0L, "speed not equal 0");
}

// requiremnt: Default Collision Threshold is Five
void initial_sensitivity_is_five()
{
    AutoBrake auto_brake{[](const BrakeCommand&){}};
    assert_that(auto_brake.get_collision_threshold_s() == 5L, "sensitivity is not 5");
}

// requirement: Sensitivity must always be greater than one
void sensitivity_greater_than_1(){
    AutoBrake auto_brake{ [](const BrakeCommand&) {}};
    try{
        auto_brake.set_collision_threshold_s(0.5L);
    } catch( const std::exception&){
        return;
    }

    assert_that(false, "no exception thrown");
}

// Requirement: Save the Car's speed Bettween Updates

void speed_is_saved() {
    AutoBrake auto_brake {[](const BrakeCommand&) {}};
    auto_brake.observe(SpeedUpdate{100L});
    assert_that(100L == auto_brake.get_speed_mps(), "speed not saved to 100");
    auto_brake.observe(SpeedUpdate{ 50L });
    assert_that(50L == auto_brake.get_speed_mps(), "speed not saved to 50");
    auto_brake.observe(SpeedUpdate {0L});
    assert_that(0L == auto_brake.get_speed_mps(), "speed not saved to 0");
}

// Requirement: AutoBrake Publishes a BrakeCommand When Collisison Detected

void alert_when_imminent() {
    int brake_commands_published{};
    AutoBrake auto_brake{[&brake_commands_published](const BrakeCommand&){
            brake_commands_published++;
        }};
    auto_brake.set_collision_threshold_s(10L);
    auto_brake.observe(SpeedUpdate{100L});
    auto_brake.observe(CarDetected{100L, 0L});
    assert_that(brake_commands_published == 1, "brake commands published not one");
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
    run_test(initial_speed_is_xero, "initial speed is 0");
    run_test(initial_sensitivity_is_five, "initial sensitivity is 5");
    run_test(sensitivity_greater_than_1, "sensitivity greater than 1");
    run_test(speed_is_saved, "speed is saved");
    run_test(alert_when_imminent, "alert when imminent");
}