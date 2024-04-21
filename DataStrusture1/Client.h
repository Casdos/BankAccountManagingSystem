#pragma once
#include<iostream>
#include<string>
#include<vector>
<<<<<<< Updated upstream

using namespace std;

=======
using namespace std;
>>>>>>> Stashed changes
class Client
{
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // 身份证号
	string cardnum; // 银行卡号
<<<<<<< Updated upstream
	int balance;//cg:账户余额
=======
	int balance;//cg:账户余额,以分为最小单位
>>>>>>> Stashed changes
public:
	Client(std::string IDn = "0", std::string n = "none", std::string phone = "0", std::string e = "@bit.edu", \
		std::string idn = "0", std::string cardn = "unknown", int bal = 0) :ID(IDn), \
		name(n), phonenum(phone), email(e), idnum(idn), cardnum(cardn), balance(bal) {};
<<<<<<< Updated upstream
	void check();//cg:检查函数，输出所有信息
	void modify();//cg:修改函数的界面
	void saveMoney();
	void getMoney();
	
=======
	void check();//检查函数，输出所有信息
	void modify();//修改函数的界面
	void saveMoney();
	void getMoney();
	int getbalance();
	void setPhone();
	void setEmail();
	void transfer_accounts(Client* target);
>>>>>>> Stashed changes
	string getID();
	string getname();
	string getphonenum();
	string getemail();
	string getidnum();
	string getcardnum();
<<<<<<< Updated upstream
	int getbalance();
	void setPhone();
	void setEmail();
	
=======
>>>>>>> Stashed changes
};

