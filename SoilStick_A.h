#ifndef SOILSTICK_A_H
#define SOILSTICK_A_H

#include <Arduino.h>

// volumetric water content-saturated
const int VWCSx100[] = {0, 212, 435, 672, 924, 1193, 1479, 1787, 2118, 2475, 2862, 3283, 3744, 4249, 4808, 5429, 6124, 6907, 7796, 8817, 10000};

#define SOILMOSITURE_WET_VOLT 1.88
#define SOILMOSITURE_DRY_VOLT 2.5

class SoilStick_A
{
public:
	SoilStick_A();
	void begin(int _analog_in_pin, int _digital_out_pin);
	void setADC(int _ADCresolution, float Vref);
	void setSoilMoistureWet(float _sm_wet_volt);	// wet
	void setSoilMoistureDry(float _sm_dry_volt);	// dry
	float readOutputVolt();
	int readOutputMilliVolt();
	float VWCS();	// volumetric water content-saturated
	float VWCS(float sonsor_out_volt);	// volumetric water content-saturated
private:
	int analog_in_pin;
	int digital_out_pin;

	int sm_wet_millivolt;
	int sm_dry_millivolt;

	int ADCresolution = 1024;
	int ACD_ref_millivolt = 5000;
};

#endif