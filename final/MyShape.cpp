#include "stdafx.h"
#include "MyShape.h"

IMPLEMENT_SERIAL(MyShape, CObject, 1)


MyShape::MyShape() 
{
	int x, y, z;            
	x = rand() % 255;
	y = rand() % 255;
	z = rand() % 255;
	fg = RGB(0, 0, 0);
	bg = RGB(x, y, z);
}
void MyShape::setBegin(const CPoint &p) { begin = p; }
void MyShape::setEnd(const CPoint &p) { end = p; }
void MyShape::getBegin(CPoint &p) { p=begin; }
void MyShape::getEnd(CPoint &p) { p = end; }
void MyShape::draw(CClientDC &dc) {
	CPen pen(PS_SOLID, 2, fg);
	CBrush brush(bg);
	CPen *oldPen = dc.SelectObject(&pen);
	CBrush *oldBrush = dc.SelectObject(&brush);
	drawShape(dc);
	dc.SelectObject(oldPen);
	dc.SelectObject(oldBrush);
}
double MyShape::getPerimeter()
{
	return this->perimeter;
}
double MyShape::getArea()
{
	return this->area;
}
void MyShape::Serialize(CArchive& archive)
{
	double x, y;
	if (archive.IsStoring())
	{
		getX(x);
		getY(y);
		archive << bg << fg << begin.x << begin.y << end.x << end.y << perimeter << area << x<<y;

	}
	else
	{
		archive >> bg >> fg >> begin.x >> begin.y >> end.x >> end.y>>perimeter>>area>>x>>y;
	}
}
