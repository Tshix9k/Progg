#pragma once
#include <vector>
#include <sstream>

#ifndef TIME_H
#define TIME_H

/// <summary>
/// Класс для работы со временем в формате "час:минута:секунда"
/// </summary>
class Time
{
private:
	unsigned int hour;
	unsigned int minute;
	unsigned int seconds;

public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Time();

	/// <summary>
	/// Конструктор с параметрами
	/// </summary>
	/// <param name="hour"></param>
	/// <param name="minute"></param>
	/// <param name="seconds"></param>
	Time(unsigned int hour, unsigned int minute, unsigned int seconds);

	/// <summary>
	/// Конструктор с сторокой в параметрах
	/// </summary>
	/// <param name="time">строка</param>
	Time(std::string& time);

	/// <summary>
	/// Констурктор копирования
	/// </summary>
	/// <param name="otherTime"></param>
	Time(const Time& time);

	//Дестрорутор
	~Time();

	/// <summary>
	/// Сетеры для каждой еденицы времени
	/// </summary>

	void setHour(unsigned int hour);
	void setMinute(unsigned int mminute);
	void setSecond(unsigned int seconds);

	/// <summary>
	/// Гетеры для каждой еденицы времени
	/// </summary>

	unsigned int getHour()const;
	unsigned int getMinute()const;
	unsigned int getSeconds()const;

	/// <summary>
	/// Перевод времени в секунды
	/// </summary>
	/// <param name="time"></param>
	/// <returns>время в секундах</returns>
	static unsigned int ConvertToSec(Time& time);

	/// <summary>
	/// Перевод времени в минуты
	/// </summary>
	/// <param name="time"></param>
	/// <returns></returns>
	static unsigned int ConvertToMin(Time& time);
	/// <summary>
	/// Фунцкия для расчета разницы двух времен
	/// </summary>
	/// <param name="time1"></param>
	/// <param name="time2"></param>
	/// <returns></returns>
	static Time TimeDifference(Time& time1, Time& time2);

	/// <summary>
	/// Перегрузка оператора вывода
	/// </summary>
	/// <param name="out"></param>
	/// <param name="time"></param>
	/// <returns></returns>
	friend std::ostream& operator<< (std::ostream& out, const Time& time);

	/// <summary>
	/// Функция для добавления ко времени некотооре кол-во секунд
	/// </summary>
	/// <param name="seconds"></param>
	void AddtTime(unsigned int seconds);

	/// <summary>
	/// Сравнение двух времен
	/// </summary>
	/// <param name="time1"></param>
	/// <param name="time2"></param>
	/// <returns></returns>
	static bool AreEqual(Time& time1, Time& time2);
};
#endif