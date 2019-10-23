#pragma once
class Speler {
private:
	int _goudstukken;
public:
	Speler(int goudStukken);
	int getGoudstukken() const;
	void setGoudstukken(int aantal);
};