#include "stdafx.h"
#include "MyRectangle.h"

IMPLEMENT_SERIAL(MyRectangle, MyShape, 1)

void MyRectangle::drawShape(CClientDC &dc)
{
	dc.Rectangle(begin.x, begin.y, end.x, end.y);
}

void MyRectangle::perimeter_calc()
{
	this->perimeter = (2 * this->x) + (2 * this->y);
	SetDetails();
}
void MyRectangle::area_calc()
{
	this->area = this->x*this->y;
}

void MyRectangle::setY(double y)
{
	this->y = y;
	
}

void MyRectangle::getY(double &y)
{
	y = this->y;
}

void MyRectangle::SetDetails()
{
	string s = "Rectangle : Edge 1=" + to_string(x) + ",Edge 2=" + to_string(y) + ",area=" + to_string(area)
		+ ",permiter=" + to_string(perimeter);
	details = (s.c_str());
}
