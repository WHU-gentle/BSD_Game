// welcome.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "welcome.h"
#include "afxdialogex.h"
#include "MFCApplication4Dlg.h"


// welcome 对话框

IMPLEMENT_DYNAMIC(welcome, CDialogEx)

welcome::welcome(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Welcome, pParent)
{

}

welcome::~welcome()
{
}

void welcome::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(welcome, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &welcome::OnBnClickedButton1)
END_MESSAGE_MAP()


// welcome 消息处理程序


void welcome::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CMFCApplication4Dlg dlg;
	HIDE_WINDOW(this);
	dlg.DoModal();
}
