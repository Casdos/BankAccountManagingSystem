#pragma once
#include<random>
#include"Administrator.h"
class User:public Administrator
{
private:
	vector<Client> data;
public:
	User(string address= "data.csv");
	void create(string ID, string name, string phonenum, string email, string idnum, string cardnum);
	//创建账户
	Client* match(const string s);//cg:检查是否匹配
};

