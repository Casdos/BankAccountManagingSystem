#include "Host.h"
void Host::find(string s) {
	bool found = false;
	for (auto& client : data) 
	{
		if (s == client.getID()) {
			cout << "查询结果:\n";
			cout << "您的身份标识号:\t" << client.getID() << endl;
			cout << "您的姓名:\t" << client.getname() << endl;
			cout << "您的电话:\t" << client.getphonenum() << endl;
			cout << "您的邮箱:\t" << client.getemail() << endl;
			cout << "您的身份证号:\t" << client.getidnum() << endl;
			cout << "您的银行卡号:\t" << client.getcardnum() << endl;
			cout << "您的余额:\t" << client.getbalance() << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "没有找到对应账号，请核验账号" << endl;
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
		std::cerr << "无法打开文件进行写入。" << std::endl;
	}
}
bool Host::loadFromFile(const std::string& filename) {
	data.clear(); // 清空现有的客户信息
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
		std::cerr << "无法打开文件进行读取。" << std::endl;
		return 0;
	}
}