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
	string idnum; // ���֤��
	string cardnum; // ���п���
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
	cout << "\t\t*                      ��ѡ������ϵͳ                        *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*               ����Ա                   �ͻ�                  *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                0                        1                    *" << endl;
	cout << "\t\t================================================================" << endl;
};

void showLogin() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      ���½�����˻�                           *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*					    �˺ţ�                                  *" << endl;
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
		if (system_i != 0 && system_i != 1) cout << "�Ƿ����룬���ٴ�����" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}
