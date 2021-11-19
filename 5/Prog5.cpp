#include <iostream>
#include <string>

using namespace std;
using std::cout;

class Empty {

};

class Indie {
	int a;
	int b;
	string m_error = "";

public:
	Indie(int a, int b) {
		this->a = a;
		this->b = b;
		m_error += "����������, �������: " + std::to_string(a) + " �� " + std::to_string(b);
	}

	Indie() {}

	const char* what() const noexcept { return (m_error).c_str(); }
};

class DivideByZeroException : public std::exception
{
private:
	std::string m_error;
	int a;
	int b;
public:
	DivideByZeroException(std::string error, int a, int b)
		: m_error(error), a(a), b(b)
	{
		m_error += ", �����: " + to_string(a) + ", " + to_string(b);
	}

	const char* what() const noexcept { return (m_error).c_str(); }
};

int firstMethod(int a, int b);
int secondMethod(int a, int b);
int thirdMethod(int a, int b);
int fourthFirstMethod(int a, int b);
int fourthSecondMethod(int a, int b);
int fourthThirdMethod(int a, int b);

int main() {
	setlocale(LC_ALL, "russian");
	int a = 10, b = 4;
	cout << "a: " << a << ", b: " << b << endl;

	cout << "\n\t������ �����:\n";
	cout << "� �����: " << firstMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: �� ������� �� ����" << "\n";
	}
	catch (exception e) {
		cout << "��������� ����������\n";
	}

	cout << "\n\t������ �����:\n";
	cout << "� �����: " << secondMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: " << "�� ������ �� 0" << "\n";
	}
	catch (exception e) {
		cout << "��������� ����������: " << e.what() << "\n";
	}

	cout << "\n\t������ �����:\n";
	cout << "� �����: " << thirdMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: " << thirdMethod(a, 0) << "\n";
	}
	catch (runtime_error e) {
		cout << "��������� ����������: " << e.what() << "\n";
	}

	cout << "\n\t�������� ������ �����:\n";
	cout << "� �����: " << fourthFirstMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: " << fourthFirstMethod(a, 0) << "\n";
	}
	catch (Empty e) {
		cout << "��������� ����������: ������" << "\n";
	}

	cout << "\n\t�������� ������ �����:\n";
	cout << "� �����: " << fourthSecondMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: " << fourthSecondMethod(a, 0) << "\n";
	}
	catch (Indie e) {
		cout << "��������� ����������: " << e.what() << "\n";
	}

	cout << "\n\t�������� ������ �����:\n";
	cout << "� �����: " << fourthThirdMethod(a, b) << "\n";
	try {
		cout << "��� ������� �� 0: " << fourthThirdMethod(a, 0) << "\n";
	}
	catch (DivideByZeroException e) {
		cout << "��������� ����������: " << e.what() << "\n";
	}
}




//���������� ��� ������������ ����������
int firstMethod(int a, int b) {
	return a / b;
}

int secondMethod(int a, int b) {
	if (b == 0) {
		throw;
	}
	else {
		return a / b;
	}
}

int thirdMethod(int a, int b) {
	if (b == 0) {
		throw runtime_error("overlow error");
	}
	else {
		return a / b;
	}
}


int fourthFirstMethod(int a, int b) {
	if (b == 0) {
		throw Empty();
	}
	else {
		return a / b;
	}
}


int fourthSecondMethod(int a, int b) {
	if (b == 0) {
		throw Indie(a, b);
	}
	else {
		return a / b;
	}
}


int fourthThirdMethod(int a, int b) {
	if (b == 0) {
		throw DivideByZeroException("Divide by zero", a, b);
	}
	else {
		return a / b;
	}
}
