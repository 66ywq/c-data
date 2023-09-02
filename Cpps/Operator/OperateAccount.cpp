#include "../../Heads/Operator/OperateAccount.h"

/*
* 静态变量定义
*/
unordered_map<string, string> OperateAccount::root_map = {};
unordered_map<string, string> OperateAccount::user_map = {};

/*
* 构造方法
*/
OperateAccount::OperateAccount() {
	read();
}

/*
* public方法
*/
bool OperateAccount::login(string& account, string& password, bool isAdminLogin) {
	if (checkAccount(account, isAdminLogin)) {
		if (checkPassword(account, password, isAdminLogin)) {
			return true;
		}
	}
	return false;
}

bool OperateAccount::checkAccount(string& account, bool isAdminLogin) {
	unordered_map <string, string> ::iterator item;

	switch (isAdminLogin) {
	case true:
		item = root_map.find(account);
		if (item != root_map.end()) {
			return true;
		}
		break;
	case false:
		item = user_map.find(account);
		if (item != user_map.end()) {
			return true;
		}
		break;
	}

	return false;	//帐号不存在
}

int OperateAccount::checkPermission(string& account) {
	unordered_map <string, string> ::iterator item;

	item = root_map.find(account);
	if (item != root_map.end()) {
		return 1;
	}

	item = user_map.find(account);
	if (item != user_map.end()) {
		return 0;
	}

	return -1;	//帐号不存在
}

bool OperateAccount::createAccount(string& account, string& password, bool isAdmin) {
	if (checkAccount(account, isAdmin)) {
		return false;
	}

	addAccount(account, password, isAdmin);

	flush();

	return true;
}

int OperateAccount::removeAccount(string& account) {
	bool isAdmin = false;
	if (checkAccount(account, isAdmin)) {
		deleteAccount(account, isAdmin);
		flush();
		return 0;
	}

	isAdmin = true;
	if (checkAccount(account, isAdmin)) {
		if (checkOnlyAdminAccount()) {
			return -2;
		}
		deleteAccount(account, isAdmin);
		flush();
		return 1;
	}
	return -1;
}

bool OperateAccount::changePassword(string& account, string& newPassword, bool isAdmin) {
	switch (isAdmin) {
	case false:
		user_map[account] = newPassword;
		flush();
		return true;
	case true:
		root_map[account] = newPassword;
		flush();
		return true;
	}

	return false;
}

void OperateAccount::listAdminUser() {
	unordered_map<string, string> ::iterator it = root_map.begin();
	int count = 1;
	for (; it != root_map.end(); it++) {
		cout << it->first << "\t";
		if (count == 5) {
			cout << endl;
			count = 1;
			continue;
		}
		count++;
	}
	cout << endl;
}

void OperateAccount::listUser() {
	unordered_map<string, string> ::iterator it = user_map.begin();
	int count = 1;
	for (; it != user_map.end(); it++) {
		cout << it->first << "\t";
		if (count == 5) {
			cout << endl;
			count = 1;
			continue;
		}
		count++;
	}
	cout << endl;
}

void OperateAccount::refresh() {
	read();
}

/*
* private方法
*/
bool OperateAccount::read() {
	string rootPath = "./Data/Account/root.csv";
	string userPath = "./Data/Account/user.csv";

	ifstream in_root_file(rootPath, ios::in);

	string line_root;
	while (getline(in_root_file, line_root)) {
		int n = 0;
		stringstream ss(line_root);
		string str;
		vector<string> array_root(2);
		// 按照逗号分隔
		while (getline(ss, str, ',')) {
			array_root.at(n++) = str;
			if (n == 2) {
				root_map[array_root.at(0)] = array_root.at(1);
				n = 0;
			}
		}
	}
	in_root_file.close();
	ifstream in_user_file(userPath, ios::in);

	string line_user;
	while (getline(in_user_file, line_user)) {
		int n = 0;
		stringstream ss(line_user);
		string str;
		vector<string> array_user(2);
		// 按照逗号分隔
		while (getline(ss, str, ',')) {
			array_user.at(n++) = str;
			if (n == 2) {
				user_map[array_user.at(0)] = array_user.at(1);
				n = 0;
			}
		}
	}
	in_user_file.close();
	return true;
}

bool OperateAccount::flush() {
	string rootPath = "./Data/Account/root.csv";
	string userPath = "./Data/Account/user.csv";

	unordered_map<string, string>::iterator i, j;
	ofstream out_file1, out_file2;
	out_file1.open(rootPath, ios::out);
	for (i = root_map.begin(); i != root_map.end(); i++) {
		out_file1 << (*i).first << "," << (*i).second << endl;
	}
	out_file2.open(userPath, ios::out);
	for (j = user_map.begin(); j != user_map.end(); j++) {
		out_file2 << (*j).first << "," << (*j).second << endl;
	}
	out_file1.close();
	out_file2.close();
	return true;
}

bool OperateAccount::checkPassword(string account, string password, bool isAdminLogin) {
	switch (isAdminLogin) {
	case false:
		if (user_map[account].compare(password) == 0) {
			return true;
		}
		break;
	case true:
		if (root_map[account].compare(password) == 0) {
			return true;
		}
		break;
	}
	return false;
}

bool OperateAccount::checkOnlyAdminAccount() {
	return root_map.size() == 1 ? true : false;
}

void OperateAccount::addAccount(string account, string password, bool isAdmin) {
	if (isAdmin) {
		root_map[account] = password;
	}
	else {
		user_map[account] = password;
	}
}

void OperateAccount::deleteAccount(string account, bool isAdmin) {
	unordered_map <string, string> ::iterator item;
	if (!isAdmin) {
		user_map.erase(account);
	}
	else {
		root_map.erase(account);
	}
}
