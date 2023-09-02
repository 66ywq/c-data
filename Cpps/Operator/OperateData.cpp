#include "../../Heads/Operator/OperateData.h"

int flag = 0;
mutex mtx;

/*
* 子方法
*/
//正则表达式分割函数
void stringSplit(const string& str, const string& split, vector<string>& res) {
	std::regex reg(split);
	std::sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
	decltype(pos) end;
	for (; pos != end; ++pos) {
		res.push_back(pos->str());
	}
}

//在getBelongData里
void aBelong(vector<Node>& list, vector<Node>& data) {
	size_t const n = list.size();
	for (int i = 1; i < n / 3; ++i) {
		Node& temp = list.at(i);
		printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
			temp.name.c_str(), temp.sex.c_str(), temp.work.c_str(),
			temp.phone_num.c_str(), temp.kind_phone.c_str(), temp.note.c_str(),
			temp.change_time.c_str());
		/*if (temp.belong == str) {
			mtx.lock();
			data.push_back(temp);
			mtx.unlock();
		}*/

	}
}

void bBelong(vector<Node>& list, vector<Node>& data) {
	size_t const n = list.size();
	if (n == 1 || n == 2)
		return;
	for (int i = n / 3; i < 2 * n / 3; ++i) {
		Node& temp = list.at(i);
		printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
			temp.name.c_str(), temp.sex.c_str(), temp.work.c_str(),
			temp.phone_num.c_str(), temp.kind_phone.c_str(), temp.note.c_str(),
			temp.change_time.c_str());
		/*if (temp.belong == str) {
			mtx.lock();
			data.push_back(temp);
			mtx.unlock();
		}*/
	}
}

void cBelong(vector<Node>& list, vector<Node>& data) {
	size_t const n = list.size();
	if (n == 1)
		return;
	for (int i = 2 * n / 3; i < n; ++i) {
		Node& temp = list.at(i);
		printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
			temp.name.c_str(), temp.sex.c_str(), temp.work.c_str(),
			temp.phone_num.c_str(), temp.kind_phone.c_str(), temp.note.c_str(),
			temp.change_time.c_str());
		/*if (temp.belong == str) {
			mtx.lock();
			data.push_back(temp);
			mtx.unlock();
		}*/
	}
}

//在findThread里
void findSequence(vector<Node>& list, string str, int& f, int order) {
	size_t const n = list.size();
	if (n == 0) {
		f = -1;
		return;
	}
	int left = 1;
	int right = n - 1;
	int mid = 0;
	if (order == 0) {
		while (left <= right)
		{
			if (flag == 1) {
				f = -1;
				return;
			}
			mid = (left + right) / 2;
			if (list.at(mid).name < str)
				left = mid + 1;
			else if (list.at(mid).name > str)
				right = mid - 1;
			else {
				flag = 1;
				f = mid;
				return;
			}

		}
	}
	else if (order == 1) {
		while (left <= right)
		{
			if (flag == 1) {
				f = -1;
				return;
			}
			mid = (left + right) / 2;
			if (list.at(mid).phone_num < str)
				left = mid + 1;
			else if (list.at(mid).phone_num > str)
				right = mid - 1;
			else {
				flag = 1;
				f = mid;
				return;
			}
		}
	}
	f = -1;
	return;
}

void sequence(vector<Node>& list, string str, int& f, int order) {
	size_t const n = list.size();
	if (n == 0) {
		f = -1;
		return;
	}
	int left = 1;
	int right = n - 1;
	if (order == 0) {
		if ((str < list.at(left).name) || (str > list.at(right).name)) {
			f = -1;
			return;
		}
		while (left <= right) {
			if (flag == 1) {
				f = -1;
				return;
			}
			if (list.at(left).name == str) {
				flag = 1;
				f = left;
				return;
			}
			else
				++left;
			if (list.at(right).name == str) {
				flag = 1;
				f = right;
				return;
			}
			else
				--right;
		}
	}
	else if (order == 1) {
		if ((str < list.at(left).phone_num) || (str > list.at(right).phone_num)) {
			f = -1;
			return;
		}
		while (left <= right) {
			if (flag == 1) {
				f = -1;
				return;
			}
			if (list.at(left).phone_num == str) {
				flag = 1;
				f = left;
				return;
			}
			else
				++left;
			if (list.at(right).phone_num == str) {
				flag = 1;
				f = right;
				return;
			}
			else
				--right;
		}
	}
	f = -1;
	return;
}

/*
* 构造方法
*/
OperateData::OperateData() {
}

/*
* private方法
*/
void OperateData::setChange_time(Node& data) {
	time_t const now = time(0);
	data.change_time = ctime(&now);
	size_t const n = data.change_time.length();
	data.change_time.at(n - 1) = '\0';

}

void OperateData::exchangeName(vector<Node>& list, int k, int end) {
	int i = k;
	int j = i * 2;
	while (j <= end)
	{
		if (j < end && list.at(j).name < list.at(j + 1).name)
			j++;
		if (list.at(i).name < list.at(j).name) {
			list.at(0) = list.at(i);
			list.at(i) = list.at(j);
			list.at(j) = list.at(0);
		}
		i = j;
		j = i * 2;
	}
	return;
}

void OperateData::exchangePhone(vector<Node>& list, int k, int end) {
	int i = k;
	int j = i * 2;
	while (j <= end)
	{
		if (j < end && list.at(j).phone_num < list.at(
			j + 1).phone_num)
			j++;
		if (list.at(i).phone_num < list.at(j).phone_num) {
			list.at(0) = list.at(i);
			list.at(i) = list.at(j);
			list.at(j) = list.at(0);
		}
		i = j;
		j = i * 2;
	}
	return;
}

void OperateData::setData(Node& data, Node a) {
	if (a.kind_phone != "None" && a.kind_phone != "none")
		data.kind_phone = a.kind_phone;

	if (a.note != "None" && a.note != "none")
		data.note = a.note;

	if (a.phone_num != "None" && a.phone_num != "none")
		data.phone_num = a.phone_num;

	if (a.sex != "None" && a.sex != "none")
		data.sex = a.sex;

	if (a.work != "None" && a.work != "none")
		data.work = a.work;

	if (a.name != "None" && a.name != "none")
		data.name = a.name;

	setChange_time(data);
}

/*
* public方法
*/
void OperateData::read(vector<Node>& list, string account) {
	string filePath = "./Data/Contacts/" + account + ".csv";

	ifstream inFile;
	inFile.open(filePath, ios::out);
	string line;
	vector<string> res;
	Node emptyNode;

	list.push_back(emptyNode);
	while (getline(inFile, line)) {
		stringSplit(line, ",,", res);
		Node newNode;
		newNode.name = res.at(0);
		newNode.sex = res.at(1);
		newNode.work = res.at(2);
		newNode.phone_num = res.at(3);
		newNode.kind_phone = res.at(4);
		newNode.note = res.at(5);
		newNode.change_time = res.at(6);
		list.push_back(newNode);
		res.clear();
	}

	inFile.close();
	return;
}

void OperateData::write(vector<Node>& list, string account) {
	string filePath = "./Data/Contacts/" + account + ".csv";

	ofstream outFile;
	outFile.open(filePath, ios::out);

	auto node = list.begin() + 1;
	for (; node != list.end(); node++) {
		outFile << node->name << ",," << node->sex << ",," << node->work << ",,";
		outFile << node->phone_num << ",," << node->kind_phone << ",," << node->note << ",,";
		outFile << node->change_time;
		outFile << endl;
	}

	outFile.close();
	return;
}

void OperateData::add(vector<Node>& list, Node a) {
	setChange_time(a);
	list.push_back(a);
}

bool OperateData::del(vector<Node>& list, Node a) {
	int i = -1;
	i = find(list, a.name, 0);
	if (i != -1) {
		swap(list.at(i), list.back());
		list.pop_back();
	}
	int j = -1;
	j = find(list, a.phone_num, 1);
	if (j != -1) {
		swap(list.at(j), list.back());
		list.pop_back();
	}
	if (j == -1 && i == -1)
		return false;
	else
		return true;
}

bool OperateData::transform(vector<Node>& list, string name, Node a) {
	int i = -1;
	i = find(list, name, 0);
	if (i != -1) {
		setData(list.at(i), a);
		return true;
	}
	return false;
}

int OperateData::find(vector<Node>& list, string str, int order) {
	size_t const n = list.size();
	if (n == 0)
		return -1;
	int low = 1;
	int high = n - 1;
	int mid = 0;
	if (order == 0) {
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (list.at(mid).name < str)
				low = mid + 1;
			else if (list.at(mid).name > str)
				high = mid - 1;
			else
				return mid;
		}
	}
	else if (order == 1) {
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (list.at(mid).phone_num < str)
				low = mid + 1;
			else if (list.at(mid).phone_num > str)
				high = mid - 1;
			else
				return mid;
		}
	}
	return -1;
}

int OperateData::findThread(vector<Node>& list, string str, int order) {
	int a = -1;
	int b = -1;
	thread find1(findSequence, ref(list), str, ref(a), order);
	thread find2(sequence, ref(list), str, ref(b), order);
	find1.join();
	find2.join();
	/*cout << endl << "a:" << a << endl;
	cout << "b:" << b << endl;*/
	if (a == -1 && b == -1)
		return -1;
	else {
		if (a != -1)
			return a;
		else
			return b;
	}
}

void OperateData::sort(vector<Node>& list, int order) {
	if (list.capacity() <= 1) {
		return;
	}

	size_t const n = list.size() - 1;
	for (int k = n / 2; k >= 1; --k) {
		if(order==0)
			exchangeName(list, k, n);
		else
			exchangePhone(list, k, n);
	}
	for (int k = 1; k < n; ++k) {
		list.at(0) = list.at(1);
		list.at(1) = list.at(n - k + 1);
		list.at(n - k + 1) = list.at(0);
		if (order == 0)
			exchangeName(list, 1, n - k);
		else
			exchangePhone(list, 1, n - k);
	}

}

void OperateData::listAllThread(vector<Node>& list) {
	vector<Node> data;
	printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
		"姓名", "性别", "工作", "电话号码", "号码种类", "便签", "更改时间"
	);
	thread td1(aBelong, ref(list), ref(data));
	thread td2(bBelong, ref(list), ref(data));
	thread td3(cBelong, ref(list), ref(data));
	td1.join();
	td2.join();
	td3.join();
}

void OperateData::listAll(vector<Node>& list) {
	printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
		"姓名", "性别", "工作", "电话号码", "号码种类", "便签", "更改时间"
	);
	auto node = list.begin() + 1;
	for (; node != list.end(); node++) {
		printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
			node->name.c_str(), node->sex.c_str(), node->work.c_str(),
			node->phone_num.c_str(), node->kind_phone.c_str(), node->note.c_str(),
			node->change_time.c_str());
	}
}

void OperateData::listOne(vector<Node>& list, int index) {
	printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
		"姓名", "性别", "工作", "电话号码", "号码种类", "便签", "更改时间"
	);
	Node& temp = list.at(index);
	printf("%-10s%-10s%-15s%-15s%-15s%-15s%s\n",
		temp.name.c_str(), temp.sex.c_str(), temp.work.c_str(),
		temp.phone_num.c_str(), temp.kind_phone.c_str(), temp.note.c_str(),
		temp.change_time.c_str());
}
