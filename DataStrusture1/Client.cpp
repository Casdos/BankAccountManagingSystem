#include "Client.h"
using namespace std;
std::string Client::getID() 
{ 
	return ID; 
}
std::string Client::getname()
{
	return name;
}
std::string Client::getphonenum()
{
	return phonenum;
}
std::string Client::getemail()
{
	return email;
}
std::string Client::getidnum()
{
	return idnum;
}
std::string Client::getcardnum()
{
	return cardnum;
}
int Client::getbalance()
{
	return balance;
}
void Client::setPhone() 
{
	std::string s; 
	std::cout << "�������޸ĺ�绰��"; 
	std::cin >> s; 
	phonenum = s; 
}
void Client::setEmail()
{
	std::string s; std::cout << "�������޸ĺ��ʼ���"; std::cin >> s; email = s;
}
void Client::check() {
	std::cout << "������ݱ�ʶ��:\t" << ID << std::endl;
	std::cout << "��������:\t" << name << std::endl;
	std::cout << "���ĵ绰:\t" << phonenum << std::endl;
	std::cout << "��������:\t" << email << std::endl;
	std::cout << "�������֤��:\t" << idnum << std::endl;
	std::cout << "�������п���:\t" << cardnum << std::endl;
	std::cout << "�������:\t" << balance << std::endl;
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
		//wuhanhan:���лᱨ������ע�͵�.���⣬if���{}û��ƥ��
		//bal = 0;cg:����Ϊ�����гɹ�ע�͵���{}����ƥ����
	}
	else cout << "�޷���������" << endl;
	}
