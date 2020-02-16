#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

void ReadTxtOfLine(string file);// 逐行读入

void ReadTxtOfAllChar(string file);//逐个字符读入（忽略空格与回车)

void ReadTxtOfChar(string file);//逐个字符读入（包括空格与回车）

void ReadRecord(vector<Employee*> &userlist);

