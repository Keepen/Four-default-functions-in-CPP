#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Date {
public:
	Date(int year, int month, int day );
	//��ȡÿһ���µ��������
	inline int GetMonthDay(int year, int month) {	
		static int MonthArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((month == 2)
			&& (year % 4 == 0 && year % 100 != 0) && (year % 400 == 0)) {
			//�����2��
			return 29;
		}
		return MonthArray[month];
	}

	//�������캯����ǳ����/ֵ����
	Date(const Date& d); 

	//��ӡ����
	void Print();

	//���ֲ�����������
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// ǰ��++
	Date operator++(int);	// ����++

	Date& operator--();		// ǰ��--
	Date operator--(int);	// ����--

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