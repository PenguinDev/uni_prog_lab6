#include "pch.h"
#include "table.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include "table.h"

int widthAdditionalSpacer = 70;

void getWidths(vector<Substance>* items, vector<int>* widths);
wchar_t* getNormalString(string string);

void createChart(CListCtrl* list, vector<Substance> items)
{
    list->DeleteAllItems();

    vector<int> widths = {};
    getWidths(&items, &widths);

    if (list->GetHeaderCtrl()->GetItemCount() == 0)
    {
        list->InsertColumn(0, _T("Name"), LVCFMT_LEFT, widths[0]);
        list->InsertColumn(1, _T("Mass"), LVCFMT_LEFT, widths[1]);
        list->InsertColumn(2, _T("Conductivity"), LVCFMT_LEFT, widths[2]);
    }
 
    for (int i = 0; i < items.size(); i++)
    {
        list->InsertItem(i, getNormalString(items[i].name));
        list->SetItemText(i, 1, getNormalString(to_string(items[i].mass)));
        list->SetItemText(i, 2, getNormalString(items[i].conductivity));
    }
}

void addItem(CListCtrl* list, Substance item)
{
    int id = list->GetItemCount();
    list->InsertItem(id, getNormalString(item.name));
    list->SetItemText(id, 1, getNormalString(to_string(item.mass)));
    list->SetItemText(id, 2, getNormalString(item.conductivity));
}

void createColumns(CListCtrl* list)
{
    list->DeleteAllItems();

    if (list->GetHeaderCtrl()->GetItemCount() == 0)
    {
        list->InsertColumn(0, _T("Name"), LVCFMT_LEFT, widthAdditionalSpacer);
        list->InsertColumn(1, _T("Mass"), LVCFMT_LEFT, widthAdditionalSpacer);
        list->InsertColumn(2, _T("Conductivity"), LVCFMT_LEFT, widthAdditionalSpacer);
    }
}

void getWidths(vector<Substance>* items, vector<int>* widths)
{
    widths->push_back(0); 
    widths->push_back(0);
    widths->push_back(0);

    for (int i = 0; i < items->size(); i++)
    {
        Substance item = items->at(i);

        if (widths->at(0) < item.name.length())
            widths->at(0) = item.name.length() + widthAdditionalSpacer;

        if (widths->at(1) < to_string(item.mass).length())
            widths->at(1) = to_string(item.mass).length() + widthAdditionalSpacer;

        if (widths->at(2) < item.conductivity.length())
            widths->at(2) = item.conductivity.length() + widthAdditionalSpacer;
    }
}

wchar_t* getNormalString(string string)
{
    wchar_t* wmsg = new wchar_t[strlen(string.c_str()) + 1]; //memory allocation
    mbstowcs(wmsg, string.c_str(), strlen(string.c_str()) + 1);
    return wmsg;
}