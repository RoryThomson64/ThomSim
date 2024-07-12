#pragma once
#include <vector>

class base_dataref {
public:
	virtual void handleListeners() = 0;
};



template<typename T>
class dataref: public base_dataref
{
public:
	dataref(T initialValue) {
		dataref<T>::value = initialValue;
	}
	void set(T inVal) {
		if (dataref<T>::value != inVal) {
			dataref<T>::hasChanged = true;
		}
		dataref<T>::value = inVal;
	}
	T get() {
		return dataref<T>::value;
	}
	void addListener(void (*newFunc)(T value)) {
		dataref<T>::listenerFunctions.push_back(newFunc);
	}

	void handleListeners() {
		if (dataref<T>::hasChanged) {
			for (int i = 0; i < dataref<T>::listenerFunctions.size(); i++) {
				dataref<T>::listenerFunctions[i](value);
			}
			dataref<T>::hasChanged = false;
		}
	}
private:
	T value;
	bool hasChanged =false ;
	std::vector<void (*)(T value)> listenerFunctions ;
};

