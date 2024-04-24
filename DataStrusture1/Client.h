#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
using namespace std;
class Client
{
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // 身份证号
	string cardnum; // 银行卡号
	double balance;//cg:账户余额
public:
	Client(std::string IDn = "0", std::string n = "none", std::string phone = "0", std::string e = "@bit.edu", \
		std::string idn = "0", std::string cardn = "unknown", double bal = 0) :ID(IDn), \
		name(n), phonenum(phone), email(e), idnum(idn), cardnum(cardn), balance(bal) {};
	void check();//检查函数，输出所有信息
	void modify();//修改函数的界面
	void saveMoney();
	void getMoney();
	double getbalance();
	void setPhone();
	void setEmail();
	void transfer_accounts(Client* target);
	string getID();
	string getname();
	string getphonenum();
	string getemail();
	string getidnum();
	string getcardnum();
};

