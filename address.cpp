#include "address.h"

address::~address()
{
	//dtor
}

void address::set(string na, string se, string cl, string el)
{
	cout << "姓名：";
	name = na;
	cout << "" << endl;
	cout << "性别:";
	sex = se;
	cout << "" << endl;
	cout << "班级:";
	Class = cl;
	cout << "" << endl;
	cout << "电话：";
	tel = el;
	cout << "输入完毕！" << endl;
}

void address::setname(string str)
{
	//cout << "name:" << name << endl;
	name = str;
	cout << "name:" << name << endl;
}
void address::settel(string str)
{
	//cout << "tel:" << tel << endl;
	tel = str;
	cout << "tel:" << tel << endl;
}
void address::setsex(string str)
{
	//cout << "sex:" << sex << endl;
	sex = str;
	cout << "sex:" << sex << endl;
}
void address::setclass(string str)
{
	//cout << "Class:" << Class << endl;
	Class = str;
	cout << "Class:" << Class << endl;
}
string address::getname()
{
	return name;
}
string address::gettel()
{
	return tel;
}

void address::get()
{
	perror("get01");
	cout << "姓名:" << name << "----";
	cout << "性别:" << sex << "----";
	cout << "班级:" << Class << "----";
	cout << "电话:" << tel << endl;
}

