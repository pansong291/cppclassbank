#include"date.h"
#include<iostream.h>

Date::Date(int year,int month,int day)
{
	this->year=year;
	this->month=month;
	this->day=day;
}
void Date::show()const//输出当前日期
{
	cout<<"日期："<<year<<"年"<<month<<"月"<<day<<"日\n";
}
bool Date::isLeapYear()const//判断当年是否为闰年
{
	return year%4==0&&year%100!=0||year%400==0;
}
int Date::distance(const Date&date)const//计算当前日期与指定日期之间相差天数
{
	return 0;
}
int Date::getYear()const{return year;}
int Date::getMonth()const{return month;}
int Date::getDay()const{return day;}