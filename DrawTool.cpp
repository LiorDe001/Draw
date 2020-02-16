#include "DrawTool.h"

void ReadTxtOfLine(string file)// ���ж���
{
	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ���������
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ��������

	string s;
	while(getline(infile,s))
	{
		cout<<s<<endl;
	}
	infile.close();             //�ر��ļ�������
}

void ReadTxtOfAllChar(string file)//����ַ����루���Կո���س�)
{
	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ���������
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ��������

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout<<c<<endl;

	}
	infile.close();             //�ر��ļ�������
}


void ReadTxtOfChar(string file)//����ַ����루�����ո���س���
{
	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ���������
	assert(infile.is_open());   //��ʧ��,�����������Ϣ,����ֹ��������

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile>>c;
		cout<<c<<endl;

	}
	infile.close();             //�ر��ļ�������
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
		//getline��istream�ж�ȡ����n���ַ�(����������Ƿ�)������s��Ӧ��������

		if (!fin.getline(buffer, 256).good())
		{
			flag = true;
		}
		vector<char*> list;
		char* p = strtok(buffer, " ");//�и��ַ�������str�зֳ�һ�����Ӵ�
		while (p != NULL)
		{
			list.push_back(p);
			p = strtok(NULL, " ");
		}
		if (list.size() >= 6)
		{
			//atof���ַ���תΪdouble����
			//atoi�������ַ���ת����int���
			userlist.push_back(new Employee((list[0]), (list[1]), (list[2]), (list[3]), (list[4]), (list[5])));
		}
		fin.close();
	}
}


