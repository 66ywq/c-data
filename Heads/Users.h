#pragma once

#include "HeadRoot.h"
#include "Contacts.h"
#include "Operator/Operator.h"

class AdminUser;

class User {
private:
	string userName;
	string password;
	Contacts contacts;
public:
	User();											//���췽��(�޲���)
	User(string name, string pw);					//���췽��(�в���)

	void updateContactsToFile();					//��ͨѶ¼�ļ�д���µ�ͨѶ¼
	void updateContactsFromFile();					//��ͨѶ¼�ļ���ȡͨѶ¼��Ϣ

	//Get/Set����
	string getUserName();
	string getPassword();
	Contacts* getContacts();							
	void setContacts(Contacts c);

	void changePassword(string& newPassword);							//�޸ĵ�ǰ����
};

class AdminUser {
public:
	AdminUser(string name, string pw);				//���췽��(�в���)

	//void addUser(bool isAdmin, string account);	//����˺�
	bool delUser(string account);					//ɾ���˺�
	bool resetPassword(string account, bool isAdmin);				//������������
	// ������ɾ�Ĳ鹦��
private:
	string userName;
	string password;
};
