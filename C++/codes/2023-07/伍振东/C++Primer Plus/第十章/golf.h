#pragma once
// 10.3ͷ�ļ�
const int Len = 40;
class golf
{
private:
	char fullname[Len];
	int handicap;

public:
	golf(const char* name, int hc);
	golf();
	void set_handicap(int hc);
	void showgolf();
};