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

void Client::check() {
	cout << "������ݱ�ʶ��:\t" << ID << endl;
	cout << "��������:\t" << name << endl;
	cout << "���ĵ绰:\t" << phonenum << endl;
	cout << "��������:\t" << email << endl;
	cout << "�������֤��:\t" << name << endl;
	cout << "�������п���:\t" << name << endl;
	cout << "�������:\t" << name << endl;
}

void Client::modify() {

}

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
	cout << "\t\t*                      ���½�����˻�                          *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                       �˺ţ�                                 *" << endl;
	cout << "\t\t*                   �����˺ţ������뿪������1��                *" << endl;
	cout << "\t\t================================================================" << endl;
};

int main()
{
	vector <Client> user;
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	int system_i = -1;
	bool LoginFlag = true;
	//�������������
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
					cout << "������������ݱ�ʶ�ţ�";
					cin >> ID;
					cout << "����������������";
					cin >> name;
					cout << "���������ĵ绰��";
					cin >> phonenum;
					cout << "���������ĵ������䣺";
					cin >> email;
					cout << "�������������֤�ţ�";
					cin >> idnum;
					//�������16λ���п���
					for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
					user.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
					cout << "�ѿ����ɹ�������˻ص�½����" << endl;
					getchar();
					continue;
				}
				else {
					//��ѯ�Ƿ���������˻�
					int position = 0;

					LoginFlag = false;
					int choice = 0;
					//ѡ����
					cout << "\t\t================================================================" << endl;
					cout << "\t\t*                          ���ܱ�                              *" << endl;
					cout << "\t\t*        ��ѯ��2                               �޸ģ�3         *" << endl;
					cout << "\t\t*        ��4                               ȡ�5         *" << endl;
					cout << "\t\t*        ������6                                               *" << endl;
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
						cout << "�Ƿ����룬���ٴ�����" << endl;
					}
				}

			}
		}
		if (system_i != 0 && system_i != 1) cout << "�Ƿ����룬���ٴ�����" << endl;
	} while (system_i != 0 && system_i != 1);
	return 0;
}
