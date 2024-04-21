#pragma once
#include<vector>
#include<fstream>
#include<random>
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
	void browse();//�������
	void saveToFile(const std::string& filename);//���浽�ļ���������ϢΪ�ļ��������޸��ļ����Զ�����
	bool loadFromFile(const std::string& filename);//���ļ��ж�ȡ������޸����ļ������������Ϣ��������0��
	void create(string ID, string name, string phonenum, string email, string idnum, string cardnum);
	//�����˻�
	Client* match_ID(const string s);//cg:����Ƿ�ƥ��
	Client* match_cardnum(string s);
	bool cancellation(const string s);//cg:ע��

	void find(string s);
};

