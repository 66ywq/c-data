#include "../../Heads/Menu/Menu.h"

bool inputAccount(string& str) {
	regex reg("^[A-Za-z0-9]{5,16}|exit");		// 数字 字母 下划线

	cin >> str;

	if (!regex_match(str, reg)) {
		str.clear();
		return false;
	}

	return true;
}

bool inputPassWord(string& str) {
	int size = 16;						//密码数组长度长度，默认16
	int count = 0;						//目前已经输入的位数
	char c;								//输入缓存变量
	char* password = new char[size];	//动态申请默认长度的存储密码的数组
	regex reg("^[A-Za-z0-9_]{6,18}");	//校验密码格式

	while ((c = getch()) != '\r') {

		// 数组扩容
		if (count == size) {
			size = size * 2 + 1;
			char* newPassword = new char[size];
			strcpy(newPassword, password);
			delete[] password;
			password = newPassword;
		}

		// 退格的输入
		else if (c == '\b') { // 退格
			if (count == 0) {
				continue;
			}
			putchar('\b'); // 回退一格
			putchar(' '); // 输出一个空格将原来的*隐藏
			putchar('\b'); // 再回退一格等待输入
			count--;
		}

		// 录入数据
		else {
			putchar('*');  // 接收到一个字符后, 打印一个*
			password[count] = c;
			count++;
		}
	}
	password[count] = '\0';
	str = password;
	delete[] password; // 释放空间
	cout << endl;

	if (!regex_match(str, reg)) {
		str.clear();
		return false;
	}

	return true;
}

void returnToMainMenu() {
	cout << "用户终止操作！即将返回主菜单！" << endl;
	OperateAccount::refresh();
	Sleep(1000);
	loadLoginMenu();
}
