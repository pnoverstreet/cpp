// LogFile.cpp: MFC implementation of the LogFile class.

#include "stdafx.h"
#include "LogFile.h"
#include <fstream.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LogFile::LogFile(BSTR pFilename)
{
	m_sName = pFilename;
}

LogFile::~LogFile()
{

}

void LogFile::Log()
{
	// Declare variables to hold the date and time
	char	szDate[32],
				szTime[32];

	// Initialize the variables
	memset(szDate, 0, sizeof(szDate));
	memset(szTime, 0, sizeof(szTime));
	
	// Retrieve the current date
	_strdate(szDate);
	// Retrieve the current time
	_strtime(szTime);

	// Instantiate the output file stream
	ofstream filOutput;
	
	// Open the file stream
	filOutput.open(m_sName, ios::app, filebuf::sh_none);
	
	// Output the date, time, message and line terminator on a single line in the file
	filOutput << szDate << " ";
	filOutput << szTime << " - ";
	filOutput << m_sMsg << endl;
	
	// Flush everything in the buffer to the file
	filOutput.flush();
	
	// Make sure you close the file stream before we exit
	filOutput.close();
}
