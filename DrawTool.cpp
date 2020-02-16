#include "DrawTool.h"

void ReadTxtOfLine(string file)// 逐行读入
{
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

	string s;
	while(getline(infile,s))
	{
		cout<<s<<endl;
	}
	infile.close();             //关闭文件输入流
}

void ReadTxtOfAllChar(string file)//逐个字符读入（忽略空格与回车)
{
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout<<c<<endl;

	}
	infile.close();             //关闭文件输入流
}


void ReadTxtOfChar(string file)//逐个字符读入（包括空格与回车）
{
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile>>c;
		cout<<c<<endl;

	}
	infile.close();             //关闭文件输入流
}

void ReadRecord(vector<Employee*> &userlist)
{
	/*
	ifstream fin("Address.dat",ios::binary);
	AddressHeader ifh;
	memset(&ifh,0,sizeof(AddressHeader));
	fin.read((char*)&ifh,sizeof(ifh));
	for (int i= 0; i< ifh.dwPacketCount;i++)
	{
		AddressInfo iphInfo;
		fin.read((char*)&iphInfo.Name,32);
		fin.read((char*)&iphInfo.Tel,32);
		fin.read((char*)&iphInfo.Sex,32);
		fin.read((char*)&iphInfo.Class,32);
		Employee *ad = new Employee(iphInfo.Name,iphInfo.Tel,iphInfo.Sex,iphInfo.Class);
		p.push_back(ad);

	}
	fin.close();
	*/
	char buffer[256];
	bool flag = false;
	//Employee* Employee;
	ifstream fin("../employee.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "Error opening file";
	}
	while (!fin.eof() && !flag)
	{
		//getline从istream中读取至多n个字符(包含结束标记符)保存在s对应的数组中

		if (!fin.getline(buffer, 256).good())
		{
			flag = true;
		}
		vector<char*> list;
		char* p = strtok(buffer, " ");//切割字符串，将str切分成一个个子串
		while (p != NULL)
		{
			list.push_back(p);
			p = strtok(NULL, " ");
		}
		if (list.size() >= 6)
		{
			//atof将字符串转为double类型
			//atoi把数字字符串转换成int输出
			userlist.push_back(new Employee((list[0]), (list[1]), (list[2]), (list[3]), (list[4]), (list[5])));
		}
		fin.close();
	}
}


