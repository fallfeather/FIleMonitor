#pragma once
#include "ShowPathListCtrl.h"

// CSetMenu �Ի���

class CSetMenu : public CDialogEx
{
	DECLARE_DYNAMIC(CSetMenu)

public:
	CSetMenu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetMenu();

// �Ի�������
	enum { IDD = IDD_SETMENU };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();

public:
	CShowPathListCtrl m_listctrlShowPath;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();

	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
