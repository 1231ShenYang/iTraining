#include"stack.h"
#include<iostream>
#include<string>
using namespace std;

// ��ʼ������
Stack::Stack() {
	top = 0;
	payments = 0;
}

void Stack::add_customer() {
	if (top == 10) {
		cout << "��ǰջ�������޷���ӹ˿�!" << endl;
		return;
	}
	cout << "����˿͵�������";
	cin >> item[top].fullname;
	cout << "����˿͵����ѽ�";
	cin >> item[top].payment;
	top += 1;
}

void Stack::delete_customer() {
	if (top == 0) {
		cout << "��ǰ�˿�����Ϊ�գ��޷�ɾ���˿ͣ�" << endl;
		return;
	}
	top -= 1;
	payments += item[top].payment;
	cout << "�˿�" << item[top].fullname << "������ϣ�" << endl;
	cout << "��ǰ�����ܶ�Ϊ��" << payments << endl;
}
