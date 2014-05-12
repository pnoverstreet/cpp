// MemoryPool.cpp : Example of implementing a shared memory pool on Windows CE 5.0
// Developer: Paul Overstreet
//

#include "stdafx.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PNO: Shared memory pool
int		g_iMemPoolSize = 1024;
char	*g_szMemPool;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// PNO: Function Prototypes
bool MemoryPoolReserve();
bool MemoryPoolRelease();
int MemoryPoolPush(char *pData);
void MemoryPoolRead();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int _tmain(int argc, _TCHAR* argv[])
{
	MemoryPoolReserve();
	MemoryPoolPush("key1=value1\r\nkey2=value2\r\nkey3=value3");
	MemoryPoolRead();
	MemoryPoolRelease();
	return 0;
}

// PNO: Reserve the memory for the shared memory pool.
// PNO: Since this app is running on Windows CE and an embedded device, C-style memory management is being used to conserve memory on both the stack and the heap.
bool MemoryPoolReserve()
{
	bool bResult = false;

	g_szMemPool = (char *)malloc(g_iMemPoolSize);
	memset(g_szMemPool, 0, g_iMemPoolSize);
	bResult = true;

	return bResult;
}

// PNO: Free the memory in the shared memory pool.
bool MemoryPoolRelease()
{
	bool bResult = false;

	free(g_szMemPool);
	g_szMemPool = NULL;
	bResult = true;

	return bResult;
}

// PNO: Push some data onto the MemoryPool (optionally replace what may already be in it).
int MemoryPoolPush(char *pData)
{
	int iIndex,
		iByteCount;

	iIndex = iByteCount = 0;
	
	// Reinitialize the memory pool to all zeros before copying any new data to it.
	memset(g_szMemPool, 0, g_iMemPoolSize);
	
	// PNO: If we're not replacing what's in the pool, just append the new data to the end.
	_memccpy(g_szMemPool, pData, 0, g_iMemPoolSize); 
	iByteCount = (int)strlen(g_szMemPool);

	return iByteCount;
}

// PNO: Return the length of the string contained by the memory pool.
int MemoryPoolGetLength()
{
	int	iEndOfPool;

	iEndOfPool = 0;

	while((g_szMemPool[iEndOfPool] != 0) && (iEndOfPool < g_iMemPoolSize))
		iEndOfPool++;
}

// PNO: Main method for parsing out the data we pushed onto the memory pool for identifying the patterns we're interested in.
// PNO: Parsing out the data in the memory pool in INI-style format (Key=Value\r\n).
void MemoryPoolReadAsINI()
{
	char	*pEqualsSignPtr,
			*pStartOfKeyPtr,
			*pEndOfValuePtr;

	int	iIndex,
			iKeyIndex,
			iValueIndex;

	char	szKey[32],
				szValue[32];

	pEqualsSignPtr = pStartOfKeyPtr = pEndOfValuePtr = NULL;

	iIndex = iKeyIndex = iValueIndex = 0;

	memset(szKey,	0, sizeof(szKey));
	memset(szValue, 0, sizeof(szValue));

	pStartOfKeyPtr = g_szMemPool;

	for(iIndex = 0; iIndex < MemoryPoolGetLength(); iIndex++)
	{
		switch(g_szMemPool[iIndex])
		{
			case '=':	// Process
				// Increment indexer beyond '='
				// Accumulate characters forward until you hit CRLF for the Value.
				szKey[iKeyIndex] = 0;
				while(iIndex++ < MemoryPoolGetLength())
				{
					// If the next position is a CR or LF, exit the loop.
					if((g_szMemPool[iIndex] == '\r') || (g_szMemPool[iIndex] == '\n'))
						break;

					// Current index position is not a CRLF
					if(iValueIndex < sizeof(szValue)-1)
						szValue[iValueIndex++] = g_szMemPool[iIndex];
					else
						break;
				}

				// Should have Key name and Value defined, do something with them.

				memset(szKey,		0, sizeof(szKey));
				memset(szValue, 0, sizeof(szValue));
				iKeyIndex = iValueIndex = 0;
				break;
			case '\r':	// Ignore Carriage Return/LineFeed chars.
			case '\n':
				break;
			default:
			{
				if(iKeyIndex < sizeof(szKey)-1)
					szKey[iKeyIndex++] = g_szMemPool[iIndex];
			}
		}
	}
}