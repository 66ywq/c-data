#include "../../Heads/Menu/AdminMenu.h"

// 全局变量：当前管理员用户
AdminUser* currentUser = NULL;

// 函数声明：保证子菜单不能被外界调用
void adminMenu();
void listAccountMenu();
void delAccountMenu();
void resetPasswordMenu();

// 函数主体
void loadAdminMenu(AdminUser* u) {
	currentUser = u;
	OperateAccount::refresh();
	adminMenu();
}

void adminMenu() {
	system("cls");
	setTextColor(Color::LIGHTYELLOW);

	printf("%52s\n", "*==================================================*");
	printf("%s%38s%13s\n", "*", "欢迎使用通讯录账号管理系统", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%30s%21s\n", "*", "1.查看账号", "*");
	printf("%s%30s%21s\n", "*", "2.删除账号", "*");
	printf("%s%30s%21s\n", "*", "3.重置密码", "*");
	printf("%s%30s%21s\n", "*", "4.登出系统", "*");
	printf("%s%30s%21s\n", "*", "0.退出系统", "*");
	printf("%52s\n", "*==================================================*");
	cout << "请输入您的选择（0-4）：";

	int selection = -1;

	while (true) {
		cin >> selection;

		switch (selection) {
		case 1:
			listAccountMenu();
			break;
		case 2:
			delAccountMenu();
			break;
		case 3:
			resetPasswordMenu();
			break;
		case 4:
			currentUser = NULL;
			cout << "登出成功！即将返回主菜单！" << endl;
			Sleep(500);
			returnToMainMenu();
			break;
		case 0:
			cout << "谢谢您的使用！";
			Sleep(1000);
			exit(0);
		default:
			cout << "你输入的选项有误，请重新输入：";
			break;
		}

		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void listAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "您选择了账号查看功能", "*");
	printf("%s%31s%20s\n", "*", "账号列表如下", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "管理员用户：" << endl;
	OperateAccount::listAdminUser();
	cout << "普通用户：" << endl;
	OperateAccount::listUser();
	cout << endl;

	cout << "输入任意信息返回上级菜单" << endl;
	system("pause");
	adminMenu();
}

void delAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "您选择了账号删除功能", "*");
	printf("%s%35s%16s\n", "*", "请输入需要删除的账号", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "账号由5-16位由数字、字母组成" << endl;
	cout << "账号中输入exit则终止操作，返回主菜单" << endl;
	cout << "请输入需要删除的账号！" << endl << endl;

	string account;

	while (true) {
		cout << "账号：";
		if (inputAccount(account)) {
			if (account.compare("exit") == 0) {
				cout << "您选择了退出，即将返回上级菜单" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			switch (OperateAccount::removeAccount(account)) {
			case -2:
				setTextColor(Color::LIGHTRED);
				cout << "必须存在一个管理员用户，无法删除！" << endl;
				break;
			case -1:
				setTextColor(Color::LIGHTRED);
				cout << "账号不存在，无法删除！" << endl;
				break;
			case 0:
				cout << "成功删除普通用户：" << account << "！" << endl;
				cout << "即将返回上级菜单！" << endl;
				Sleep(1000);
				adminMenu();
				break;
			case 1:
				cout << "成功删除管理员用户：" << account << "！" << endl;
				cout << "即将返回上级菜单！" << endl;
				Sleep(1000);
				adminMenu();
				break;
			default:
				setTextColor(Color::LIGHTRED);
				break;
			}
		}
		setTextColor(Color::LIGHTRED);
		cout << "你输入的信息有误，请重新输入！" << endl << endl;
		setTextColor(Color::LIGHTYELLOW);
	}
}

void resetPasswordMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "您选择了密码重置功能", "*");
	printf("%s%35s%16s\n", "*", "请输入需要重置的账号", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "账号由5-16位由数字、字母组成" << endl;
	cout << "账号中输入exit则终止操作，返回主菜单" << endl;
	cout << "请输入需要重置的账号！" << endl << endl;

	string account;

	while (true) {
		cout << "账号：";
		if (inputAccount(account)) {
			if (account.compare("exit") == 0) {
				cout << "您选择了退出，即将返回上级菜单" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			int permission = OperateAccount::checkPermission(account);
			if (permission != -1) {
				string defaultPassword = "123456";
				OperateAccount::changePassword(account, defaultPassword, (permission == 0 ? false : true));
				cout << "重置密码成功，初始密码为\"123456\"" << endl;
				cout << "即将返回上级菜单" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			else if (permission == -1) {
				setTextColor(Color::LIGHTRED);
				cout << "账号不存在！" << endl;
			}
		}
		setTextColor(Color::LIGHTRED);
		cout << "你输入的信息有误，请重新输入！" << endl << endl;
		setTextColor(Color::LIGHTYELLOW);
	}
}
