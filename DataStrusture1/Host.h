#pragma once
#include"Administrator.h"
using namespace std;
class Host:public Administrator
{
public:
	Host(string address= "data.csv");
	void browse();
	void find();
	void find(string s);//查找函数，查找完成后输出所有查询结果
};

