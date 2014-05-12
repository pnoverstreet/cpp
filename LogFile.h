// LogFile.h: MFC interface for the LogFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGFILE_H__9FE24F50_DDFD_48F3_A75F_9162116A369C__INCLUDED_)
#define AFX_LOGFILE_H__9FE24F50_DDFD_48F3_A75F_9162116A369C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class LogFile  
{
public:
	LogFile(BSTR pFile);
	virtual ~LogFile();
	void Log();	// Write the message to the log file

	CString	m_sName,
					m_sMsg;
};

#endif // !defined(AFX_FILE_H__9FE24F50_DDFD_48F3_A75F_9162116A369C__INCLUDED_)
