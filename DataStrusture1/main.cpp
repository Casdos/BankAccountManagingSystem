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
	//Client(string ID,):ID()
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
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t================================================================" << endl;
};

int main()
{
	vector <Client> client;
	int system_i = -1;
	string ID;
	do {
		showIniMean();
		cin >> system_i;
		if (system_i == 0) {

		}
		if (system_i == 1) {
			showLogin();
			cin >> ID;
		}
		if (system_i != 0 && system_i != 1) cout << "非法输入，请再次输入" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}
