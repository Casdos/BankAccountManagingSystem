#include "Host.h"
Host::Host(string address) :Administrator(address)
{}
void Host::find(string s) {
	bool found = false;
	for (auto& client : data) 
	{
		if (s == client.getID()) {
			cout << "��ѯ���:\n";
			cout << "������ݱ�ʶ��:\t" << client.getID() << endl;
			cout << "��������:\t" << client.getname() << endl;
			cout << "���ĵ绰:\t" << client.getphonenum() << endl;
			cout << "��������:\t" << client.getemail() << endl;
			cout << "�������֤��:\t" << client.getidnum() << endl;
			cout << "�������п���:\t" << client.getcardnum() << endl;
			cout << "�������:\t" << client.getbalance() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "û���ҵ���Ӧ�˺ţ�������˺�" << endl;
	}
}