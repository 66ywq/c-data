#pragma once

#include "../HeadRoot.h"

class OperateAccount {
public:
	OperateAccount();																	//�ղι���
	static bool login(string& account, string& password, bool isAdminLogin);			//��¼��֤
	static bool checkAccount(string& account, bool isAdminLogin);						//����Ȩ�޼���˺Ŵ��ڣ����ش������
	static int checkPermission(string& account);										//����˺Ŵ��ڣ�����Ȩ�ޣ�-1Ϊ������
	static bool createAccount(string& account, string& password, bool isAdmin);			//����˻�
	static int removeAccount(string& account);											//ɾ���˻�������ɾ���˺ŵ�Ȩ��
	static bool changePassword(string& account, string& newPassword, bool isAdmin);		//�޸�����
	static void listAdminUser();														//�б�ȫ������Ա�û�
	static void listUser();																//�б�ȫ����ͨ�û�
	static void refresh();																//���ļ�ˢ���û�
private:
	static unordered_map<string, string> root_map;										//�����û��˻��洢��
	static unordered_map<string, string> user_map;										//��ͨ�û��˻��洢��

	static bool read();																	//���˻�����
	static bool flush();																//ˢ���˻���������
	static bool checkPassword(string account, string password, bool isAdminLogin);		//�������ƥ���
	static void addAccount(string account, string password, bool isAdmin);				//����˻�(ֻ���)
	static void deleteAccount(string account, bool isAdmin);							//ɾ���˻�
	static bool checkOnlyAdminAccount();												//����Ƿ����Ψһ����Ա�û�
};
