#pragma once
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <typeinfo>

using namespace std;

#define W  1        //write only
#define ADD 2       //addition write

class comFile
{
public:
    comFile();
    ~comFile();

    void file_empty(const string out_file);
    void write_txt(vector<string> info, string out_file, int Mode = 1);
    void write_addtxt(vector<string> info, string in_file, string out_file);

    void read_txt(vector<string>& info, string in_file);
    void read_txt(vector<Employee> **info, string in_file);
};

