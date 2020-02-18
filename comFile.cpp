#include "comFile.h"

comFile::comFile()
{
    //ctor
}

comFile::~comFile()
{
    //dtor
}

void comFile::file_empty(string out_file)
{
    fstream file(out_file, ios::ate | ios::out);
    file.close();
}

void comFile::write_txt(vector<string> info, string out_file, int Mode)
{
    int num = info.size();

    if (num <= 0)
    {
        std::cout << "write information is empty!!!please check input " << endl;
        return;
    }

    ofstream outfile;

    switch (Mode)
    {
    case 1:outfile.open(out_file.c_str());
        break;
    case 2:outfile.open(out_file.c_str(), ios::app);
        break;
    default:outfile.open(out_file.c_str());
        break;
    }

    if (!outfile.is_open())
    {
        std::cout << "open file :" << out_file << "has failed!!!!" << endl;
        return;
    }
    
    for (int i = 0; i < num; i++)
    {
        cout << info[i].c_str() << endl;
        outfile << info[i] << "\r";
    }
    
    outfile.close();
    std::cout << "write done!!" << endl;
    return;
}



void comFile::read_txt(vector<string>& info, string in_file)
{
    // char buf[1024];

    ifstream file(in_file.c_str());

    if (!file.is_open())
    {
        std::cout << "open file :" << in_file << "has failed!!" << endl;
        return;
    }

    for (int i = 0; file.good() && !file.eof(); i++)
    {
        // memset(buf, 0, 1024);
         //file.getline(buf, 1024);      //读取的内容包含换行符
         //string message(buf);

        string message;
        file >> message;                //读取的内容不包含换行符

        std::cout << "comFile::read_txt--line :" << message << endl;
        info.push_back(message);
    }

    file.close();
    std::cout << "read done!!" << endl;
    //return 0;
}
void comFile::read_txt(vector<Employee > **info, string in_file)
{
    // char buf[1024];
    *info = new vector<Employee>();
    Employee *in = new Employee(" ", " ", " ", " ", " ", " ");
    //string message;
    ifstream file(in_file.c_str());

    if (!file.is_open())
    {
        std::cout << "open file :" << in_file << "has failed!!" << endl;
        return ;
    }

    for (int i = 0; file.good() && !file.eof(); i++)
    {
        // memset(buf, 0, 1024);
         //file.getline(buf, 1024);      //读取的内容包含换行符
         //string message(buf);
        string message;
        //cout << i << ":" << endl;

        file >> message;
        (*in).SetNum(message);

        file >> message;
        (*in).SetName(message);

        file >> message;
        (*in).SetTeam(message);

        file >> message;
        (*in).SetDepartment(message);

        file >> message;
        (*in).SetDrawFactor(message);

        file >> message;
        (*in).SetAward(message);

        (*info)->push_back(*in);
    }
    (*info)->pop_back();

    vector<Employee>::iterator tem;
    for (tem = (*info)->begin(); tem != (*info)->end(); ++tem)
    {
        (*tem).Print();
    }
    std::cout << "info.size():" << (*info)->size() << endl;
    file.close();
    std::cout << "read done!!" << endl;
    return ;
}