#include <cstddef>
#include <cstring>
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
	char* _type;
public:
	Handelsgoed();
	Handelsgoed(int prijs, int aantal, int maxPrijs, int minPrijs, int maxAantal, int minAantal, char* type);
	~Handelsgoed();
	Handelsgoed(const Handelsgoed& copyHandelsgoed);
	Handelsgoed& operator=(const Handelsgoed& copyHandelsgoed);
	Handelsgoed(Handelsgoed&& moveHandelsgoed) noexcept;
	Handelsgoed& operator=(Handelsgoed&& moveHandelsgoed) noexcept;
	int getPrijs() const;
	int getAantal() const;
	int getMinAantal() const;
	int getMaxAantal() const;
	int getMinPrijs() const;
	int getMaxPrijs() const;
	void setAantal(int aantal);
	void setPrijs(int prijs);
	
};