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
	cout << "�������޸ĺ�绰��"; 
	cin >> s; 
	phonenum = s; 
}
void Client::setEmail()
{
	string s; cout << "�������޸ĺ��ʼ���"; cin >> s; email = s;
}
void Client::check() {
	cout << "�������ݱ�ʶ��:\t" << ID << endl;
	cout << "��������:\t" << name << endl;
	cout << "���ĵ绰:\t" << phonenum << endl;
	cout << "��������:\t" << email << endl;
	cout << "��������֤��:\t" << idnum << endl;
	cout << "�������п���:\t" << cardnum << endl;
	cout << "�������:\t" << balance << endl;
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
	int m;
	// wuhanhan:ԭ��Ϊcin<<m,���޸���һ�£�cin>>m ���֪���Ϳ���ɾ��
	cin >> m;
	//wuhanhan:�ǲ��Ǹĳ� >=
	if (balance > m)
	{
		balance = balance - m;
		cout << "ȡ��ɹ���" << endl;
		cout << "��ǰ�˻����Ϊ��" << balance << endl;
	}
	else cout << "��������" << endl;
}

void Client::saveMoney() {
	int deposit;
	cout << "����������:" << endl;
	cin >> deposit;
	balance = balance + deposit;
	cout << "��ǰ�˻����Ϊ��" << balance << endl;
}

//wuhanhan: Ҫɾ�������Ӧ��vectorԪ�أ�������Ҫ��ָ�����ʲô������
void Client::cancellation() {
	if (balance == 0) {
		cout << "�˻��ѳɹ�ע��" << endl;
		ID = "0";
		name = "none";
		phonenum = "0";
		email = "@bit.edu";
		idnum = "0";
		cardnum = "unknown";
		//wuhanhan:���лᱨ��������ע�͵�.���⣬if���{}û��ƥ��
		//bal = 0;cg:����Ϊ�����гɹ�ע�͵���{}����ƥ����
	}
	else cout << "�޷���������" << endl;
	}