#pragma once

#include "MyCircle.h"
#include <math.h>
class MyEllipse : public MyCircle
{
	DECLARE_SERIAL(MyEllipse)
	MyEllipse():MyCircle(){};
	~MyEllipse(){};
	void drawShape(CClientDC &dc);
	void perimeter_calc();
	void area_calc();
	void getY(double &y);
	void setY(double);
	void SetDetails();
protected:
	double y;
};