
// MFCApplication4Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication4.h"
#include "MFCApplication4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

vector<FILE_TEXT> File_Text;
vector<CString> m_FileList;

using namespace std;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
bool flag;
bool keep=false;
int s_nItem;

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
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CMFCApplication4Dlg::OnCbnDropdownCombo1)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 对话框


CMFCApplication4Dlg::CMFCApplication4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION4_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, M_chapter_edit);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_COMBO2, m_character);
	DDX_Control(pDX, IDC_COMBO3, m_position);
	DDX_Control(pDX, IDC_EDIT2, m_dialogue);
	DDX_Control(pDX, IDC_COMBO1, m_bg_graph);
}

BEGIN_MESSAGE_MAP(CMFCApplication4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication4Dlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication4Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication4Dlg::OnBnClickedButton2)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CMFCApplication4Dlg::OnCbnDropdownCombo1)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication4Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication4Dlg::OnBnClickedButton7)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication4Dlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication4Dlg::OnBnClickedButton6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication4Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication4Dlg::OnBnClickedButton4)
//	ON_EN_SETFOCUS(IDC_EDIT1, &CMFCApplication4Dlg::OnEnSetfocusEdit1)
//ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFCApplication4Dlg::OnNMClickList1)
ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCApplication4Dlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CMFCApplication4Dlg 消息处理程序

BOOL CMFCApplication4Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	m_list.InsertColumn(0, _T("对话内容"), LVCFMT_LEFT, 750);
	m_list.InsertColumn(0, _T("位置"), LVCFMT_CENTER, 80);
	m_list.InsertColumn(0, _T("角色"), LVCFMT_CENTER, 130);
	m_list.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication4Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCApplication4Dlg::OnCbnSelchangeCombo1()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}


void CMFCApplication4Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	flag = false;
}


void CMFCApplication4Dlg::OnBnClickedButton2()
{
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	// TODO: 在此添加控件通知处理程序代码
	else {
		CEdit* pEditUser_chapter = NULL;
		pEditUser_chapter = (CEdit*)GetDlgItem(IDC_EDIT1);//获取文本框指针
		pEditUser_chapter->SetReadOnly(TRUE);   //设置为只读状态
		CString chapter, bg_graph, character, position, dialogue;
		M_chapter_edit.GetWindowText(chapter);
		if (chapter.IsEmpty()) {
			MessageBox(TEXT("章节不能为空！"));
		}
		else {
			m_character.GetWindowText(character);
			if (character.IsEmpty()) {
				MessageBox(TEXT("角色不能为空！"));
			}
			else {
				m_position.GetWindowText(position);
				if (position.IsEmpty()) {
					MessageBox(TEXT("位置不能为空！"));
				}
				else {
					m_dialogue.GetWindowText(dialogue);
					if (dialogue.IsEmpty()) {
						MessageBox(TEXT("对话不能为空！"));
					}
					else {
						int count = m_list.GetItemCount();
						CString c_count;
						FILE_TEXT file_temp;
						c_count.Format(_T("%d"), count + 1);
						file_temp.count = count;
						file_temp.character = character;
						file_temp.position = position;
						file_temp.text = dialogue;
						m_list.InsertItem(count, character);
						m_list.SetItemText(count, 0, c_count);
						m_list.SetItemText(count, 1, file_temp.character);
						m_list.SetItemText(count, 2, file_temp.position);
						m_list.SetItemText(count, 3, file_temp.text);
						File_Text.push_back(file_temp);
						UpdateData(TRUE);//将界面的数据更新到对应的变量中
					}
				}

			}


		}
	}
}

void GetFileFromDir(CString csDirPath,vector<CString>& m_FileList)
{
	csDirPath += "\\*.png";
	HANDLE file;
	WIN32_FIND_DATA fileData;
	char line[1024];
	char fn[1000];
	//mbstowcs(fn,csDirPath.GetBuffer(),999);  
	file = FindFirstFile(csDirPath.GetBuffer(), &fileData);
	m_FileList.push_back(fileData.cFileName);
	bool bState = false;
	bState = FindNextFile(file, &fileData);
	while (bState) {
		//wcstombs(line,(const char*)fileData.cFileName,259);  
		m_FileList.push_back(fileData.cFileName);
		bState = FindNextFile(file, &fileData);
	}
}

void CMFCApplication4Dlg::OnCbnDropdownCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
		// TODO: 在此添加控件通知处理程序代码
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	else {
		m_FileList.clear();
		CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框  
		CString csDirParth;
		CString m_csFileName;
		if (dlg.DoModal() == IDOK)
			m_csFileName = dlg.GetPathName();
		else
			m_csFileName.Empty();

		int iEndPos = 0;
		iEndPos = m_csFileName.ReverseFind('\\');
		csDirParth = m_csFileName.Left(iEndPos);

		m_FileList.clear();
		GetFileFromDir(csDirParth, m_FileList);
		vector<CString>::iterator it = m_FileList.begin();
		m_bg_graph.ResetContent();
		for (it; it < m_FileList.end(); it++) {
			m_bg_graph.AddString(*it);
		}
	}
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCApplication4Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	// TODO: 在此添加控件通知处理程序代码
	else {
		CEdit* pEditUser_chapter = NULL;
		pEditUser_chapter = (CEdit*)GetDlgItem(IDC_EDIT1);//获取文本框指针
		pEditUser_chapter->SetReadOnly(TRUE);   //设置为只读状态
		CString chapter, bg_graph, character, position, dialogue;
		M_chapter_edit.GetWindowText(chapter);
		if (chapter.IsEmpty()) {
			MessageBox(TEXT("章节不能为空！"));
		}
		else {
			m_character.GetWindowText(character);
			if (character.IsEmpty()) {
				MessageBox(TEXT("角色不能为空！"));
			}
			else {
				m_position.GetWindowText(position);
				if (position.IsEmpty()) {
					MessageBox(TEXT("位置不能为空！"));
				}
				else {
					m_dialogue.GetWindowText(dialogue);
					if (dialogue.IsEmpty()) {
						MessageBox(TEXT("对话不能为空！"));
					}
					else {
						CString c_count;
						FILE_TEXT file_temp;
						c_count.Format(_T("%d"), s_nItem + 1);
						file_temp.count = s_nItem;
						file_temp.character = character;
						file_temp.position = position;
						file_temp.text = dialogue;
						m_list.InsertItem(s_nItem, c_count);
						m_list.SetItemText(s_nItem, 1, file_temp.character);
    					m_list.SetItemText(s_nItem, 2, file_temp.position);
						m_list.SetItemText(s_nItem, 3, file_temp.text);
						int coun = m_list.GetItemCount();
						for (int i = s_nItem+1; i <= coun+1; i++) {
							m_list.DeleteItem(s_nItem+1);
						}
						UpdateData(TRUE);
						vector<FILE_TEXT>::iterator it;
						for (it = File_Text.begin(); it < File_Text.end(); it++) {
							if ((*it).count == s_nItem) {
								break;
							}
						}
						File_Text.insert(it, file_temp);
						for (it = File_Text.begin(); it < File_Text.end(); it++) {
							if ((*it).count == file_temp.count) {
								it++;
								break;
							}
						}
						for (it; it < File_Text.end(); it++) {
							(*it).count++;
							CString c_count1;
							c_count1.Format(_T("%d"), (*it).count + 1);
							m_list.InsertItem((*it).count, c_count1);
							m_list.SetItemText((*it).count, 1, (*it).character);
							m_list.SetItemText((*it).count, 2, (*it).position);
							m_list.SetItemText((*it).count, 3, (*it).text);
						}
						UpdateData(TRUE);//将界面的数据更新到对应的变量中
					}
				}

			}

		}
	}
}


void CMFCApplication4Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	// TODO: 在此添加控件通知处理程序代码
	else {
		CEdit* pEditUser_chapter = NULL;
		pEditUser_chapter = (CEdit*)GetDlgItem(IDC_EDIT1);//获取文本框指针
		pEditUser_chapter->SetReadOnly(TRUE);   //设置为只读状态
		CString chapter, bg_graph, character, position, dialogue;
		M_chapter_edit.GetWindowText(chapter);
		if (chapter.IsEmpty()) {
			MessageBox(TEXT("章节不能为空！"));
		}
		else {
			m_character.GetWindowText(character);
			if (character.IsEmpty()) {
				MessageBox(TEXT("角色不能为空！"));
			}
			else {
				m_position.GetWindowText(position);
				if (position.IsEmpty()) {
					MessageBox(TEXT("位置不能为空！"));
				}
				else {
					m_dialogue.GetWindowText(dialogue);
					if (dialogue.IsEmpty()) {
						MessageBox(TEXT("对话不能为空！"));
					}
					else {
						CString c_count;
						FILE_TEXT file_temp;
						c_count.Format(_T("%d"), s_nItem + 1);
						file_temp.count = s_nItem;
						file_temp.character = character;
						file_temp.position = position;
						file_temp.text = dialogue;
						m_list.SetItemText(s_nItem, 1, file_temp.character);
						m_list.SetItemText(s_nItem, 2, file_temp.position);
						m_list.SetItemText(s_nItem, 3, file_temp.text);
						vector<FILE_TEXT>::iterator it;
						for (it = File_Text.begin(); it < File_Text.end(); it++) {
							if ((*it).count == s_nItem) {
								(*it).character = file_temp.character;
								(*it).position = file_temp.position;
								(*it).text = file_temp.text;
							}
						}
						UpdateData(TRUE);//将界面的数据更新到对应的变量中
					}
				}

			}

		}
	}
}


void CMFCApplication4Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	// TODO: 在此添加控件通知处理程序代码
	else {
		int coun = m_list.GetItemCount();
		for (int i = s_nItem ; i <coun; i++) {
			m_list.DeleteItem(s_nItem);
		}
		UpdateData(TRUE);
		vector<FILE_TEXT>::iterator it;
		for (it = File_Text.begin(); it < File_Text.end(); it++) {
			if ((*it).count == s_nItem) {
				break;
			}
		}
		if (it < File_Text.end()-1)
			for (it++; it < File_Text.end(); it++) {
				(*it).count--;
				CString c_count1;
				c_count1.Format(_T("%d"), (*it).count + 1);
				m_list.InsertItem((*it).count, c_count1);
				m_list.SetItemText((*it).count, 1, (*it).character);
				m_list.SetItemText((*it).count, 2, (*it).position);
				m_list.SetItemText((*it).count, 3, (*it).text);
			}
		for (it = File_Text.begin(); it < File_Text.end(); it++) {
			if ((*it).count == s_nItem) {
				break;
			}
		}
		File_Text.erase(it);
		UpdateData(TRUE);//将界面的数据更新到对应的变量中
	}
}

void text_keep() {

}

void CMFCApplication4Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
		CString str;
		CString chapter1("Chapter");
		CString chapter2(".txt");
		M_chapter_edit.GetWindowText(str);

		text_keep();
		if (str.IsEmpty()) {
			MessageBox(TEXT("章节不能为空！"));
		}
		else {
			chapter1.Append(str);
			chapter1.Append(chapter2);
			ifstream infile(chapter1);
			if (infile.good()) {
				flag = true;
				//添加文件打开后的数据！
				m_list.DeleteAllItems();	
				CString chapter1("Chapter");
				CString chapter2(".txt");
				CString chapter3;
				M_chapter_edit.GetWindowText(str);
				chapter1.Append(str);
				chapter3 = chapter1;
				chapter3.Append("_support");
				chapter3.Append(chapter2);
				chapter1.Append(chapter2);
				HEADER in_temp;
				ifstream infile(chapter3);
				infile.read((char*)&in_temp, sizeof(HEADER));
				m_FileList.clear();
				File_Text.clear();
//				for (int i = 0; i < in_temp.count_character; i++) {
//					CString temp;
//					infile.read((char*)& temp, sizeof(CString));
//					m_FileList.push_back(temp);
//				}
				for (int i = 0; i < in_temp.count_text; i++) {
					FILE_TEXT1 temp1;
					FILE_TEXT temp2;
					infile.read((char*)& temp1, sizeof(FILE_TEXT1));
					temp2.character.Format(temp1.character);
					temp2.position.Format(temp1.position);
					temp2.text.Format(temp1.text);
					temp2.count = temp1.count;
					File_Text.push_back(temp2);
				}
//				vector<CString>::iterator it;
//				for (it = m_FileList.begin(); it < m_FileList.end(); it++) {
//					m_character.AddString((*it));
//				}
				vector<FILE_TEXT>::iterator it1;
				m_list.DeleteAllItems();
				for (it1 = File_Text.begin(); it1 < File_Text.end(); it1++) {
					CString c_count;
					c_count.Format(_T("%d"), (*it1).count+1);
					m_list.InsertItem(((*it1).count),c_count);
					m_list.SetItemText(((*it1).count), 1, (*it1).character);
					m_list.SetItemText(((*it1).count), 2, (*it1).position);
					m_list.SetItemText(((*it1).count), 3, (*it1).text);
					UpdateData(TRUE);//将界面的数据更新到对应的变量中
				}
			}
			else {
				int result = MessageBox(TEXT("确定创建章节" + str + "?"), TEXT("新建章节"), MB_YESNO);
				switch (result)
				{
					case IDYES:
					{
						//点击YES按钮的具体实现功能
						ofstream outfile(chapter1);
						MessageBox(TEXT("创建完毕"));
						m_list.DeleteAllItems();
						File_Text.clear();
						flag = true;
						break;
					}
					case IDNO:
						break;
				}
			}
		}
}


void CMFCApplication4Dlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!flag) {
		MessageBox(TEXT("请先选择章节！"));
	}
	else {
		CFileDialog dlg(TRUE);///TRUE为OPEN对话框，FALSE为SAVE AS对话框  
		CString csDirParth;
		CString m_csFileName;
		if (dlg.DoModal() == IDOK)
			m_csFileName = dlg.GetPathName();
		else
			m_csFileName.Empty();

		int iEndPos = 0;
		iEndPos = m_csFileName.ReverseFind('\\');
		csDirParth = m_csFileName.Left(iEndPos);

		m_FileList.clear();
		GetFileFromDir(csDirParth, m_FileList);
		vector<CString>::iterator it = m_FileList.begin();
		m_character.ResetContent();
		CString c_sys("sys");
		m_character.AddString(c_sys);
		CString c_temp(".");
		for (it; it < m_FileList.end(); it++) {
			m_character.AddString((*it).Left((*it).Find(c_temp)));
		}
	}
}


void CMFCApplication4Dlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication4Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	CString chapter1("Chapter");
	CString chapter2(".txt");
	CString chapter3;
	M_chapter_edit.GetWindowText(str);
	chapter1.Append(str);
	chapter3=chapter1;
	chapter3.Append("_support");
	chapter3.Append(chapter2);
	chapter1.Append(chapter2);
	ofstream outFile(chapter1);

	CString temp;
	CString c_temp(".");
	CString chapter, bg_graph;

	m_character.GetWindowText(chapter);
	m_bg_graph.GetWindowText(bg_graph);

	HEADER file_temp;
	std::string a2 = bg_graph.GetBuffer(0);
	strcpy(file_temp.bg_graph, a2.data());
	file_temp.count_character = m_FileList.size();
	file_temp.count_text =File_Text.size();

	outFile << "Chapter" << " " << str << "\n";
	outFile << "background" << " " <<"="<< "\""<<bg_graph<<"\";"<< "\n";
	vector<CString>::iterator it;
	for (it = m_FileList.begin(); it < m_FileList.end(); it++) {
		outFile<<"character "<< (*it).Left((*it).Find(c_temp))<<"="<< "\"" << (*it)<< "\";" << "\n";
	}
	vector<FILE_TEXT>::iterator it1;
	for (it1 = File_Text.begin(); it1 < File_Text.end(); it1++) {
		outFile << (*it1).count+1<<" "<< (*it1).character <<" "<<(*it1).position << " " <<"\""<< (*it1).text << "\"" << ";" << "\n";
	}


	ofstream outfile1(chapter3);
	outfile1.write((char*)& (file_temp), sizeof(HEADER));
//	for (it = m_FileList.begin(); it < m_FileList.end(); it++) {
//		outfile1.write((char*) & (*it), sizeof(CString));
//	}
	for (it1 = File_Text.begin(); it1 < File_Text.end(); it1++) {	
		FILE_TEXT1 f_temp;
		f_temp.count = (*it1).count;
		std::string a3 = (*it1).character.GetBuffer(0);
		strcpy(f_temp.character, a3.data());
		a3 = (*it1).position.GetBuffer(0);
		strcpy(f_temp.position, a3.data());
		a3 = (*it1).text.GetBuffer(0);
		strcpy(f_temp.text, a3.data());
		outfile1.write((char*) & f_temp, sizeof(FILE_TEXT1));
	}
	outfile1.close();
	outFile << "end Chapter;";
	outFile.close();
	keep = true;
}


//void CMFCApplication4Dlg::OnEnSetfocusEdit1()
//{
//
//}

//void CMFCApplication4Dlg::OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//	POSITION pos = m_list.GetFirstSelectedItemPosition();
//	if (pos)  //如果鼠标点击了某行的
//	{
//		int nItem = m_list.GetNextSelectedItem(pos);   //获取该行行号 
//		MessageBox(TEXT("%d",nItem));
//	}
//}


void CMFCApplication4Dlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos)  //如果鼠标点击了某行的
	{
		int nItem = m_list.GetNextSelectedItem(pos);   //获取该行行号 
		s_nItem = nItem;
	}
}
