#include"Client.h"
<<<<<<< Updated upstream
#include"Host.h"
#include"User.h"
#include"Window.h"
int main()
{

	Host host;
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
=======
#include"Window.h"
#include"Administrator.h"
int main()
{
	string ID, name, phonenum, email, idnum, cardnum;
	int balance = 0;
	string system_i;
	Window window;//创建窗口对象，调用窗口函数
	Administrator admin;
	while (1)
	{
		window.showHomeMean();
		cin >> system_i;
		if (system_i == "0")
		{
			while (1)
			{
				window.showHostFuncTable();
				string choice;
				cin >> choice;
				if (choice == "7")
				{
					admin.browse();
					continue;
				}
				else if (choice == "8")
				{
					cout << "请输出查找的账户" << endl;
					string name;
					cin >> name;
					admin.find(name);
					continue;
				}
				else if (choice == "q")
				{
					break;
				}
				cout << "非法输入，请再次输入" << endl;
			}
		}
		else if (system_i == "1")
		{
			while (1)
			{
				window.showLogin();
				cin >> ID;
				if (ID == "1") {
					admin.create(ID, name, phonenum, email, idnum, cardnum);
>>>>>>> Stashed changes
					cout << "已开户成功，点击退回登陆界面" << endl;
					getchar();
					continue;
				}
<<<<<<< Updated upstream
				else 
				{
					//查询是否存在输入账户，若不存在，则重新输入账号
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
<<<<<<< Updated upstream
						user.cancellation();
=======
						user.cancellation(ID);
>>>>>>> Stashed changes
					default:
						cout << "非法输入，请再次输入" << endl;
=======
				else if (ID == "q")
					break;
				else
				{
					//查询是否存在输入账户，若不存在，则重新输入账号
					Client* position = admin.match_ID(ID);
					if (position == nullptr)
					{
						cout << "此账户不存在" << endl;
						continue;
					}
					else
					{
						string choice;
						while (1)
						{
							window.showClientFuncTable();
							cin >> choice;
							if (choice == "2")
							{
								position->check();
								continue;
							}
							else if (choice == "3")
							{
								position->modify();
								continue;
							}
							else if (choice == "4")
							{
								position->saveMoney();
								continue;
							}
							else if (choice == "5")
							{
								position->getMoney();
								continue;
							}
							else if (choice == "6")
							{
								if (admin.cancellation(ID))
								{
									cout << "销户成功！" << endl;
									break;
								}
								else
								{
									cout << "此账户仍有余额，销户失败！" << endl;
									continue;
								}
							}
							else if (choice == "9")
							{
								Client* target=nullptr;
								string cardnum_t;
								while (1)
								{
									cout << "请输入转入账户" << endl;
									cin >> cardnum_t;
									if (cardnum_t == "q")
										break;
									target = admin.match_cardnum(cardnum_t);
									if (target != nullptr)
										break;
									cout << "账户不存在！请重新输入或按q退出" << endl;
								}
								if (cardnum_t == "q")
									continue;
								position->transfer_accounts(target);
								cout << "转账成功！" << endl;

							}
							else if (choice == "q")
								break;
							else
								cout << "非法输入，请再次输入" << endl;
						}
>>>>>>> Stashed changes
					}
				}
			}
		}
<<<<<<< Updated upstream
		if (system_i != '0' && system_i != '1') cout << "非法输入，请再次输入" << endl;
	} while (system_i != 'q');
	return 0;
=======
		else if (system_i == "q")
			break;
		else
			cout << "非法输入，请再次输入" << endl;
		return 0;
	}
>>>>>>> Stashed changes
}