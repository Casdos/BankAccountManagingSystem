#pragma once
#include<vector>
#include"Client.h"
#include<fstream>
using namespace std;
class Host 
{
private:
	vector<Client> data;
public:
	void browse();
	void find();
	void find(string s);//���Һ�����������ɺ�������в�ѯ���
	void saveToFile(const std::string& filename);//���浽�ļ���������ϢΪ�ļ��������޸��ļ����Զ�����
	bool loadFromFile(const std::string& filename);//���ļ��ж�ȡ������޸����ļ������������Ϣ��������0��
};

