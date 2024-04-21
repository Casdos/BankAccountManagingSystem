#pragma once
#include<vector>
#include<fstream>
#include"Client.h"
using namespace std;
class Administrator
{
protected:
	vector<Client> data;
	string address;
public:
	Administrator(string address="data.csv");
	~Administrator();
	void saveToFile(const std::string& filename);//保存到文件，参数信息为文件名，如无该文件将自动创建
	bool loadFromFile(const std::string& filename);//从文件中读取，如果无给定文件将输出报错信息，并返回0；

};

