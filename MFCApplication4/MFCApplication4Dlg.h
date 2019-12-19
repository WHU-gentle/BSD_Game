
// MFCApplication4Dlg.h: 头文件
//
#include<fstream>
#include<vector>
#pragma once

typedef struct file_text {
	int count;
	CString character;
	CString position;
	CString text;
}FILE_TEXT;
typedef struct file_text1 {
	int count;
	char character[100];
	char position[100];
	char text[1000];
}FILE_TEXT1;
typedef struct header {
	//CString back_sound;
	char bg_graph[100];
	//CString character_graph;
	int count_character;
	int count_text;
}HEADER;


// CMFCApplication4Dlg 对话框
class CMFCApplication4Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication4Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnEnChangeEdit1();
	CEdit M_chapter_edit;
	CListCtrl m_list;
	afx_msg void OnBnClickedButton2();
	CComboBox m_character;
	CComboBox m_position;
	CEdit m_dialogue;
	CComboBox m_bg_graph;
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButton4();
//	afx_msg void OnEnSetfocusEdit1();
//	afx_msg void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
