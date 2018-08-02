// SetMenu.cpp : 实现文件
//

#include "stdafx.h"
#include "3.2.h"
#include "SetMenu.h"
#include "afxdialogex.h"


// CSetMenu 对话框

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


// CSetMenu 消息处理程序


void CSetMenu::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strPath = CMy32App::GetBrowseFolderSelectPath(this);
	if(strPath != L"")
	{
	//在列表上插入
		m_listctrlShowPath.InsertItem(m_listctrlShowPath.GetItemCount(),strPath);
	}
}


BOOL CSetMenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_listctrlShowPath.SetExtendedStyle(LVS_EX_CHECKBOXES); //添加复选按钮


	return TRUE; // return TRUE unless you set the focus to a control

}


void CSetMenu::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i = 0; i<m_listctrlShowPath.GetItemCount();i++)
	{
		//判断i 这一项是否选中
		if(m_listctrlShowPath.GetCheck(i) == TRUE)
		//删除这一项
		m_listctrlShowPath.DeleteItem(i);
	}

}


void CSetMenu::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int nHeadNum = m_listctrlShowPath.GetItemCount();
	TRACE("%d\n",nHeadNum);

	////打开另存为对话框 ，需要包含#include<Afxdlgs.h>
	//wchar_t szFilters[] = L"txt文件(*.txt)";
	//CFileDialog dlg(FALSE,L"txt",L"PowerModel_Detail",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilters,this);

	//if(dlg.DoModal() != IDOK)
	//	return ;
	//CString strFilePath;
	////获得文件路径名
	//strFilePath = dlg.GetPathName();
	////判断文件是否已经存在，存在删除重建
	//DWORD dwRe  = GetFileAttributes(strFilePath);
	//if(dwRe !=(DWORD)-1)
	//{
	//	DeleteFile(strFilePath);
	//}

	////保存文件数据
	//FILE *fp;
	//fopen(strFilePath,"w");
	//char str[1024];
	//	if(fp == NULL)
	//	{
	//		printf("存储失败\n");
	//		return ;
	//	}

//		CFile  file;  
//	if(!file.Open(L"文本.txt",CFile::modeWrite))  
//			file.Open(L"文本.txt",CFile::Create));   
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
			strShowNum.Format(_T("第%d条记录："),i);
			//CString strOut=strShowNum+_T("\t\t")+m_listctrlShowPath.GetItemText(i,0) + _T("      \t\t")+m_listctrlShowPath.GetItemText(i,1)+_T("\r\n");
			CString strOut=m_listctrlShowPath.GetItemText(i,0)+L"\r\n";
			sf.WriteString(strOut);
		}
		sf.Close();
		MessageBox(_T("保存成功!"),_T("提示"),MB_ICONINFORMATION);
	}

	else
		MessageBox(_T("保存失败!"),_T("提示"),MB_ICONINFORMATION);	


}


void CSetMenu::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
