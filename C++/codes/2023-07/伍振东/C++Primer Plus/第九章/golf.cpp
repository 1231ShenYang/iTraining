// 9.1����ʵ���ļ�
#include<iostream>
#include<string>
#include"golf.h"

void setgolf(golf& g, const char* name, int hc) {
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g) {
	using namespace std;
	cout << "�����û���������";
	cin >> g.fullname;
	if (strcmp(g.fullname, "") == 0) {
		return 0;
	}
	cout << "�����û��ĵȼ���";
	cin >> g.handicap;
	return 1;
}

void handicap(golf& g, int hc) {
	g.handicap = hc;
}

void showgolf(const golf& g) {
	using namespace std;
	cout << "�û�������" << g.fullname << endl;
	cout << "�û��ȼ���" << g.handicap << endl;
}