#pragma once
#include "MyShape.h"


class MyCircle : public MyShape
{
public:
	DECLARE_SERIAL(MyCircle)
	MyCircle():MyShape() {};
	virtual ~MyCircle() {};
	virtual void drawShape(CClientDC &dc);
	virtual void perimeter_calc();
	virtual void area_calc();
	virtual void SetDetails();
	void setX(double);
	void getX(double &x);
	void getY(double &y);
	
protected:
	double x;
};

