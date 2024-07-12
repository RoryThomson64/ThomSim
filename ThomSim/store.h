#pragma once
#include <vector>
#include <unordered_map>
#include "dataref.h"
#include<string>
#include <memory>
#include <iostream>

template<typename T>
void printValue(std::string name, T inVal) {
	std::cout << name;
	std::cout << " -> ";
	std::cout << inVal << std::endl;
}

class Store
{
public:
	Store() {
	}
	template<typename T>
	dataref<T>* add(std::string name, T initialValue) {
		dataref <T>* dref = new dataref<T>(initialValue);
		//dataref<T>* dref = &tempDref;
		Store::datarefs.insert(std::pair<std::string, base_dataref*>(name, dref));
		return dref;
	}
	template<typename T>
	dataref <T>* get(std::string name) {
		dataref<T>* dref = static_cast<dataref<T>*>(Store::datarefs[name]);
		return dref;
		//return datarefs[name];
	}
	template<typename T>
	void addListener(std::string name, void (*newFunc)(T value)) {
		dataref<T>* dref = Store::get<T>(name);
		dref->addListener(newFunc);
	}
	void handleListeners() {
		for (auto dref : Store::datarefs) {
			dref.second->handleListeners();
		}
	}

	

private:
	std::unordered_map<std::string, base_dataref*> datarefs ;
};


