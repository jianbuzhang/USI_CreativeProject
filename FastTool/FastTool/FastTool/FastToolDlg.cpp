
// FastToolDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "FastTool.h"
#include "FastToolDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFastToolDlg 对话框


IMPLEMENT_DYNAMIC(CFastToolDlg, CDialog);

CFastToolDlg::CFastToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FASTTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CFastToolDlg::~CFastToolDlg()
{
	// 如果该对话框有自动化代理，则
	//  将此代理指向该对话框的后向指针设置为 NULL，以便
	//  此代理知道该对话框已被删除。
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CFastToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFastToolDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CFastToolDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_READDUT, &CFastToolDlg::OnBnClickedButtonReaddut)
	ON_BN_CLICKED(IDC_BUTTON_NETCHK, &CFastToolDlg::OnBnClickedButtonNetchk)
	ON_BN_CLICKED(IDC_BUTTON_CATCHLOG, &CFastToolDlg::OnBnClickedButtonCatchlog)
	ON_BN_CLICKED(IDC_FACTORYRESET, &CFastToolDlg::OnBnClickedFactoryreset)
END_MESSAGE_MAP()


// CFastToolDlg 消息处理程序

BOOL CFastToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFastToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFastToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFastToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 当用户关闭 UI 时，如果控制器仍保持着它的某个
//  对象，则自动化服务器不应退出。  这些
//  消息处理程序确保如下情形: 如果代理仍在使用，
//  则将隐藏 UI；但是在关闭对话框时，
//  对话框仍然会保留在那里。

void CFastToolDlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void CFastToolDlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void CFastToolDlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL CFastToolDlg::CanExit()
{
	// 如果代理对象仍保留在那里，则自动化
	//  控制器仍会保持此应用程序。
	//  使对话框保留在那里，但将其 UI 隐藏起来。
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

//读取手机并设置手机重启
void CFastToolDlg::OnBnClickedButtonReaddut()
{
	// TODO: 在此添加控件通知处理程序代码
	//ShellExecuteW(NULL, _T("open"), _T("C:\ADB\cmd.exe"), _T("reboot.bat"), NULL, SW_SHOW);
	system("E:\\7_CreativeProject\\USI_CreativeProject\\FastTool\\FastTool\\reboot.bat");
	//system("reboot.bat");
	Sleep(3000);
}

//网络检查
void CFastToolDlg::OnBnClickedButtonNetchk()
{
	// TODO: 在此添加控件通知处理程序代码
	system("E:\\7_CreativeProject\\USI_CreativeProject\\FastTool\\FastTool\\Route_set.bat");
}

//抓取手机log
void CFastToolDlg::OnBnClickedButtonCatchlog()
{
	// TODO: 在此添加控件通知处理程序代码
	system("E:\\7_CreativeProject\\USI_CreativeProject\\FastTool\\FastTool\\LogCat.bat");
}

//恢复出厂设定
void CFastToolDlg::OnBnClickedFactoryreset()
{
	// TODO: 在此添加控件通知处理程序代码
	system("E:\\7_CreativeProject\\USI_CreativeProject\\FastTool\\FastTool\\Need_factoryReset.bat");
}
