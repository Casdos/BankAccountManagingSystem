#pragma once
#include<vector>
#include<iostream>
#include <random>
#include<fstream>
#include"Client.h"
class User
{
private:
	vector<Client> data;
public:
	void create(string ID, string name, string phonenum, string email, string idnum, string cardnum);
	//�����˻�
	Client* match(const string s);//cg:����Ƿ�ƥ��
	void saveToFile(const std::string& filename);//���浽�ļ���������ϢΪ�ļ��������޸��ļ����Զ�����
	bool loadFromFile(const std::string& filename);//���ļ��ж�ȡ������޸����ļ������������Ϣ��������0��
};

