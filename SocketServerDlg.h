// SocketServerDlg.h : header file
//

#if !defined(AFX_SOCKETSERVERDLG_H__ACF9E692_C1DB_4F1A_9409_B3BCD09AB045__INCLUDED_)
#define AFX_SOCKETSERVERDLG_H__ACF9E692_C1DB_4F1A_9409_B3BCD09AB045__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ServerSocket.h"

/////////////////////////////////////////////////////////////////////////////
// CSocketServerDlg dialog

class CSocketServerDlg : public CDialog
{
// Construction
public:
	CSocketServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSocketServerDlg)
	enum { IDD = IDD_SOCKETSERVER_DIALOG };
	CListBox	m_cResults;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSocketServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	bool			m_iListening;
	CServerSocket	m_oServer;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSocketServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOCKETSERVERDLG_H__ACF9E692_C1DB_4F1A_9409_B3BCD09AB045__INCLUDED_)
