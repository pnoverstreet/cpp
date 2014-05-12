
#if !defined(AFX_EVALUNIONSIZEOF_H__2C39DD3E_F664_4B6E_AB36_24093200B6CF__INCLUDED_)
#define AFX_EVALUNIONSIZEOF_H__2C39DD3E_F664_4B6E_AB36_24093200B6CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

// sizeof(stOne) should return 8 [char(8)]
struct stOne 
{
	char szData01[8];
};

// sizeof(stTwo) should return 20 [int(4) + char(8) + char(8)]
struct stTwo
{
public:
	int		iValue02a;
	char	szData02a[8],
			szData02b[8];
	void SetData(CString pData)
	{
		pData.GetBuffer(sizeof(szData02a)-1);
	}
};

// sizeof(stThree) should return ?
struct stThree
{
	char	szData03b[2],
			szData03c[2];
};


// sizeof(unOne) will return the size of the largest structure it contains.
union unAll
{
	struct stOne	One;
	struct stTwo	Two;
	struct stThree	Three;
};


#endif // !defined(AFX_EVALUNIONSIZEOF_H__2C39DD3E_F664_4B6E_AB36_24093200B6CF__INCLUDED_)
