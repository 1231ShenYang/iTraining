#include<iostream>
#include<string>
using namespace std;

// ��������
double tiaohe(double x, double y);
void controller7_1();

// ��������ϰ��
// 7.1������ƽ����
double tiaohe(double x, double y) {
	return 2.0 * x * y / (x + y);
}
void controller7_1() {
	int x, y;
	cin >> x >> y;
	while (x != 0 && y != 0) {
		cout << tiaohe(x, y);
	}
}

// 7.2�����롢��ʾ�ͼ���ƽ���ɼ�
void controller7_2() {
	double grades[10] = { 0 };
	int len = 0;
	double sum_grade = 0;
	cout << "������߶���ɼ�������-1��ǰ��������";
	for (int i = 0; i < 10; ++i) {
		int t;
		cin >> t;
		if (t == -1) {
			break;
		}
		len += 1;
		grades[i] = t;
	}
	
	cout << "��ʾ�ɼ���";
	for (int i = 0; i < len; ++i) {
		sum_grade += grades[i];
		cout << grades[i] << ' ';
	}

	cout << endl;
	cout << "ƽ���ɼ���" << sum_grade / len << endl;
}

// 7.3���ṹ���뺯��
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

// ����1������box�ṹ����ʾ��Ա��ֵ
void show_value(box x) {
	cout << x.maker << endl;
	cout << x.height << endl;
	cout << x.width << endl;
	cout << x.length << endl;
	cout << x.volume << endl;
}

// ����2������box�ĵ�ַ���ı��Ա��ֵ
void change_value(box * x) {
	x->height = 10;
	x->length = 10;
	x->width = 10;
	cout << "�޸��Ժ��ֵ��" << endl;
	show_value(*x);
}


// ����3��ʹ��������������
void controller7_3() {
	box box1 = { "sdad", 20, 20, 20, 20 };
	show_value(box1);
	change_value(&box1);
}

// 7.4�������Ʊͷ���ĸ���
// �����������䣬�������ͷ���ĸ���
long double probability(unsigned numbers, unsigned picks) {
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--) {
		result = result * n / p;
	}
	return result;
}

void controller7_4() {
	long double result;
	cout << "������������䣺";
	int first, second;
	cin >> first >> second;
	result = probability(first, second);
	cout << "������ѡ�������䣺";
	cin >> first;
	result = result / first;
	cout << "��Ʊ�н����ʣ�" << result << endl;
}

// 7.5���ݹ麯�����ؽ׳�
long int jiecheng(unsigned n) {
	if (n == 1)return n;
	else {
		return n * jiecheng(n - 1);
	}
}

void controller7_5() {
	while (true) {
		cout << "����Ҫ����ĵݹ�ֵ��";
		int n;
		cin >> n;
		if (n <= 0)break;
		cout << jiecheng(n) << endl;
	}
}

// 7.6���Զ������麯��
// ����1�����ַ���ת��Ϊ����
double transfer(string a) {
	int n = a.length();
	double result = 0;
	for (int i = 0; i < n; ++i) {
		if (!isdigit(a[i])) {
			return -1;
		}
		result = result * 10 + (a[i] - '0');
	}
	return result;
}
// ����б�
int Fill_array(double numbers[], int length) {
	string temp;
	cout << "�����������飺" << endl;
	for (int i = 0; i < length; ++i) {
		cin >> temp;
		double t_n = transfer(temp);
		if (t_n == -1) {
			return i;
			break;
		}
		numbers[i] = t_n;
	}
	return length;
}
// ��ʾ�б�
void Show_array(double numbers[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << numbers[i] << ' ';
	}
	cout << endl;
}
// ��ת�б�
void Reverse_array(double numbers[], int length) {
	for (int i = 0; i < length / 2; ++i) {
		double temp = numbers[i];
		numbers[i] = numbers[length - i - 1];
		numbers[length - i - 1] = temp;
	}
}

void controller7_6() {
	double numbers[10];
	int len = Fill_array(numbers, 10);
	Show_array(numbers, len);
	Reverse_array(numbers, len);
	Show_array(numbers, len);
}

// 7.7��ʹ��ָ������������в���
double* fill_array(double* ar, double* limit) {
	double temp;
	double* p;
	int i = 0;
	for (p = ar; p != limit; ++p, ++i) {
		cout << "Enter value #" << (i + 1) << ":";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process treminated. \n";
			break;
		}
		else if (temp < 0) {
			break;
		}
		*p = temp;
	}
	return p;
}

void show_array(const double* ar,const double* end) {
	const double* p = ar;
	int i = 0;
	for (p = ar; p != end; ++p, ++i) {
		cout << "Property #" << (i + 1) << ": $";
		cout << *p << endl;
	}
}

void revalue(double r, double* ar, double* n) {
	for (double* p = ar; p != n; ++p) {
		*p *= r;
	}
}

void controller7_7() {
	double properties[5];
	double* size = fill_array(properties, properties + 5);
	show_array(properties, size);

	cout << "Enter revaluation factor: ";
	double factor;
	cin >> factor;
	revalue(factor, properties, size);
	show_array(properties, size);
	cout << "Done.\n";
	system("pause");

}

// 7.9����������ͽṹ�ĺ���
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		cout << "��" << i + 1 << "��ѧ��" << endl;
		cout << "����fullname��";
		cin >> pa[i].fullname;
		cout << "����hobby��";
		cin >> pa[i].hobby;
		cout << "����ooplevel��";
		cin >> pa[i].ooplevel;
		count++;
	}
	cout << "�������" << endl;
	return count;
}

void display1(student st) {
	cout << "fullname:" << st.fullname << endl;
	cout << "hobby:" << st.hobby << endl;
	cout << "ooplevel:" << st.ooplevel << endl;
}

void display2(const student* st) {
	cout << "fullname:" << st->fullname << endl;
	cout << "hobby:" << st->hobby << endl;
	cout << "ooplevel:" << st->ooplevel << endl;
}

void display3(const student pa[], int n) {
	for (int i = 0; i < n; ++i) {
		display1(pa[i]);
	}
}

void controller7_9() {
	cout << "Enter class size:";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n') {
		continue;
	}
	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; ++i) {
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete[] ptr_stu;
	cout << "Done\n";
}

// 7.10��calculate����
double add(double x, double y) {
	return x + y;
}

double sub(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}

double calculate(double x, double y, double(*func)(double x, double y)) {
	return func(x, y);
}

void controller7_10() {
	double(*pf[3])(double, double);
	pf[0] = add;
	pf[1] = sub;
	pf[2] = mul;

	double x, y;
	while (1) {
		cout << "����ɶԵ�x��y��������������˳�����";
		cin >> x >> y;
		if (!cin) {
			break;
		}
		cout << "����add��sub��mul��Ľ���ֱ�Ϊ��";
		for (int i = 0; i < 3; ++i) {
			cout<<pf[i](x, y)<<" ";
		}
		cout << endl;
	}

}

int main() {
	controller7_10();
	return 0;
}