#pragma once
#include<vector>
#include<fstream>
<<<<<<< Updated upstream
=======
#include<random>
>>>>>>> Stashed changes
#include"Client.h"
using namespace std;
class Administrator
{
protected:
	vector<Client> data;
	string address;
public:
	Administrator(string address="data.csv");
	~Administrator();
<<<<<<< Updated upstream
	void saveToFile(const std::string& filename);//保存到文件，参数信息为文件名，如无该文件将自动创建
	bool loadFromFile(const std::string& filename);//从文件中读取，如果无给定文件将输出报错信息，并返回0；
=======
	void browse();//浏览函数
	void saveToFile(const std::string& filename);//保存到文件，参数信息为文件名，如无该文件将自动创建
	bool loadFromFile(const std::string& filename);//从文件中读取，如果无给定文件将输出报错信息，并返回0；
	void create(string ID, string name, string phonenum, string email, string idnum, string cardnum);
	//创建账户
	Client* match_ID(const string s);//cg:检查是否匹配
	Client* match_cardnum(string s);
	bool cancellation(const string s);//cg:注销

	void find(string s);
>>>>>>> Stashed changes

};

