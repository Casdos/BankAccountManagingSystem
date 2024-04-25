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
	cout << "全体账户列表:" << endl;
	cout << "ID" << "\t" << "姓名" << "\t" << "余额" << "\t" << "银行卡号" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].getID() << "\t" << data[i].getname() << "\t" << fixed << setprecision(2) << data[i].getbalance() << "\t" << data[i].getcardnum() << endl;
		sumt += data[i].getbalance();
	}
	cout << "当前账户的数量：" << data.size() << endl;
	cout << "当前的总存款数：" << fixed << setprecision(2) << sumt << endl;
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
		std::cerr << "无法打开文件进行写入。" << std::endl;
	}
}
bool Administrator::loadFromFile(const std::string& filename) {
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

			double balance = std::stoi(line);
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
void Administrator::create() 
{
	string ID,name, phonenum, email, idnum, cardnum;
	cout << "请设置您的身份标识号：";
	while (1)
	{
		cin >> ID;
		if (match_ID == nullptr)
			break;
		else
		cout << "用户名重复，请设置新的用户名。" << endl;
	}
	
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
	cout << "已开户成功，您的银行卡号是：" << cardnum << endl;
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
	cout << "没有找到对应账号,请核验账号" << endl;
	return nullptr;
}
bool Administrator::cancellation(const string s)
{
	for (auto it = data.begin(); it != data.end(); ) {
		if (it->getID() == s) {
			// 删除当前元素
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
		cout << "没有找到对应账号,请核验账号" << endl;
		return nullptr;
	}
}//通过输入的银行卡号匹配账户
void Administrator::find(string s)
{
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
				cout << "您的余额:\t" << fixed << setprecision(2) << client.getbalance() << endl;
				found = true;
				break;
			}
		}
		if (!found) 
		{
			cout << "没有找到对应账号，请核验账号" << endl;
		}
}