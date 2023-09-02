#include "../../Heads/Menu/LoginMenu.h"
#include "../../Heads/Menu/ContactsMenu.h"

// ������������֤�Ӳ˵����ܱ�������
void loginMenu();										//�����溯��
void loginAccount(bool isAdminLogin);					//��¼���溯��
void addAccountMenu();									//����˺Ž��溯��
bool inputUserInfo(string& account, string& password);	//�˺���Ϣ���뺯��

// ��������
void loadLoginMenu() {
	OperateAccount::refresh();
	loginMenu();
}

void loginMenu() {
	system("cls");
	setTextColor();
	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ӭʹ��ͨѶ¼����ϵͳ", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%32s%19s\n", "*", "1.��½�����˺�", "*");
	printf("%s%32s%19s\n", "*", "2.ע���µ��˺�", "*");
	printf("%s%32s%19s\n", "*", "3.�˺Ź���ϵͳ", "*");
	printf("%s%32s%19s\n", "*", "0.�˳���¼ϵͳ", "*");
	printf("%52s\n", "*==================================================*");
	cout << "����������ѡ��0-3����";

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
			cout << "лл����ʹ�ã�";
			Sleep(1000);
			exit(0);
		default:
			cout << "�������ѡ���������������룺";
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
		printf("%s%35s%16s\n", "*", "��ѡ�����˺Ź���ϵͳ", "*");
		printf("%s%33s%18s\n", "*", "��������Ա�û�", "*");
		printf("%52s\n", "*==================================================*");
		cout << endl;
	}
	else {
		setTextColor();
		printf("%52s\n", "*==================================================*");
		printf("%s%36s%15s\n", "*", "��ѡ���˵�¼ͨѶ¼ϵͳ", "*");
		printf("%s%32s%19s\n", "*", "�������ͨ�û�", "*");
		printf("%52s\n", "*==================================================*");
		cout << endl;
	}

	string account;
	string password;

	cout << "�˺���5-16λ�����֡���ĸ���" << endl;
	cout << "������6-18λ�����֡���ĸ���»������" << endl;
	cout << "�˺�������exit����ֹ�������������˵�" << endl;
	cout << "�������˺ź����룡" << endl << endl;

	for (int i = 2; i >= 0; i--) {
		inputUserInfo(account, password);
		int permission = OperateAccount::checkPermission(account);
		int temp = (isAdminLogin == true ? 1 : 0);
		if (permission == temp) {
			if (OperateAccount::login(account, password, isAdminLogin)) {
				cout << "��½�ɹ���" << endl;
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
		cout << "��������û������������������Ȩ�޲��ԣ�" << endl;
		if (i == 0) {
		cout << "���Ѿ��������3�Σ�ϵͳ��ǿ���˳���";
		Sleep(1000);
		exit(1);
		}
		else {
			cout << "����ʣ��" << i << "�ε�¼����" << endl << endl;
		}
		setTextColor(isAdminLogin == true ? Color::LIGHTYELLOW : Color::LIGHTWHITE);
	}
	
}

void addAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "��ѡ�����˺�ע�Ṧ��", "*");
	printf("%s%33s%18s\n", "*", "��ע���������˺�", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string account;
	string password;

	cout << "�˺���5-16λ�����֡���ĸ���" << endl;
	cout << "������6-18λ�����֡���ĸ���»������" << endl;
	cout << "�˺�������exit����ֹ�������������˵�" << endl;
	cout << "�������˺ź����룡" << endl << endl;

	while (!inputUserInfo(account, password)) {
		cout << "��������û����������ʽ�������������룡" << endl << endl;
	}
	

	if (!OperateAccount::createAccount(account, password, false)) {
		setTextColor(Color::LIGHTRED);
		cout << "ע��ʧ�ܣ��˺��������ظ��������������˵�" << endl;
		returnToMainMenu();
	}

	cout << "ע��ɹ������μ������˻������룡�����������˵�" << endl;
	returnToMainMenu();
}

bool inputUserInfo(string& account, string& password) {
	bool isAccountRight = false;
	bool isPasswordRight = false;

	cout << "�˺ţ�";
	isAccountRight = inputAccount(account);
	if (account.compare("exit") == 0) {
		returnToMainMenu();
	}

	cout << "���룺";
	isPasswordRight = inputPassWord(password);
	return (isAccountRight == true && isPasswordRight == true) ? true : false;
}
