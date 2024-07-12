#pragma once
#include "simulationComponent.h"
#include "dataref.h"
#include <functional>
#include "AtmosphereCalculations.h"






class Atmosphere: public simulationComponent
{
private:
	dataref<float>* pressure;
	dataref<float>* oat;
	dataref<float>* elevation;
	dataref<float>* airDensity;
	dataref<float>* speedOfSound;
	dataref<float>* machNumber;
	dataref<float>* trueAirSpeed;
public:
	void setup();
	void flightLoop();

	
};

