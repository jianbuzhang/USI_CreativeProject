
// FastToolDlg.h: 头文件
//

#pragma once

class CFastToolDlgAutoProxy;


// CFastToolDlg 对话框
class CFastToolDlg : public CDialog
{
	DECLARE_DYNAMIC(CFastToolDlg);
	friend class CFastToolDlgAutoProxy;

// 构造
public:
	CFastToolDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual ~CFastToolDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FASTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	CFastToolDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonReaddut();
	afx_msg void OnBnClickedButtonNetchk();
	afx_msg void OnBnClickedButtonCatchlog();
	afx_msg void OnBnClickedFactoryreset();
};
