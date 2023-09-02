#include "../../Heads/Menu/AdminMenu.h"

// ȫ�ֱ�������ǰ����Ա�û�
AdminUser* currentUser = NULL;

// ������������֤�Ӳ˵����ܱ�������
void adminMenu();
void listAccountMenu();
void delAccountMenu();
void resetPasswordMenu();

// ��������
void loadAdminMenu(AdminUser* u) {
	currentUser = u;
	OperateAccount::refresh();
	adminMenu();
}

void adminMenu() {
	system("cls");
	setTextColor(Color::LIGHTYELLOW);

	printf("%52s\n", "*==================================================*");
	printf("%s%38s%13s\n", "*", "��ӭʹ��ͨѶ¼�˺Ź���ϵͳ", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%30s%21s\n", "*", "1.�鿴�˺�", "*");
	printf("%s%30s%21s\n", "*", "2.ɾ���˺�", "*");
	printf("%s%30s%21s\n", "*", "3.��������", "*");
	printf("%s%30s%21s\n", "*", "4.�ǳ�ϵͳ", "*");
	printf("%s%30s%21s\n", "*", "0.�˳�ϵͳ", "*");
	printf("%52s\n", "*==================================================*");
	cout << "����������ѡ��0-4����";

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
			cout << "�ǳ��ɹ��������������˵���" << endl;
			Sleep(500);
			returnToMainMenu();
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

void listAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "��ѡ�����˺Ų鿴����", "*");
	printf("%s%31s%20s\n", "*", "�˺��б�����", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "����Ա�û���" << endl;
	OperateAccount::listAdminUser();
	cout << "��ͨ�û���" << endl;
	OperateAccount::listUser();
	cout << endl;

	cout << "����������Ϣ�����ϼ��˵�" << endl;
	system("pause");
	adminMenu();
}

void delAccountMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "��ѡ�����˺�ɾ������", "*");
	printf("%s%35s%16s\n", "*", "��������Ҫɾ�����˺�", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "�˺���5-16λ�����֡���ĸ���" << endl;
	cout << "�˺�������exit����ֹ�������������˵�" << endl;
	cout << "��������Ҫɾ�����˺ţ�" << endl << endl;

	string account;

	while (true) {
		cout << "�˺ţ�";
		if (inputAccount(account)) {
			if (account.compare("exit") == 0) {
				cout << "��ѡ�����˳������������ϼ��˵�" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			switch (OperateAccount::removeAccount(account)) {
			case -2:
				setTextColor(Color::LIGHTRED);
				cout << "�������һ������Ա�û����޷�ɾ����" << endl;
				break;
			case -1:
				setTextColor(Color::LIGHTRED);
				cout << "�˺Ų����ڣ��޷�ɾ����" << endl;
				break;
			case 0:
				cout << "�ɹ�ɾ����ͨ�û���" << account << "��" << endl;
				cout << "���������ϼ��˵���" << endl;
				Sleep(1000);
				adminMenu();
				break;
			case 1:
				cout << "�ɹ�ɾ������Ա�û���" << account << "��" << endl;
				cout << "���������ϼ��˵���" << endl;
				Sleep(1000);
				adminMenu();
				break;
			default:
				setTextColor(Color::LIGHTRED);
				break;
			}
		}
		setTextColor(Color::LIGHTRED);
		cout << "���������Ϣ�������������룡" << endl << endl;
		setTextColor(Color::LIGHTYELLOW);
	}
}

void resetPasswordMenu() {
	system("cls");
	printf("%52s\n", "*==================================================*");
	printf("%s%35s%16s\n", "*", "��ѡ�����������ù���", "*");
	printf("%s%35s%16s\n", "*", "��������Ҫ���õ��˺�", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "�˺���5-16λ�����֡���ĸ���" << endl;
	cout << "�˺�������exit����ֹ�������������˵�" << endl;
	cout << "��������Ҫ���õ��˺ţ�" << endl << endl;

	string account;

	while (true) {
		cout << "�˺ţ�";
		if (inputAccount(account)) {
			if (account.compare("exit") == 0) {
				cout << "��ѡ�����˳������������ϼ��˵�" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			int permission = OperateAccount::checkPermission(account);
			if (permission != -1) {
				string defaultPassword = "123456";
				OperateAccount::changePassword(account, defaultPassword, (permission == 0 ? false : true));
				cout << "��������ɹ�����ʼ����Ϊ\"123456\"" << endl;
				cout << "���������ϼ��˵�" << endl;
				Sleep(1000);
				adminMenu();
				break;
			}
			else if (permission == -1) {
				setTextColor(Color::LIGHTRED);
				cout << "�˺Ų����ڣ�" << endl;
			}
		}
		setTextColor(Color::LIGHTRED);
		cout << "���������Ϣ�������������룡" << endl << endl;
		setTextColor(Color::LIGHTYELLOW);
	}
}
