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
	User();											//构造方法(无参数)
	User(string name, string pw);					//构造方法(有参数)

	void updateContactsToFile();					//向通讯录文件写入新的通讯录
	void updateContactsFromFile();					//从通讯录文件读取通讯录信息

	//Get/Set方法
	string getUserName();
	string getPassword();
	Contacts* getContacts();							
	void setContacts(Contacts c);

	void changePassword(string& newPassword);							//修改当前密码
};

class AdminUser {
public:
	AdminUser(string name, string pw);				//构造方法(有参数)

	//void addUser(bool isAdmin, string account);	//添加账号
	bool delUser(string account);					//删除账号
	bool resetPassword(string account, bool isAdmin);				//重置他人密码
	// 增加增删改查功能
private:
	string userName;
	string password;
};
