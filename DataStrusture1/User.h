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
	//�����˻�
	Client* match(const string s);//cg:����Ƿ�ƥ��
};

