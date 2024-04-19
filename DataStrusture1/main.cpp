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
	cout << "\t\t*                   �����˺ţ������뿪������1��                   *" << endl;
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
				cout << "�������������֤��ʶ�ţ�";
				cin >> ID;
				cout << "����������������";
				cin >> name;
				cout << "���������ĵ绰��";
				cin >> phonenum;
				cout << "���������ĵ������䣺";
				cin >> email;
				cout << "�������������֤�ţ�";
				cin >> idnum;
				user.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
				cout << "�ѿ����ɹ�������˻ص�½����" << endl;
				getchar();
			}
			showLogin();
		}
		if (system_i != 0 && system_i != 1) cout << "�Ƿ����룬���ٴ�����" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}
