#include "Computer.h"
#include <string>
#include <stdexcept>
#pragma warning (disable:4996)

void Computer::free()
{
	delete[] brand;
	delete[] processor;
}

void Computer::copyFrom(const Computer& other)
{
	brand = new char[strlen(other.brand)+1];
	strcpy(brand, other.brand);
	processor = new char[strlen(other.processor)+1];
	strcpy(processor, other.processor);
	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	batteryLife = other.batteryLife;
	price = other.price;
	setQuantity(other.quantity);
}

void Computer::setQuantity(double num)
{
	if (num < 0) {
		throw std::invalid_argument("quantity cant be negative");
	}
	quantity = num;
}

double Computer::getQuantity() const
{
	return quantity;
}

Computer::Computer()
{
	id = counter;
	counter++;
	brand = nullptr;
	processor = nullptr;
	video = 0;
	hardDrive = 0;
	weight = 0;
	batteryLife = 0;
	price = 0;
	quantity = 0;
}

Computer::~Computer()
{
	free();
}

Computer::Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife, double price, double quantity)
{
	this->brand = new char[strlen(brand)];
	strcpy(this->brand, brand);
	this->processor = new char[strlen(processor)];
	strcpy(this->processor, processor);
	this->video = video;
	this->hardDrive = hardDrive;
	this->weight = weight;
	this->batteryLife = batteryLife;
	this->price = price;
	setQuantity(quantity);
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
