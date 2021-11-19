#include <iostream>
#include <string>

/// <summary>
/// ����� ������
/// </summary>
class Triad
{
private:
	/// <summary>
	/// ������ �����
	/// </summary>
	int _a;

	/// <summary>
	/// ������ �����
	/// </summary>
	int _b;

	/// <summary>
	/// ������ �����
	/// </summary>
	int _c;

public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Triad() : _a(0), _b(0), _c(0) {}

	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="a">������� �����</param>
	/// <param name="b">������ �����</param>
	/// <param name="c">������� �����</param>
	Triad(int a, int b, int c) : _a(a), _b(b), _c(c) {}

	/// <summary>
	/// �������� ��������� ���������� �. ���������� ��� ������� ���� Triad
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>���������� ������ � ������ ���� ��� ������ �����</returns>
	bool operator==(const Triad& triad)
	{
		return this->_a == triad._a && this->_b == triad._b && this->_c == triad._c;
	}

	/// <summary>
	/// ������� ��������� ���������� ��� ���������� ��� ������� ���� Triad
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>���������� ������ � ������ ���� ���� �� ���� ������ ����� ���������� �� ������/returns>
	bool operator !=(const Triad& triad)
	{
		return this->_a != triad._a || this->_b != triad._b || this->_c != triad._c;
	}

	/// <summary>
	/// �������� ��������� ������ 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ���� ����� ������� �������</returns>
	bool operator > (const Triad& triad)
	{
		return this->_a > triad._a && this->_b > triad._b && this->_c > triad._c;
	}

	/// <summary>
	/// �������� ��������� ������
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ���� ����� ������� �������</returns>
	bool operator < (const Triad& triad)
	{
		return this->_a < triad._a&& this->_b < triad._b&& this->_c < triad._c;
	}

	/// <summary>
	/// �������� ��������� ������ ��� �����
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ��� ����� ���� ����� ������� �������</returns>
	bool operator >= (const Triad& triad)
	{
		return this->_a >= triad._a && this->_b >= triad._b && this->_c >= triad._c;
	}

	/// <summary>
	/// �������� ��������� ������ ��� �����
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ��� ����� ���� ����� ������� �������</returns>
	bool operator <= (const Triad& triad)
	{
		return this->_a <= triad._a && this->_b <= triad._b && this->_c <= triad._c;
	}

	/// <summary>
	/// ���������� �������� ������ ������
	/// </summary>
	/// <returns></returns>
	int getA()
	{
		return _a;
	}

	/// <summary>
	/// ���������� �������� ������ ������
	/// </summary>
	/// <returns></returns>
	int getB()
	{
		return _b;
	}

	/// <summary>
	/// ���������� �������� ������ ������
	/// </summary>
	/// <returns></returns>
	int getC()
	{
		return _c;
	}

	/// <summary>
	/// ������� ���������� �� �������
	/// </summary>
	void ShowInfo()
	{
		std::cout << "Triada: (" << _a << ", " << _b << ", " << _c << ")";
	}
};

/// <summary>
/// ����� �����
/// </summary>
class Time
{
private:
	/// <summary>
	/// ����
	/// </summary>
	int _h;

	/// <summary>
	/// ������
	/// </summary>
	int _m;

	/// <summary>
	/// �������
	/// </summary>
	int _s;

public:
	/// <summary>
	/// ����������� �� ��������� 
	/// </summary>
	Time() : _h(0), _m(0), _s(0) {}

	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="h"></param>
	/// <param name="m"></param>
	/// <param name="s"></param>
	Time(int h, int m, int s)
	{
		if (isHourse(h))
		{
			if (isMinutesOrSeconds(m))
			{
				if (isMinutesOrSeconds(s))
				{
					_h = h;
					_m = m;
					_s = s;
				}
				else
				{
					std::cout << "������� ������ ���� � ��������� [0, 59].\n";
					throw - 1;
				}
			}
			else
			{
				std::cout << "������ ������ ���� � ��������� [0, 59].\n";
				throw - 1;
			}
		}
		else
		{
			std::cout << "���� ������ ���� � ��������� [0, 24].\n";
			throw - 1;
		}
	}

	/// <summary>
	/// �������� ��������� ���������� �. ���������� ��� ������� ���� Time
	/// </summary>
	/// <param name="t"></param>
	/// <returns>���������� ������ � ������ ���� ��� ������ �����</returns>
	bool operator==(const Time& t)
	{
		return this->_h == t._h && this->_m == t._m && this->_s == t._s;
	}

	/// <summary>
	/// �������� ��������� ���������� �. ���������� ��� ������� ���� Time
	/// </summary>
	/// <param name="t"></param>
	/// <returns>���������� ������ � ������ ���� ���� �� ���� ������ �� ����� ������</returns>
	bool operator !=(const Time& t)
	{
		if (this->_h != t._h)
		{
			return true;
		}
		else
		{
			if (this->_m != t._m)
			{
				return true;
			}
			else
			{
				return this->_s != t._s;
			}
		}
	}

	/// <summary>
	/// �������� ��������� ������ 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ���� ����� ������� �������</returns>
	bool operator > (const Time& t)
	{
		if (this->_h > t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m > t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s > t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// �������� ��������� ������ 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ���� ����� ������� �������</returns>
	bool operator < (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s < t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// �������� ��������� ������ ��� ����� 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ��� ����� ���� ����� ������� �������</returns>
	bool operator <= (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s <= t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// �������� ��������� ������ ��� ����� 
	/// </summary>
	/// <param name="triad"></param>
	/// <returns>������ � ������ ���� ��� ������ ������� ������� ������ ��� ����� ���� ����� ������� �������</returns>
	bool operator >= (const Time& t)
	{
		if (this->_h < t._h)
		{
			return true;
		}
		else if (this->_h == t._h)
		{
			if (this->_m < t._m)
			{
				return true;
			}
			else if (this->_m == t._m)
			{
				return this->_s >= t._s;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	/// <summary>
	/// ���������� ����
	/// </summary>
	/// <returns></returns>
	int getHours()
	{
		return _h;
	}

	/// <summary>
	/// ���������� ������
	/// </summary>
	/// <returns></returns>
	int getMinutes()
	{
		return _m;
	}

	/// <summary>
	/// ���������� �������
	/// </summary>
	/// <returns></returns>
	int getSeconds()
	{
		return _s;
	}

	/// <summary>
	/// ������� ���������� � ������� �� �������
	/// </summary>
	/// <returns></returns>
	void ShowInfo()
	{
		std::cout << "Time: (";
		printLessTime(_h);
		std::cout << ":";
		printLessTime(_m);
		std::cout << ":";
		printLessTime(_s);
		std::cout << ")";
	}

private:
	/// <summary>
	/// ���������� ����� �������
	/// </summary>
	/// <param name="value"></param>
	void printLessTime(int value)
	{
		std::cout << ((value < 9) ? "0" + value : std::to_string(value));
	}

	/// <summary>
	/// �������� �� ������������ �����
	/// </summary>
	/// <param name="h"></param>
	/// <returns></returns>
	bool isHourse(int h)
	{
		return h >= 0 && h <= 24;
	}

	/// <summary>
	/// �������� �� ������������ ����� ��� ������
	/// </summary>
	/// <param name="h"></param>
	/// <returns></returns>
	bool isMinutesOrSeconds(int ms)
	{
		return ms >= 0 && ms < 60;
	}
};

/// <summary>
/// ���� ������������ 
/// </summary>
/// <returns>������ ���� Triad</returns>
Triad getTriadFromUser()
{
	int a;
	int b;
	int c;
	std::cout << "������� ������\n";
	std::cout << "������� ������ �����: ";
	std::cin >> a;
	std::cout << "������� ������ �����: ";
	std::cin >> b;
	std::cout << "������� ������ �����: ";
	std::cin >> c;
	return Triad(a, b, c);
}

/// <summary>
/// ���� ������������ 
/// </summary>
/// <returns>������ ���� Time</returns>
Time getTimeFromUser()
{
	int a;
	int b;
	int c;
	std::cout << "������� �����\n";
	std::cout << "������� ����: ";
	std::cin >> a;
	std::cout << "������� �����: ";
	std::cin >> b;
	std::cout << "������� �������: ";
	std::cin >> c;
	try
	{
		return Time(a, b, c);
	}
	catch (...)
	{

	}
}

/// <summary>
/// ����� ��������� Triad
/// </summary>
/// <param name="tr1"></param>
/// <param name="tr2"></param>
void Show�omparisoTriad(Triad tr1, Triad tr2)
{
	tr1.ShowInfo();
	std::cout << " == ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 == tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " != ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 != tr2) << "\n";

	tr1.ShowInfo();
	std::cout << " > ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 > tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " < ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 < tr2) << "\n";

	tr1.ShowInfo();
	std::cout << " >= ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 >= tr2) << "\n";
	tr1.ShowInfo();
	std::cout << " <= ";
	tr2.ShowInfo();
	std::cout << " = " << (tr1 <= tr2) << "\n";
}

/// <summary>
/// ����� ��������� Time
/// </summary>
/// <param name="tr1"></param>
/// <param name="tr2"></param>
void Show�omparisoTime(Time t1, Time t2)
{
	t1.ShowInfo();
	std::cout << " == ";
	t2.ShowInfo();
	std::cout << " = " << (t1 == t2) << "\n";
	t1.ShowInfo();
	std::cout << " != ";
	t2.ShowInfo();
	std::cout << " = " << (t1 != t2) << "\n";

	t1.ShowInfo();
	std::cout << " > ";
	t2.ShowInfo();
	std::cout << " = " << (t1 > t2) << "\n";
	t1.ShowInfo();
	std::cout << " < ";
	t2.ShowInfo();
	std::cout << " = " << (t1 < t2) << "\n";

	t1.ShowInfo();
	std::cout << " >= ";
	t2.ShowInfo();
	std::cout << " = " << (t1 >= t2) << "\n";
	t1.ShowInfo();
	std::cout << " <= ";
	t2.ShowInfo();
	std::cout << " = " << (t1 <= t2) << "\n";
}

/// <summary>
/// ����� ���� ��� ������ � Triad
/// </summary>
void ShowMenuTriad()
{
	bool isExist = false;
	int numberCommand;
	Triad tr1;
	Triad tr2;
	while (isExist == false)
	{
		std::cout << "1) ������ ������.\n";
		std::cout << "2) ������� ������ �� �������.\n";
		std::cout << "3) ������� ��������� �����.\n";
		std::cout << "4) ����������� ������������ ������ ������.\n";
		std::cout << "5) ����� ����� �� ���������.\n";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			tr1 = getTriadFromUser();
			tr2 = getTriadFromUser();
			break;
		}
		case 2:
		{
			tr1.ShowInfo();
			std::cout << '\n';
			tr2.ShowInfo();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			Show�omparisoTriad(tr1, tr2);
			break;
		}
		case 4:
		{
			int index;
			tr1.ShowInfo();
			std::cout << '\n';
			bool isCorrect = false;
			while (isCorrect == false)
			{
				std::cout << "������� ������ ������(1, 2, 3): ";
				std::cin >> index;
				switch (index)
				{
				case 1:
				{
					std::cout << tr1.getA() << '\n';
					isCorrect = true;
					break;
				}
				case 2:
				{
					std::cout << tr1.getB() << '\n';
					isCorrect = true;
					break;
				}
				case 3:
				{
					std::cout << tr1.getC() << '\n';
					isCorrect = true;
					break;
				}

				default:
					std::cout << "�������� ������!\n";
					break;
				}
			}
			break;
		}
		case 5:
		{
			isExist = true;
			break;
		}
		default:
			break;
		}
		std::cout << "--------------------\n";
	}
}

/// <summary>
/// ����� ���� ��� ������ � Time
/// </summary>
void ShowMenuTime()
{
	bool isExist = false;
	int numberCommand;
	Time t1;
	Time t2;
	while (isExist == false)
	{
		std::cout << "1) ������ �����.\n";
		std::cout << "2) ������� ����� �� �������.\n";
		std::cout << "3) ������� ��������� �������.\n";
		std::cout << "4) ����������� ������������ ������ �������.\n";
		std::cout << "5) ����� ����� �� ���������.\n";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			t1 = getTimeFromUser();
			t2 = getTimeFromUser();
			break;
		}
		case 2:
		{
			t1.ShowInfo();
			std::cout << '\n';
			t2.ShowInfo();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			Show�omparisoTime(t1, t2);
			break;
		}
		case 4:
		{
			int index;
			t1.ShowInfo();
			std::cout << '\n';
			bool isCorrect = false;
			while (isCorrect == false)
			{
				std::cout << "������� ������ �������(1, 2, 3): ";
				std::cin >> index;
				switch (index)
				{
				case 1:
				{
					std::cout << t1.getHours() << '\n';
					isCorrect = true;
					break;
				}
				case 2:
				{
					std::cout << t1.getMinutes() << '\n';
					isCorrect = true;
					break;
				}
				case 3:
				{
					std::cout << t1.getSeconds() << '\n';
					isCorrect = true;
					break;
				}

				default:
					std::cout << "�������� ������!\n";
					break;
				}
			}
			break;
		}
		case 5:
		{
			isExist = true;
			break;
		}
		default:
			std::cout << "�������� �������!\n";
			break;
		}
		std::cout << "--------------------\n";
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	bool isExist = false;
	int numberCommand;
	while (isExist == false)
	{
		std::cout << "1) ������ �� ��������.\n";
		std::cout << "2) ������ � ��������.\n";
		std::cout << "3) ����� �� ����������.\n";
		std::cin >> numberCommand;
		switch (numberCommand)
		{
		case 1:
		{
			ShowMenuTime();
			break;
		}
		case 2:
		{
			ShowMenuTriad();
			break;
		}
		case 3:
		{
			isExist = true;
			break;
		}
		default:
			std::cout << "�������� �������!\n";
			break;
		}
	}
	return 0;
}