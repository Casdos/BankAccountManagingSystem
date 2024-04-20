#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Client
{
private:
	std::string ID;
	std::string name;
	std::string phonenum;
	std::string email;
	std::string idnum; // ���֤��
	std::string cardnum; // ���п���
	int balance;//cg:�˻����
public:
	Client(std::string IDn = "0", std::string n = "none", std::string phone = "0", std::string e = "@bit.edu", \
		std::string idn = "0", std::string cardn = "unknown", int bal = 0) :ID(IDn), \
		name(n), phonenum(phone), email(e), idnum(idn), cardnum(cardn), balance(bal) {};
	void check();//cg:��麯�������������Ϣ
	void modify();//cg:�޸ĺ����Ľ���
	void saveMoney();
	void getMoney();
	void cancellation();//cg:ע��
	std::string getID();
	std::string getname();
	std::string getphonenum();
	std::string getemail();
	std::string getidnum();
	std::string getcardnum();
	int getbalance();
	void setPhone();
	void setEmail();
	
};

