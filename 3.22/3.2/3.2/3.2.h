
// 3.2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy32App:
// �йش����ʵ�֣������ 3.2.cpp
//

class CMy32App : public CWinApp
{
public:
	CMy32App();

// ��д
public:
	virtual BOOL InitInstance();
public:
	static CString GetBrowseFolderSelectPath(CWnd* pWnd); //��ȡ ����Ի����ѡ���·��

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy32App theApp;