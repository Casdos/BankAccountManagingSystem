#include"Client.h"
#include"Host.h"
#include"User.h"
#include"Window.h"
int main()
{
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	char system_i = NULL;
	Window window;

	do {
		window.showHomeMean();
		cin >> system_i;
		if (system_i == '0') 
		{
			Host host;
		}
		else if (system_i == '1') 
		{
			User user;
			bool LoginFlag = true;
			while (LoginFlag) {
			care:window.showLogin();
				cin >> ID;
				if (ID == "1") {
					user.create(ID, name, phonenum, email, idnum, cardnum);
					cout << "�ѿ����ɹ�������˻ص�½����" << endl;
					getchar();
					continue;
				}
				else 
				{
					//��ѯ�Ƿ���������˻����������ڣ������������˺�
					Client* position = user.match(ID);
					if (position) goto care;
					LoginFlag = false;
					int choice = 0;
					window.showClientFuncTable();
					cin >> choice;
					switch (choice) {
					case 2:
						position->check();
						break;
					case 3:
						position->modify();
					case 4:
						position->saveMoney();
					case 5:
						position->getMoney();
					case 6:
						position->cancellation();
					default:
						cout << "�Ƿ����룬���ٴ�����" << endl;
					}
				}
			}
		}
		if (system_i != '0' && system_i != '1') cout << "�Ƿ����룬���ٴ�����" << endl;
	} while (system_i != 'q');
	return 0;
}