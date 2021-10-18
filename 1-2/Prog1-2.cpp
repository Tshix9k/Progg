#pragma once
#include<stdint.h>
#include<string>
#include<iostream>
#include <sstream>
#include <vector>
#include<cmath>

using namespace std;
typedef unsigned int uint;
/*
* Класс для работы со временем в формате "час:минута:секунда"
*/
class Time
{
private:
	uint hour;
	uint minute;
	uint seconds;
	/**
	\brief	Устанавливает значиния для времени
	*/

public:
	/**
	\brief	Конструктор с параметрами/по умолчанию
	*/
	Time(uint hour = 0, uint minute = 0, uint seconds = 0) {
		this->hour = hour;
		this->minute = minute;
		this->seconds = seconds;
	}
	/**
	\brief	Конструктор с сторокой в параметрах
	*/
	Time(string time = "00:00:00")
	{
		vector<uint> vec;
		istringstream iss(time);
		string str;
		int val;

		while (getline(iss, str, ':'))
		{
			stringstream ss;
			ss << str;
			ss >> val;
			vec.push_back(val);
		}
		hour = vec[0];
		minute = vec[1];
		seconds = vec[2];
	}
	/**
	\brief	Констурктор копирования
	*/
	Time(const Time& otherTime) {
		Time time = otherTime;
	}
	/**
	\brief	Дестрорутор
	*/
	~Time() {}

	/**
	\brief	Сетеры для каждой еденицы времени
	*/
	void setHour(uint hour) { this->hour = hour; }
	void setMinute(uint mminute) { this->minute = minute; }
	void setSecond(uint seconds) { this->seconds = seconds; }

	/**
	\brief	Гетеры для каждой еденицы времени
	*/
	uint getHour()const { return hour; }
	uint getMinute()const { return minute; }
	uint getSeconds()const { return seconds; }

	/**
	\brief	Перевод времени в секунды
	*/
	static uint ConvertToSec(Time time) {
		return (time.getSeconds() + time.getMinute() * 60 + time.getHour() * 60 * 60);
	}
	/**
	\brief	Перевод времени в минуты
	*/
	static uint ConvertToMin(Time time) {
		return (round(time.getSeconds() / 60) + time.getMinute() + time.getHour() * 60);
	}
	/**
	\brief Фунцкия для расчета разницы двух времен
	*/
	static Time TimeDifference(Time time1, Time time2) {
		uint hour = abs(int(time1.getHour() - time2.getHour()));
		uint minute = abs(int(time1.getMinute() - time2.getMinute()));
		uint seconds = abs(int(time1.getSeconds() - time2.getSeconds()));

		return Time(hour, minute, seconds);
	}

	/**
	\brief Вывод времени в консоль
	*/
	void ShowTime() const {
		cout << hour << ":" << minute << ":" << seconds << endl;
	}
	/**
	\brief Функция для добавления ко времени некотооре кол-во секунд
	*/
	void AddtTime(uint seconds) {
		if ((this->seconds + seconds) > 60) {
			this->seconds = (this->seconds + seconds) % 60;
			this->minute = (this->seconds + seconds) / 60;
		}
		else {
			this->seconds += seconds;
		}
	}

	/**
	\brief	Сравнение двух времен
	*/
	static bool AreEqual(Time time1, Time time2) {
		return time1.getHour() == time2.getHour() && time1.getMinute() == time2.getMinute() && time1.getSeconds() == time2.getSeconds();
	}
};
