#pragma once
#include<vector>
#include"Client.h"
#include<fstream>
using namespace std;
class Host 
{
private:
	vector<Client> data;
public:
	void browse();
	void find();
	void find(string s);//查找函数，查找完成后输出所有查询结果
	void saveToFile(const std::string& filename);//保存到文件，参数信息为文件名，如无该文件将自动创建
	bool loadFromFile(const std::string& filename);//从文件中读取，如果无给定文件将输出报错信息，并返回0；
};

