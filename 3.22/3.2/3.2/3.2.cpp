
// 3.2.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "3.2.h"
#include "3.2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy32App

BEGIN_MESSAGE_MAP(CMy32App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMy32App ����

CMy32App::CMy32App()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMy32App ����

CMy32App theApp;


// CMy32App ��ʼ��

BOOL CMy32App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMy32Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

CString CMy32App::GetBrowseFolderSelectPath(CWnd* pWnd)
{
	wchar_t szFolderName[MAX_PATH] = {0}; //�洢�ļ��е�����
	wchar_t szFolderPath[MAX_PATH] = {0}; //�洢�ļ��е�·��
	BROWSEINFO info;
	info.hwndOwner = pWnd->m_hWnd; //�ĸ�����ӵ������Ի���
	info.pidlRoot = NULL; //NULL�Ǵ������ļ��п�ʼ���
	info.pszDisplayName = szFolderName; //�����ļ��е�����
	info.lpszTitle = L"��ѡ��Ҫ��ص��ļ��У�"; //����
	info.ulFlags = NULL; //��Ӷ���Ŀؼ�
	info.lpfn = NULL;
	info.lParam = NULL;
	info.iImage = NULL;

	PCIDLIST_ABSOLUTE pa = ::SHBrowseForFolder(&info); //��ʾһ������ļ��еĶԻ���

	if(::SHGetPathFromIDList(pa,(LPWSTR)szFolderPath) == TRUE)
	{
	int a = 100;
	if(wcscmp(szFolderPath,L"") != 0) //��ȡ�ɹ���
	{
	return szFolderPath;
	}
	}
	return L"";

}