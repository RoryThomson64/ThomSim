#pragma once
#include "store.h"
class simulationComponent
{
public:
	void setup();
	void flightLoop();
protected:
	static Store store;

};

