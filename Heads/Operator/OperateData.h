#pragma once
#include "../HeadRoot.h"

void stringSplit(const string& str, const string& split, vector<string>& res);  //������ʽ�ָ��

//��getBelongData��
void aBelong(vector<Node>& list, vector<Node>& data);
void bBelong(vector<Node>& list, vector<Node>& data);
void cBelong(vector<Node>& list, vector<Node>& data);

//��findThread��
void findSequence(vector<Node>& list, string str, int &f, int order = 0);
void sequence(vector<Node>& list, string str, int &f, int order = 0);

class OperateData
{
public:
    // ���췽��
    OperateData();

    // �ļ���д����
    static void read(vector<Node>& list, string account);
    static void write(vector<Node>& list, string account);

    // ��ȡvector<Node> list��������ɾ���ġ��顢����ķ���
    static void add(vector<Node>& list, Node a);                           //������ϵ��
    static bool del(vector<Node>& list, Node a);                           //ɾ����ϵ��
    static bool transform(vector<Node>& list, string name, Node a);        //�޸���ϵ��
    static int find(vector<Node>& list, string str, int order = 0);        //���� order=0������(Ĭ��)��order=1������
    static int findThread(vector<Node>& list, string str, int order = 0);  //���̲߳��� order=0������(Ĭ��)��order=1������
    static void sort(vector<Node>& list, int order = 0);                   //���� order=0������(Ĭ��)��order=1������
    static void listAllThread(vector<Node>& list);                         //���߳�������Լ��˺ŵ�ͨѶ¼��
    static void listAll(vector<Node>& list);                               //������Լ��˺ŵ�ͨѶ¼��
    static void listOne(vector<Node>& list, int index);                    //���һ���ڵ����Ϣ
private:
    static void setChange_time(Node& data);                                //�����޸�ʱ��
    static void exchangeName(vector<Node>& list, int k, int end);          //end=list.size()-1
    static void exchangePhone(vector<Node>& list, int k, int end);         //end=list.size()-1
    static void setData(Node& data, Node a);                               //�޸���ϵ�ˣ���transform����
};
