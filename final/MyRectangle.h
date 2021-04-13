#pragma once

#include "MySquare.h"
class MyRectangle : public MySquare 
{
	DECLARE_SERIAL(MyRectangle)
	MyRectangle(){};
	void drawShape(CClientDC &dc);
	void perimeter_calc();
	void area_calc();
	void getY(double &y);
	void setY(double);
	void SetDetails();
private:
	double y;
};