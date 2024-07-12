#include <iostream>
#include "dataref.h"
#include "Atmosphere.h"

Atmosphere atmosphere;

int main() {
	atmosphere.setup();
	while (true) {
		atmosphere.flightLoop();
	}
	
}