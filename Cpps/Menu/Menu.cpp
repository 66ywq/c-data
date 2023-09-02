#include "../../Heads/Menu/Menu.h"

bool inputAccount(string& str) {
	regex reg("^[A-Za-z0-9]{5,16}|exit");		// ���� ��ĸ �»���

	cin >> str;

	if (!regex_match(str, reg)) {
		str.clear();
		return false;
	}

	return true;
}

bool inputPassWord(string& str) {
	int size = 16;						//�������鳤�ȳ��ȣ�Ĭ��16
	int count = 0;						//Ŀǰ�Ѿ������λ��
	char c;								//���뻺�����
	char* password = new char[size];	//��̬����Ĭ�ϳ��ȵĴ洢���������
	regex reg("^[A-Za-z0-9_]{6,18}");	//У�������ʽ

	while ((c = getch()) != '\r') {

		// ��������
		if (count == size) {
			size = size * 2 + 1;
			char* newPassword = new char[size];
			strcpy(newPassword, password);
			delete[] password;
			password = newPassword;
		}

		// �˸������
		else if (c == '\b') { // �˸�
			if (count == 0) {
				continue;
			}
			putchar('\b'); // ����һ��
			putchar(' '); // ���һ���ո�ԭ����*����
			putchar('\b'); // �ٻ���һ��ȴ�����
			count--;
		}

		// ¼������
		else {
			putchar('*');  // ���յ�һ���ַ���, ��ӡһ��*
			password[count] = c;
			count++;
		}
	}
	password[count] = '\0';
	str = password;
	delete[] password; // �ͷſռ�
	cout << endl;

	if (!regex_match(str, reg)) {
		str.clear();
		return false;
	}

	return true;
}

void returnToMainMenu() {
	cout << "�û���ֹ�����������������˵���" << endl;
	OperateAccount::refresh();
	Sleep(1000);
	loadLoginMenu();
}
