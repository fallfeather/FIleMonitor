// SetMenu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "3.2.h"
#include "SetMenu.h"
#include "afxdialogex.h"


// CSetMenu �Ի���

IMPLEMENT_DYNAMIC(CSetMenu, CDialogEx)

CSetMenu::CSetMenu(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetMenu::IDD, pParent)
{

}

CSetMenu::~CSetMenu()
{
}

void CSetMenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST1,m_listctrlShowPath);
}


BEGIN_MESSAGE_MAP(CSetMenu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CSetMenu::OnBnClickedButton3)

	ON_BN_CLICKED(IDC_BUTTON5, &CSetMenu::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSetMenu::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CSetMenu::OnBnClickedButton7)
END_MESSAGE_MAP()


// CSetMenu ��Ϣ�������


void CSetMenu::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strPath = CMy32App::GetBrowseFolderSelectPath(this);
	if(strPath != L"")
	{
	//���б��ϲ���
		m_listctrlShowPath.InsertItem(m_listctrlShowPath.GetItemCount(),strPath);
	}
}


BOOL CSetMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_listctrlShowPath.SetExtendedStyle(LVS_EX_CHECKBOXES); //��Ӹ�ѡ��ť


	return TRUE; // return TRUE unless you set the focus to a control

}


void CSetMenu::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i = 0; i<m_listctrlShowPath.GetItemCount();i++)
	{
		//�ж�i ��һ���Ƿ�ѡ��
		if(m_listctrlShowPath.GetCheck(i) == TRUE)
		//ɾ����һ��
		m_listctrlShowPath.DeleteItem(i);
	}

}


void CSetMenu::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nHeadNum = m_listctrlShowPath.GetItemCount();
	TRACE("%d\n",nHeadNum);

	////�����Ϊ�Ի��� ����Ҫ����#include<Afxdlgs.h>
	//wchar_t szFilters[] = L"txt�ļ�(*.txt)";
	//CFileDialog dlg(FALSE,L"txt",L"PowerModel_Detail",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilters,this);

	//if(dlg.DoModal() != IDOK)
	//	return ;
	//CString strFilePath;
	////����ļ�·����
	//strFilePath = dlg.GetPathName();
	////�ж��ļ��Ƿ��Ѿ����ڣ�����ɾ���ؽ�
	//DWORD dwRe  = GetFileAttributes(strFilePath);
	//if(dwRe !=(DWORD)-1)
	//{
	//	DeleteFile(strFilePath);
	//}

	////�����ļ�����
	//FILE *fp;
	//fopen(strFilePath,"w");
	//char str[1024];
	//	if(fp == NULL)
	//	{
	//		printf("�洢ʧ��\n");
	//		return ;
	//	}

//		CFile  file;  
//	if(!file.Open(L"�ı�.txt",CFile::modeWrite))  
//			file.Open(L"�ı�.txt",CFile::Create));   
//for(int   i   =   0;i   <   row;i++)  
//	{  
//		CString   str;  
//		for(int   j   =   0;j   <col;j   ++   )  
//		{  
//			str   =   GetItemText(i,j);  
//			file.Write(str.GetBuffer(0),srt.GetLength());  
//			str   =   ",";  
//			file.Write(str.GetBuffer(0),srt.GetLength());  
//		}  
//		str   =   "\r\n";  
//		file.Write(str.GetBuffer(0),srt.GetLength());  
//	}   
//file.Close();

	
	CStdioFile sf;
	if(sf.Open(_T("AppName.txt"),CFile::modeCreate | CFile::modeWrite|CFile::typeBinary))
	{
		sf.WriteString(L"\r\n");
		for(int i=0;i<m_listctrlShowPath.GetItemCount();i++)
		{
			CString strShowNum;
			strShowNum.Format(_T("��%d����¼��"),i);
			//CString strOut=strShowNum+_T("\t\t")+m_listctrlShowPath.GetItemText(i,0) + _T("      \t\t")+m_listctrlShowPath.GetItemText(i,1)+_T("\r\n");
			CString strOut=m_listctrlShowPath.GetItemText(i,0)+L"\r\n";
			sf.WriteString(strOut);
		}
		sf.Close();
		MessageBox(_T("����ɹ�!"),_T("��ʾ"),MB_ICONINFORMATION);
	}

	else
		MessageBox(_T("����ʧ��!"),_T("��ʾ"),MB_ICONINFORMATION);	


}


void CSetMenu::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	EndDialog(0);
}
