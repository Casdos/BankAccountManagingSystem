#include"Client.h"
#include"Window.h"
#include"Administrator.h"
int main()
{
	string ID, name, phonenum, email, idnum, cardnum;
	double balance = 0;
	string system_i;
	Window window;//�������ڶ��󣬵��ô��ں���
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
					cout << "��������ҵ��˻�" << endl;
					string name;
					cin >> name;
					admin.find(name);
					continue;
				}
				else if (choice == "10")
				{
					cout << "����������ַ" << endl;
					string address;
					cin >> address;
					admin.loadFromFile(address);
					cout << "����ɹ�" << endl;
					continue;
				}
				else if (choice == "11")
				{
					cout << "�����������ַ" << endl;
					string address;
					cin >> address;
					admin.saveToFile(address);
					cout << "�����ɹ�" << endl;
					continue;
				}
				else if (choice == "q")
				{
					break;
				}
				cout << "�Ƿ����룬���ٴ�����" << endl;
			}
		}
		else if (system_i == "1")
		{
			while (1)
			{
				window.showLogin();
				cin >> ID;
					if (ID == "1") {
						admin.create();
						cout << "�ѿ����ɹ�������˻ص�½����" << endl;
						getchar();
						continue;
					}
				else if (ID == "q")
					break;
				else
				{
					//��ѯ�Ƿ���������˻����������ڣ������������˺�
					Client* position = admin.match_ID(ID);
					if (position == nullptr)
					{
						cout << "���˻�������" << endl;
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
									cout << "�����ɹ���" << endl;
									break;
								}
								else
								{
									cout << "���˻�����������ʧ�ܣ�" << endl;
									continue;
								}
							}
							else if (choice == "9")
							{
								Client* target=nullptr;
								string cardnum_t;
								while (1)
								{
									cout << "������ת���˻�" << endl;
									cin >> cardnum_t;
									if (cardnum_t == "q")
										break;
									target = admin.match_cardnum(cardnum_t);
									if (target != nullptr)
										break;
									cout << "�˻������ڣ������������q�˳�" << endl;
								}
								if (cardnum_t == "q")
									continue;
								position->transfer_accounts(target);
								cout << "ת�˳ɹ���" << endl;

							}
							else if (choice == "q")
								break;
							else
								cout << "�Ƿ����룬���ٴ�����" << endl;
						}
					}
				}
			}
		}
		else if (system_i == "q")
			break;
		else
			cout << "�Ƿ����룬���ٴ�����" << endl;
		
	}
	return 0;
}