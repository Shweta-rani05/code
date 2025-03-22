#include <iostream>
#include <string>

// Base class
class ClimateEffect {
public:
    std::string region;
    double temperature_rise;
    double precipitation_change;

    // Constructor
    ClimateEffect(std::string r, double t_rise, double p_change) 
        : region(r), temperature_rise(t_rise), precipitation_change(p_change) {}

    // Display method
    virtual void display_effect() const {
        std::cout << "Region: " << region << std::endl;
        std::cout << "Temperature Rise: " << temperature_rise << "°C" << std::endl;
        std::cout << "Precipitation Change: " << precipitation_change << "mm" << std::endl;
    }
};

// Derived class for Agriculture
class AgricultureEffect : public ClimateEffect {
public:
    double crop_yield_change;

    // Constructor
    AgricultureEffect(std::string r, double t_rise, double p_change, double c_yield_change) 
        : ClimateEffect(r, t_rise, p_change), crop_yield_change(c_yield_change) {}

    // Display method
    void display_effect() const override {
        ClimateEffect::display_effect();
        std::cout << "Crop Yield Change: " << crop_yield_change << "%" << std::endl;
    }
};

// Derived class for Health
class HealthEffect : public ClimateEffect {
public:
    double disease_risk_increase;

    // Constructor
    HealthEffect(std::string r, double t_rise, double p_change, double d_risk_increase) 
        : ClimateEffect(r, t_rise, p_change), disease_risk_increase(d_risk_increase) {}

    // Display method
    void display_effect() const override {
        ClimateEffect::display_effect();
        std::cout << "Disease Risk Increase: " << disease_risk_increase << "%" << std::endl;
    }
};

int main() {
    // Create instances of AgricultureEffect and HealthEffect
    AgricultureEffect agri_effect("Asia", 1.5, -200.0, -10.0);
    HealthEffect health_effect("Asia", 1.5, -200.0, 20.0);

    // Display the information
    std::cout << "Agriculture Effect:" << std::endl;
    agri_effect.display_effect();
    std::cout << std::endl;

    std::cout << "Health Effect:" << std::endl;
    health_effect.display_effect();

    return 0;
}

