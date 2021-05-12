#include "pch.h"
#include "l6Dlg.h"
#include "l6.h"

void Cl6Dlg::OnBnClickedadditem()
{
	UpdateData(1);

	if (var_text_name.IsEmpty())
	{
		AfxMessageBox(
			_T("Why is the name of Substance empty? U can't create new Substance without name. Think, User, Think."), 
			MB_OK | MB_ICONSTOP);
		return;
	}

	if (var_text_mass.IsEmpty())
	{
		AfxMessageBox(
			_T("Why is the mass of Substance empty? U can't create new Substance without mass. Think, User, Think."), 
			MB_OK | MB_ICONSTOP);
		return;
	}

	if (!is_numeric(to_std_string(var_text_mass)))
	{
		AfxMessageBox(
			_T("Why is Substance's mass non numeric? Mass is numeric value and can't be non numeric. Think, User, Think."), 
			MB_OK | MB_ICONSTOP);
		return;
	}

	Substance item = {};
	item.name = to_std_string(var_text_name);
	item.mass = stod(to_std_string(var_text_mass));

	if (IsDlgButtonChecked(IDC_RADIO_Conductor) == BST_CHECKED)
		item.conductivity = "Conductor";
	if (IsDlgButtonChecked(IDC_RADIO_Semiconductor) == BST_CHECKED)
		item.conductivity = "Semiconductor";
	if (IsDlgButtonChecked(IDC_RADIO_Insulator) == BST_CHECKED)
		item.conductivity = "Insulator";

	listCustomSubstances.push_back(item);
	addItem(&list_all_control, item);

}

void Cl6Dlg::OnBnClickedButtonDb()
{
	itemsSourceView(0);
	allItemsView(1);

	findItemsView(1);

	listCustomSubstances.clear();
	createChart(&list_all_control, getCachedSubstances());
}

void Cl6Dlg::OnBnClickedButton5()
{
	itemsSourceView(0);
	findItemsView(0);
	conductivityItemsView(1);
	inputItemsView(1);
	allItemsView(1);

	var_edit_mass_control.SetWindowText(_T(""));
	var_edit_name_control.SetWindowText(_T(""));

	if (listCustomSubstances.empty())
		createColumns(&list_all_control);
	else
		createChart(&list_all_control, listCustomSubstances);
}

void Cl6Dlg::OnBnClickedButtonFind()
{
	UpdateData(1);

	if (IsDlgButtonChecked(IDC_RADIO_CONDUCTIVITY) != BST_CHECKED 
		&& text_what_to_find.IsEmpty())
	{
		AfxMessageBox(
			_T("Why are you trying to find with empty input? It is nothing to find. Think, User, Think."), 
			MB_OK | MB_ICONSTOP);
		return;
	}

	if (IsDlgButtonChecked(IDC_RADIO_NAME) == BST_CHECKED)
		searchType = "n";
	if (IsDlgButtonChecked(IDC_RADIO_MASS) == BST_CHECKED)
	{
		searchType = "m";
		if (!is_numeric(to_std_string(text_what_to_find)))
		{
			AfxMessageBox(
				_T("Why is your mass non numeric? Mass is numeric value and can't be non numeric. Think, User, Think."), 
				MB_OK | MB_ICONSTOP);
			return;
		}
	}
	if (IsDlgButtonChecked(IDC_RADIO_CONDUCTIVITY) == BST_CHECKED)
	{
		searchType = "c";

		if (IsDlgButtonChecked(IDC_RADIO_Conductor) == BST_CHECKED)
			text_what_to_find = "Conductor";
		if (IsDlgButtonChecked(IDC_RADIO_Semiconductor) == BST_CHECKED)
			text_what_to_find = "Semiconductor";
		if (IsDlgButtonChecked(IDC_RADIO_Insulator) == BST_CHECKED)
			text_what_to_find = "Insulator";
	}


	vector<Substance> findedItems = 
		findSubstances(listCustomSubstances.empty() 
			? getCachedSubstances() 
			: listCustomSubstances, 
			to_std_string(text_what_to_find), searchType);
	createChart(&list_finded, findedItems);
}

void Cl6Dlg::OnBnClickedRadioConductivity()
{
	isConductivityPressed = true;
	var_what_to_find_control.SetWindowText(_T(""));
	conductivityItemsView(isConductivityPressed);
	GetDlgItem(IDC_EDIT_WHAT_TO_FIND)->ShowWindow(0);

}

void Cl6Dlg::OnBnClickedRadioName()
{
	isConductivityPressed = false;
	var_what_to_find_control.SetWindowText(_T(""));
	conductivityItemsView(isConductivityPressed);
	GetDlgItem(IDC_EDIT_WHAT_TO_FIND)->ShowWindow(1);

}

void Cl6Dlg::OnBnClickedRadioMass()
{
	isConductivityPressed = false;
	var_what_to_find_control.SetWindowText(_T(""));
	conductivityItemsView(isConductivityPressed);
	GetDlgItem(IDC_EDIT_WHAT_TO_FIND)->ShowWindow(1);

}

void Cl6Dlg::OnBnClickedButtonHome()
{
	itemsSourceView(1);

	allItemsView(0);
	findItemsView(0);
	conductivityItemsView(0);
	inputItemsView(0);

}

void Cl6Dlg::OnBnClickedButtonToFind()
{
	if (listCustomSubstances.empty())
	{
		AfxMessageBox(
			_T("Why is list of Substances empty? U can't find sth in empty list. Think, User, Think."), 
			MB_OK | MB_ICONSTOP);
		return;
	}

	findItemsView(1);
	conductivityItemsView(0);
	inputItemsView(0);
}