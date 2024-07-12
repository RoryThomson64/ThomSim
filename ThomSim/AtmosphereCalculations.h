#pragma once
#include <corecrt_math.h>

const float AIR_GAS_CONSTANT = 287;
//https://en.wikipedia.org/wiki/Density_of_air
const float MOLAR_MASS_DRY_AIR = 0.0289652;
//https://en.wikipedia.org/wiki/Density_of_air
const float GAS_CONSTANT = 8.31446261815324;
//https://www1.grc.nasa.gov/beginners-guide-to-aeronautics/properties-of-air-text-version/
//Ratio of specific heats, likely will need to be calculated in the future
const float GAMMA = 1.4;

float calculateOat(float elevation);
float celToKel(float Cel);
float calculatePressure(float elevation, float temperature);

float calculateAirDensity(float pressure, float temperature);

float calculateSpeedOfSound(float temperature);

float calculateMachNumber(float trueAirSpeed, float speedOfSound);