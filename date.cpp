#include"date.h"
#include<iostream.h>

Date::Date(int year,int month,int day)
{
	this->year=year;
	this->month=month;
	this->day=day;
}
void Date::show()const//�����ǰ����
{
	cout<<"���ڣ�"<<year<<"��"<<month<<"��"<<day<<"��\n";
}
bool Date::isLeapYear()const//�жϵ����Ƿ�Ϊ����
{
	return year%4==0&&year%100!=0||year%400==0;
}
int Date::distance(const Date&date)const//���㵱ǰ������ָ������֮���������
{
	return 0;
}
int Date::getYear()const{return year;}
int Date::getMonth()const{return month;}
int Date::getDay()const{return day;}