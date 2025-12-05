#pragma once

enum class ShipClass {
	bb, bc
};

class Ship {
private:
	char* shipName = nullptr;
	int year = 0;
	ShipClass sc = ShipClass(0);
	int cannonCount = 0;

public:
	void SetName(char* sn);
	void SetYear(int year);
	void SetClass(ShipClass sc);
	void SetCannonCount(int cc);
	char* GetName();
	int GetYear();
	ShipClass GetClass();
	int GetCannonCount();
	Ship() = default;
	Ship(const char* shipName, int year, ShipClass sc, int cannonCount);
	~Ship();
	Ship(const Ship& s);
	Ship& operator=(const Ship& s);
private:
	void CopyFrom(const Ship& s);
	void free();
};