#pragma once
#include "Location.h"
#include <stdexcept>
#include <iostream>

class Control
{
protected:
	Location loc;
	int height = 0;
	int width = 0;

	void copyFrom(const Control& other);
public:
	virtual Control* clone() const = 0;
	virtual void setDataDialog() = 0;
	Location getLoc()const;
	void setLoc(int x, int y);
	int getHeight()const;
	int getWidth()const;
	void setHeight(int h);
	void setWidth(int w);
	Control(int x, int y, int h, int w);
	Control() = default;
	virtual ~Control() = default;
};

