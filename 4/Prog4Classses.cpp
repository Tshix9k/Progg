#include <iostream>
#include <string>

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
	virtual std::string showInfo() = 0;

	~Figure()
	{
		// ����������� ����������
	}
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
	std::string showInfo() override
	{
		std::string info;
		info.append("Figure Parallelogram\n");
		info.append("a: ");
		info.append(std::to_string(_a));
		info.append("\n");
		info.append("b: ");
		info.append("\n");
		info.append("h: ");
		info.append(std::to_string(_h));
		info.append("\n");
		return info;
	}
	~Parallelogram()
	{
		// ����������
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
		double pi = 3.141519;
		return _r * _r * pi;
	}

	/// <summary>
	/// ���������� �������� �����
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		double pi = 3.141519;
		return 2.0 * pi * _r;
	}

	/// <summary>
	/// ����� ���������� � ����� �� �������
	/// </summary>
	std::string showInfo()
	{
		std::string info;
		info.append("Figure Parallelogram\n");
		info.append("r: ");
		info.append(std::to_string(_r));
		return info;
	}

	~Circle()
	{
	// ����������
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
	std::string showInfo() override
	{
		std::string info;
		info.append("Figure Parallelogram\n");
		info.append("a: ");
		info.append(std::to_string( _a));
		info.append("\n");
		info.append("b: ");
		info.append(std::to_string(_b));
		info.append("\n");
		info.append("c: ");
		info.append(std::to_string(_c));
		info.append("\n");
		info.append("d: ");
		info.append(std::to_string(_d));
		info.append("\n");
		info.append("h: ");
		info.append(std::to_string(_h));
		info.append("\n");
		return info;
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
			std::cout << figure->showInfo() << '\n';
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
			continue;
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