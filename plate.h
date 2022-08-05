#pragma once
#include <iostream>

class plate
{
private:
	std::string number;
	int version;//0:reset 1~8 -1:unknown
	int vehicle_type;
	void process();
	void reset();
	void set_version();
	void set_type_V8();
public:
	friend std::istream& operator>>(std::istream& is, plate& p);
	friend std::ostream& operator<<(std::ostream& os, plate& p);
};

std::istream& operator>>(std::istream& is, plate& p);
std::ostream& operator<<(std::ostream& os, plate& p);
