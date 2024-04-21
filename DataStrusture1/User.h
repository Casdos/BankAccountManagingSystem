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
	bool cancellation(const string s);//cg:注销,成功返回1，不成功返回0,这样把输出的信息可以挪移到函数调用的地方，方便一点
};

