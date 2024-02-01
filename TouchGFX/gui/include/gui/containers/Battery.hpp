#pragma once

#include <gui_generated/containers/BatteryBase.hpp>

class Battery : public BatteryBase
{
private:
	static constexpr const float kMaxLevel = 53.5; // Maximum battery voltage (assuming a 13s battery)
	static constexpr const float kMinLevel = 48.0; // Minimum battery voltage (assuming a 13s battery)
	static constexpr const float kWorkRange = kMaxLevel - kMinLevel; // Working amplitude of the battery
	static constexpr const int kMaxFillerHeight = 67; // Maximum battery filler height, in pixels
	static constexpr const int kMinPositionY = 10; // Minimum Y position of battery filler
	static constexpr const float kGreenZoneStart = kMaxFillerHeight * 0.7; // Battery almost full
	static constexpr const float kYellowZoneStart = kMaxFillerHeight * 0.4; // Battery level good
	static constexpr const float kOrangeZoneStart = kMaxFillerHeight * 0.2; // Battery level correct

public:
    Battery();
    virtual ~Battery() {}

    virtual void initialize();

    virtual void SetValue(float value);
protected:
};
