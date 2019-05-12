#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Date {
public:
	Date(int year, int month, int day );
	//获取每一个月的最大天数
	inline int GetMonthDay(int year, int month) {	
		static int MonthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2)
			&& (year % 4 == 0 && year % 100 != 0) && (year % 400 == 0)) {
			//闰年的2月
			return 29;
		}
		return MonthArray[month];
	}

	//拷贝构造函数：浅拷贝/值拷贝
	Date(const Date& d); 

	//打印日期
	void Print();

	//各种操作符的重载
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// 前置++
	Date operator++(int);	// 后置++

	Date& operator--();		// 前置--
	Date operator--(int);	// 后置--

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);


private:
	int _year;
	int _month;
	int _day;
};