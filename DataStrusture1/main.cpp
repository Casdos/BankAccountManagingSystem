#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

class Client {
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // 身份证号
	string cardnum; // 银行卡号
	int balance;
public:
	Client(string IDn = "0", string n = "none", string phone = "0", string e = "@bit.edu", \
		string idn = "0", string cardn = "unknown", int bal = 0) :ID(IDn), \
		name(n), phonenum(phone), email(e), idnum(idn), cardnum(cardn), balance(bal) {};
	void create();
	void check();
	void modify();
	void saveMoney();
	void getMoney();
	void cancellation();
};

class Host {
private:
public:
	void browse();
	void find();
};

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

}

void showIniMean() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请选择进入的系统                        *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*               管理员                   客户                  *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                0                        1                    *" << endl;
	cout << "\t\t================================================================" << endl;
};

void showLogin() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请登陆您的账户                          *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                       账号：                                 *" << endl;
	cout << "\t\t*                   如无账号，请申请开户（按1）                *" << endl;
	cout << "\t\t================================================================" << endl;
};

int main()
{
	vector <Client> user;
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	int system_i = -1;
	bool LoginFlag = true;
	//生成随机数种子
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);

	do {
		showIniMean();
		cin >> system_i;
		if (system_i == 0) {

		}
		if (system_i == 1) {
			while (LoginFlag) {
				showLogin();
				cin >> ID;
				if (ID == "1") {
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
					for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
					user.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
					cout << "已开户成功，点击退回登陆界面" << endl;
					getchar();
					continue;
				}
				else {
					//查询是否存在输入账户
					int position = 0;

					LoginFlag = false;
					int choice = 0;
					//选择功能
					cout << "\t\t================================================================" << endl;
					cout << "\t\t*                          功能表                              *" << endl;
					cout << "\t\t*        查询：2                               修改：3         *" << endl;
					cout << "\t\t*        存款：4                               取款：5         *" << endl;
					cout << "\t\t*        销户：6                                               *" << endl;
					cout << "\t\t================================================================" << endl;
					cin >> choice;
					switch (choice) {
					case 2:
						user[position].check();
						break;
					case 3:
						user[position].modify();
					case 4:
						user[position].saveMoney();
					case 5:
						user[position].getMoney();
					case 6:
						user[position].cancellation();
					default:
						cout << "非法输入，请再次输入" << endl;
					}
				}




			}
		}
		if (system_i != 0 && system_i != 1) cout << "非法输入，请再次输入" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}




void Client::getMoney()
{
	cout<<"请输入取款金额:"<<endl;
	int m;
	// wuhanhan:原本为cin<<m,我修改了一下，cin>>m 如果知晓就可以删除
	cin>>m;
	if(balance>m)
	{
		balance=balance-m;
		cout<<"取款成功！"<<endl;
		cout<<"当前账户余额为："<<balance<<endl;
	}
	else cout<<"您的余额不足"<<endl;
}

void Client::saveMoney(){
	int deposit;
	cout<<"请输入存款金额:"<<endl;
	cin>>deposit;
	balance = balance + deposit;
	cout<<"当前账户余额为："<<balance<<endl;
}

//wuhanhan: 要删除这个对应的vector元素，可能需要传指针或者什么其他的
void Client::cancellation(){
	if(balance == 0){
		cout<<"账户已成功注销"<<endl;
		ID = "0";
        name = "none";
        phonenum = "0";
        email = "@bit.edu";
        idnum = "0";
        cardnum = "unknown";
		bal = 0;
	else cout<<"无法办理销户"<<endl;
}
