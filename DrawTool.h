#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;

void ReadTxtOfLine(string file);// ���ж���

void ReadTxtOfAllChar(string file);//����ַ����루���Կո���س�)

void ReadTxtOfChar(string file);//����ַ����루�����ո���س���

void ReadRecord(vector<Employee*> &userlist);

