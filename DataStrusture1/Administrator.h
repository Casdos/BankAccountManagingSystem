#pragma once
#include<vector>
#include<fstream>
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
	void saveToFile(const std::string& filename);//���浽�ļ���������ϢΪ�ļ��������޸��ļ����Զ�����
	bool loadFromFile(const std::string& filename);//���ļ��ж�ȡ������޸����ļ������������Ϣ��������0��

};

