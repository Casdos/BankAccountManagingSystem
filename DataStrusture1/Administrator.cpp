#include "Administrator.h"
Administrator::Administrator(string address):address(address)
{
	loadFromFile(address);
}
Administrator::~Administrator()
{
	saveToFile(address);
}
void Administrator::browse()
{
	double sumt = 0;
	cout << "ȫ���˻��б�:" << endl;
	cout << "ID" << "\t" << "����" << "\t" << "���" << "\t" << "���п���" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].getID() << "\t" << data[i].getname() << "\t" << fixed << setprecision(2) << data[i].getbalance() << "\t" << data[i].getcardnum() << endl;
		sumt += data[i].getbalance();
	}
	cout << "��ǰ�˻���������" << data.size() << endl;
	cout << "��ǰ���ܴ������" << fixed << setprecision(2) << sumt << endl;
}
void Administrator::saveToFile(const std::string& filename)
{
	std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
	if (outfile.is_open()) {
		for (auto& client : data) {
			outfile << client.getID() << "," << client.getname() << "," << client.getphonenum() << "," << client.getemail() << "," << client.getidnum() << "," << client.getcardnum() << "," << client.getbalance() << std::endl;
		}
		outfile.close();
	}
	else {
		std::cerr << "�޷����ļ�����д�롣" << std::endl;
	}
}
bool Administrator::loadFromFile(const std::string& filename) {
	data.clear(); // ������еĿͻ���Ϣ
	std::ifstream infile(filename);
	if (infile.is_open()) {
		std::string line;
		while (std::getline(infile, line)) {
			size_t pos = line.find(",");
			std::string ID = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			std::string name = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			std::string phonenum = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			std::string email = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			std::string idnum = line.substr(0, pos);
			line.erase(0, pos + 1);

			pos = line.find(",");
			std::string cardnum = line.substr(0, pos);
			line.erase(0, pos + 1);

			double balance = std::stoi(line);
			data.emplace_back(ID, name, phonenum, email, idnum, cardnum);
		}
		infile.close();
		return 1;
	}
	else {
		std::cerr << "�޷����ļ����ж�ȡ��" << std::endl;
		return 0;
	}
}
void Administrator::create() 
{
	string ID,name, phonenum, email, idnum, cardnum;
	cout << "������������ݱ�ʶ�ţ�";
	while (1)
	{
		cin >> ID;
		if (match_ID == nullptr)
			break;
		else
		cout << "�û����ظ����������µ��û�����" << endl;
	}
	
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
	cout << "�ѿ����ɹ����������п����ǣ�" << cardnum << endl;
	data.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
}
Client* Administrator::match_ID(const string s)
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
	}
	cout << "û���ҵ���Ӧ�˺�,������˺�" << endl;
	return nullptr;
}
bool Administrator::cancellation(const string s)
{
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
Client* Administrator::match_cardnum(string s)
{
	bool found = false;
	for (auto& client : data)
	{
		{
			if (s == client.getcardnum())
			{
				return &client;
			}
		}
		cout << "û���ҵ���Ӧ�˺�,������˺�" << endl;
		return nullptr;
	}
}//ͨ����������п���ƥ���˻�
void Administrator::find(string s)
{
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
				cout << "�������:\t" << fixed << setprecision(2) << client.getbalance() << endl;
				found = true;
				break;
			}
		}
		if (!found) 
		{
			cout << "û���ҵ���Ӧ�˺ţ�������˺�" << endl;
		}
}