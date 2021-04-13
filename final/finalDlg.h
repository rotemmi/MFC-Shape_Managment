
// finalDlg.h : header file
//

#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "MyShape.h"

using namespace std;

static int x_cord = 30;
#define y_cord 210
static MyShape *shape;


// CfinalDlg dialog
class CfinalDlg : public CDialogEx
{
// Construction
public:
	CfinalDlg(CWnd* pParent = nullptr);	// standard constructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	vector<MyShape*> shapes;
	stack<MyShape*> undone;
	stack<MyShape*> done;
	list<CString> details;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void Loading();
	void drawVector();
	void UpdateListBox(CListBox&);
	void viewPermiterArea(MyShape * s);
	void searchAndDelete(MyShape *);
	void initTexts();
	void initialWindow();
	CButton Circle_c;
	CButton Ellipse_c;
	CButton Rectangle_c;
	CButton Square_c;
	double a_value;
	double b_value;
	double perimeter_value;
	double area_value;
	CButton undo_c;
	CButton redo_c;
	void EnableForm(int id);
	afx_msg void OnBnClickedButton4();
	CButton draw_c;
	CStatic texta;
	CStatic textb;
	
	afx_msg void OnBnClickedButton8();

	CButton add_s;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CButton clear_c;
	afx_msg void OnBnClickedButton9();
	CButton save_c;
	afx_msg void OnBnClickedButton10();
	CStatic text3;
	CStatic text4;
	CListBox list_c;
	CStatic history_c;
	afx_msg void OnBnClickedButton11();
};
