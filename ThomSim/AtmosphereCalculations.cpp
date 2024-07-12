#include "AtmosphereCalculations.h"

float calculateOat(float elevation) {
	//https://www.grc.nasa.gov/www/k-12/VirtualAero/BottleRocket/airplane/atmosmet508.html
	float temperature = 0;
	if (elevation <= 11000) {
		temperature = 15.04 - 0.00649 * elevation;
	}
	else if (elevation <= 25000) {
		temperature = -56.46;
	}
	else {
		temperature = -131.21 + 0.00299 * elevation;
	}
	return temperature;
}
float celToKel(float Cel) {
	return Cel + 273.1;
}
float calculatePressure(float elevation, float temperature) {
	float pressure = 0;
	if (elevation <= 11000) {
		pressure = 101.29 * powf(celToKel(temperature) / 288.08, 5.256);
	}
	else if (elevation <= 25000) {
		pressure = 22.65 * exp(1.73 - 0.000157 * elevation);
	}
	else {
		pressure = 2.488 * pow(celToKel(temperature) / 216.6, -11.388);
	}
	return pressure*1000;
}
//https://en.wikipedia.org/wiki/Density_of_air
/*
float calculateAirDensity(float pressure, float temperature) {
	return pressure / (celToKel(temperature) * AIR_GAS_CONSTANT);
}
*/
//https://en.wikipedia.org/wiki/Density_of_air
float calculateAirDensity(float pressure, float temperature) {
	return (pressure* MOLAR_MASS_DRY_AIR) / (celToKel(temperature) * GAS_CONSTANT);
}

//https://en.wikipedia.org/wiki/Speed_of_sound
float calculateSpeedOfSound(float temperature) {
	return sqrtf(GAMMA * AIR_GAS_CONSTANT * celToKel(temperature));
}

float calculateMachNumber(float trueAirSpeed, float speedOfSound) {
	return trueAirSpeed / speedOfSound;
}