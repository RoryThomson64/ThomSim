#include "Atmosphere.h"
void Atmosphere::setup() {
	simulationComponent::setup();
	pressure = store.add<float>("sim/atmosphere/pressure", 1024.0);
	Atmosphere::oat = simulationComponent::store.add<float>("sim/atmosphere/oat", 15.04);
	Atmosphere::elevation = simulationComponent::store.add<float>("flightmodel/elevaton_rad", 0);
	Atmosphere::airDensity = simulationComponent::store.add<float>("sim/atmosphere/air_density", 0.2378);
	Atmosphere::speedOfSound = simulationComponent::store.add<float>("sim/atmosphere/speed_of_sound", 343);
	Atmosphere::machNumber = simulationComponent::store.add<float>("flightmodel/mach_number", 0);
	Atmosphere::trueAirSpeed = simulationComponent::store.add<float>("flightmodel/true_air_speed", 0);

}
void Atmosphere::flightLoop() {
	simulationComponent::flightLoop();

	Atmosphere::oat->set(calculateOat(Atmosphere::elevation->get()));
	Atmosphere::pressure->set(calculatePressure(Atmosphere::elevation->get(), Atmosphere::oat->get()));
	Atmosphere::airDensity->set(calculateAirDensity(Atmosphere::pressure->get(), Atmosphere::oat->get()));
	Atmosphere::speedOfSound->set(calculateSpeedOfSound(Atmosphere::oat->get()));
	Atmosphere::machNumber->set(calculateMachNumber(Atmosphere::trueAirSpeed->get(), Atmosphere::speedOfSound->get()));
}