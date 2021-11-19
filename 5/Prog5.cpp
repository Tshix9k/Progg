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
		m_error += "Исключение, деление: " + std::to_string(a) + " на " + std::to_string(b);
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
		m_error += ", числа: " + to_string(a) + ", " + to_string(b);
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

	cout << "\n\tПервый метод:\n";
	cout << "В норме: " << firstMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: не делится на ноль" << "\n";
	}
	catch (exception e) {
		cout << "сработало исключение\n";
	}

	cout << "\n\tВторой метод:\n";
	cout << "В норме: " << secondMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: " << "не деится на 0" << "\n";
	}
	catch (exception e) {
		cout << "сработало исключение: " << e.what() << "\n";
	}

	cout << "\n\tТретий метод:\n";
	cout << "В норме: " << thirdMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: " << thirdMethod(a, 0) << "\n";
	}
	catch (runtime_error e) {
		cout << "сработало исключение: " << e.what() << "\n";
	}

	cout << "\n\tЧетвёртый первый метод:\n";
	cout << "В норме: " << fourthFirstMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: " << fourthFirstMethod(a, 0) << "\n";
	}
	catch (Empty e) {
		cout << "сработало исключение: пустое" << "\n";
	}

	cout << "\n\tЧетвёртый второй метод:\n";
	cout << "В норме: " << fourthSecondMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: " << fourthSecondMethod(a, 0) << "\n";
	}
	catch (Indie e) {
		cout << "сработало исключение: " << e.what() << "\n";
	}

	cout << "\n\tЧетвёртый третий метод:\n";
	cout << "В норме: " << fourthThirdMethod(a, b) << "\n";
	try {
		cout << "При деление на 0: " << fourthThirdMethod(a, 0) << "\n";
	}
	catch (DivideByZeroException e) {
		cout << "сработало исключение: " << e.what() << "\n";
	}
}




//Реализация без спецификации исключений
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
