#include "Date.h"
//���캯����
Date::Date(int year = 1900, int month = 1, int day = 1) {
	if (year >= 1900 && month < 13 && day>0 && day <= GetMonthDay(year, month)) {
		//��ʼ���Ϸ����ٽ��и�ֵ
		_year = year;
		_month = month;
		_day = day;
	}
	else {
		cout << "����Ƿ�������" << endl;
	}
}

//�������캯����ǳ����/ֵ����
Date::Date(const Date& d) {
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//��ӡ����
void Date::Print() {
	cout << _year << "-" << _month << "-" << _day << endl;
}

//���������������

//+=������
Date& Date::operator+=(int day) {
	_day = _day + day;
	if (_day <= GetMonthDay(_year, _month)) {
		return *this;
	}
	while (_day  > GetMonthDay(_year, _month)) {
		_day = _day - GetMonthDay(_year, _month);
		_month = _month + 1;
		if (_month == 13) {
			_month = 1;
			++_year;
		}
	}
	return *this;
}

//ǰ��++������
Date& Date::operator++() {
	*this += 1;
	return *this;
}

//����++������
Date Date::operator++(int a) {
	Date ret(*this);
	*this += 1;
	return ret;
}

//-=������
Date& Date::operator-=(int day) {
	_day = _day - day;
	if (_day > 0 && _day <= GetMonthDay(_year, _month)) {
		return *this;
	}
	while (_day <= 0 || _day>GetMonthDay(_year,_month)) {
		_day = GetMonthDay(_year, _month-1) + _day;
		_month--;
		if (_month == 0) {
			_month = 12;
			_year--;
		}
	}
	return *this;
}

//ǰ��--������
Date& Date::operator--() {
	*this -= 1;
	return *this;
}

//����--������
Date Date::operator--(int a) {
	Date ret(*this);
	*this -= 1;
	return ret;
}

//> ������
bool Date::operator>(const Date& d)const {
	if (_year > d._year) {
		return true;
	}
	else if (_year == d._year) {
		if (_month > d._month) {
			return true;
		}
		else if (_month == d._month) {
			if (_day > d._day) {
				return true;
			}
		}
	}
	return false;
}

//>= ������
bool Date::operator>=(const Date& d) const {
	//>= ����<ȡ��
	return !(*this < d);
}

//< ������
bool Date:: operator<(const Date& d) const {
	//< ����>= ȡ��
	return !(*this > d || *this == d);
}

//<= ������
bool Date::operator<=(const Date& d) const {
	//<= ����>ȡ��
	return !(*this > d);
}

//== ������
bool Date::operator==(const Date& d) const {
	return _year == d._year
		&&_month == d._month
		&&_day == d._day;
}

//!= ������
bool Date::operator!=(const Date& d) const {
	return !(*this == d);
}

//+ ������
Date Date::operator+(int day) const {
	Date ret(*this);
	ret += day;
	return ret;
}

//- ������
//Date Date::operator-(int day) const {
//	Date ret(*this);
//	ret -= day;
//	return ret;
//}

//����-����
int Date:: operator-(const Date&d) {
	//��ȡ���н�С������
	Date d2 = d;	//��������
	bool key = (*this < d2);
	int count = 0;
	if (key) {
		while (*this == d2) {
			this->_day++;
			count++;
		}
	}
	else {
		count = 0;
		while (*this == d2) {
			d2._day++;
			count++;
		}
	}
	return count;
}





void test() {
	Date d1(1999, 1, 2);
	d1.Print();
	d1 += 30;
	d1.Print();
	Date d2(d1);
	//d2 += 10;
	//d2.Print();
	//++d2;
	//d2.Print();
	//d2++;
	//d2.Print();
	//d2 -= 10;
	//d2.Print();
	//(--d2).Print();
	
	d2.Print();
	bool key = (d2 <= d1);
	if (key) {
		cout << "true!" << endl;
	}
	else {
		cout << "false!" << endl;
	}

	d2 -= 10;
	d2.Print();


	(d2 + 2).Print();
	int count = d2 - d1;
	cout << "��������֮�����" << count << "��" << endl;

}

int main() {
	test();
	system("pause");
	return 0;
}

