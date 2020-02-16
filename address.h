#pragma once
#include <string>
#include <iostream>

using namespace std;

class address
{
public:
	address() {};
	address(string na, string te, string se, string cl)
	{
		name = na;
		tel = te;
		sex = se;
		Class = cl;
	}
	~address();
	void set(string na, string se, string cl, string el);
	void setname(string str);
	void settel(string str);
	void setsex(string str);
	void setclass(string str);
	//void correct();
	string getname();
	string gettel();
	string getsex() { return sex; };
	string getclass() { return Class; };
	void get();
private:
	string name = " ";
	string tel = " ";
	string sex = " ";
	string Class = " ";
};

