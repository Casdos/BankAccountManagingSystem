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
double Client::getbalance()
{
	return balance;
}
void Client::setPhone() 
{
	string s; 
	cout << "�������޸ĺ�绰��"; 
	cin >> s; 
	phonenum = s; 
}
void Client::setEmail()
{
	string s; cout << "�������޸ĺ��ʼ���"; cin >> s; email = s;
}
void Client::check() {
	cout << "������ݱ�ʶ��:\t" << ID << endl;
	cout << "��������:\t" << name << endl;
	cout << "���ĵ绰:\t" << phonenum << endl;
	cout << "��������:\t" << email << endl;
	cout << "�������֤��:\t" << idnum << endl;
	cout << "�������п���:\t" << cardnum << endl;
	cout << "�������:\t" << fixed<<setprecision(2)<<balance << endl;
}
void Client::modify() {
	char choice = NULL;
	while (choice != 'q') {
		cout << "\t\t================================================================" << endl;
		cout << "\t\t*                          �޸�                                 *" << endl;
		cout << "\t\t*   �޸ĵ绰�밴1                         �޸��ʼ��밴2           *" << endl;
		cout << "\t\t*   ͬʱ�޸��밴3                         �˳��޸��밴q           *" << endl;
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
			cout << "�˳��޸�ģʽ";
			return;
		default:
			cout << "�Ƿ����룬���ٴ�����" << endl;
		}
	}
}
void Client::getMoney()
{
	cout << "������ȡ����:" << endl;
	double m;
	cin >> m;
	if (balance >= m)
	{
		balance = balance - m;
		cout << "ȡ��ɹ���" << endl;
		cout << "��ǰ�˻����Ϊ��" << fixed << setprecision(2) << balance << endl;
	}
	else cout << "��������" << endl;
}

void Client::saveMoney() {
	double deposit;
	cout << "����������:" << endl;
	cin >> deposit;
	balance = balance + deposit;
	cout << "��ǰ�˻����Ϊ��" << fixed << setprecision(2) << balance << endl;
}
void Client::transfer_accounts(Client* target)
{
	double fund;
	while (1)
	{
		cout << "������ת�˽��" << endl;
		cin >> fund;
		if (fund <= 0)
			cout << "�����������������" << endl;
		else
			break;
	}
	if (fund <= 5000) {
		balance -= fund;
	}
	else if (fund > 5000 && fund <= 10000) {
		balance = balance - fund - 5;
	}
	else if (fund > 10000 && fund <= 50000) 
	{
		balance = balance - fund - 7.5;
	}
	else
	{
		balance = balance - fund - fund * 0.00015;
	}
	target->balance += fund;
}