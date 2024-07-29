#pragma once
#include<iostream>

class Date
{
public:

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		static int MonthDay[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return MonthDay[month];
		}
	}

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		
		return *this;
	}

	// ��������
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}

	// ����+=����
	Date& operator+=(int day)
	{
		if (day < 0)
		{
			*this -= day;
		}
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	// ����+����
	Date operator+(int day)
	{
		Date tmp = *this;
		tmp += day;
		return tmp;
	}

	// ����-����
	Date operator-(int day)
	{
		Date tmp = *this;
		tmp -= day;
		return tmp;
	}

	// ����-=����
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			*this += day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
			}
			_day += GetMonthDay(_year, _month);

		}

		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++
	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	// ����--
	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	// ǰ��--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >���������
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if(_month==d._month)
			{
				return _day > d._day;
			}
		}

		return false;
	}

	// ==���������
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// >=���������
	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}

	// <���������
	bool operator < (const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				return _day < d._day;
			}
		}

		return false;
	}

	// <=���������
	bool operator <= (const Date& d)
	{
		return *this < d || *this == d;

	}

	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (min != max)
		{
			++min;
			++n;
		}

		return n * flag;
	}

private:
	int _year;
	int _month;
	int _day;
};