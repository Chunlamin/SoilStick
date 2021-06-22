#include <SoilStick_A.h>

SoilStick_A::SoilStick_A()
{

}

void SoilStick_A::begin(int _analog_in_pin, int _digital_out_pin)
{
	analog_in_pin = _analog_in_pin;
	digital_out_pin = _digital_out_pin;

	pinMode(analog_in_pin, INPUT);
	pinMode(digital_out_pin, OUTPUT);
	digitalWrite(digital_out_pin, LOW);

	sm_wet_millivolt = SOILMOSITURE_WET_VOLT * 1000.0;
	sm_dry_millivolt = SOILMOSITURE_DRY_VOLT * 1000.0;
	
	return;
}

void SoilStick_A::setADC(int _ADCresolution, float Vref)
{
	ADCresolution = _ADCresolution;
	ACD_ref_millivolt = Vref * 1000.0;

	return;
}

void SoilStick_A::setSoilMoistureWet(float _sm_wet_volt)
{
	sm_wet_millivolt = _sm_wet_volt * 1000.0;

	return;
}

void SoilStick_A::setSoilMoistureDry(float _sm_dry_volt)
{
	sm_dry_millivolt = _sm_dry_volt * 1000.0;

	return;
}

float SoilStick_A::readOutputVolt()
{
	digitalWrite(digital_out_pin, HIGH);
	delay(200);

	int readADC = analogRead(analog_in_pin);

	digitalWrite(digital_out_pin, LOW);

	float output_volt = (float(readADC) / float(ADCresolution)) * (float(ACD_ref_millivolt) / 1000.0);

	return output_volt;
}

int SoilStick_A::readOutputMilliVolt()
{
	digitalWrite(digital_out_pin, HIGH);
	delay(200);

	int readADC = analogRead(analog_in_pin);

	digitalWrite(digital_out_pin, LOW);

	int output_millivolt = int((float(readADC) / float(ADCresolution)) * float(ACD_ref_millivolt));

	return output_millivolt;
}

float SoilStick_A::VWCS()
{
	int sensor_output_mV = readOutputMilliVolt();

	int output_percentx10_and_invert = map(sensor_output_mV, sm_dry_millivolt, sm_wet_millivolt, 0, 1000);

	for (int i = 1; i <= 20; i++)
	{
		if(output_percentx10_and_invert < i * 50 || i == 20) {

			float _VWCS = map(output_percentx10_and_invert, (i - 1) * 50, i * 50, VWCSx100[i-1], VWCSx100[i]);

			_VWCS /= 100.0;

			return _VWCS;
		}
	}

	return -1;
}

float SoilStick_A::VWCS(float sonsor_out_volt)
{
	int sensor_output_mV = sonsor_out_volt * 1000;

	int output_percentx10_and_invert = map(sensor_output_mV, sm_dry_millivolt, sm_wet_millivolt, 0, 1000);

	for (int i = 1; i <= 20; i++)
	{
		if(output_percentx10_and_invert < i * 50 || i == 20) {

			float _VWCS = map(output_percentx10_and_invert, (i - 1) * 50, i * 50, VWCSx100[i-1], VWCSx100[i]);

			_VWCS /= 100.0;

			return _VWCS;
		}
	}

	return -1;
}