
// CMyDlg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCMyDlgApp: 
// �йش����ʵ�֣������ CMyDlg.cpp
//

class CCMyDlgApp : public CWinApp
{
public:
	CCMyDlgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCMyDlgApp theApp;