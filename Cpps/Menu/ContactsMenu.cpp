#include "../../Heads/Menu/ContactsMenu.h"
#include "../../Heads/Menu/LoginMenu.h"

User* currentUser = NULL;

//������������֤�Ӳ˵����ܱ��ⲿ����
void contactsMainMenu();
void contactsListMenu();
void contactsAddMenu();
void contactsDelMenu();
void contactsFindMenu();
void contactsTransfromMenu();
void changePasswordMenu();
void inputContactsNode(Node* n);

// ��������
void load(User* u) {
	currentUser = u;
	contactsMainMenu();
}

void contactsMainMenu() {
	system("cls");
	setTextColor();

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ӭʹ��ͨѶ¼����ϵͳ", "*");
	printf("%52s\n", "*==================================================*");
	printf("%s%31s%20s\n", "*", "1.�鿴ͨѶ¼", "*");
	printf("%s%31s%20s\n", "*", "2.������ϵ��", "*");
	printf("%s%31s%20s\n", "*", "3.ɾ����ϵ��", "*");
	printf("%s%31s%20s\n", "*", "4.�޸���ϵ��", "*");
	printf("%s%31s%20s\n", "*", "5.��ѯ��ϵ��", "*");
	printf("%s%31s%20s\n", "*", "6.����������", "*");
	printf("%s%31s%20s\n", "*", "7.�ǳ�������", "*");
	printf("%s%31s%20s\n", "*", "0.�ǳ����˳�", "*");
	printf("%52s\n", "*==================================================*");
	cout << "����������ѡ��0-7����";

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
			cout << "�ǳ��ɹ��������������˵���" << endl;
			Sleep(500);
			returnToMainMenu();
			break;
		case 0:
			currentUser->updateContactsToFile();
			cout << "лл����ʹ�ã�";
			exit(0);
			break;
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

void contactsListMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ����ͨѶ¼�鿴����", "*");
	printf("%s%32s%19s\n", "*", "ͨѶ¼�б�����", "*");
	printf("%52s\n", "*==================================================*");
	
	cout << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	cout << "����������Ϣ�����ϼ��˵�" << endl;
	system("pause");
	Sleep(1000);
	contactsMainMenu();
}

void contactsAddMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ������ϵ����ӹ���", "*");
	printf("%s%35s%16s\n", "*", "������ϵ����Ϣ�����", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	while (true) {
		cout << "����ʱ����none��ΪĬ������" << endl;
		cout << "��ϵ�����ֺ͵绰���벻���ظ�" << endl;

		Node newNode = Node();
		inputContactsNode(&newNode);

		currentUser->getContacts()->add(newNode);

		cout << "��ӳɹ�������Ҫ���������" << endl;
		cout << "����y������������������˳���";
		string selection;
		cin >> selection;
		if (selection.compare("y") == 0) {
			continue;
		}
		cout << endl << "�����������˵�" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsDelMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ������ϵ��ɾ������", "*");
	printf("%s%35s%16s\n", "*", "������ϵ����Ϣ��ɾ��", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "ͨѶ¼�б�����" << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	string input;

	while(true) {
		cout << "��������Ҫɾ������ϵ��������";
		cin >> input;
		int index = currentUser->getContacts()->find(input, 0);
		if (index == -1) {
			cout << "��ϵ�˲����ڣ����������룡" << endl << endl;
			continue;
		}
		currentUser->getContacts()->del(index);

		cout << "ɾ���ɹ�������Ҫ���������" << endl;
		cout << "����y������������������˳���";
		cin >> input;
		if (input.compare("y") == 0) {
			cout << endl;
			continue;
		}
		cout << endl << "�����������˵�" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsTransfromMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ������ϵ���޸Ĺ���", "*");
	printf("%s%35s%16s\n", "*", "������ϵ����Ϣ���޸�", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	cout << "ͨѶ¼�б�����" << endl;
	currentUser->getContacts()->listAll();
	cout << endl;

	string input;

	while (true) {
		cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
		cin >> input;
		int index = currentUser->getContacts()->find(input, 0);
		if (index == -1) {
			cout << "��ϵ�˲����ڣ����������룡" << endl << endl;
			continue;
		}

		Node node = currentUser->getContacts()->getNode(index);
		Node newNode = Node(node.name, node.sex, node.work,
							node.phone_num, node.kind_phone, node.note); 

		cout << "����ʱ����none������������" << endl;
		inputContactsNode(&newNode);
		currentUser->getContacts()->transform(input, newNode);

		cout << "�޸ĳɹ�������Ҫ���������" << endl;
		cout << "����y������������������˳���";
		cin >> input;
		if (input.compare("y") == 0) {
			continue;
		}
		cout << endl << "�����������˵�" << endl;
		Sleep(1000);
		contactsMainMenu();
		break;
	}
}

void contactsFindMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ������ϵ�˲��ҹ���", "*");
	printf("%s%35s%16s\n", "*", "������ϵ����Ϣ�Բ���", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string input;
	int order = 0;

	cout << "��ѡ����ҷ�ʽ��1Ϊ����������2Ϊ���ҵ绰���룺";
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
		cout << "������ĸ�ʽ�������������룺";
	}

	cout << "�����������Ϣ��";
	cin >> input;
	int index = currentUser->getContacts()->find(input, order);
	if (index == -1) {
		cout << "δ�ҵ������Ϣ��" << endl;
	}
	else {
		Node node = currentUser->getContacts()->getNode(index);
		cout << "�ҵ������Ϣ!" << endl;
		currentUser->getContacts()->listOne(index);
	}

	cout << endl << "����������Ϣ�������˵�" << endl;
	system("pause");
	Sleep(1000);
	contactsMainMenu();
}

void changePasswordMenu() {
	system("cls");

	printf("%52s\n", "*==================================================*");
	printf("%s%36s%15s\n", "*", "��ѡ���������޸Ĺ���", "*");
	printf("%s%35s%16s\n", "*", "�����µ��������޸�", "*");
	printf("%52s\n", "*==================================================*");
	cout << endl;

	string newPassword;
	cout << "�������µ�����" << endl;

	while (true) {
		cout << "���룺";
		if (inputPassWord(newPassword)) {
			break;
		}
		cout << "������������ʽ�������������룡" << endl << endl;
	}

	currentUser->changePassword(newPassword);
	cout << endl << "��������ɹ��������������˵���";
	Sleep(1000);
	contactsMainMenu();
	return;
}

void inputContactsNode(Node* n) {
	regex phone("^[0-9\\-]{1,15}$");
	regex str("^[A-Za-z0-9]{1,10}");
	regex def("none");
	string input;

	cout << endl << "��������ϵ�����������������ţ������10���ַ���";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (std::regex_match(input, str)) {
			if (currentUser->getContacts()->find(input, 0) != -1) {
				cout << "��ϵ�������ظ���" << endl;
			}
			else {
				n->name = input;
				input.clear();
				break;
			}
		}
		cout << "���������Ϣ�������������룺";
	}

	cout << endl << "��ѡ���Ա�1Ϊ�У�2ΪŮ��";
	while (true) {
		cin >> input;
		if (input.compare("1") == 0) {
			n->sex = "��";
			input.clear();
			break;
		}
		else if (input.compare("2") == 0) {
			n->sex = "Ů";
			input.clear();
			break;
		}
		else if (regex_match(input, def)) {
			break;
		}
		cout << "���������Ϣ�������������룺";
	}

	cout << endl << "�����빤����Ϣ�����������ţ������10���ַ���";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "���������Ϣ�������������룺";
			continue;
		}
		n->work = input;
		input.clear();
		break;
	}

	cout << endl << "������绰���룬ֻ�����ֺ͡�-�����ţ������15���ַ���";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (std::regex_match(input, phone)) {
			if (currentUser->getContacts()->find(input, 1) != -1) {
				cout << "�绰�����ظ���" << endl;
			}
			else {
				n->phone_num = input;
				input.clear();
				break;
			}
		}
		cout << "���������Ϣ�������������룺";
	}

	cout << endl << "������������࣬���������ţ������10���ַ���";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "���������Ϣ�������������룺";
			continue;
		}
		n->kind_phone = input;
		input.clear();
		break;
	}

	cout << endl << "�����뱸ע��Ϣ�����������ţ������10���ַ���";
	while (true) {
		cin >> input;
		if (regex_match(input, def)) {
			break;
		}
		else if (!std::regex_match(input, str)) {
			cout << "���������Ϣ�������������룺";
			continue;
		}
		n->note = input;
		input.clear();
		break;
	}

	return;
}
