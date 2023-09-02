#pragma once

#include "../HeadRoot.h"
#include "../Users.h"
#include "../Contacts.h"

#include "LoginMenu.h"
#include "AdminMenu.h"
#include "ContactsMenu.h"

bool inputAccount(string& str);				//账号输入函数
bool inputPassWord(string& str);			//密码输入函数
void returnToMainMenu();					//返回主菜单函数
