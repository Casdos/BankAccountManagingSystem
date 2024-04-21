#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Client
{
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // ���֤��
	string cardnum; // ���п���
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
	string getID();
	string getname();
	string getphonenum();
	string getemail();
	string getidnum();
	string getcardnum();
	int getbalance();
	void setPhone();
	void setEmail();
	
};

