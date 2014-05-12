// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "SocketServer.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	 // Windows Socket Server Programming - client part sample code to receive data

	TCHAR buff[4096];
	CString m_strRecv;
	int nRead;
	nRead = Receive(buff, 4096);

	switch(nRead)
	{
		case 0:
			  Close();
			  break;
		case SOCKET_ERROR:
			if (GetLastError() != WSAEWOULDBLOCK)
			{
				  AfxMessageBox ("Error occurred");
				  Close();
			}
			break;
		default:
			buff[nRead] = 0; //terminate the string
	}
	CString szTemp(buff);
	m_strRecv += szTemp; // m_strRecv is a CString declared
	AfxMessageBox(m_strRecv);

	// in CMyAsyncSocket
	if (szTemp.CompareNoCase("bye") == 0 ) ShutDown();

	// Call base OnReceive method to complete processing.
	CAsyncSocket::OnReceive(nErrorCode);
}