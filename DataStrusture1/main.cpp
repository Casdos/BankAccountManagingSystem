#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include<fstream>
using namespace std;

//�������������,����Ϊ global ����
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0, 9);

class Client {
private:
	string ID;
	string name;
	string phonenum;
	string email;
	string idnum; // ���֤��
	string cardnum; // ���п���
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
	std::string getname();//�������������ɸ��������ڻ�ø�����Ϣ�Դ洢��Ҫ��Ҫ�ɴ���ĳ�public����
	std::string getphonenum();
	std::string getemail();
	std::string getidnum();
	std::string getcardnum();
	double getbalance();
	void setPhone() { string s; cout << "�������޸ĺ�绰��"; cin >> s; phonenum = s; };
	void setEmail() { string s; cout << "�������޸ĺ��ʼ���"; cin >> s; email = s; };
};
class Host {
private:
public:
	void browse(vector<Client>data);
	void find();
};
void Host::browse(vector<Client>data) {
	int sumt = 0;
	cout << "ȫ���˻��б�:" << endl;
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i].getname() << " " << data[i].getbalance() << endl;
		sumt += data[i].getbalance();
	}
	cout << "��ǰ�˻���������" << data.size() << endl;
	cout << "��ǰ���ܴ������" << sumt << endl;
}
void Client::check() {
	cout << "������ݱ�ʶ��:\t" << ID << endl;
	cout << "��������:\t" << name << endl;
	cout << "���ĵ绰:\t" << phonenum << endl;
	cout << "��������:\t" << email << endl;
	cout << "�������֤��:\t" << idnum << endl;
	cout << "�������п���:\t" << cardnum << endl;
	cout << "�������:\t" << balance << endl;
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
void showHomeMean() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      ��ѡ������ϵͳ                        *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*               ����Ա                   �ͻ�                  *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                0                        1                    *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                        �˳�ϵͳ�밴q                          *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showLogin() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      ���½�����˻�                          *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                       �˺ţ�                                 *" << endl;
	cout << "\t\t*                   �����˺ţ������뿪������1��                *" << endl;
	cout << "\t\t*                       �˳��밴q                              *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showClientFuncTable() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          ���ܱ�                              *" << endl;
	cout << "\t\t*        ��ѯ��2                               �޸ģ�3         *" << endl;
	cout << "\t\t*        ��4                               ȡ�5         *" << endl;
	cout << "\t\t*        ������6                               ת�ˣ�9         *" << endl;
	cout << "\t\t================================================================" << endl;
};
void showHostFuncTable() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          ���ܱ�                              *" << endl;
	cout << "\t\t*        �����7                               ���ң�8         *" << endl;
	cout << "\t\t================================================================" << endl;
};
int match(vector<Client>::iterator begin, vector<Client>::iterator end, string s) {
	int i = 0;
	for (; begin != end; begin++, i++) {
		if (s == (*begin).getID()) return i;
	}
	if (begin == end) {
		cout << "û���ҵ���Ӧ�˺�,������˺�" << endl;
		return -1;
	}
};
int matchcardnum(vector<Client>::iterator begin, vector<Client>::iterator end, string s) {
	int i = 0;
	for (; begin != end; begin++, i++) {
		if (s == (*begin).getcardnum()) return i;
	}
	if (begin == end) {
		cout << "û���ҵ���Ӧ�˺�,������˺�" << endl;
		return -1;
	}
};//ͨ����������п���ƥ���˻�
void create(string ID, string name, string phonenum, string email, string idnum, string cardnum, vector<Client>& vec) {
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
	for (int i = 0; i < 16; i++) cardnum += to_string(dis(gen));
	cout << cardnum;//���߿��������п���
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
				cout << "�Ƿ����룬���ٴ�����" << endl;
				}
			}
		}
		if (system_i == '1') {
			while (LoginFlag) {
			care:showLogin();
				cin >> ID;
				if (ID == "1") {
					create(ID, name, phonenum, email, idnum, cardnum, user);
					cout << "�ѿ����ɹ�������˻ص�½����" << endl;
					getchar();
					continue;
				}
				else {
					//��ѯ�Ƿ���������˻����������ڣ������������˺�
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
						cout << "������ת���˻�" << endl;
						cin >> cardnum1;
						i = matchcardnum(user.begin(), user.end(), cardnum1);
						double fund, balance_1, balance_2;
						balance_1 = user[position].getbalance();
						cout << "������ת�˽��" << endl;
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
						cout << "�Ƿ����룬���ٴ�����" << endl;
					}
				}




			}
		}
		if (system_i != '0' && system_i != '1' && system_i != 'q') cout << "�Ƿ����룬���ٴ�����" << endl;
	} while (system_i != 'q');
	return 0;
}




void Client::getMoney()
{
	cout << "������ȡ����:" << endl;
	double m;
	cin >> m;
	if (balance >= m)
	{
		balance = balance - m;
		cout << "ȡ��ɹ���" << endl;
		cout << "��ǰ�˻����Ϊ��" << balance << endl;
	}
	else cout << "��������" << endl;
}

void Client::saveMoney() {
	double deposit;
	cout << "����������:" << endl;
	cin >> deposit;
	balance = balance + deposit;
	cout << "��ǰ�˻����Ϊ��" << balance << endl;
}

//wuhanhan: Ҫɾ�������Ӧ��vectorԪ�أ�������Ҫ��ָ�����ʲô������
void Client::cancellation(vector<Client>& user) {
	auto it = find(user.begin(), user.end(), *this);
	if (it != user.end() && (*it).getbalance() == 0) {
		user.erase(it);
		cout << "�˻��ѳɹ�ע��" << endl;
		ID = "0";
		name = "none";
		phonenum = "0";
		email = "@bit.edu";
		idnum = "0";
		cardnum = "unknown";
		balance = 0;
	}
	else {
		cout << "�޷���������" << endl;
	}
}
void Client::transfer(double fund) {
	balance =  fund;//zengyunqiao��Ӧ����balance +=  fund��
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
		std::cerr << "�޷����ļ�����д�롣" << std::endl;
	}
}
bool loadFromFile(const std::string& filename, vector<Client> data) {
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
