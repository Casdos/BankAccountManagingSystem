#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include<fstream>
using namespace std;

//生成随机数种子,设置为 global 变量
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 9);

class Client {
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // 身份证号
	string cardnum; // 银行卡号
	double balance;
public:
	Client(string IDn = "0", string n = "none", string phone = "0", string e = "@bit.edu", \
		string idn = "0", string cardn = "unknown", int bal = 0) :ID(IDn), \
		name(n), phonenum(phone), email(e), idnum(idn), cardnum(cardn), balance(bal) {};
	void check();
	void modify();
	void saveMoney();
	void getMoney();
	void cancellation(vector<Client>&);
	void transfer(double fund);
	string getID() { return ID; };
	std::string getname();//增添了下列若干个函数用于获得各项信息以存储，要不要干脆类改成public得了
	std::string getphonenum();
	std::string getemail();
	std::string getidnum();
	std::string getcardnum();
	double getbalance();
	void setPhone() { string s; cout << "请输入修改后电话："; cin >> s; phonenum = s; };
	void setEmail() { string s; cout << "请输入修改后邮件："; cin >> s; email = s; };
};
class Host {
private:
public:
	void browse(vector<Client>data);
	void find();
};
void Host::browse(vector<Client>data) {
	int sumt = 0;
	cout << "全体账户列表:" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].getname() << " " << data[i].getbalance() << endl;
		sumt += data[i].getbalance();
	}
	cout << "当前账户的数量：" << data.size() << endl;
	cout << "当前的总存款数：" << sumt << endl;
}
void Client::check() {
	cout << "您的身份标识号:\t" << ID << endl;
	cout << "您的姓名:\t" << name << endl;
	cout << "您的电话:\t" << phonenum << endl;
	cout << "您的邮箱:\t" << email << endl;
	cout << "您的身份证号:\t" << idnum << endl;
	cout << "您的银行卡号:\t" << cardnum << endl;
	cout << "您的余额:\t" << balance << endl;
}
void Client::modify() {
	char choice = NULL;
	while (choice != 'q') {
		cout << "\t\t================================================================" << endl;
		cout << "\t\t*                          修改                                 *" << endl;
		cout << "\t\t*   修改电话请按1                         修改邮件请按2           *" << endl;
		cout << "\t\t*   同时修改请按3                         退出修改请按q           *" << endl;
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
			cout << "退出修改模式";
			return;
		default:
			cout << "非法输入，请再次输入" << endl;
		}
	}
}
void showHomeMean() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请选择进入的系统                        *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*               管理员                   客户                  *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                0                        1                    *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                        退出系统请按q                          *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showLogin() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请登陆您的账户                          *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                       账号：                                 *" << endl;
	cout << "\t\t*                   如无账号，请申请开户（按1）                *" << endl;
	cout << "\t\t*                       退出请按q                              *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showClientFuncTable() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          功能表                              *" << endl;
	cout << "\t\t*        查询：2                               修改：3         *" << endl;
	cout << "\t\t*        存款：4                               取款：5         *" << endl;
	cout << "\t\t*        销户：6                               转账：9         *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showHostFuncTable() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          功能表                              *" << endl;
	cout << "\t\t*        浏览：7                               查找：8         *" << endl;
	cout << "\t\t================================================================" << endl;
};
int match(vector<Client>::iterator begin, vector<Client>::iterator end, string s) {
	int i = 0;
	for (; begin != end; begin++, i++) {
		if (s == (*begin).getID()) return i;
	}
	if (begin == end) {
		cout << "没有找到对应账号,请核验账号" << endl;
		return -1;
	}
};
int matchcardnum(vector<Client>::iterator begin, vector<Client>::iterator end, string s) {
	int i = 0;
	for (; begin != end; begin++, i++) {
		if (s == (*begin).getcardnum()) return i;
	}
	if (begin == end) {
		cout << "没有找到对应账号,请核验账号" << endl;
		return -1;
	}
};//通过输入的银行卡号匹配账户
void create(string ID, string name, string phonenum, string email, string idnum, string cardnum, vector<Client>& vec) {
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
	for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
	cout << cardnum;//告诉开户人银行卡号
	vec.push_back(Client(ID, name, phonenum, email, idnum, cardnum));
};
int main()
{
	vector <Client> user;
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	char system_i = NULL;
	bool LoginFlag = true;


	do {
		showHomeMean();
		cin >> system_i;
		if (system_i == '0') {
			int choice = 0;
			showHostFuncTable();
			while (1){			
			cin >> choice;
			switch (choice) {
			case 7:
				Host::browse(user);
				break;
			case 8:
		
				break;
			default:
				cout << "非法输入，请再次输入" << endl;
				}
			}
		}
		if (system_i == '1') {
			while (LoginFlag) {
			care:showLogin();
				cin >> ID;
				if (ID == "1") {
					create(ID, name, phonenum, email, idnum, cardnum, user);
					cout << "已开户成功，点击退回登陆界面" << endl;
					getchar();
					continue;
				}
				else {
					//查询是否存在输入账户，若不存在，则重新输入账号
					int position = match(user.begin(), user.end(), ID);
					if (position == -1) goto care;
					LoginFlag = false;
					int choice = 0;
					showClientFuncTable();
					cin >> choice;
					switch (choice) {
					case 2:
						user[position].check();
						break;
					case 3:
						user[position].modify();
						break;
					case 4:
						user[position].saveMoney();
						break;
					case 5:
						user[position].getMoney();
						break;
					case 6:
						user[position].cancellation(user);
						break;
					case 9:
					{
						int i;
						string cardnum1;
						cout << "请输入转入账户" << endl;
						cin >> cardnum1;
						i = matchcardnum(user.begin(), user.end(), cardnum1);
						double fund, balance_1, balance_2;
						balance_1 = user[position].getbalance();
						cout << "请输入转账金额" << endl;
						cin >> fund;
						if (fund <= 5000) {
							balance_1 = balance_1 - fund;
						}
						if (fund > 5000 && fund <= 10000) {
							balance_1 = balance_1 - fund - 5;
						}
						if (fund > 10000 && fund <= 50000) {
							balance_1 = balance_1 - fund - 7.5;
						}
						if (fund > 50000) {
							balance_1 = balance_1 - fund - fund * 0.00015;
						}
						user[position].transfer(balance_1);
						balance_2 = user[i].getbalance();
						balance_2 = balance_2 + fund;
						user[i].transfer(balance_2);
						break;
					}
					default:
						cout << "非法输入，请再次输入" << endl;
					}
				}




			}
		}
		if (system_i != '0' && system_i != '1' && system_i != 'q') cout << "非法输入，请再次输入" << endl;
	} while (system_i != 'q');
	return 0;
}




void Client::getMoney()
{
	cout << "请输入取款金额:" << endl;
	double m;
	cin >> m;
	if (balance >= m)
	{
		balance = balance - m;
		cout << "取款成功！" << endl;
		cout << "当前账户余额为：" << balance << endl;
	}
	else cout << "您的余额不足" << endl;
}

void Client::saveMoney() {
	double deposit;
	cout << "请输入存款金额:" << endl;
	cin >> deposit;
	balance = balance + deposit;
	cout << "当前账户余额为：" << balance << endl;
}

//wuhanhan: 要删除这个对应的vector元素，可能需要传指针或者什么其他的
void Client::cancellation(vector<Client>& user) {
	auto it = find(user.begin(), user.end(), *this);
	if (it != user.end() && (*it).getbalance() == 0) {
		user.erase(it);
		cout << "账户已成功注销" << endl;
		ID = "0";
		name = "none";
		phonenum = "0";
		email = "@bit.edu";
		idnum = "0";
		cardnum = "unknown";
		balance = 0;
	}
	else {
		cout << "无法办理销户" << endl;
	}
}
void Client::transfer(double fund) {
	balance =  fund;//zengyunqiao：应该是balance +=  fund？
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
double Client::getbalance()
{
	return balance;
}
void saveToFile(const std::string& filename, vector<Client> data)
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
bool loadFromFile(const std::string& filename, vector<Client> data) {
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
