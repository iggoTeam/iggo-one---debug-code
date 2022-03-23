/*
						Typ		Max
Conversion Time tCONV 
14-bit temperature — 	7 		10.8 ms
13-bit temperature — 	4 		6.2 ms
12-bit temperature — 	2.4 	3.8 ms
11-bit temperature — 	1.5 	2.4 ms

Temperature conversion 
in progress — 			90 120 μA
*/

#include <Wire.h>
#include "tp51.h"

tp51::tp51()
{
}

void tp51::begin(uint8_t address) {
	_address = address;
	Wire.begin();
	setResolution(14);
}

void tp51::reset()
{
	Wire.beginTransmission(_address);
	Wire.write(0xFE);
	Wire.endTransmission();
	delay(15); // Datasheet P4 Rev. 1.2
	
}

uint8_t tp51::readFirmwareVersion()
{
	Wire.beginTransmission(_address);
	Wire.write(0x84);
	Wire.write(0xB8);
	Wire.endTransmission();
	Wire.requestFrom(_address, (uint8_t)1);
	return Wire.read();
}

void tp51::setResolution(uint8_t resolution)
{
	SI7051_Register reg;

	switch (resolution)
	{
		case 12:
			reg.resolution0 = 1;
			break;	
		case 13:
			reg.resolution7 = 1;
			break;
		case 11:
			reg.resolution0 = 1;
			reg.resolution7 = 1;
			break;
	}
	
	Wire.beginTransmission(_address);
	Wire.write(0xE6);
	Wire.write(reg.rawData);
	Wire.endTransmission();
}

float tp51::readTemperature() {
	Wire.beginTransmission(_address);
	Wire.write(0xF3);
	Wire.endTransmission();
	delay(10);
	Wire.requestFrom(_address, (uint8_t)2);

	byte msb = Wire.read();
	byte lsb = Wire.read();

	uint16_t val = msb << 8 | lsb;

	return (175.72*val) / 65536 - 46.85;
}




