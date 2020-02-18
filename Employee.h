#pragma once
#include <string>
#include <iostream>

using namespace std;

class Employee
{
public:
    Employee() {};
    Employee(string num, string name, string team, string department, string factor, string award);
    Employee(string num, string name, string team, string department);
    ~Employee();

    void Set();
    void SetNum(string num);
    void SetName(string name);
    void SetTeam(string team);
    void SetDepartment(string department);
    void SetDrawFactor(string factor);
    void SetAward(string award);

    string GetNum();
    string GetName();
    string GetTeam();
    string GetDepartment();
    string GetDrawFactor();
    string GetAward();
    void Print();//显示员工信息
private:
    string num = " ";//工号
    string name = " ";//姓名
    string team = " ";//团队
    string department = " ";//部门
    string drawfactor = " ";//抽奖权重
    string award = " ";
};


/*
：本题中绩效系数、工资等数据均为double型，输出不保留小数部分
输入实例：
6
101 bob Manager 1.4
102 Sam Sales 100000
103 Apple Sales 150000
104 Bill Engineer 12
105 Mike Manager 1.3
106 Henry Engineer 15
输出实例：
Top Manager: 101 bob A Manager with salary 11200
Top Sales: 103 Apple A Sales with salary 11500
Top Engineer: 106 Henry A Engineer with salary 10500

程序代码如下：
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
    protected:
        int id;
        string name;
        double basic_salary;
        string title;
    public:
        Employee(int i, string n, double b, string t): id(i), name(n), basic_salary(b), title(t) {}
        virtual double salary_computing() const = 0;
        string get_title() const
        {
            return title;
            }
        void print() const
        {
            cout << id << " " << name << " A " << title << " with salary " << fixed << setprecision(0) << salary_computing() << endl;
            }
};

class Manager : public Employee
{
    static Employee* top;
    double effiency;
    public:
        Manager(int id, string name, double e): Employee(id,name,8000,"Manager"), effiency(e)
        {
            if(top==NULL || salary_computing() > top->salary_computing())
                top = this;
            }
        double salary_computing() const
        {
            return effiency * basic_salary;
            }
        static void printmax()
        {
            cout << "Top Manager: ";
            if(top) top->print();
            }
};

Employee* Manager::top = NULL;

class Sales : public Employee
{
    static Employee* top;
    double sales;
    public:
        Sales(int id, string name, double s): Employee(id,name,4000,"Sales"), sales(s)
        {
            if(top==NULL || salary_computing() > top->salary_computing())
                top = this;
            }
        double salary_computing() const
        {
            return basic_salary + 0.05 * sales;
            }
        static void printmax()
        {
            cout << "Top Sales: ";
            if(top) top->print();
            }
};

Employee* Sales::top = NULL;

class Engineer : public Employee
{
    static Employee* top;
    double num;
    public:
        Engineer (int id, string name, double m): Employee(id,name,6000,"Engineer"), num(m)
        {
            if(top==NULL || salary_computing() > top->salary_computing())
                top = this;
            }
        double salary_computing() const
        {
            return basic_salary + 300 * num;
            }
        static void printmax()
        {
            cout << "Top Engineer: ";
            if(top) top->print();
            }
};

Employee* Engineer::top = NULL;

int main()
{
    int n, i;
    cin >> n;
    Employee **pt2employ = new Employee*[n];
    for(i=0;i<n;i++)
    {
        int id;
        cin >> id;
        string name;
        cin >> name;
        string title;
        cin >> title;
        double e;
        cin >> e;
        if(title == "Manager")
        {
            pt2employ[i] = new Manager(id,name,e);
        }
        else if(title == "Sales")
        {
            pt2employ[i] = new Sales(id,name,e);
        }
        else if(title == "Engineer")
        {
            pt2employ[i] = new Engineer(id,name,e);
        }
    }
    Manager::printmax();
    Sales::printmax();
    Engineer::printmax();
}
*/


