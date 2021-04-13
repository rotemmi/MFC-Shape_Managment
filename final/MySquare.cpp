#include "stdafx.h"
#include "MySquare.h"

IMPLEMENT_SERIAL(MySquare, MyShape, 1)

void MySquare::drawShape(CClientDC &dc)
{
	dc.Rectangle(begin.x, begin.y, end.x, end.y);
}

void MySquare::perimeter_calc()
{
	this->perimeter = (2 * this->x) + (2 * this->x);
	SetDetails();
}
void MySquare::area_calc()
{
	this->area = this->x* this->x;
}

void MySquare::setX(double x)
{
	this->x = x;
}

void MySquare::getX(double &x)
{
	x = this->x;
}

void MySquare::getY(double &y)
{
	y = this->x;
}

void MySquare::SetDetails()
{
	string s = "Square : Edge 1=" + to_string(x) + "," + ",area=" + to_string(area)
		+ ",permiter=" + to_string(perimeter);
	details = (s.c_str());
}
