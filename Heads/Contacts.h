#pragma once

#include "HeadRoot.h"
#include "Operator/Operator.h"

class Contacts {
public:
    void write(string account);                     //���ļ�д��ͨѶ¼
    void read(string account);                      //���ļ���ȡͨѶ¼
    int find(string str, int order);                //������Ϣ������ϵ�ˣ����ز��ҵ�����
    void add(Node newNode);                         //������ϵ��
    bool del(int index);                            //ɾ����ϵ��
    bool transform(string name, Node newNode);      //�޸���ϵ��
    void listAll(int order = 0);                    //��ͨѶ¼�б�
    void listOne(int index);                        //��������ϵ���б�
    Node getNode(int index);                        //
private:
	vector<Node> nodeSet;
};
