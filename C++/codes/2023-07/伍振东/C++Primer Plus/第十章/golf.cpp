// 9.1����ʵ���ļ�
#include<iostream>
#include<string>
#include"golf.h"

golf::golf(const char* name, int hc) {
	strcpy_s(fullname, name);
	handicap = hc;
}

golf::golf() {
	using namespace std;
	cout << "�����û���������";
	cin >> fullname;
	cout << "�����û��ĵȼ���";
	cin >> handicap;
}

void golf::set_handicap(int hc) {
	handicap = hc;
}

void golf::showgolf() {
	using namespace std;
	cout << "�û�������" << fullname << endl;
	cout << "�û��ȼ���" << handicap << endl;
}