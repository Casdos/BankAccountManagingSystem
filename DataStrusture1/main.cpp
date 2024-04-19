#define _CRT_SECURE_NO_WARNINGS   
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Client {
private:

public:
	void create();
	void check();
	void modify();
	void saveMoney();
	void getMoney();
	void cancellation();
};

class Host {
private:
public:
	void browse();
	void find();
};


int main()
{
	vector <Client> client;
	return 0;
}
