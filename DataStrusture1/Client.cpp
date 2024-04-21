#include "Client.h"
using namespace std;
string Client::getID() 
{ 
	return ID; 
}
string Client::getname()
{
	return name;
}
string Client::getphonenum()
{
	return phonenum;
}
string Client::getemail()
{
	return email;
}
string Client::getidnum()
{
	return idnum;
}
string Client::getcardnum()
{
	return cardnum;
}
int Client::getbalance()
{
	return balance;
}
void Client::setPhone() 
{
	string s; 
	cout << "请输入修改后电话："; 
	cin >> s; 
	phonenum = s; 
}
void Client::setEmail()
{
	string s; cout << "请输入修改后邮件："; cin >> s; email = s;
}
void Client::check() {
	cout << "您的身份标识号:\t" << ID << endl;
	cout << "您的姓名:\t" << name << endl;
	cout << "您的电话:\t" << phonenum << endl;
	cout << "您的邮箱:\t" << email << endl;
	cout << "您的身份证号:\t" << idnum << endl;
	cout << "您的银行卡号:\t" << cardnum << endl;
	cout << "您的余额:\t" << balance << endl;
}
void Client::modify() {
	char choice = NULL;
	while (choice != 'q') {
		cout << "\t\t================================================================" << endl;
		cout << "\t\t*                          修改                                 *" << endl;
		cout << "\t\t*   修改电话请按1                         修改邮件请按2           *" << endl;
		cout << "\t\t*   同时修改请按3                         退出修改请按q           *" << endl;
		cout << "\t\t================================================================" << endl;
		cin >> choice;
		switch (choice) {
		case '1':
			this->setPhone();
			break;
		case '2':
			this->setEmail();
			break;
		case '3':
			this->setPhone();
			this->setEmail();
		case 'q':
			cout << "退出修改模式";
			return;
		default:
			cout << "非法输入，请再次输入" << endl;
		}
	}
}
void Client::getMoney()
{
	cout << "请输入取款金额:" << endl;
	int m;
	// wuhanhan:原本为cin<<m,我修改了一下，cin>>m 如果知晓就可以删除
	cin >> m;
	//wuhanhan:是不是改成 >=
	if (balance > m)
	{
		balance = balance - m;
		cout << "取款成功！" << endl;
		cout << "当前账户余额为：" << balance << endl;
	}
	else cout << "您的余额不足" << endl;
}

void Client::saveMoney() {
	int deposit;
	cout << "请输入存款金额:" << endl;
	cin >> deposit;
	balance = balance + deposit;
	cout << "当前账户余额为：" << balance << endl;
}