#pragma once

static size_t counter = 0;
class Computer
{
	size_t id;
	char* brand;
	char* processor;
	int video;
	int hardDrive;
	int weight;
	int batteryLife;
	double price;
	double quantity;

	void free();
	void copyFrom(const Computer& other);
public:
	void setQuantity(double num);
	double getQuantity() const;

	Computer();
	~Computer();
	Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife, double price, double quantity);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
};

