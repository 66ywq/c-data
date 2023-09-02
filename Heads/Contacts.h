#pragma once

#include "HeadRoot.h"
#include "Operator/Operator.h"

class Contacts {
public:
    void write(string account);                     //向文件写入通讯录
    void read(string account);                      //从文件读取通讯录
    int find(string str, int order);                //根据信息查找联系人，返回查找的索引
    void add(Node newNode);                         //增加联系人
    bool del(int index);                            //删除联系人
    bool transform(string name, Node newNode);      //修改联系人
    void listAll(int order = 0);                    //将通讯录列表
    void listOne(int index);                        //将单个联系人列表
    Node getNode(int index);                        //
private:
	vector<Node> nodeSet;
};
