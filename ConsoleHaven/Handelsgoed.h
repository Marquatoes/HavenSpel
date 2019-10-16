#pragma once
class Handelsgoed
{
private:
	int _prijs;
	int _aantal;
	int _minAantal;
	int _maxAantal;
	int _maxPrijs;
	int _minPrijs;
public:
	Handelsgoed();
	Handelsgoed(int prijs, int aantal, int maxPrijs, int minPrijs, int maxAantal, int minAantal);
	const int getPrijs();
	const int getAantal();
	const int getMinAantal();
	const int getMaxAantal();
	const int getMinPrijs();
	const int getMaxPrijs();
	void setAantal(int aantal);
	void setPrijs(int prijs);
	
};