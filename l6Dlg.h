
// l6Dlg.h : header file
//

#pragma once
#include "Substance.h"
#include "table.h"
#include "helper.h"
#include <atlconv.h>

// Cl6Dlg dialog
class Cl6Dlg : public CDialogEx
{
// Construction
public:
	Cl6Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_L6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString var_text_name;
	CString var_text_mass;
	void allItemsView(bool isOpen);
	void itemsSourceView(bool isOpen);
	void findItemsView(bool isOpen);
	void conductivityItemsView(bool isOpen);
	void inputItemsView(bool isOpen);
	void setViewsSettings();
	void setStarView();
	string searchType;
	bool isConductivityPressed;
	vector<Substance> listCustomSubstances;
	CListCtrl list_all_control;
	CButton var_radio_name;
	CListCtrl list_finded;
	CString text_what_to_find;
	CEdit var_what_to_find_control;
	CEdit var_edit_mass_control;
	CEdit var_edit_name_control;
	CButton var_radio_conductivity;
	CButton var_radio_mass;
	CButton var_radio_insulator;
	CButton var_radio_semiconductor;
	CButton var_radio_conductor;
	afx_msg void OnBnClickedButtonFind();
	afx_msg void OnBnClickedButtonDb();
	afx_msg void OnBnClickedadditem();
	afx_msg void OnBnClickedRadioConductivity();
	afx_msg void OnBnClickedRadioName();
	afx_msg void OnBnClickedRadioMass();
	afx_msg void OnBnClickedButtonHome();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButtonToFind();
};
