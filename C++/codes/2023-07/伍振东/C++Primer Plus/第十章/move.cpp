#include<iostream>
#include"move.h"
using namespace std;

Move::Move(double a, double b) {
	x = a;
	y = b;
}

void Move::showmove()const {
	cout << "x����Ϊ��" << x << endl;
	cout << "y����Ϊ��" << y << endl;
}

Move Move::add(const Move& m)const {
	Move temp(x, y);
	temp.x += m.x;
	temp.y += m.y;
	return temp;
}

void Move::reset(double a, double b) {
	x = a;
	y = b;
}