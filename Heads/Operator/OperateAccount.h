#pragma once

#include "../HeadRoot.h"

class OperateAccount {
public:
	OperateAccount();																	//空参构造
	static bool login(string& account, string& password, bool isAdminLogin);			//登录认证
	static bool checkAccount(string& account, bool isAdminLogin);						//根据权限检查账号存在，返回存在与否
	static int checkPermission(string& account);										//检查账号存在，返回权限，-1为不存在
	static bool createAccount(string& account, string& password, bool isAdmin);			//添加账户
	static int removeAccount(string& account);											//删除账户，返回删除账号的权限
	static bool changePassword(string& account, string& newPassword, bool isAdmin);		//修改密码
	static void listAdminUser();														//列表全部管理员用户
	static void listUser();																//列表全部普通用户
	static void refresh();																//从文件刷新用户
private:
	static unordered_map<string, string> root_map;										//管理用户账户存储表
	static unordered_map<string, string> user_map;										//普通用户账户存储表

	static bool read();																	//读账户数据
	static bool flush();																//刷新账户密码数据
	static bool checkPassword(string account, string password, bool isAdminLogin);		//检查密码匹配否
	static void addAccount(string account, string password, bool isAdmin);				//添加账户(只添加)
	static void deleteAccount(string account, bool isAdmin);							//删除账户
	static bool checkOnlyAdminAccount();												//检查是否存在唯一管理员用户
};
