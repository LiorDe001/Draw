#include "address.h"

address::~address()
{
	//dtor
}

void address::set(string na, string se, string cl, string el)
{
	cout << "������";
	name = na;
	cout << "" << endl;
	cout << "�Ա�:";
	sex = se;
	cout << "" << endl;
	cout << "�༶:";
	Class = cl;
	cout << "" << endl;
	cout << "�绰��";
	tel = el;
	cout << "������ϣ�" << endl;
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
	cout << "����:" << name << "----";
	cout << "�Ա�:" << sex << "----";
	cout << "�༶:" << Class << "----";
	cout << "�绰:" << tel << endl;
}

