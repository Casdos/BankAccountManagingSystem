#include "User.h"
User::User(string address):Administrator(address)
{
}
void User::create(string ID, string name, string phonenum, string email, string idnum, string cardnum) {
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
	//�������������,����Ϊ global ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 9);
	for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
	data.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
}
Client* User::match(const string s)
{
	bool found = false;
	for (auto& client : data) 
	{
		{
			if (s == client.getID())
			{
				return &client;
			}
		}
		cout << "û���ҵ���Ӧ�˺�,������˺�" << endl;
		return nullptr;
	}
}
//wuhanhan: Ҫɾ�������Ӧ��vectorԪ�أ�������Ҫ��ָ�����ʲô������
bool User::cancellation() 
{
	string s = "1";//�����⣬�Ȼ��
	for (auto it = data.begin(); it != data.end(); ) {
		if (it->getID() == s) {
			// ɾ����ǰԪ��
			if (it->getbalance() == 0)
			{
				it = data.erase(it);
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else {
			it++;
		}
	}
	return 0;
}
