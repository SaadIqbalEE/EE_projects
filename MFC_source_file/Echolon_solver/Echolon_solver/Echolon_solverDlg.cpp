
// Echolon_solverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Echolon_solver.h"
#include "Echolon_solverDlg.h"
#include "afxdialogex.h"
#include<cctype>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

float a_value_out = 0, b_value_out = 0, c_value_out = 0;

void swap(float x, float y){
	float temporay;
	temporay = x;
	x = y;
	y = temporay;
}

bool solve(float M[3][4]){
	for (int t1 = 0; t1 < 2; t1++){
		for (int t2 = 0; t2 < 2 - t2 - 1; t2++){
			if (abs(M[t2][0]) < abs(M[t2 + 1][0])){
				for (int t3 = 0; t3 <= 3; t3++){
					swap(M[t2][t3], M[t2 - 1][t3]);
				}
			}
		}
	}

	if (!abs(M[0][0]) < 0.0001){
		float temp = M[0][0];
		for (int a = 0; a <= 3; a++){
			M[0][a] = M[0][a] / temp;
		}
		temp = M[1][0];
		for (int a = 0; a <= 3; a++){
			M[1][a] = M[1][a] - (M[0][a] * temp);
		}
		temp = M[2][0];
		for (int a = 0; a <= 3; a++){
			M[2][a] = M[2][a] - (M[0][a] * temp);
		}
		if (abs(M[1][1])<abs(M[2][1])){
			for (int a = 1; a <= 3; a++){
				swap(M[2][a], M[1][a]);
			}
		}
		if (!abs(M[1][1]) < 0.0001){
			temp = M[1][1];
			for (int a = 1; a <= 3; a++){
				M[1][a] = M[1][a] / temp;
			}
			temp = M[0][1];
			for (int a = 1; a <= 3; a++){
				M[0][a] = M[0][a] - (M[1][a] * temp);
			}
			temp = M[2][1];
			for (int a = 0; a <= 3; a++){
				M[2][a] = M[2][a] - (M[1][a] * temp);
			}

			if (!abs(M[2][2]) < 0.0001){
				temp = M[2][2];
				for (int a = 2; a <= 3; a++){
					M[2][a] = M[2][a] / temp;
				}
				temp = M[0][2];
				for (int a = 2; a <= 3; a++){
					M[0][a] = M[0][a] - (M[2][a] * temp);
				}
				temp = M[1][2];
				for (int a = 0; a <= 3; a++){
					M[1][a] = M[1][a] - (M[2][a] * temp);
				}
				a_value_out = M[0][3];
				b_value_out = M[1][3];
				c_value_out = M[2][3];
				return 1;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEcholon_solverDlg dialog

CEcholon_solverDlg::CEcholon_solverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEcholon_solverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


BEGIN_MESSAGE_MAP(CEcholon_solverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(BUTTON, &CEcholon_solverDlg::OnBnClickedButton)
END_MESSAGE_MAP()


// CEcholon_solverDlg message handlers

BOOL CEcholon_solverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

void CEcholon_solverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEcholon_solverDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEcholon_solverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool Validate(CString str)
{
	int j = 0;
	for (int i = 0; i < str.GetLength(); i++) {
		if (!std::isdigit(str[i])){
			if (str[i] == '.' && j == 0)
				j += 1;
			else
				return 0;
		}
	}
	return 1;
	}

void CEcholon_solverDlg::OnBnClickedButton()
{
	CString N1, N2, N3, N4, N5, N6, N7, N8, N9, N10, N11, N12;
	GetDlgItemText(A_1, N1);
	GetDlgItemText(B_1, N2);
	GetDlgItemText(C_1, N3);
	GetDlgItemText(D_1, N4);
	GetDlgItemText(A_2, N5);
	GetDlgItemText(B_2, N6);
	GetDlgItemText(C_2, N7);
	GetDlgItemText(D_2, N8);
	GetDlgItemText(A_3, N9);
	GetDlgItemText(B_3, N10);
	GetDlgItemText(C_3, N11);
	GetDlgItemText(D_3, N12);

	if (Validate(N1) && Validate(N2) && Validate(N3) &&
		Validate(N4) && Validate(N5) && Validate(N6) &&
		Validate(N7) && Validate(N8) && Validate(N9) &&
		Validate(N10) && Validate(N11) && Validate(N12)){

		float argument_xyz[3][4];
		argument_xyz[0][0] = _tstof((LPCTSTR)N1);
		argument_xyz[0][1] = _tstof((LPCTSTR)N2);
		argument_xyz[0][2] = _tstof((LPCTSTR)N3);
		argument_xyz[0][3] = _tstof((LPCTSTR)N4);
		argument_xyz[1][0] = _tstof((LPCTSTR)N5);
		argument_xyz[1][1] = _tstof((LPCTSTR)N6);
		argument_xyz[1][2] = _tstof((LPCTSTR)N7);
		argument_xyz[1][3] = _tstof((LPCTSTR)N8);
		argument_xyz[2][0] = _tstof((LPCTSTR)N9);
		argument_xyz[2][1] = _tstof((LPCTSTR)N10);
		argument_xyz[2][2] = _tstof((LPCTSTR)N11);
		argument_xyz[2][3] = _tstof((LPCTSTR)N12);
		
		CString xv1, yv1, zv1;
		CString message;
		if (solve(argument_xyz)){
			xv1.Format(_T("%f"), a_value_out);
			yv1.Format(_T("%f"), b_value_out);
			zv1.Format(_T("%f"), c_value_out);
			message = L"";
		}
		else{
			xv1 = L"";
			xv1 = L"";
			xv1 = L"";
			message = L"Unique solution does not exist or solution is empty";
		}
		SetDlgItemText(xvalue, xv1);
		SetDlgItemText(yvalue, yv1);
		SetDlgItemText(zvalue, zv1);
		SetDlgItemText(error, message);
	}
	else
	{
		SetDlgItemText(xvalue, L"");
		SetDlgItemText(yvalue, L"");
		SetDlgItemText(zvalue, L"");
		SetDlgItemText(error, L"Input is Invalid");
	}
	// TODO: Add your control notification handler code here
}

