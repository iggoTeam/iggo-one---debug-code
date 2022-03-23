
#ifndef _tp51_h
#define _tp51_h
#include <Arduino.h>

class tp51 {
public:
	tp51();

	uint8_t readFirmwareVersion();

	void begin(uint8_t address);
	void setResolution(uint8_t resolution);
	void reset();
	float readTemperature();

private:
	uint8_t _address;
};

#endif

