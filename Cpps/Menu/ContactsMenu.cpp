#include "../../Heads/Menu/ContactsMenu.h"
#include "../../Heads/Menu/LoginMenu.h"

User* currentUser = NULL;

//函数声明：保证子菜单不能被外部调用
void contactsMainMenu();
void contactsListMenu();
void contactsAddMenu();
void contactsDelMenu();
void contactsFindMenu();
void contactsTransfromMenu();
void changePasswordMenu();
void inputContactsNode(Node* n);

// 函数主体
void load(User* u) {
	currentUser = u;
	contactsMainMenu();
}

void contactsMainMenu() {
	system("cls");
	setTextColor();

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "欢迎使用通讯录管理系统", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%31s%20s\n", "*", "1.查看通讯录", "*");
	printf("%s%31s%20s\n", "*", "2.增加联系人", "*");
	printf("%s%31s%20s\n", "*", "3.删除联系人", "*");
	printf("%s%31s%20s\n", "*", "4.修改联系人", "*");
	printf("%s%31s%20s\n", "*", "5.查询联系人", "*");
	printf("%s%31s%20s\n", "*", "6.更改新密码", "*");
	printf("%s%31s%20s\n", "*", "7.登出并返回", "*");
	printf("%s%31s%20s\n", "*", "0.登出并退出", "*");
	printf("%52s\n", "*==================================================*");
	cout << "请输入您的选择（0-7）：";

	int selection = -1;

	while (true) {
		cin >> selection;
		switch (selection) {
		case 1:
			contactsListMenu();
			break;
		case 2:
			contactsAddMenu();
			break;
		case 3:
			contactsDelMenu();
			break;
		case 4:
			contactsTransfromMenu();
			break;
		case 5:
			contactsFindMenu();
			break;
		case 6:
			changePasswordMenu();
			break;
		case 7:
			currentUser->updateContactsToFile();
			currentUser = NULL;
			cout << "登出成功！即将返回主菜单！" << endl;
			Sleep(500);
			returnToMainMenu();
			break;
		case 0:
			currentUser->updateContactsToFile();
			cout << "谢谢您的使用！";
			exit(0);
			break;
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

void contactsListMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了通讯录查看功能", "*");
	printf("%s%32s%19s\n", "*", "通讯录列表如下", "*");
	printf("%52s\n", "*==================================================*");
	
	cout << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	cout << "输入任意信息返回上级菜单" << endl;
	system("pause");
	Sleep(1000);
	contactsMainMenu();
}

void contactsAddMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了联系人添加功能", "*");
	printf("%s%35s%16s\n", "*", "输入联系人信息以添加", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	while (true) {
		cout << "输入时输入none即为默认数据" << endl;
		cout << "联系人名字和电话号码不可重复" << endl;

		Node newNode = Node();
		inputContactsNode(&newNode);

		currentUser->getContacts()->add(newNode);

		cout << "添加成功！还需要继续添加吗？" << endl;
		cout << "输入y则继续，输入其他则退出：";
		string selection;
		cin >> selection;
		if (selection.compare("y") == 0) {
			continue;
		}
		cout << endl << "即将返回主菜单" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsDelMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了联系人删除功能", "*");
	printf("%s%35s%16s\n", "*", "输入联系人信息以删除", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "通讯录列表如下" << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	string input;

	while(true) {
		cout << "请输入需要删除的联系人姓名：";
		cin >> input;
		int index = currentUser->getContacts()->find(input, 0);
		if (index == -1) {
			cout << "联系人不存在！请重新输入！" << endl << endl;
			continue;
		}
		currentUser->getContacts()->del(index);

		cout << "删除成功！还需要继续添加吗？" << endl;
		cout << "输入y则继续，输入其他则退出：";
		cin >> input;
		if (input.compare("y") == 0) {
			cout << endl;
			continue;
		}
		cout << endl << "即将返回主菜单" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsTransfromMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了联系人修改功能", "*");
	printf("%s%35s%16s\n", "*", "输入联系人信息以修改", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "通讯录列表如下" << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	string input;

	while (true) {
		cout << "请输入需要修改的联系人姓名" << endl;
		cin >> input;
		int index = currentUser->getContacts()->find(input, 0);
		if (index == -1) {
			cout << "联系人不存在！请重新输入！" << endl << endl;
			continue;
		}

		Node node = currentUser->getContacts()->getNode(index);
		Node newNode = Node(node.name, node.sex, node.work,
							node.phone_num, node.kind_phone, node.note); 

		cout << "输入时输入none即不更改数据" << endl;
		inputContactsNode(&newNode);
		currentUser->getContacts()->transform(input, newNode);

		cout << "修改成功！还需要继续添加吗？" << endl;
		cout << "输入y则继续，输入其他则退出：";
		cin >> input;
		if (input.compare("y") == 0) {
			continue;
		}
		cout << endl << "即将返回主菜单" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsFindMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了联系人查找功能", "*");
	printf("%s%35s%16s\n", "*", "输入联系人信息以查找", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string input;
	int order = 0;

	cout << "请选择查找方式，1为查找姓名，2为查找电话号码：";
	while (true) {
		cin >> input;
		if (input.compare("1") == 0) {
			order = 0;
			break;
		}
		else if (input.compare("2") == 0) {
			order = 1;
			break;
		}
		cout << "你输入的格式有误，请重新输入：";
	}

	cout << "请输入查找信息：";
	cin >> input;
	int index = currentUser->getContacts()->find(input, order);
	if (index == -1) {
		cout << "未找到相关信息！" << endl;
	}
	else {
		Node node = currentUser->getContacts()->getNode(index);
		cout << "找到相关信息!" << endl;
		currentUser->getContacts()->listOne(index);
	}

	cout << endl << "输入任意信息返回主菜单" << endl;
	system("pause");
	Sleep(1000);
	contactsMainMenu();
}

void changePasswordMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "您选择了密码修改功能", "*");
	printf("%s%35s%16s\n", "*", "输入新的密码以修改", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string newPassword;
	cout << "请输入新的密码" << endl;

	while (true) {
		cout << "密码：";
		if (inputPassWord(newPassword)) {
			break;
		}
		cout << "您输入的密码格式有误，请重新输入！" << endl << endl;
	}

	currentUser->changePassword(newPassword);
	cout << endl << "重置密码成功，即将返回主菜单！";
	Sleep(1000);
	contactsMainMenu();
	return;
}

void inputContactsNode(Node* n) {
	regex phone("^[0-9\\-]{1,15}$");
	regex str("^[A-Za-z0-9]{1,10}");
	regex def("none");
	string input;

	cout << endl << "请输入联系人姓名，不包含符号，最多有10个字符：";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (std::regex_match(input, str)) {
			if (currentUser->getContacts()->find(input, 0) != -1) {
				cout << "联系人姓名重复！" << endl;
			}
			else {
				n->name = input;
				input.clear();
				break;
			}
		}
		cout << "你输入的信息有误，请重新输入：";
	}

	cout << endl << "请选择性别，1为男，2为女：";
	while (true) {
		cin >> input;
		if (input.compare("1") == 0) {
			n->sex = "男";
			input.clear();
			break;
		}
		else if (input.compare("2") == 0) {
			n->sex = "女";
			input.clear();
			break;
		}
		else if (regex_match(input, def)) {
			break;
		}
		cout << "你输入的信息有误，请重新输入：";
	}

	cout << endl << "请输入工作信息，不包含符号，最多有10个字符：";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "你输入的信息有误，请重新输入：";
			continue;
		}
		n->work = input;
		input.clear();
		break;
	}

	cout << endl << "请输入电话号码，只含数字和“-”符号，最多有15个字符：";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (std::regex_match(input, phone)) {
			if (currentUser->getContacts()->find(input, 1) != -1) {
				cout << "电话号码重复！" << endl;
			}
			else {
				n->phone_num = input;
				input.clear();
				break;
			}
		}
		cout << "你输入的信息有误，请重新输入：";
	}

	cout << endl << "请输入号码种类，不包含符号，最多有10个字符：";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "你输入的信息有误，请重新输入：";
			continue;
		}
		n->kind_phone = input;
		input.clear();
		break;
	}

	cout << endl << "请输入备注信息，不包含符号，最多有10个字符：";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "你输入的信息有误，请重新输入：";
			continue;
		}
		n->note = input;
		input.clear();
		break;
	}

	return;
}
