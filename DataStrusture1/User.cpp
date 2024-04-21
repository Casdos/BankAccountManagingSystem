#include "User.h"
User::User(string address):Administrator(address)
{
}
void User::create(string ID, string name, string phonenum, string email, string idnum, string cardnum) {
	cout << "请设置您的身份标识号：";
	cin >> ID;
	cout << "请输入您的姓名：";
	cin >> name;
	cout << "请输入您的电话：";
	cin >> phonenum;
	cout << "请输入您的电子邮箱：";
	cin >> email;
	cout << "请输入您的身份证号：";
	cin >> idnum;
	//随机生成16位银行卡号
	//生成随机数种子,设置为 global 变量
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 9);
	for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
	data.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
}
Client* User::match(const string s)
{
	bool found = false;
	for (auto& client : data) 
	{
		{
			if (s == client.getID())
			{
				return &client;
			}
		}
		cout << "没有找到对应账号,请核验账号" << endl;
		return nullptr;
	}
}
//wuhanhan: 要删除这个对应的vector元素，可能需要传指针或者什么其他的
bool User::cancellation() 
{
	string s = "1";//有问题，等会改
	for (auto it = data.begin(); it != data.end(); ) {
		if (it->getID() == s) {
			// 删除当前元素
			if (it->getbalance() == 0)
			{
				it = data.erase(it);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else {
			it++;
		}
	}
	return 0;
}
