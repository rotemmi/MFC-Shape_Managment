
// finalDlg.cpp : implementation file
//


#include "stdafx.h"
#include "final.h"
#include "finalDlg.h"
#include "MyEllipse.h"
#include "MyRectangle.h"
#include "MySquare.h"
#include "MyCircle.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CfinalDlg dialog


CfinalDlg::CfinalDlg(CWnd* pParent )
	: CDialogEx(IDD_FINAL_DIALOG, pParent)
	, a_value(0)
	, b_value(0)
	, perimeter_value(0)
	, area_value(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CfinalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Circle_c);
	DDX_Control(pDX, IDC_BUTTON3, Ellipse_c);
	DDX_Control(pDX, IDC_BUTTON4, Rectangle_c);
	DDX_Control(pDX, IDC_BUTTON2, Square_c);
	DDX_Text(pDX, IDC_EDIT4, a_value);
	DDX_Text(pDX, IDC_EDIT3, b_value);
	DDX_Text(pDX, IDC_EDIT1, perimeter_value);
	DDX_Text(pDX, IDC_EDIT2, area_value);
	DDX_Control(pDX, IDC_BUTTON5, undo_c);
	DDX_Control(pDX, IDC_BUTTON6, redo_c);
	DDX_Control(pDX, IDC_BUTTON8, draw_c);
	DDX_Control(pDX, IDC_TEXTA, texta);
	DDX_Control(pDX, IDC_TEXTB, textb);
	DDX_Control(pDX, IDC_BUTTON7, add_s);
	DDX_Control(pDX, IDC_BUTTON9, clear_c);
	DDX_Control(pDX, IDC_BUTTON10, save_c);
	DDX_Control(pDX, IDC_TEXTA2, text3);
	DDX_Control(pDX, IDC_TEXTB2, text4);
	DDX_Control(pDX, IDC_LIST1, list_c);
	DDX_Control(pDX, IDC_TEXTA3, history_c);
}

BEGIN_MESSAGE_MAP(CfinalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CfinalDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CfinalDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CfinalDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CfinalDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CfinalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CfinalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CfinalDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CfinalDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CfinalDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CfinalDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CfinalDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CfinalDlg message handlers

BOOL CfinalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	list_c.ShowWindow(SW_HIDE);
	history_c.ShowWindow(SW_HIDE);
	initialWindow();
	
	



	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CfinalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CfinalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);


		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);


	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CfinalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CfinalDlg::EnableForm(int id)
{
	CWnd* Button;
	int arr[4] = { 1000,1001,1002,1003};

	undo_c.EnableWindow(false);
	redo_c.EnableWindow(false); 
	list_c.ShowWindow(SW_SHOW);
	history_c.ShowWindow(SW_SHOW);
	draw_c.ShowWindow(SW_SHOW);
	texta.ShowWindow(SW_SHOW);
	textb.ShowWindow(SW_SHOW);
	Button = GetDlgItem(IDC_EDIT3);
	Button->ShowWindow(SW_SHOW);
	Button = GetDlgItem(IDC_EDIT4);
	Button->ShowWindow(SW_SHOW);
	for (int i = 0; i < 4; i++)
	{
			Button = GetDlgItem(arr[i]);
			Button->EnableWindow(false);
			switch (id)
			{
			case 1: 
				texta.SetWindowTextW(CString("Radius"));
				textb.ShowWindow(SW_HIDE);
				Button = GetDlgItem(IDC_EDIT4);
				Button->ShowWindow(SW_HIDE);
				break;
			case 2:
				texta.SetWindowTextW(CString("Edge x"));
				textb.ShowWindow(SW_HIDE);
				Button = GetDlgItem(IDC_EDIT4);
				Button->ShowWindow(SW_HIDE);
				break;
			case 3:
				texta.SetWindowTextW(CString("Radius A"));
				textb.SetWindowTextW(CString("Radius B"));
				textb.ShowWindow(SW_SHOW);
				Button = GetDlgItem(IDC_EDIT3);
				Button->ShowWindow(SW_SHOW);
				break;
			case 4: 
				texta.SetWindowTextW(CString("Edge x"));
				textb.SetWindowTextW(CString("Edge y"));
				textb.ShowWindow(SW_SHOW);
				Button = GetDlgItem(IDC_EDIT3);
				Button->ShowWindow(SW_SHOW);
				break;
			}
		}
	initTexts();
}

void CfinalDlg::OnBnClickedButton4() // rectangle
{

	shape = new MyRectangle;
	shapes.push_back(shape);
	done.push(shape);
	EnableForm(4);                          // we need in the headder to make a static *myshape and here to make is rectangle
}

void CfinalDlg::OnBnClickedButton2()
{
	shape = new MySquare;
	shapes.push_back(shape);
	done.push(shape);
	EnableForm(2);
}

void CfinalDlg::OnBnClickedButton3()
{
	shape = new MyEllipse;
	shapes.push_back(shape);
	done.push(shape);
	EnableForm(3);
}

void CfinalDlg::OnBnClickedButton1()
{
	shape = new MyCircle;
	shapes.push_back(shape);
	done.push(shape);
	EnableForm(1);
}

void CfinalDlg::OnBnClickedButton8() // Draw
{
	UpdateData(true);
	if ((typeid(*shape) == typeid(MyRectangle) || typeid(*shape) == typeid(MyEllipse))&&(!a_value || !b_value))
	{
		 add_s.ShowWindow(SW_HIDE);
		 MessageBox(_T("Invalid input - please correct"));
		 return;
		 	
	}
	else if (!b_value)
	{
		add_s.ShowWindow(SW_HIDE);
		MessageBox(_T("Invalid input - please correct"));
		return;
	}
	else
	{
		CClientDC dc(this);
		dc.SetROP2(R2_NOTXORPEN);
		shape->draw(dc);
		viewPermiterArea(shape);
		shape->setBegin(CPoint(x_cord, y_cord));
		shape->setEnd(CPoint(x_cord + (int(b_value) * 45), y_cord + (int(a_value) * 45)));       // b_value - x , a_value-y
		shape->draw(dc);
		add_s.ShowWindow(SW_SHOW);
		undo_c.EnableWindow(true);
		redo_c.EnableWindow(true);
	}
}

void CfinalDlg::viewPermiterArea(MyShape * s)
{
	UpdateData(true);
	s->setX(b_value);
	if (typeid(*s)==typeid(MySquare)|| typeid(*s) == typeid(MyCircle))
	{
		a_value = b_value;
	}
	else
	{
		s->setY(a_value);
	}
	s->area_calc();
	s->perimeter_calc();
	perimeter_value = s->getPerimeter();
	area_value = s->getArea();
	UpdateData(false);
	text3.ShowWindow(SW_SHOW);
	text4.ShowWindow(SW_SHOW);
	CWnd *edit = GetDlgItem(IDC_EDIT1);
	edit->ShowWindow(SW_SHOW);
	edit = GetDlgItem(IDC_EDIT2);
	edit->ShowWindow(SW_SHOW);
	UpdateListBox(list_c);
}

void CfinalDlg::OnBnClickedButton7() // add
{
	x_cord += (int(b_value) * 45) + 10;
	initialWindow();
	Rectangle_c.EnableWindow(true);
	Square_c.EnableWindow(true);
	Ellipse_c.EnableWindow(true);
	Circle_c.EnableWindow(true);
	undo_c.EnableWindow(false);
	redo_c.EnableWindow(false);
} 

 void CfinalDlg::initialWindow()
{
	draw_c.ShowWindow(SW_HIDE);
	add_s.ShowWindow(SW_HIDE);
	texta.ShowWindow(SW_HIDE);
	textb.ShowWindow(SW_HIDE);
	text3.ShowWindow(SW_HIDE);
	text4.ShowWindow(SW_HIDE);
	CWnd *edit = GetDlgItem(IDC_EDIT1);
	edit->ShowWindow(SW_HIDE);
	edit = GetDlgItem(IDC_EDIT2);
	edit->ShowWindow(SW_HIDE);
	edit = GetDlgItem(IDC_EDIT3);
	edit->ShowWindow(SW_HIDE);
	edit = GetDlgItem(IDC_EDIT4);
	edit->ShowWindow(SW_HIDE);
	Rectangle_c.EnableWindow(true);
	Square_c.EnableWindow(true);
	Ellipse_c.EnableWindow(true);
	Circle_c.EnableWindow(true);
}

 void CfinalDlg::drawVector()
 {
	 Invalidate();
	 CClientDC dc(this);
	 vector<MyShape*>::iterator i;
	 UpdateWindow();
	 for (i = shapes.begin(); i != shapes.end(); ++i)
	 {
		 (*i)->draw(dc);
	 }
 }


 void CfinalDlg::searchAndDelete(MyShape *shape)
 {
		 vector<MyShape*>::iterator it;
		 for (it = shapes.begin(); it != shapes.end(); ++it)
			 if (*it == shape)
				 break;
		 if (it != shapes.end())
			 shapes.erase(it);
	 
 }

 void CfinalDlg::OnBnClickedButton5() // UNDO
 {
	 initialWindow();
	 if (!done.empty() && shapes.size())
	 {
			 MyShape *top = done.top();
			 done.pop();
			 undone.push(top);
			 if (shapes.size() == 1)
			 {
				 shapes.pop_back();
				 x_cord = 30;
			 }
			 else
			 {
				 searchAndDelete(top);
				 double x;
				 MyShape *end = *(shapes.end() - 1);
				 end->getX(x);
				 CPoint p;
				 end->getBegin(p);
				 x_cord = p.x + ((int)x * 45) + 10;
			 }
			 drawVector();
			 redo_c.EnableWindow(true);
	 }

 }

 void CfinalDlg::initTexts()
 {
	 a_value =b_value=perimeter_value=area_value = 0;
	 UpdateData(false);
 }

 void CfinalDlg::OnBnClickedButton6()
 {
	 if (!undone.empty())
	 {
		 MyShape *top = undone.top();
		 undone.pop();
		 done.push(top);
		 shapes.push_back(top);
		 double x;
		 MyShape *end = *(shapes.end() - 1);
		 end->getX(x);
		 CPoint p;
		 end->getBegin(p);
		 x_cord = p.x + ((int)x * 45) + 10;
		 drawVector();
	 }	 
 }
	 
 void CfinalDlg::OnBnClickedButton9()
 {
	 initTexts();
	 Invalidate();
	 initialWindow();
	 while (!undone.empty())
	 {
		 undone.pop();
	 }
	 while (!done.empty())
	 {
		 done.pop();
	 }
	 shapes.clear();
	 UpdateWindow();
	 x_cord = 30;
	 list_c.ResetContent();
 }

 void CfinalDlg::OnBnClickedButton10()
 {
	 initialWindow();
	 CFile file(L"shapes.bin", CFile::modeCreate | CFile::modeWrite);
	 CArchive archive(&file, CArchive::store);
	 archive << shapes.size();
	 for(unsigned int i = 0; i < shapes.size(); ++i)
		 archive << shapes[i];
 }

 void CfinalDlg::Loading() // load
 {
	 vector<MyShape*>::iterator i;
	 if (shapes.size())
	 {
		 MyShape *top = *(shapes.end() - 1);
		 CPoint c;
		 top->getEnd(c);
		 x_cord = c.x + 10;
	 }
	 for (i = shapes.begin(); i != shapes.end(); ++i)
	 {
		 done.push(*i);
	 }
 }


 void CfinalDlg::UpdateListBox(CListBox& ListBox)
 {
	 if (shapes.size())
	 {
		 MyShape *top = *(shapes.end() - 1);

		 CString info = top->getDetails();
		 ListBox.AddString(info);
	 }
 }



 void CfinalDlg::OnBnClickedButton11()
 {
	 CFile file(L"shapes.bin", CFile::modeRead);
	 CArchive archive(&file, CArchive::load);
	 int count;
	 archive >> count;
	 for (int i = 0; i < count; ++i)
	 {
		 MyShape *s;
		 archive >> s;
		 shapes.push_back(s);
	 }
	 Loading();
	 drawVector();
 }
