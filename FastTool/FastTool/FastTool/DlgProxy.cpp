
// DlgProxy.cpp: 实现文件
//

#include "stdafx.h"
#include "FastTool.h"
#include "DlgProxy.h"
#include "FastToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFastToolDlgAutoProxy

IMPLEMENT_DYNCREATE(CFastToolDlgAutoProxy, CCmdTarget)

CFastToolDlgAutoProxy::CFastToolDlgAutoProxy()
{
	EnableAutomation();

	// 为使应用程序在自动化对象处于活动状态时一直保持
	//	运行，构造函数调用 AfxOleLockApp。
	AfxOleLockApp();

	// 通过应用程序的主窗口指针
	//  来访问对话框。  设置代理的内部指针
	//  指向对话框，并设置对话框的后向指针指向
	//  该代理。
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CFastToolDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CFastToolDlg)))
		{
			m_pDialog = reinterpret_cast<CFastToolDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CFastToolDlgAutoProxy::~CFastToolDlgAutoProxy()
{
	// 为了在用 OLE 自动化创建所有对象后终止应用程序，
	//	析构函数调用 AfxOleUnlockApp。
	//  除了做其他事情外，这还将销毁主对话框
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CFastToolDlgAutoProxy::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CFastToolDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CFastToolDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IFastTool 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {fbdd846e-f10e-4be0-ba72-2b6cef4f67a8}
static const IID IID_IFastTool =
{0xfbdd846e,0xf10e,0x4be0,{0xba,0x72,0x2b,0x6c,0xef,0x4f,0x67,0xa8}};

BEGIN_INTERFACE_MAP(CFastToolDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CFastToolDlgAutoProxy, IID_IFastTool, Dispatch)
END_INTERFACE_MAP()

// IMPLEMENT_OLECREATE2 宏在此项目的 StdAfx.h 中定义
// {4e828ecd-c582-4a7d-8cd0-258c2efa56bd}
IMPLEMENT_OLECREATE2(CFastToolDlgAutoProxy, "FastTool.Application", 0x4e828ecd,0xc582,0x4a7d,0x8c,0xd0,0x25,0x8c,0x2e,0xfa,0x56,0xbd)


// CFastToolDlgAutoProxy 消息处理程序
