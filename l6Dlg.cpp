
// l6Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "l6.h"
#include "l6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// Cl6Dlg dialog



Cl6Dlg::Cl6Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_L6_DIALOG, pParent)
	, var_text_name(_T(""))
	, var_text_mass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cl6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, var_text_name);
	DDX_Text(pDX, IDC_EDIT_MASS, var_text_mass);
	DDX_Control(pDX, IDC_LIST_ALL_ITEMS, list_all_control);
	DDX_Control(pDX, IDC_RADIO_NAME, var_radio_name);
	DDX_Control(pDX, IDC_LIST_FINDED, list_finded);
	DDX_Text(pDX, IDC_EDIT_WHAT_TO_FIND, text_what_to_find);
	DDX_Control(pDX, IDC_EDIT_WHAT_TO_FIND, var_what_to_find_control);
	DDX_Control(pDX, IDC_EDIT_NAME, var_edit_name_control);
	DDX_Control(pDX, IDC_EDIT_MASS, var_edit_mass_control);
	DDX_Control(pDX, IDC_RADIO_CONDUCTIVITY, var_radio_conductivity);
	DDX_Control(pDX, IDC_RADIO_MASS, var_radio_mass);
	DDX_Control(pDX, IDC_RADIO_Conductor, var_radio_conductor);
	DDX_Control(pDX, IDC_RADIO_Insulator, var_radio_insulator);
	DDX_Control(pDX, IDC_RADIO_Semiconductor, var_radio_semiconductor);
}

BEGIN_MESSAGE_MAP(Cl6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btn_add_item, &Cl6Dlg::OnBnClickedadditem)
	ON_BN_CLICKED(IDC_BUTTON_DB, &Cl6Dlg::OnBnClickedButtonDb)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &Cl6Dlg::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_RADIO_CONDUCTIVITY, &Cl6Dlg::OnBnClickedRadioConductivity)
	ON_BN_CLICKED(IDC_RADIO_NAME, &Cl6Dlg::OnBnClickedRadioName)
	ON_BN_CLICKED(IDC_RADIO_MASS, &Cl6Dlg::OnBnClickedRadioMass)
	ON_BN_CLICKED(IDC_BUTTON_HOME, &Cl6Dlg::OnBnClickedButtonHome)
	ON_BN_CLICKED(IDC_BUTTON5, &Cl6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_TO_FIND, &Cl6Dlg::OnBnClickedButtonToFind)
END_MESSAGE_MAP()


// Cl6Dlg message handlers

BOOL Cl6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	setViewsSettings();

	setStarView();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cl6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cl6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cl6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}