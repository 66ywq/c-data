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

// 10��Ԫ��
typedef struct Node {
    string name = "None";           //����
    string sex = "None";            //�Ա�
    string work = "None";           //����	

    string phone_num = "None";      //�绰����
    string kind_phone = "None";     //��������
    string note = "None";           //��ǩ

    string change_time = "None";    //����ʱ��

    // ���췽��
    Node() {};
    Node(string name, string sex, string work,
        string phone_num, string kind_phone, string note) :
        name(name), sex(sex), work(work),
        phone_num(phone_num), kind_phone(kind_phone), note(note) {};
}Node;
