#include "Window.h"
using namespace std;
void Window::showLogin() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请登陆您的账户                          *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                       账号：                                 *" << endl;
	cout << "\t\t*                   如无账号，请申请开户（按1）                *" << endl;
	cout << "\t\t*                       退出请按q                              *" << endl;
	cout << "\t\t================================================================" << endl;
}
void Window::showClientFuncTable()
{
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          功能表                              *" << endl;
	cout << "\t\t*        查询：2                               修改：3         *" << endl;
	cout << "\t\t*        存款：4                               取款：5         *" << endl;
	cout << "\t\t*        销户：6                               转账：9         *" << endl;
	cout << "\t\t*                       退出请按q                              *" << endl;
	cout << "\t\t================================================================" << endl;
};
void Window::showHomeMean()
{
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                      请选择进入的系统                        *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*               管理员                   客户                  *" << endl;
	cout << "\t\t*                                                              *" << endl;
	cout << "\t\t*                0                        1                    *" << endl;
	cout << "\t\t*                       退出请按q                              *" << endl;
	cout << "\t\t================================================================" << endl;
}
void Window::showHostFuncTable() {
	cout << "\t\t================================================================" << endl;
	cout << "\t\t*                          功能表                              *" << endl;
	cout << "\t\t*        浏览：7                               查找：8         *" << endl;
	cout << "\t\t*        导入：10                              导出：11        *" << endl;
	cout << "\t\t*                       退出请按q                              *" << endl;
	cout << "\t\t================================================================" << endl;
};
