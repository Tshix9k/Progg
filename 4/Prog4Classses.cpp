#include <iostream>
#include <string>

/// <summary>
/// Абстрактный класс фигура
/// </summary>
class Figure
{
public:
	/// <summary>
	/// Возвращает площадь фигуры
	/// </summary>
	/// <returns></returns>
	virtual double getSquare() = 0;

	/// <summary>
	/// Возвращает периметр фигуры
	/// </summary>
	/// <returns></returns>
	virtual double getPerimeter() = 0;

	/// <summary>
	/// Вывод информации о фигуре на монитор
	/// </summary>
	virtual std::string showInfo() = 0;

	~Figure()
	{
		// виртуальный деструктор
	}
};

/// <summary>
/// Класс Параллелограм
/// </summary>
class Parallelogram : public Figure
{
private:
	/// <summary>
	/// Большая сторона
	/// </summary>
	double _a;
	/// <summary>
	/// Меньшая сторона
	/// </summary>
	double _b;
	/// <summary>
	/// Высота к большей стороне
	/// </summary>
	double _h;
public:
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="a">большая сторона</param>
	/// <param name="b">меньшая сторона</param>
	/// <param name="h">высота к большей стороне</param>
	Parallelogram(double a, double b, double h) : _a(a), _b(b), _h(h)
	{}

	/// <summary>
	/// Возвращает площадь параллелограмма 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		return _a * _h;
	}

	/// <summary>
	/// Возвращает Периметр параллелограмма
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		return _a * 2 + _b * 2;
	}

	/// <summary>
	/// Вывод информации о параллелограме на монитор
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
		// деструктор
	}
};

/// <summary>
/// Класс круг
/// </summary>
class Circle : public Figure
{
private:
	/// <summary>
	/// Радиус
	/// </summary>
	double _r;

public:
	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="r">радиус</param>
	Circle(double r) : _r(r)
	{}

	/// <summary>
	/// Возвращает площадь круга 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		double pi = 3.141519;
		return _r * _r * pi;
	}

	/// <summary>
	/// Возвращает Периметр круга
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		double pi = 3.141519;
		return 2.0 * pi * _r;
	}

	/// <summary>
	/// Вывод информации о круге на монитор
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
	// деструктор
	}
};

/// <summary>
/// Класс трапеция
/// </summary>
class Trapeze : public Figure
{
private:
	/// <summary>
	/// Большее основание трапеции
	/// </summary>
	double _a;
	
	/// <summary>
	/// Меньшее основание трапеции
	/// </summary>
	double _b;
	
	/// <summary>
	/// Левая сторона трапеции
	/// </summary>
	double _c;

	/// <summary>
	/// Правая сторона трапеции
	/// </summary>
	double _d;

	/// <summary>
	/// Высота к большему основанию
	/// </summary>
	double _h;

public:
	/// <summary>
	/// Конструкор с параметрами
	/// </summary>
	/// <param name="a">Большее основание трапеции</param>
	/// <param name="b">Меньшее основание трапеции</param>
	/// <param name="c">Левая сторона трапеции</param>
	/// <param name="d">Правая сторона трапеции</param>
	/// <param name="h">Высота к большему основанию</param>
	Trapeze(double a, double b, double c, double d, double h) : _a(a), _b(b), _c(c), _d(d), _h(h)
	{}

	/// <summary>
	/// Возвращает площадь трапеции 
	/// </summary>
	/// <returns></returns>
	double getSquare() override
	{
		return _a * _b * _h / 2.0;
	}

	/// <summary>
	/// Возвращает Периметр трапеции
	/// </summary>
	/// <returns></returns>
	double getPerimeter() override
	{
		return _a * _b * _c * _d;
	}

	/// <summary>
	/// Вывод информации о трапеции на монитор
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
/// Вывод меню
/// </summary>
void ShowMenu()
{
	std::cout << "1) Круг:\n";
	std::cout << "2) Параллелограм:\n";
	std::cout << "3) Трапеция:\n";
	std::cout << "4) Выйти из программы:\n";
	std::cout << "Введите номер команды: ";
}

/// <summary>
/// Показать действия с фигурой
/// </summary>
/// <param name="figure"></param>
void ShowAction(Figure* figure)
{
	if (figure == NULL)
	{
		return;
	}
	bool isExit = false; // флаг выхода из программы
	while (isExit == false)
	{
		int numberCommand;
		std::cout << "Выберете действие: \n";
		std::cout << "1) Площадь:\n";
		std::cout << "2) Периметр:\n";
		std::cout << "3) Показать информацию о фигуре:\n";
		std::cout << "4) Выйти из действий:\n";
		std::cout << "Введите номер команды: ";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
			std::cout << "Площадь:\n";
			std::cout << figure->getSquare() << '\n';
			break;
		case 2:
			std::cout << "Периметр:\n";
			std::cout << figure->getPerimeter() << '\n';
			break;
		case 3:
			std::cout << "Информацию о фигуре:\n";
			std::cout << figure->showInfo() << '\n';
			break;
		case 4:
			isExit = true;
			break;

		default:
			std::cout << "Неизвестная команда!\n";
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	bool isExit = false;
	int numberCommand; // номер команды 
	Figure* figure = NULL; // указатель на объект класса Figure
	while (isExit == false)
	{
		ShowMenu();
		std::cin >> numberCommand; // ввод команды
		switch (numberCommand)
		{
		case 1:
			std::cout << "Фигура Круг:\n";
			double r;
			std::cout << "Введите радиус: ";
			std::cin >> r;
			figure = new Circle(r); // присваиваем указателю Фигура новый объект типа круг
			break;

		case 2:
			std::cout << "Фигура Параллелограм:\n";
			double a;
			double b;
			double h;
			std::cout << "Введите сторону a(большую): ";
			std::cin >> a;
			std::cout << "Введите высоту к стороне a: ";
			std::cin >> h;
			std::cout << "Введите сторону b(меньшую): ";
			std::cin >> b;
			figure = new Parallelogram(a, b, h); // присваиваем указателю Фигура новый объект типа параллелограм
			break;

		case 3:
			std::cout << "Фигура Трапеция:\n";
			double c;
			double d;
			std::cout << "Введите сторону a: ";
			std::cin >> a;
			std::cout << "Введите сторону c: ";
			std::cin >> c;
			std::cout << "Введите сторону d: ";
			std::cin >> d;
			std::cout << "Введите сторону b(меньшую): ";
			std::cin >> b;
			std::cout << "Введите высоту к стороне a: ";
			std::cin >> h;
			figure = new Trapeze(a, b, c, d, h); // присваиваем указателю Фигура новый объект типа трапеция
			break;

		case 4:
			isExit = true;
			continue;
			break;

		default:
			std::cout << "Неизвестная команда!\n";
			break;
		}

		ShowAction(figure);
		std::cout << "-------------------------\n";
	}
	std::cout << "Программа закончила свою работу!\n";
	system("pause");
	return 0;
}