
// 3.2Dlg.h : ͷ�ļ�
//

#pragma once
#include "SetMenu.h"
#include "ShowListCtrl.h"

// CMy32Dlg �Ի���
class CMy32Dlg : public CDialogEx
{
// ����
public:
	CMy32Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY32_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CSetMenu m_setmenu;
	CShowListCtrl m_showlistctrl;



// ʵ��
protected:
	HICON m_hIcon;
	HANDLE hThread[50];

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
public:

	afx_msg void OnBnClickedButton2();
	static DWORD WINAPI ThreadProc(LPVOID lParam);
	#define LVS_EX_HIDELABELS 0x00020000 
	
};
