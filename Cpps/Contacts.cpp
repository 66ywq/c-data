#include "../Heads/Contacts.h"

/*
* public方法
*/
void Contacts::write(string account) {
	OperateData::write(this->nodeSet, account);
}

void Contacts::read(string account) {
	OperateData::read(this->nodeSet, account);
	OperateData::sort(this->nodeSet);
}

int Contacts::find(string str, int order = 0) {
	OperateData::sort(this->nodeSet, order);
	return OperateData::find(this->nodeSet, str, order);
}

void Contacts::add(Node newNode) {
	OperateData::add(this->nodeSet, newNode);
}

bool Contacts::del(int index) {
	return OperateData::del(this->nodeSet, nodeSet.at(index));
}

bool Contacts::transform(string name, Node newNode) {
	return OperateData::transform(this->nodeSet, name, newNode);
}

void Contacts::listAll(int order) {
	OperateData::sort(this->nodeSet, order);
	//OperateData::listAll(this->nodeSet);
	OperateData::listAllThread(this->nodeSet);
}

void Contacts::listOne(int index) {
	OperateData::listOne(this->nodeSet, index);
}

Node Contacts::getNode(int index) {
	return this->nodeSet.at(index);
}
