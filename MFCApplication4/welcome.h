#pragma once


// welcome 对话框

class welcome : public CDialogEx
{
	DECLARE_DYNAMIC(welcome)

public:
	welcome(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~welcome();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Welcome };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
