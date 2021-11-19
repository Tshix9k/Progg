#include "Time.h"

Time::Time()
{
	hour = 0;
	minute = 0;
	seconds = 0;
}

Time::Time(unsigned int hour, unsigned int minute, unsigned int seconds)
{
	if(hour >= 24 || minute >= 61 || seconds >= 61)
	{
		throw std::invalid_argument("Invalic argument");
	}
	this->hour = hour;
	this->minute = minute;
	this->seconds = seconds;
}

Time::Time(std::string& time)
{
	std::vector<unsigned int> vec;
	std::istringstream iss(time);
	std::string str;
	int val;

	while(getline(iss, str, ':'))
	{
		std::stringstream ss;
		ss << str;
		ss >> val;
		vec.push_back(val);
	}
	hour = vec[0];
	minute = vec[1];
	seconds = vec[2];
}

Time::Time(const Time& time)
{
	this->hour = time.hour;
	this->minute = time.minute;
	this->seconds = time.seconds;
}

Time::~Time() {}

void Time::setHour(unsigned int hour) { this->hour = hour; }
void Time::setMinute(unsigned int mminute) { this->minute = minute; }
void Time::setSecond(unsigned int seconds) { this->seconds = seconds; }

unsigned int Time::getHour()const { return hour; }
unsigned int Time::getMinute()const { return minute; }
unsigned int Time::getSeconds()const { return seconds; }

unsigned int Time::ConvertToSec(Time& time)
{
	int numberSecondsInHour = 3600;
	int numberSecondsInMinute = 60;
	return (time.getSeconds() + time.getMinute() * numberSecondsInMinute + time.getHour() * numberSecondsInHour);
}

unsigned int Time::ConvertToMin(Time& time)
{
	return unsigned int(round(time.getSeconds() / 60) + time.getMinute() + time.getHour() * 60);
}

Time Time::TimeDifference(Time& time1, Time& time2)
{
	unsigned int hour = abs(int(time1.getHour() - time2.getHour()));
	unsigned int minute = abs(int(time1.getMinute() - time2.getMinute()));
	unsigned int seconds = abs(int(time1.getSeconds() - time2.getSeconds()));

	return Time(hour, minute, seconds);
}

std::ostream& operator<< (std::ostream& out, const Time& time)
{
	out << time.hour << ":" << time.minute << ":" << time.seconds;
	return out;
}

bool Time::AreEqual(Time& time1, Time& time2)
{
	return time1.getHour() == time2.getHour() && time1.getMinute() == time2.getMinute() && time1.getSeconds() == time2.getSeconds();
}

void Time::AddtTime(unsigned int seconds)
{
	if((this->seconds + seconds) > 60)
	{
		this->seconds = (this->seconds + seconds) % 60;
		this->minute = (this->seconds + seconds) / 60;
	}
	else
	{
		this->seconds += seconds;
	}
}