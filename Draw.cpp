// Draw.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
/*
#include <iostream>
#include <fstream>

using namespace std;

char *myStrcpy(char *dest, const char *src)
{
	//assert(dest != NULL && src != NULL);
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	if (dest == src) {
		return dest;
	}
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}
class person
{
public:
	enum {SIZE=50};
	int id;
	int age;
	char name[SIZE];
	char address[SIZE];
};

class ConfigFile
{
private:
	fstream fs;
	string filename;

	void openfin()
	{
		try
		{
			fs.open(this->filename.c_str(),fstream::in|fstream::out|fstream::app);
			cout << "in" << endl;
		}catch(...)
		{
			cout << "错误" << endl;
		}
	}

	void openfout()
	{
		try
		{
			fs.open(this->filename.c_str(),fstream::out|fstream::trunc);
			cout << "out" << endl;
		}catch(...)
		{
			cout << "错误" << endl;
		}
	}
public:
	ConfigFile(string fn):filename(fn)
	{
	}

	~ConfigFile()
	{
		if(fs.is_open())
			fs.close();
	}


	//通过id查找位置
	size_t query(size_t id)
	{
		size_t index=0;
		if(!fs.is_open())
			openfin();
		fs.seekg(0,ios_base::beg);
		while(!fs.eof())
		{
			fs.read(reinterpret_cast<char*>(&index),sizeof(int));
			if(index==id)
			{
				fs.seekg(-sizeof(int),ios_base::cur);
				return fs.tellg();
			}
			fs.seekg(sizeof(person)-sizeof(int),ios_base::cur);
		}
		fs.close();

		return -1;
	}


	//返回位置n的person记录
	person retrieve(size_t n)
	{
		person p;
		if(!fs.is_open())
			openfin();
		int resultindex=query(n);
		if(resultindex!=-1)//找到了
		{
			fs.seekg(resultindex);
			fs.read(reinterpret_cast<char*>(&p),sizeof(person));
			fs.close();
			return p;
		}

		fs.close();
		throw("no result");
	}


	//修改位置n的person记录
	int update(size_t n, person& p)
	{
		if(!fs.is_open())
			fs.open(filename.c_str(),fstream::in|fstream::out);
		int resultindex=query(n);
		if(resultindex!=-1)//找到了
		{
			fs.seekp(resultindex);
			fs.write(reinterpret_cast<char*>(&p),sizeof(person));
			fs.close();
			return 0;
		}
		fs.close();
		return 1;
	}


	//添加一个人的记录
	void add(person& p)
	{
		if(!fs.is_open())
			openfout();
		cout << "1" << endl;
		fs.seekp(0,ios::end);
		cout << "12" << endl;
		fs.write(reinterpret_cast<char*>(&p),sizeof(person));
		cout << "2" << endl;
		fs.close();
	}
};


int main()
{
	ConfigFile db("User.txt");


	person p,p1;
	p.id=1;
	p.age=1;
	myStrcpy(p.name,"学生");
	myStrcpy(p.address,"湖南");

	db.add(p);

	p1=db.retrieve(1);
	cout<<"p.id="<<p1.id<<endl;
	cout<<"p.age="<<p1.age<<endl;
	cout<<"p.name="<<p1.name<<endl;
	cout<<"p.address="<<p1.address<<endl;
	cout<<"-------------------------------"<<endl;



/*

	cout<<"Change 2 happend...."<<endl;
	person ppp;
	ppp.id=1;
	ppp.age=222;
	myStrcpy(ppp.name,"new person 1");
	myStrcpy(ppp.address,"中华人们公共和国");
	db.update(1,ppp);//修改

	for(int i=0;i<3;i++)
	{
		try
		{
			person p=db.retrieve(i+1);
			cout<<"p.id="<<p.id<<endl;
			cout<<"p.age="<<p.age<<endl;
			cout<<"p.name="<<p.name<<endl;
			cout<<"p.address="<<p.address<<endl;
		}catch(...)
		{
			cout<<"Can't not find the person "<<i+1<<endl;
		}

	}

	*/

	//}

	/*
	ios::app：   以追加的方式打开文件
	ios::ate：   文件打开后定位到文件尾，ios:app就包含有此属性
	ios::binary： 以二进制方式打开文件，缺省的方式是文本方式。两种方式的区别见前文
	ios::in：    文件以输入方式打开（文件数据输入到内存）
	ios::out：   文件以输出方式打开（内存数据输出到文件）
	ios::nocreate： 不建立文件，所以文件不存在时打开失败
	ios::noreplace：不覆盖文件，所以打开文件时如果文件存在失败
	ios::trunc：  如果文件存在，把文件长度设为0
	*/

	/*
	//#include "stdafx.h"
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <string.h>
	#include <vector>
	#include<stdio.h>

	using namespace std;
	#define DWORD unsigned long
	#define CHAR char
	static int num=0;
	struct AddressHeader
	{
		DWORD dwPacketCount;			//4个字节 包的个数
		DWORD dwReserve;
	};
	struct AddressInfo			//包的信息
	{
		CHAR  Name[32];
		CHAR  Tel[32];
		CHAR  Sex[32];
		CHAR  Class[32];
	};
	class address
	{
	public:
		address(){};
		address(string na,string te,string se,string cl)
		{
			name = na;
			tel = te;
			sex = se;
			Class = cl;
		}
		void set();
		void correct();
		string getname();
		string gettel();
		string getsex(){return sex;};
		string getclass(){return Class;};
		void get();
	private:
		string name;
		string tel;
		string sex;
		string Class;
	};
	void address::set()
	{
		cout<<"姓名：";
		cin>>name;
		cout<<""<<endl;
		cout<<"性别:";
		cin>>sex;
		cout<<""<<endl;
		cout<<"班级:";
		cin>>Class;
		cout<<""<<endl;
		cout<<"电话：";
		cin>>tel;
		cout<<"输入完毕！"<<endl;
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
		cout<<"姓名:"<<name<<"----";
		cout<<"性别:"<<sex<<"----";
		cout<<"班级:"<<Class<<"----";
		cout<<"电话:"<<tel<<endl;
	}
	void ReadRecord(vector<address*>& p)
	{

		ifstream fin("Address.dat",ios::binary);
		AddressHeader ifh;
		int h = ifh.dwPacketCount;
		memset(&ifh,0,sizeof(AddressHeader));
		fin.read((char*)&ifh,sizeof(ifh));
		for (int i= 0; i< ifh.dwPacketCount;i++)
		{
			h--;
			printf("ifhe.dwPacketCount:%d\n",h);
			AddressInfo iphInfo;
			fin.read((char*)&iphInfo.Name,32);
			fin.read((char*)&iphInfo.Tel,32);
			fin.read((char*)&iphInfo.Sex,32);
			fin.read((char*)&iphInfo.Class,32);
			address *ad = new address(iphInfo.Name,iphInfo.Tel,iphInfo.Sex,iphInfo.Class);
			p.push_back(ad);
		}
		fin.close();
	/*
		ifstream fine("bspline.txt",ios::in);
		//char* h = nullptr;
		AddressHeader ifhe;
		memset(&ifhe,0,sizeof(AddressHeader));
		fine.read((char*)&ifhe,sizeof(ifhe));
		int h = ifhe.dwPacketCount;
		for (int i= 0; i< ifhe.dwPacketCount;i++)
		{
			h--;
			printf("ifhe.dwPacketCount:%d\n",h);
			AddressInfo iphInfo;
			fine.read((char*)&iphInfo.Name,sizeof(iphInfo.Name));
			fine.read((char*)&iphInfo.Tel,1);
			perror("test02");

			fine.read((char*)&iphInfo.Tel,sizeof(iphInfo.Tel));
			fine.read((char*)&iphInfo.Sex,1);

			fine.read((char*)&iphInfo.Sex,sizeof(iphInfo.Sex));
			fine.read((char*)&iphInfo.Class,1);

			fine.read((char*)&iphInfo.Class,sizeof(iphInfo.Class));

			address *ad = new address(iphInfo.Name,iphInfo.Tel,iphInfo.Sex,iphInfo.Class);
			p.push_back(ad);
		}
		//fin.close();
		fine.close();
		perror("end read");
		*/
		/*
		}
		void SaveRecord(vector<address*>& p)
		{
			ofstream fout("Address.dat",ios::binary);
			AddressHeader ph;
			ph.dwPacketCount = p.size();
			ph.dwReserve	 = 0;
			fout.write((char*)(&ph),sizeof(ph));
			for (int i = 0; i < p.size(); i++)
			{
				//写包数据
				AddressInfo phInfo;
				strcpy(phInfo.Name, p[i]->getname().c_str());
				strcpy(phInfo.Class, p[i]->getclass().c_str());
				strcpy(phInfo.Sex, p[i]->getsex().c_str());
				strcpy(phInfo.Tel, p[i]->gettel().c_str());
				fout.write((char*)&phInfo.Name,32);
				fout.write((char*)&phInfo.Tel,32);
				fout.write((char*)&phInfo.Sex,32);
				fout.write((char*)&phInfo.Class,32);
			}
			char buf[22];
			ofstream fin("bspline.txt");
			for (int i = 0; i < p.size(); i++)
			{
				/*
				sprintf_s(buf,"%lf", p[i]->getname().c_str());
				fin.write(buf,strlen(buf));
				fin.write("\0", 1);
				sprintf_s(buf, "%lf", p[i]->getclass().c_str());
				fin.write(buf, strlen(buf));
				fin.write("\0", 1);
				sprintf_s(buf, "%lf", p[i]->getsex().c_str());
				fin.write(buf, strlen(buf));
				fin.write("\0", 1);
				sprintf_s(buf, "%lf", p[i]->gettel().c_str());
				fin.write(buf, strlen(buf));
				fin.write("\0", 1);
				fin.write("\r\n", 2);

				strcpy(buf,p[i]->getname().c_str());
				fin.write(buf,strlen(buf));
				fin.write(" ", 1);
				strcpy(buf, p[i]->getclass().c_str());
				fin.write(buf, strlen(buf));
				fin.write(" ", 1);
				strcpy(buf,p[i]->getsex().c_str());
				fin.write(buf, strlen(buf));
				fin.write(" ", 1);
				strcpy(buf, p[i]->gettel().c_str());
				fin.write(buf, strlen(buf));
				fin.write(" ", 1);
				fin.write("\r\n", 2);

			}
			fout.close();
		}


		int main()
		{
			vector<address*> P;
			ReadRecord(P);
			num = P.size();
			cout<<"Welcome to the address system!"<<endl;
			for(int y=0;;y++)
			{
				cout<<"*******************************"<<endl;
				cout<<"功能介绍："<<endl;
				cout<<"1.浏览通讯录" <<endl;
				cout<<"2.增加新成员"<<endl;
				cout<<"3.修改原数据"<<endl;
				cout<<"4.按姓名查询"<<endl;
				cout<<"5.按电话查询"<<endl;
				cout<<"6.退出"<<endl;
				cout<<"*******************************"<<endl;
				int choise;
				string NA,m,z;
				string TE;
		lop:cout<<"请选择你要进行的操作编号：";
				cin>>choise;
				int j,i,h;
				address* pus = new address;
				switch (choise)
				{
				case 1:
					for(j=1;j<=num;j++)
					{
						P[j-1]->get();
					}
					break;

				case 2:
					cout<<"请输入："<<endl;
					pus->set();
					P.push_back(pus);
					num++;
					break;

				case 3:
					cout<<"请输入要修改的人的姓名：";
					cin>>m;
					for(i=0;i<=num-1;i++)
					{
						z=P[i]->getname();
						if(z==m)
							break;
					}
					cout<<"请输入新信息：";
					P[i]->set();
					break;

				case 4:
					cout<<"请输入要查找的人的姓名：";
					cin>>NA;
					cout<<""<<endl;
					for( j=1;j<=num;j++)
					{
						if(P[j-1]->getname()==NA)
						{
							P[j-1]->get();
							break;
						}
					}
					break;

				case 5:

					cout<<"请输入要查询的号码：";
					cin>>TE;
					for(h=1;h<=num;h++)
					{
						if(P[h-1]->gettel()==TE)
						{
							P[h-1]->get();
							break;
						}
					}
					break;

				case 6:goto loop;
				default:
					cout<<"输入有误，请重新输入！"<<endl;
					goto lop;
				}
			}
		loop:cout<<"欢迎再次使用本系统，再见！" <<endl;
			SaveRecord(P);
			for (int i = 0; i < P.size(); i++)
			{
				if (P[i])
				{
				  delete P[i];
				  P[i] = NULL;
				}
			}
			return 0;
		}

		*/


#include "comFile.h"
#include "address.h"
#include "Employee.h"
#include "DrawAlgo.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define DWORD unsigned long
#define CHAR char
static int num = 0;

#define NumSunAward  6    //阳光普照奖名额
#define NumThrAward  3   //三等奖名额
#define NumSndAward  2   //二等奖名额
#define NumOneAward  1   //一等奖名额
#define NumTopAward  2   //特等奖名额



int main()
{
	string fileName = "原始员工池.txt";
	string fileName_Award = "中奖者名单.txt";
	string fileName_NoAward = "未中奖者名单.txt";
	string fileName_WrSunAward = "阳光普照奖奖池名单.txt";
	string fileName_WrThrAward = "三等奖奖池名单.txt";
	string fileName_WrSndAward = "二等奖奖池名单.txt";
	string fileName_WrOneAward = "一等奖奖池名单.txt";
	string fileName_WrTopAward = "特等奖奖池名单.txt";

	string fileName_WrAward = "特殊抽奖池名单.txt";//指定部门或团队内部抽奖所用


	comFile Rd,Wr;
	vector<string> information;
	vector<Employee> *Prd;
	//vector<Employee> *Pwr;
	vector<Employee> *Paw;//已中奖
	
	//设置员工的初始抽奖权重。。。
	vector<int> weight;//权重
	int* p = NULL; //定义与封装函数返回值类型相同的指针变量,来接收返回地址
	Rd.read_txt(&Prd, fileName);
	//ReadRecord(P);
	num = Prd->size();
	cout << "Welcome to the Lottery system!" << endl;
	for (int y = 0;; y++)
	{
		cout << "*******************************" << endl;
		cout << "功能介绍：" << endl;
		cout << "1.抽取阳光普照奖" << endl;
		cout << "2.抽取三等奖" << endl;
		cout << "3.抽取二等奖" << endl;
		cout << "4.抽取一等奖" << endl;
		cout << "5.抽取特等奖" << endl;
		cout << "6.添加特定员工" << endl;
		cout << "7.删除特定员工" << endl;
		cout << "8.按工号修改员工抽奖权重" << endl;
		cout << "9.按团队修改员工抽奖权重" << endl;
		cout << "10.已中奖员工返回奖池" << endl;
		cout << "11.特定中奖员工群返回奖池" << endl;//按中奖属性返回（未中奖池中保存的）
		cout << "12.退出" << endl;
		cout << "*******************************" << endl;
		int choise;
		Employee* add = new Employee;
		Employee* del = new Employee;
		string NA, m, z;
		string TE;
	lop:cout << "请选择你要进行的操作编号：";
		cin >> choise;
		int nPosition;
		switch (choise)
		{
		case 1://抽取阳光普照奖
		{
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
			{
				weight.push_back(atoi((iter->GetDrawFactor()).c_str()));
			}
			Wr.file_empty(fileName_Award);//清空文件内容，重新抽奖

			std::cout << " 颁发阳光普照奖 " << endl;
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); ++iter)
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_WrSunAward);//保存阳光普照奖奖池名单
				information.clear();
			}

			p = GetRandomNumWithWeight(weight, NumSunAward);//
			vector<Employee>::iterator iter;
			for (int i = 0; i < NumSunAward; i++)
			{
				iter = Prd->begin() + p[i];
				iter->SetAward("阳光普照奖");
			}

			for (iter = Prd->begin(); iter != Prd->end();)
			{
				if (iter->GetAward() == "阳光普照奖")
				{
					string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
					information.push_back(text);
					Wr.write_txt(information, fileName_Award, 2);//保存中奖者名单
					information.clear();

						//perror("test01");
						//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					iter = (Prd->erase(iter));
					if (iter == Prd->end()) break;
				}
				else
					//迭代器指向下一个元素位置
					++iter;
			}
			weight.clear();
			information.clear();
		}
			break;

		case 2://抽取三等奖
		{
			std::cout << " 颁发三等奖 " << endl;
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
			{
				weight.push_back(atoi((iter->GetDrawFactor()).c_str()));
			}
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); ++iter)
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_WrThrAward);//保存三等奖奖池名单
				information.clear();
			}

			vector<Employee>::iterator iter;
			p = GetRandomNumWithWeight(weight, NumThrAward);//生成3个随机数三等奖
			for (int i = 0; i < NumThrAward; i++)
			{
				iter = Prd->begin() + p[i];
				iter->SetAward("三等奖");
			}
			for (iter = Prd->begin(); iter != Prd->end();)
			{
				if (iter->GetAward() == "三等奖")
				{
					string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
					information.push_back(text);
					Wr.write_txt(information, fileName_Award, 2);//保存中奖者名单
					information.clear();

					//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					iter = (Prd->erase(iter));
					if (iter == Prd->end()) break;
				}
				else
					//迭代器指向下一个元素位置
					++iter;
			}
			weight.clear();
		}
		break;

		case 3://抽取二等奖
		{
			std::cout << " 颁发二等奖 " << endl;
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
			{
				weight.push_back(atoi((iter->GetDrawFactor()).c_str()));
			}
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); ++iter)
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_WrSndAward);//保存二等奖奖池名单
				information.clear();
			}

			vector<Employee>::iterator iter;
			p = GetRandomNumWithWeight(weight, NumSndAward);//生成2个随机数二等奖
			for (int i = 0; i < NumSndAward; i++)
			{
				iter = Prd->begin() + p[i];
				iter->SetAward("二等奖");
			}
			for (iter = Prd->begin(); iter != Prd->end();)
			{
				if (iter->GetAward() == "二等奖")
				{
					string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
					information.push_back(text);
					Wr.write_txt(information, fileName_Award, 2);//保存中奖者名单
					information.clear();

					//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					iter = (Prd->erase(iter));
					if (iter == Prd->end()) break;
				}
				else
					//迭代器指向下一个元素位置
					++iter;
			}
			weight.clear();
		}
		break;

		case 4://抽取一等奖
		{
			//颁发一等奖
			std::cout << " 颁发一等奖 " << endl;
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
			{
				weight.push_back(atoi((iter->GetDrawFactor()).c_str()));
			}
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); ++iter)
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_WrOneAward);//保存一等奖奖池名单
				information.clear();
			}
			vector<Employee>::iterator iter;
			p = GetRandomNumWithWeight(weight, NumOneAward);//生成1个随机数一等奖
			for (int i = 0; i < NumOneAward; i++)
			{
				iter = Prd->begin() + p[i];
				iter->SetAward("一等奖");
			}
			for (iter = Prd->begin(); iter != Prd->end();)
			{
				if (iter->GetAward() == "一等奖")
				{
					string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
					information.push_back(text);
					Wr.write_txt(information, fileName_Award, 2);//保存中奖者名单
					information.clear();

					//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					iter = (Prd->erase(iter));
					if (iter == Prd->end()) break;
				}
				else
					//迭代器指向下一个元素位置
					++iter;
			}
			weight.clear();
		}
		break;

		case 5://抽取特等奖
		{
			//颁发特等奖
//将部分中奖员工返回奖池。。。
			std::cout << " 颁发特等奖 " << endl;
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
			{
				weight.push_back(atoi((iter->GetDrawFactor()).c_str()));
			}
			for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); ++iter)
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_WrTopAward);//保存一等奖奖池名单
				information.clear();
			}

			vector<Employee>::iterator iter;
			p = GetRandomNumWithWeight(weight, NumTopAward);//生成1个随机数一等奖
			for (int i = 0; i < NumTopAward; i++)
			{
				iter = Prd->begin() + p[i];
				iter->SetAward("特等奖");
			}
			for (iter = Prd->begin(); iter != Prd->end();)
			{
				if (iter->GetAward() == "特等奖")
				{
					string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
					information.push_back(text);
					Wr.write_txt(information, fileName_Award, 2);//保存中奖者名单
					information.clear();

					//删除指定元素，返回指向删除元素的下一个元素的位置的迭代器
					iter = (Prd->erase(iter));
					if (iter == Prd->end()) break;
				}
				else
					//迭代器指向下一个元素位置
					++iter;
			}
			weight.clear();
		}

		break;

		case 6://添加特定员工
		{
			cout << "请输入：" << endl;
			add->Set();
			Prd->push_back(*add);
			num++;
		}

		break;
		case 7://删除特定员工
		{
			cout << "请输入：" << endl;
			del->Set();
			vector<Employee>::iterator iElement = std::find(Prd->begin(), Prd->end(), *del);
			if (iElement != Prd->end())
			{
				//int nPosition = distance(Prd->begin(), iElement);
				int nPosition = std::distance(std::begin(*Prd), iElement);
			}
			Prd->erase(Prd->begin() + nPosition);
			//Prd->push_back(*in);
			num--;
			break;
		}
		case 8://按工号修改员工抽奖权重
		{
			cout << "请输入要修改抽奖权重的员工工号：";
			cin >> m;
			cout << "" << endl;
			for (vector<Employee>::iterator iElement = Prd->begin(); iElement != Prd->end(); iElement++)
			{
				if (iElement->GetNum() == m)
				{
					cout << "请输入新的抽奖权重(0-100,默认10)：";
					cin >> z;
					cout << "" << endl;
					iElement->SetDrawFactor(z);
					break;
				}
			}
		}

		case 9://按团队修改员工抽奖权重
		{
			cout << "请输入要修改抽奖权重的团队(如“MCP1队”)：";
			cin >> m;
			cout << "" << endl;
			for (vector<Employee>::iterator iElement = Prd->begin(); iElement != Prd->end(); iElement++)
			{
				if (iElement->GetTeam() == m)
				{
					cout << "请输入新的抽奖权重(0-100,默认10)：";
					cin >> z;
					cout << "" << endl;
					iElement->SetDrawFactor(z);
				}
			}
			break;
		}

		case 10://已中奖员工返回奖池
		{
			cout << "已中奖且需返回奖池员工工号：";
			cin >> m;
			cout << "" << endl;
			Rd.read_txt(&Paw, fileName_Award);
			for (vector<Employee>::iterator iElement = Paw->begin(); iElement != Paw->end(); iElement++)
			{
				if (iElement->GetNum() == m)
				{
					cout << "请输入：" << endl;
					Prd->push_back(*iElement);
					num++;
					//fileName_Award删除此元素
					break;
				}
			}
		}
		case 11://特定中奖员工群返回奖池
		{
			cout << "特定中奖员工群的中奖信息(如“三等奖”)：";
			cin >> m;
			cout << "" << endl;
			Rd.read_txt(&Paw, fileName_Award);
			for (vector<Employee>::iterator iElement = Paw->begin(); iElement != Paw->end(); iElement++)
			{
				if (iElement->GetAward() == m)
				{
					cout << "请输入：" << endl;
					Prd->push_back(*iElement);
					num++;
					//fileName_Award删除此元素
					break;
				}
			}
		}
		case 12://退出系统
		{
			goto loop;
		}
		default:
			cout << "输入有误，请重新输入！" << endl;
			goto lop;
		}
	}
loop:cout << "欢迎再次使用本系统，再见！" << endl;
{
		//未中奖人员名单
		std::cout << " 未中奖人员名单 " << endl;
		for (vector<Employee>::iterator iter = Prd->begin(); iter != Prd->end(); iter++)
		{
			if (iter->GetAward() == "0")
			{
				string text = iter->GetNum() + " " + iter->GetName() + " " + iter->GetTeam() + " " + iter->GetDepartment() + " " + iter->GetDrawFactor() + " " + iter->GetAward();
				information.push_back(text);
				Wr.write_txt(information, fileName_NoAward);//保存中奖者名单
				information.clear();
			}
			iter->Print();
		}

}
	if (Prd)
	{
		delete Prd;
		Prd = NULL;
	}
	if (Paw)
	{
		delete Paw;
		Paw = NULL;
	}
	if (p)
	{
		delete p;
		p = NULL;
	}

	return 0;
}

