#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <vector>
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
	cout << "\t\t*                      请登陆您的账户                           *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*					    账号：                                  *" << endl;
	cout << "\t\t*                   如无账号，请申请开户（按1）                   *" << endl;
	cout << "\t\t================================================================" << endl;
};

int main()
{
	vector <Client> user;
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	int system_i = -1;
	do {
		showIniMean();
		cin >> system_i;
		if (system_i == 0) {

		}
		if (system_i == 1) {
			showLogin();
			cin >> ID;
			if (ID == "1") {
				cout << "请设置您的身份证标识号：";
				cin >> ID;
				cout << "请输入您的姓名：";
				cin >> name;
				cout << "请输入您的电话：";
				cin >> phonenum;
				cout << "请输入您的电子邮箱：";
				cin >> email;
				cout << "请输入您的身份证号：";
				cin >> idnum;
				user.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
				cout << "已开户成功，点击退回登陆界面" << endl;
				getchar();
			}
			showLogin();
		}
		if (system_i != 0 && system_i != 1) cout << "非法输入，请再次输入" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}
