#pragma once
#include"Administrator.h"
using namespace std;
class Host:public Administrator
{
public:
	Host(string address= "data.csv");
	void browse();
	void find();
	void find(string s);//���Һ�����������ɺ�������в�ѯ���
};

