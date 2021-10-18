#include <iostream>

/// <summary>
/// ����������� ����� ������
/// </summary>
class Figure
{
public:
	/// <summary>
	/// ���������� ������� ������
	/// </summary>
	/// <returns></returns>
	virtual double getSquare() = 0;

	/// <summary>
	/// ���������� �������� ������
	/// </summary>
	/// <returns></returns>
	virtual double getPerimeter() = 0;

	/// <summary>
	/// ����� ���������� � ������ �� �������
	/// </summary>
	virtual void showInfo() = 0;
};

/// <summary>
/// ����� �������������
/// </summary>
class Parallelogram : public Figure
{
private:
	/// <summary>
	/// ������� �������
	/// </summary>
	double _a;
	/// <summary>
	/// ������� �������
	/// </summary>
	double _b;
	/// <summary>
	/// ������ � ������� �������
	/// </summary>
	double _h;
public:
	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="a">������� �������</param>
	/// <param name="b">������� �������</param>
	/// <param name="h">������ � ������� �������</param>
	Parallelogram(double a, double b, double h) : _a(a), _b(b), _h(h)
	{}

	/// <summary>
	/// ���������� ������� ��������������� 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		return _a * _h;
	}

	/// <summary>
	/// ���������� �������� ���������������
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		return _a * 2 + _b * 2;
	}

	/// <summary>
	/// ����� ���������� � �������������� �� �������
	/// </summary>
	void showInfo()
	{
		std::cout << "Figure Parallelogram\n";
		std::cout << "a: " << _a << '\n';
		std::cout << "b: " << _b << '\n';
		std::cout << "h: " << _h << '\n';
	}
};

/// <summary>
/// ����� ����
/// </summary>
class Circle : public Figure
{
private:
	/// <summary>
	/// ������
	/// </summary>
	double _r;

public:
	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="r">������</param>
	Circle(double r) : _r(r)
	{}

	/// <summary>
	/// ���������� ������� ����� 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		return _r * _r * 3.141519;
	}

	/// <summary>
	/// ���������� �������� �����
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		return 2.0 * 3.141519 * _r;
	}

	/// <summary>
	/// ����� ���������� � ����� �� �������
	/// </summary>
	void showInfo()
	{
		std::cout << "Figure Circle\n";
		std::cout << "r: " << _r << '\n';
	}
};

/// <summary>
/// ����� ��������
/// </summary>
class Trapeze : public Figure
{
private:
	/// <summary>
	/// ������� ��������� ��������
	/// </summary>
	double _a;
	
	/// <summary>
	/// ������� ��������� ��������
	/// </summary>
	double _b;
	
	/// <summary>
	/// ����� ������� ��������
	/// </summary>
	double _c;

	/// <summary>
	/// ������ ������� ��������
	/// </summary>
	double _d;

	/// <summary>
	/// ������ � �������� ���������
	/// </summary>
	double _h;

public:
	/// <summary>
	/// ���������� � �����������
	/// </summary>
	/// <param name="a">������� ��������� ��������</param>
	/// <param name="b">������� ��������� ��������</param>
	/// <param name="c">����� ������� ��������</param>
	/// <param name="d">������ ������� ��������</param>
	/// <param name="h">������ � �������� ���������</param>
	Trapeze(double a, double b, double c, double d, double h) : _a(a), _b(b), _c(c), _d(d), _h(h)
	{}

	/// <summary>
	/// ���������� ������� �������� 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		return _a * _b * _h / 2.0;
	}

	/// <summary>
	/// ���������� �������� ��������
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		return _a * _b * _c * _d;
	}

	/// <summary>
	/// ����� ���������� � �������� �� �������
	/// </summary>
	void showInfo()
	{
		std::cout << "Figure Trapeze\n";
		std::cout << "a: " << _a << '\n';
		std::cout << "b: " << _b << '\n';
		std::cout << "c: " << _c << '\n';
		std::cout << "d: " << _d << '\n';
		std::cout << "h: " << _h << '\n';
	}
};

/// <summary>
/// ����� ����
/// </summary>
void ShowMenu()
{
	std::cout << "1) ����:\n";
	std::cout << "2) �������������:\n";
	std::cout << "3) ��������:\n";
	std::cout << "4) ����� �� ���������:\n";
	std::cout << "������� ����� �������: ";
}

/// <summary>
/// �������� �������� � �������
/// </summary>
/// <param name="figure"></param>
void ShowAction(Figure* figure)
{
	if (figure == NULL)
	{
		return;
	}
	bool isExit = false; // ���� ������ �� ���������
	while (isExit == false)
	{
		int numberCommand;
		std::cout << "�������� ��������: \n";
		std::cout << "1) �������:\n";
		std::cout << "2) ��������:\n";
		std::cout << "3) �������� ���������� � ������:\n";
		std::cout << "4) ����� �� ��������:\n";
		std::cout << "������� ����� �������: ";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
			std::cout << "�������:\n";
			std::cout << figure->getSquare() << '\n';
			break;
		case 2:
			std::cout << "��������:\n";
			std::cout << figure->getPerimeter() << '\n';
			break;
		case 3:
			std::cout << "���������� � ������:\n";
			figure->showInfo();
			break;
		case 4:
			isExit = true;
			break;

		default:
			std::cout << "����������� �������!\n";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	bool isExit = false;
	int numberCommand; // ����� ������� 
	Figure* figure = NULL; // ��������� �� ������ ������ Figure
	while (isExit == false)
	{
		ShowMenu();
		std::cin >> numberCommand; // ���� �������
		switch (numberCommand)
		{
		case 1:
			std::cout << "������ ����:\n";
			double r;
			std::cout << "������� ������: ";
			std::cin >> r;
			figure = new Circle(r); // ����������� ��������� ������ ����� ������ ���� ����
			break;

		case 2:
			std::cout << "������ �������������:\n";
			double a;
			double b;
			double h;
			std::cout << "������� ������� a(�������): ";
			std::cin >> a;
			std::cout << "������� ������ � ������� a: ";
			std::cin >> h;
			std::cout << "������� ������� b(�������): ";
			std::cin >> b;
			figure = new Parallelogram(a, b, h); // ����������� ��������� ������ ����� ������ ���� �������������
			break;

		case 3:
			std::cout << "������ ��������:\n";
			double c;
			double d;
			std::cout << "������� ������� a: ";
			std::cin >> a;
			std::cout << "������� ������� c: ";
			std::cin >> c;
			std::cout << "������� ������� d: ";
			std::cin >> d;
			std::cout << "������� ������� b(�������): ";
			std::cin >> b;
			std::cout << "������� ������ � ������� a: ";
			std::cin >> h;
			figure = new Trapeze(a, b, c, d, h); // ����������� ��������� ������ ����� ������ ���� ��������
			break;

		case 4:
			isExit = true;
			break;

		default:
			std::cout << "����������� �������!\n";
			break;
		}
		ShowAction(figure);
		std::cout << "-------------------------\n";
	}
	std::cout << "��������� ��������� ���� ������!\n";
	system("pause");
	return 0;
}
