#pragma once
#include <list>
#include<string>
#include <cstring>
using namespace std;

class MyShape : public CObject {
public:
	DECLARE_SERIAL(MyShape)
	MyShape();
	virtual ~MyShape() {};
	void getBegin(CPoint &p);
	void getEnd(CPoint &p);
	void setBegin(const CPoint &p);
	void setEnd(const CPoint &p);
	virtual void drawShape(CClientDC &dc) {};
	void draw(CClientDC &dc);
	void Serialize(CArchive& archive);
	virtual void perimeter_calc() {};
	virtual void area_calc() {};
	virtual void setX(double) {};
	virtual void setY(double) {};
	virtual void getX(double &x) {};
	virtual void getY(double &y) {};
	virtual void SetDetails() {};
	CString getDetails() { return details; }
	double getPerimeter();
	double getArea();
protected:
	CString details;
	CPoint begin;
	CPoint end;
	COLORREF fg;
	COLORREF bg;
	double perimeter;
	double area;
};