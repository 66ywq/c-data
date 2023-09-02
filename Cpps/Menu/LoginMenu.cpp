#include "../../Heads/Menu/LoginMenu.h"
#include "../../Heads/Menu/ContactsMenu.h"

// 函数声明：保证子菜单不能被外界调用
void loginMenu();										//主界面函数
void loginAccount(bool isAdminLogin);					//登录界面函数
void addAccountMenu();									//添加账号界面函数
bool inputUserInfo(string& account, string& password);	//账号信息输入函数

// 函数主体
void loadLoginMenu() {
	OperateAccount::refresh();
	loginMenu();
}

void loginMenu() {
	system("cls");
	setTextColor();
	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "欢迎使用通讯录管理系统", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%32s%19s\n", "*", "1.登陆现有账号", "*");
	printf("%s%32s%19s\n", "*", "2.注册新的账号", "*");
	printf("%s%32s%19s\n", "*", "3.账号管理系统", "*");
	printf("%s%32s%19s\n", "*", "0.退出登录系统", "*");
	printf("%52s\n", "*==================================================*");
	cout << "请输入您的选择（0-3）：";

	int selection = -1;

	while (true) {
		cin >> selection;

		switch (selection) {
		case 1:
			loginAccount(false);
			break;
		case 2:
			addAccountMenu();
			break;
		case 3:
			loginAccount(true);
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

void loginAccount(bool isAdminLogin) {
	system("cls");
	if (isAdminLogin == true) {
		setTextColor(Color::LIGHTYELLOW);
		printf("%52s\n", "*==================================================*");
		printf("%s%35s%16s\n", "*", "您选择了账号管理系统", "*");
		printf("%s%33s%18s\n", "*", "请登入管理员用户", "*");
		printf("%52s\n", "*==================================================*");
		cout << endl;
	}
	else {
		setTextColor();
		printf("%52s\n", "*==================================================*");
		printf("%s%36s%15s\n", "*", "您选择了登录通讯录系统", "*");
		printf("%s%32s%19s\n", "*", "请登入普通用户", "*");
		printf("%52s\n", "*==================================================*");
		cout << endl;
	}

	string account;
	string password;

	cout << "账号由5-16位由数字、字母组成" << endl;
	cout << "密码由6-18位由数字、字母或下划线组成" << endl;
	cout << "账号中输入exit则终止操作，返回主菜单" << endl;
	cout << "请输入账号和密码！" << endl << endl;

	for (int i = 2; i >= 0; i--) {
		inputUserInfo(account, password);
		int permission = OperateAccount::checkPermission(account);
		int temp = (isAdminLogin == true ? 1 : 0);
		if (permission == temp) {
			if (OperateAccount::login(account, password, isAdminLogin)) {
				cout << "登陆成功！" << endl;
				Sleep(1000);
				switch (isAdminLogin) {
				case true:
					loadAdminMenu(new AdminUser(account, password));
					break;
				case false:
					load(new User(account, password));
					break;
				}
			}
		}

		setTextColor(Color::LIGHTRED);
		cout << "你输入的用户名或密码有误，亦或是权限不对！" << endl;
		if (i == 0) {
		cout << "您已经输入错误3次，系统将强制退出！";
		Sleep(1000);
		exit(1);
		}
		else {
			cout << "您还剩余" << i << "次登录机会" << endl << endl;
		}
		setTextColor(isAdminLogin == true ? Color::LIGHTYELLOW : Color::LIGHTWHITE);
	}
	
}

void addAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "您选择了账号注册功能", "*");
	printf("%s%33s%18s\n", "*", "请注册您的新账号", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string account;
	string password;

	cout << "账号由5-16位由数字、字母组成" << endl;
	cout << "密码由6-18位由数字、字母或下划线组成" << endl;
	cout << "账号中输入exit则终止操作，返回主菜单" << endl;
	cout << "请输入账号和密码！" << endl << endl;

	while (!inputUserInfo(account, password)) {
		cout << "你输入的用户名或密码格式有误，请重新输入！" << endl << endl;
	}
	

	if (!OperateAccount::createAccount(account, password, false)) {
		setTextColor(Color::LIGHTRED);
		cout << "注册失败，账号名可能重复！即将返回主菜单" << endl;
		returnToMainMenu();
	}

	cout << "注册成功，请牢记您的账户和密码！即将返回主菜单" << endl;
	returnToMainMenu();
}

bool inputUserInfo(string& account, string& password) {
	bool isAccountRight = false;
	bool isPasswordRight = false;

	cout << "账号：";
	isAccountRight = inputAccount(account);
	if (account.compare("exit") == 0) {
		returnToMainMenu();
	}

	cout << "密码：";
	isPasswordRight = inputPassWord(password);
	return (isAccountRight == true && isPasswordRight == true) ? true : false;
}
