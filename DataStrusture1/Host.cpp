#include "Host.h"
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
void Host::saveToFile(const std::string& filename)
{
	std::ofstream outfile(filename, std::ios::out | std::ios::app);
	if (outfile.is_open()) {
		outfile.seekp(0, std::ios::beg);
		for (auto& client : data) {
			outfile << client.getID() << "," << client.getname() << "," << client.getphonenum() << "," << client.getemail() << "," << client.getidnum() << "," << client.getcardnum() << "," << client.getbalance() << std::endl;
		}
		outfile.close();
	}
	else {
		std::cerr << "�޷����ļ�����д�롣" << std::endl;
	}
}
bool Host::loadFromFile(const std::string& filename) {
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