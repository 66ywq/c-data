#include "../Heads/Users.h"

//User��

/*
* ���췽��
*/
User::User() {
}

User::User(string name, string pw) {
	this->userName = name;
	this->password = pw;
	updateContactsFromFile();
}

/*
* public����
*/
void User::updateContactsToFile() {
	this->contacts.write(this->userName);
}

void User::updateContactsFromFile() {
	this->contacts.read(this->userName);
}

string User::getUserName() {
	return this->userName;
}

string User::getPassword() {
	return this->password;
}

Contacts* User::getContacts() {
	return &this->contacts;
}

void User::setContacts(Contacts c) {
	this->contacts = c;
}

void User::changePassword(string& newPassword) {
	OperateAccount::changePassword(this->userName, newPassword, false);
}

//AdminUser��

/*
* ���췽��
*/
AdminUser::AdminUser(string name, string pw) {
	this->userName = name;
	this->password = pw;
}

/*
* public����
*/
bool AdminUser::delUser(string account) {
	return OperateAccount::removeAccount(account);
}

bool AdminUser::resetPassword(string account, bool isAdmin) {
	string defaultPassword = "123456";
	return OperateAccount::changePassword(account, defaultPassword, isAdmin);
}
