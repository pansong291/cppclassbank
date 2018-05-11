#ifndef _DATE_H_
#define _DATE_H_

class Date
{
	int year,month,day;
	int totalDays;//该日期是从公元元年1月1日开始的第几天
public:
	Date(int year,int month,int day);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	void show()const;//输出当前日期
	bool isLeapYear()const;//判断当年是否为闰年
	int distance(const Date&date)const;//计算当前日期与指定日期之间相差天数
	int getOrdinalDays()const;//得到当前日期是该年的第几天
};

#endif