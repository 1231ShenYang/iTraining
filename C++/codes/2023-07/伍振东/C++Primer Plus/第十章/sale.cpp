#include"sale.h"
#include<iostream>

Sales::Sales(const double ar[], int n) {
	
	max = ar[0];
	min = ar[0];
	double sum = 0;
	for (int i = 0; i < n && i < 4; ++i) {
		sales[i] = ar[i];
		max = max >= ar[i] ? max : ar[i];
		min = min <= ar[i] ? min : ar[i];
		sum += ar[i];
	}
	average = sum / n;
	if (n < 4) {
		for (int i = n; i < 4; ++i) {
			sales[i] = 0;
		}
	}
}

// �����ĸ�Ԫ������ʼ��
Sales::Sales() {
	using namespace std;
	cout << "�����ĸ����֣�";
	for (int i = 0; i < 4; ++i) {
		cin >> sales[i];
	}
	max = sales[0];
	min = sales[0];
	average = 0;
	for (int i = 0; i < 4; ++i) {
		max = max >= sales[i] ? max : sales[i];
		min = min <= sales[i] ? min : sales[i];
		average += sales[i];
	}
	average /= 4;
}

void Sales::showSales() {
	using namespace std;
	cout << "�ĸ�Ԫ�طֱ�Ϊ��";
	for (int i = 0; i < 4; ++i) {
		cout << sales[i] << ' ';
	}
	cout << endl;
	cout << "���ֵΪ��" << max << endl;
	cout << "��СֵΪ��" << min << endl;
	cout << "ƽ��ֵΪ��" << average << endl;
}