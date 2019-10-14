#pragma once
class Kannon {
private:
	int _type;
	int _prijs;
public:
	Kannon();
	Kannon(int type, int prijs);
	const int getType();
	const int getPrijs();
};
