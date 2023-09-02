#pragma once
#pragma warning(disable : 4996)

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include <conio.h>
#include <unordered_map>
#include <time.h>
#include <thread>
#include <mutex>

#include "SetTextColor.h"

using namespace std;

// 10个元素
typedef struct Node {
    string name = "None";           //姓名
    string sex = "None";            //性别
    string work = "None";           //工作	

    string phone_num = "None";      //电话号码
    string kind_phone = "None";     //号码种类
    string note = "None";           //便签

    string change_time = "None";    //更改时间

    // 构造方法
    Node() {};
    Node(string name, string sex, string work,
        string phone_num, string kind_phone, string note) :
        name(name), sex(sex), work(work),
        phone_num(phone_num), kind_phone(kind_phone), note(note) {};
}Node;
