#pragma once
#include <string> 
#include <vector> 
#include "Substance.h"

using namespace std;

void createChart(CListCtrl* list, vector<Substance> items);
void createColumns(CListCtrl* list);
void addItem(CListCtrl* list, Substance item);