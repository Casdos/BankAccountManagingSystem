#include "User.h"
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
void User::saveToFile(const std::string& filename)
{
	std::ofstream outfile(filename, std::ios::out | std::ios::app);
	if (outfile.is_open()) {
		outfile.seekp(0, std::ios::beg);
		for ( auto& client : data) {
			outfile << client.getID() << "," << client.getname() << "," << client.getphonenum() << "," << client.getemail() << "," << client.getidnum() << "," << client.getcardnum() << "," << client.getbalance() << std::endl;
		}
		outfile.close();
	}
	else {
		std::cerr << "�޷����ļ�����д�롣" << std::endl;
	}
}
bool User::loadFromFile(const std::string& filename) {
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

			int balance = std::stoi(line);
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