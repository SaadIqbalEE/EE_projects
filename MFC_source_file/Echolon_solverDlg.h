
// Echolon_solverDlg.h : header file
//

#pragma once


// CEcholon_solverDlg dialog
class CEcholon_solverDlg : public CDialogEx
{
// Construction
public:
	CEcholon_solverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ECHOLON_SOLVER_DIALOG };

	protected:

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
	afx_msg void OnBnClickedButton();
};
