// 10.5
struct customer
{
	char fullname[35] = "";
	double payment = 0;
};

typedef customer Item;

class Stack {
private:
	// �ܹ�����ʮ���˿�
	Item item[10];
	int top;
	int payments;
public:
	Stack();
	void add_customer();
	void delete_customer();
};