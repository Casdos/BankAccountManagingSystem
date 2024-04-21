#pragma once
#include<vector>
#include<iostream>
#include <random>
#include<fstream>
#include"Client.h"
class User
{
private:
	vector<Client> data;
public:
	void create(string ID, string name, string phonenum, string email, string idnum, string cardnum);
	//创建账户
	Client* match(const string s);//cg:检查是否匹配
	void saveToFile(const std::string& filename);//保存到文件，参数信息为文件名，如无该文件将自动创建
	bool loadFromFile(const std::string& filename);//从文件中读取，如果无给定文件将输出报错信息，并返回0；
};

