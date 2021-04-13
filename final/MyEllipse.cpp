#include "stdafx.h"
#include "MyEllipse.h"

IMPLEMENT_SERIAL(MyEllipse, MyShape, 1)

void MyEllipse::drawShape(CClientDC &dc)
{
	dc.Ellipse(begin.x, begin.y, end.x, end.y);
}
void MyEllipse::perimeter_calc()
{
	this->perimeter = 2 * 3.14*(sqrt((x*x + y * y) / 2));
	SetDetails();
}
void MyEllipse::area_calc()
{
	this->area = 3.14*x*y;
}

void MyEllipse::setY(double y)
{
	this->y = y;
	
}

void MyEllipse::getY(double &y)
{
	y = this->y;
}
void MyEllipse::SetDetails()
{
	string s = "Ellipse : Radius1 =" + to_string(x) + "," + "Radius2" + to_string(y) + ",area=" + to_string(area)
		+ ",permiter=" + to_string(perimeter);
	details = (s.c_str());
}
