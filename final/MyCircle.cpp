#include "stdafx.h"
#include "MyCircle.h"

IMPLEMENT_SERIAL(MyCircle, MyShape, 1)

 void MyCircle::drawShape(CClientDC &dc)
{
	 dc.Ellipse(begin.x, begin.y, end.x, end.y);
}
 void MyCircle::perimeter_calc()
 {
	 this->perimeter = 3.14 * 2 * this->x;
	 SetDetails();
 }
 void MyCircle::area_calc()
 {
	 this->area = 3.14*this->x*this->x;
 }
 void MyCircle::setX(double x)
 {
	 this->x = x;

 }
 void MyCircle::getX(double &x)
 {
	 x = this->x;
 }

 void MyCircle::getY(double &y)
 {
	 y = this->x;
 }
 void MyCircle::SetDetails()
 {
	 string s = "Rectangle : Radius=" + to_string(x) + "," + to_string(x) + ",area=" + to_string(area)
		 + ",permiter=" + to_string(perimeter);
	 details = (s.c_str());
 }