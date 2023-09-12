#include"sale.h"
#include<iostream>

void SALES::setSales(Sales& s, const double ar[], int n) {
	s.max = ar[0];
	s.min = ar[0];
	double sum = 0;
	for (int i = 0; i < n && i < 4; ++i) {
		s.sales[i] = ar[i];
		s.max = s.max >= ar[i] ? s.max : ar[i];
		s.min = s.min <= ar[i] ? s.min : ar[i];
		sum += ar[i];
	}
	s.average = sum / n;
	if (n < 4) {
		for (int i = n; i < 4; ++i) {
			s.sales[i] = 0;
		}
	}
}

// �����ĸ�Ԫ������ʼ��
void SALES::setSales(Sales& s) {
	using namespace std;
	cout << "�����ĸ����֣�";
	for (int i = 0; i < 4; ++i) {
		cin >> s.sales[i];
	}
	s.max = s.sales[0];
	s.min = s.sales[0];
	s.average = 0;
	for (int i = 0; i < 4; ++i) {
		s.max = s.max >= s.sales[i] ? s.max : s.sales[i];
		s.min = s.min <= s.sales[i] ? s.min : s.sales[i];
		s.average += s.sales[i];
	}
	s.average /= 4;
}

void SALES::showSales(const Sales& s) {
	using namespace std;
	cout << "�ĸ�Ԫ�طֱ�Ϊ��";
	for (int i = 0; i < 4; ++i) {
		cout << s.sales[i] << ' ';
	}
	cout << endl;
	cout << "���ֵΪ��" << s.max << endl;
	cout << "��СֵΪ��" << s.min << endl;
	cout << "ƽ��ֵΪ��" << s.average << endl;
}