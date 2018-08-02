// 3.2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "3.2.h"
#include "3.2Dlg.h"
#include "afxdialogex.h"
#include <ctime>
#include <list>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CRITICAL_SECTION cs;
int num = 0;
int j;


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()

public:
	
};
	


CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy32Dlg �Ի���



CMy32Dlg::CMy32Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy32Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	DWORD dwExStyle = ListView_GetExtendedListViewStyle(m_showlistctrl); 
	dwExStyle |= LVS_EX_HIDELABELS; 
	ListView_SetExtendedListViewStyle(m_showlistctrl, dwExStyle);
}

void CMy32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_LIST2,m_showlistctrl);
}

BEGIN_MESSAGE_MAP(CMy32Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CMy32Dlg::OnBnClickedButton4)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CMy32Dlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy32Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy32Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy32Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()

typedef struct thread_parameter
{
	CShowListCtrl *p_show;
	//CString lPath[50];
	TCHAR       szbuf[260];
	
}TP;
TP *tp_all[50];

// CMy32Dlg ��Ϣ�������

BOOL CMy32Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	m_showlistctrl.InsertColumn( 0, _T(""), LVCFMT_LEFT, 650);

	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy32Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy32Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy32Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//m_showlistctrl.ShowScrollBar(SB_HORZ, FALSE);
	*pResult = 0;
}



void CMy32Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	//���ϵͳʱ��
	CString str;   //��ȡϵͳʱ��
	CTime tm;
	tm=CTime::GetCurrentTime();
	str=tm.Format("%Y��%m��%d�� %X");
	//MessageBox(str,NULL,MB_OK);
	CString str1 = L"================= �����ֹͣ "+ str + L"=================";
	m_showlistctrl.InsertItem(m_showlistctrl.GetItemCount(),str1);
	//::WaitForSingleObject(hThread, INFINITE);
	//PostNcDestroy();
	::DestroyThreadpoolEnvironment((PTP_CALLBACK_ENVIRON)ThreadProc);
	for(int i =1;i<num;i++){
	TerminateThread(hThread[i],-1);
	::CloseHandle(hThread[i]);
	delete(tp_all[i]);
	}
	
    //DeleteCriticalSection(&cs);
}


void CMy32Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

		CStdioFile sf;

	if(sf.Open(_T("Log.txt"),CFile::modeCreate | CFile::modeWrite|CFile::typeBinary))
	{
		for(int i=0;i<m_showlistctrl.GetItemCount();i++)
		{
			CString strShowNum;
			strShowNum.Format(_T("��%d����¼��"),i);
			CString strOut=m_showlistctrl.GetItemText(i,0)+L"\r\n";
			sf.WriteString(strOut);
		}
		
		sf.Close();
	
		MessageBox(_T("����ɹ�!"),_T("��ʾ"),MB_ICONINFORMATION);
	}
		
	else
		MessageBox(_T("����ʧ��!"),_T("��ʾ"),MB_ICONINFORMATION);

}

void CMy32Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_setmenu.DoModal();

	//�� m_dlgShow ��������� ��ǩ �����ƶ�30
	
	
}

void CMy32Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);

 DWORD ThreadID;
	int i =0;

	//���ϵͳʱ��
	CString str;   //��ȡϵͳʱ��
	CTime tm;
	tm=CTime::GetCurrentTime();
	str=tm.Format("%Y��%m��%d�� %X");
	//MessageBox(str,NULL,MB_OK);
	CString str1 = L"================= ����ѿ��� "+ str + L"=================";
	//  m_showlistctrl.SetImageList(&m_showlistctrl,LVSIL_SMALL);//����ImageList
	//	m_showlistctrl.InsertColumn(0,"Col 1",LVCFMT_LEFT,300,0);//������
		 
	m_showlistctrl.InsertItem(m_showlistctrl.GetItemCount(),str1);

	CStdioFile sf;
			int line = 0;
			int line1 = 0;
		CString content;
			//CString str1 = L"���ڼ�ص�Ŀ¼Ϊ";
	m_showlistctrl.InsertItem(m_showlistctrl.GetItemCount(),L"���ڼ�ص�Ŀ¼Ϊ");
	if(sf.Open(_T("AppName.txt"),CFile::modeRead|CFile::typeBinary))
	{
		

			while(sf.ReadString(content))
			{
				line1++;
				if(content == L"\r")
					continue;
				m_showlistctrl.InsertItem(m_showlistctrl.GetItemCount(),content);
				//TRACE(content);
				
			}
			//TRACE("%d\n",line1);		
		sf.Close();
	}	

	//��·����ӵ�������
	CString cPath[50];
	if(sf.Open(_T("AppName.txt"),CFile::modeRead|CFile::typeBinary))
	{

			while(sf.ReadString(content))
			{
				line1++;
				cPath[i] = content;
				i++;
				//TRACE(content);
				
			}
			//TRACE("%d\n",line1);		
		sf.Close();
		num = i;
		i = 0;
	}	

	for(i = 1;i<num;i++)
	{
		TP* tp = new TP;
		tp_all[i] = tp;
     	tp->p_show = &m_showlistctrl;
		cPath[i].Replace('\r','\0'); 
		if(cPath[i]== L"")
			continue;

		wcscpy_s(tp->szbuf,sizeof(tp->szbuf)/sizeof(TCHAR),cPath[i]);
		//tp->lPath = (LPCWSTR)L"C:\\Users\\fa1lr4in\\Desktop";
		hThread[i] = ::CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadProc,(LPVOID)tp,0,&ThreadID);
		TRACE("%d\n",ThreadID);
		//delete(tp);
	}
	
	//hThread[0] = ::CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)ThreadProc,(LPVOID)tp,0,NULL);
	return ;

}

DWORD WINAPI CMy32Dlg::ThreadProc(LPVOID lParam)
{
	TP* tp1 = (TP*) lParam;
	CShowListCtrl *p_showlistctrl = tp1->p_show; 
	
	BOOL bRet = FALSE;
	BYTE Buffer[1024] = {0};
	int line = 0;
	CStdioFile sf;
	CString content;

	FILE_NOTIFY_INFORMATION *pBuffer = (FILE_NOTIFY_INFORMATION *)Buffer;
	DWORD dwByteReturn = 0;

	CString Add_Time;
	CString Modefi_Time;
	
	

	//EnterCriticalSection(&cs);


	//if(sf.Open(_T("AppName.txt"),CFile::modeRead|CFile::typeBinary))
	//{

	//		while(sf.ReadString(content))
	//		{
	//			line++;
	//			//m_showlistctrl.InsertItem(m_showlistctrl.GetItemCount(),content);
	//			//TRACE(content);

	//			
	//		}
	//		//TRACE("%d\n",line1);		
	//	sf.Close();
	//}	

	
	HANDLE hFile = ::CreateFile(/*L"E:\\"*/
		tp1->szbuf, FILE_LIST_DIRECTORY, 
		FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, 
		NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	if(INVALID_HANDLE_VALUE == hFile)
	{
		int n = GetLastError();
		TRACE("CreateFile Error!\n");
		return 1;
	}
	
	TRACE("monitoring...\r\n");
	p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),L"monitoring...\r\n");
	while(TRUE)
	{
		::ZeroMemory(Buffer, sizeof(Buffer));
		bRet = ::ReadDirectoryChangesW(hFile, 
			&Buffer,
			sizeof(Buffer),
			TRUE,
			FILE_NOTIFY_CHANGE_FILE_NAME |			// �޸��ļ���
			FILE_NOTIFY_CHANGE_ATTRIBUTES |			// �޸��ļ�����
			FILE_NOTIFY_CHANGE_LAST_WRITE,			// ���һ��д��
			&dwByteReturn, NULL, NULL);				
		if(TRUE == bRet)
		{
				//���ϵͳʱ��
				CString str;   //��ȡϵͳʱ��
				CTime tm;
				tm=CTime::GetCurrentTime();
				str=tm.Format("%Y��%m��%d�� %X");
			char szFileName[MAX_PATH] = {0};

			// ���ַ�ת��Ϊ���ֽ�
			::WideCharToMultiByte(CP_ACP,
				0,
				pBuffer->FileName,
				(pBuffer->FileNameLength / 2),
				szFileName,
				MAX_PATH,
				NULL,
				NULL);
			
			switch(pBuffer->Action)
			{
			case FILE_ACTION_ADDED:
				{
					//TRACE("���: %s\r\n", szFileName);
					Add_Time = str;
					p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),str + tp1->szbuf + L"���:"+(CString)szFileName);
					break;
				}
			case FILE_ACTION_REMOVED:
				{
					//TRACE("ɾ��:%s\r\n", szFileName);
					p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),str + tp1->szbuf + L"ɾ��:"+(CString)szFileName);
					break;
				}
			case FILE_ACTION_MODIFIED:
				{
					//TRACE("�޸�:%s\r\n", szFileName);
					if(Modefi_Time == str)
						break;
					Modefi_Time = str;
					if(Add_Time == Modefi_Time)
						break;
					p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),str + tp1->szbuf + L"�޸�:"+(CString)szFileName);
					break;
				}
			case FILE_ACTION_RENAMED_OLD_NAME:
				{
					//TRACE("������:%s", szFileName);
					CString old_name = (CString)szFileName;
					if(0 != pBuffer->NextEntryOffset)
					{
						FILE_NOTIFY_INFORMATION *tmpBuffer = (FILE_NOTIFY_INFORMATION *)
							((DWORD)pBuffer + pBuffer->NextEntryOffset);
						switch(tmpBuffer->Action)
						{
						case FILE_ACTION_RENAMED_NEW_NAME:
							{
								::ZeroMemory(szFileName, MAX_PATH);
								::WideCharToMultiByte(CP_ACP,
									0,
									tmpBuffer->FileName,
									(tmpBuffer->FileNameLength / 2),
									szFileName,
									MAX_PATH,
									NULL,
									NULL);
								//TRACE(" -> %s\r\n", szFileName);
								p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),str + tp1->szbuf + L"������:"+old_name+ L"->"+(CString)szFileName);
								break;
							}
						}
					}
					break;
				}
			case FILE_ACTION_RENAMED_NEW_NAME:
				{
					//TRACE("������(new):%s\r\n", szFileName);
					p_showlistctrl->InsertItem(p_showlistctrl->GetItemCount(),str + tp1->szbuf + L"������(new):"+(CString)szFileName);
					break;
				}
			}         
		}
	}
	
	::CloseHandle(hFile);
	//LeaveCriticalSection(&cs);
	return 0;
}
