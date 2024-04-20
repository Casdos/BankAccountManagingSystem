#include "User.h"
void User::create(string ID, string name, string phonenum, string email, string idnum, string cardnum) {
	cout << "请设置您的身份标识号：";
	cin >> ID;
	cout << "请输入您的姓名：";
	cin >> name;
	cout << "请输入您的电话：";
	cin >> phonenum;
	cout << "请输入您的电子邮箱：";
	cin >> email;
	cout << "请输入您的身份证号：";
	cin >> idnum;
	//随机生成16位银行卡号
	//生成随机数种子,设置为 global 变量
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
		cout << "没有找到对应账号,请核验账号" << endl;
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
		std::cerr << "无法打开文件进行写入。" << std::endl;
	}
}
bool User::loadFromFile(const std::string& filename) {
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