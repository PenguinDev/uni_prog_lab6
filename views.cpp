#include "pch.h"
#include "l6.h"
#include "l6Dlg.h"

void Cl6Dlg::setViewsSettings()
{
	CFont font;
	font.CreateFont(
		34,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_BOLD,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));                 // lpszFacename

	list_all_control.ModifyStyle(list_all_control.GetExtendedStyle(), LVS_REPORT);
	SetWindowTheme(list_all_control, L"Explorer", NULL);
	list_finded.ModifyStyle(list_finded.GetExtendedStyle(), LVS_REPORT);
	SetWindowTheme(list_finded, L"Explorer", NULL);

	GetDlgItem(IDC_STATIC)->SetFont(&font);
	GetDlgItem(IDC_TEXT_ALL_ITEMS)->SetFont(&font);
	GetDlgItem(IDC_STATIC_FINDED)->SetFont(&font);
	GetDlgItem(IDC_STATIC_NAME)->SetFont(&font);
	GetDlgItem(IDC_TEXT_MASS)->SetFont(&font);
	GetDlgItem(IDC_STATIC_SEARCH_BY)->SetFont(&font);
}

void Cl6Dlg::setStarView()
{
	itemsSourceView(1);
	allItemsView(0);

	GetDlgItem(btn_add_item)->ShowWindow(0);
	GetDlgItem(IDC_EDIT1)->ShowWindow(0);

	findItemsView(0);
	conductivityItemsView(0);
	inputItemsView(0);
}

void Cl6Dlg::allItemsView(bool isOpen)
{
	GetDlgItem(IDC_LIST_ALL_ITEMS)->ShowWindow(isOpen);
	GetDlgItem(IDC_TEXT_ALL_ITEMS)->ShowWindow(isOpen);
}

void Cl6Dlg::itemsSourceView(bool isOpen)
{
	GetDlgItem(IDC_BUTTON4)->ShowWindow(isOpen);
	GetDlgItem(IDC_BUTTON5)->ShowWindow(isOpen);
	GetDlgItem(IDC_STATIC)->ShowWindow(isOpen);
	GetDlgItem(IDC_BUTTON_HOME)->ShowWindow(!isOpen);
}

void Cl6Dlg::findItemsView(bool isOpen)
{
	var_radio_name.SetCheck(1);
	var_radio_mass.SetCheck(0);
	var_radio_conductivity.SetCheck(0);
	var_what_to_find_control.SetWindowText(_T(""));
	list_finded.DeleteAllItems();

	GetDlgItem(IDC_EDIT_WHAT_TO_FIND)->ShowWindow(isOpen);
	GetDlgItem(IDC_BUTTON_FIND)->ShowWindow(isOpen);
	GetDlgItem(IDC_STATIC_FINDED)->ShowWindow(isOpen);
	GetDlgItem(IDC_LIST_FINDED)->ShowWindow(isOpen);

	GetDlgItem(IDC_STATIC_SEARCH_BY)->ShowWindow(isOpen);
	GetDlgItem(IDC_RADIO_NAME)->ShowWindow(isOpen);
	GetDlgItem(IDC_RADIO_MASS)->ShowWindow(isOpen);
	GetDlgItem(IDC_RADIO_CONDUCTIVITY)->ShowWindow(isOpen);
}

void Cl6Dlg::inputItemsView(bool isOpen)
{
	GetDlgItem(btn_add_item)->ShowWindow(isOpen);
	GetDlgItem(IDC_STATIC_NAME)->ShowWindow(isOpen);
	GetDlgItem(IDC_TEXT_MASS)->ShowWindow(isOpen);
	GetDlgItem(IDC_EDIT_NAME)->ShowWindow(isOpen);
	GetDlgItem(IDC_EDIT_MASS)->ShowWindow(isOpen);
	GetDlgItem(IDC_BUTTON_TO_FIND)->ShowWindow(isOpen);
}

void Cl6Dlg::conductivityItemsView(bool isOpen)
{
	var_radio_conductor.SetCheck(1);
	var_radio_insulator.SetCheck(0);
	var_radio_semiconductor.SetCheck(0);

	GetDlgItem(IDC_RADIO_Conductor)->ShowWindow(isOpen);
	GetDlgItem(IDC_RADIO_Insulator)->ShowWindow(isOpen);
	GetDlgItem(IDC_RADIO_Semiconductor)->ShowWindow(isOpen);
}