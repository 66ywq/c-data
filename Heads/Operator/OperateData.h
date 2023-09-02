#pragma once
#include "../HeadRoot.h"

void stringSplit(const string& str, const string& split, vector<string>& res);  //正则表达式分割函数

//在getBelongData里
void aBelong(vector<Node>& list, vector<Node>& data);
void bBelong(vector<Node>& list, vector<Node>& data);
void cBelong(vector<Node>& list, vector<Node>& data);

//在findThread里
void findSequence(vector<Node>& list, string str, int &f, int order = 0);
void sequence(vector<Node>& list, string str, int &f, int order = 0);

class OperateData
{
public:
    // 构造方法
    OperateData();

    // 文件读写方法
    static void read(vector<Node>& list, string account);
    static void write(vector<Node>& list, string account);

    // 读取vector<Node> list进行增、删、改、查、排序的方法
    static void add(vector<Node>& list, Node a);                           //增加联系人
    static bool del(vector<Node>& list, Node a);                           //删除联系人
    static bool transform(vector<Node>& list, string name, Node a);        //修改联系人
    static int find(vector<Node>& list, string str, int order = 0);        //查找 order=0按姓名(默认)，order=1按号码
    static int findThread(vector<Node>& list, string str, int order = 0);  //多线程查找 order=0按姓名(默认)，order=1按号码
    static void sort(vector<Node>& list, int order = 0);                   //排序 order=0按姓名(默认)，order=1按号码
    static void listAllThread(vector<Node>& list);                         //多线程输出你自己账号的通讯录表
    static void listAll(vector<Node>& list);                               //输出你自己账号的通讯录表
    static void listOne(vector<Node>& list, int index);                    //输出一个节点的信息
private:
    static void setChange_time(Node& data);                                //设置修改时间
    static void exchangeName(vector<Node>& list, int k, int end);          //end=list.size()-1
    static void exchangePhone(vector<Node>& list, int k, int end);         //end=list.size()-1
    static void setData(Node& data, Node a);                               //修改联系人，被transform调用
};
