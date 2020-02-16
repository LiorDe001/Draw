#include "Employee.h"

Employee::Employee(string num, string name, string team, string department, string factor, string award)
{
    this->num = num;
    this->drawfactor = factor;
    this->name = name;
    this->team = team;
    this->department = department;
    this->award = award;
}
Employee::Employee(string num, string name, string team, string department)
{
    this->num = num;
    this->drawfactor = "10";
    this->name = name;
    this->team = team;
    this->department = department;
    this->award = "0";
}

Employee::~Employee()
{
    //dtor
}

void Employee::SetNum(string num)
{
    this->num = num;
    cout << "num:" << num << endl;
}

void Employee::SetName(string name)
{
    this->name = name;
    cout << "name:" << name << endl;
}

void Employee::SetTeam(string team)
{
    this->team = team;
    cout << "team:" << team << endl;
}

void Employee::SetDepartment(string department)
{
    this->department = department;
    cout << "department:" << department << endl;
}

void Employee::SetDrawFactor(string factor)
{
    this->drawfactor = factor;
    cout << "drawfactor:" << drawfactor << endl;
}

void Employee::SetAward(string award)
{
    this->award = award;
    cout << "award:" << award << endl;
}

string Employee::GetNum()
{
    return this->num;
}

string Employee::GetName()
{
    return this->name;
}
string Employee::GetTeam()
{
    return this->team;
}
string Employee::GetDepartment()
{
    return this->department;
}

string Employee::GetDrawFactor()
{
    return this->drawfactor;
}

string Employee::GetAward()
{
    return this->award;
}
//��ʾ�����н���Ϣ
void Employee::Print()
{
    cout << "����:" << this->name << "----";
    cout << "����:" << this->num << "----";
    cout << "�Ŷ�:" << this->team << "----";
    cout << "����:" << this->department << "----";
    cout << "Ȩ��:" << this->drawfactor << "----";
    cout << "�н���Ϣ:" << this->award << endl;;
    //printf("����: %d\n ����: %s\n �Ŷ�: %s\n ����: %s\n", this->num, this->name, this->team, this->department);
}

/*
void Company::Save(std::list<Employee> &list)
{
ofstream outfile("F:\\131\\VS\\Worker\\Worker\\Worker\\Employee.txt", ios::trunc);
if (outfile.is_open())
{
outfile << setw(4) << "���" << setw(9) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(9) << "�ʱ�" << setw(9) << "����" << setw(10) << "����" << endl;

for (auto it = list.begin(); it != list.end(); it++)
{
outfile << *it << endl;
}
}
outfile.close();
}

*/
