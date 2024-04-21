#include "Host.h"
Host::Host(string address) :Administrator(address)
{}
void Host::find(string s) {
	bool found = false;
	for (auto& client : data) 
	{
		if (s == client.getID()) {
			cout << "查询结果:\n";
			cout << "您的身份标识号:\t" << client.getID() << endl;
			cout << "您的姓名:\t" << client.getname() << endl;
			cout << "您的电话:\t" << client.getphonenum() << endl;
			cout << "您的邮箱:\t" << client.getemail() << endl;
			cout << "您的身份证号:\t" << client.getidnum() << endl;
			cout << "您的银行卡号:\t" << client.getcardnum() << endl;
			cout << "您的余额:\t" << client.getbalance() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "没有找到对应账号，请核验账号" << endl;
	}
}