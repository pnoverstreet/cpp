// EvalUnionSizeOf.cpp : Defines the entry point for the console application.
// Developer: Paul Overstreet
// Purpose	: This evaluation was written to test the behavior of a union with the sizeof() method.  A union
//			  assumes only one of the structures it contains.  Therefore, to be safe, Sizeof(myunion) should
//			  return the length of the largest struct the union contains (the variables, not the methods).
//			  For example:
//				- Structure stOne has a single char variable with a size of 8 bytes.
//				- Structure stTwo has two char variables each with a size of 10 bytes.
//				- Structure stThree also has two char variables but each has a size of 2 bytes.
//				- stTwo occupies more bytes in memory than either of the other structures.
//				- Therefore, when all three structures are included in unAll, sizeof(unAll) should return the
//				  same as sizeof(stTwo).

#include "stdafx.h"
#include "EvalUnionSizeOf.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		CString szMsg;
		szMsg.Format("Sizeof(stOne) = %d", sizeof(stOne));		// Should be 8
		cout << (LPCTSTR)szMsg << endl;
		szMsg.Format("Sizeof(stTwo) = %d", sizeof(stTwo));		// Should be 20
		cout << (LPCTSTR)szMsg << endl;
		szMsg.Format("Sizeof(stThree) = %d", sizeof(stThree));	// Should be 4
		cout << (LPCTSTR)szMsg << endl;
		szMsg.Format("Sizeof(unAll) = %d", sizeof(unAll));		// Should be 20
		cout << (LPCTSTR)szMsg << endl;
	}

	return nRetCode;
}


