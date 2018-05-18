#include"date.h"
#include<iostream.h>

Date::Date(int year,int month,int day)
{
	this->year=year;
	this->month=month;
	this->day=day;
	totalDays=0;
}
void Date::show()const//输出当前日期
{
	cout<<"日期："<<year<<"年"<<month<<"月"<<day<<"日\n";
}
bool Date::isLeapYear()const//判断当年是否为闰年
{
	return year%4==0&&year%100!=0||year%400==0;
}
int Date::distance(const Date& date)const//计算当前日期与指定日期之间相差天数
{
	int allDays=0;
	const Date *big,*small;
	//分出时间先后大小
	if(this->year>date.getYear())
	{
		big=this;
		small=&date;
	}else if(this->year<date.getYear())
	{
		big=&date;
		small=this;
	}else if(this->month>date.getMonth())
	{
		big=this;
		small=&date;
	}else if(this->month<date.getMonth())
	{
		big=&date;
		small=this;
	}else if(this->day>date.getDay())
	{
		big=this;
		small=&date;
	}else
	{
		big=&date;
		small=this;
	}
	//得到相差天数
	for(int i=small->getYear();i<big->getYear();i++)
	{
		allDays+=365;
		if(i%4==0&&i%100!=0||i%400==0)allDays++;
	}
	allDays-=small->getOrdinalDays();
	allDays+=big->getOrdinalDays();
	cout<<"  相差"<<allDays<<"天\n";
	return allDays;
}
int Date::getOrdinalDays()const//得到当前日期是该年的第几天
{
	int days=day;
	switch(month-1)
	{
	case 11:
		days+=30;
	case 10:
		days+=31;
	case 9:
		days+=30;
	case 8:
		days+=31;
	case 7:
		days+=31;
	case 6:
		days+=30;
	case 5:
		days+=31;
	case 4:
		days+=30;
	case 3:
		days+=31;
	case 2:
		days+=isLeapYear()?29:28;
	case 1:
		days+=31;
	}
	cout<<"  "<<month<<"月"<<day<<"日是"<<year<<"年的第"<<days<<"天\n";
	return days;
}
int Date::getYear()const{return year;}
int Date::getMonth()const{return month;}
int Date::getDay()const{return day;}

