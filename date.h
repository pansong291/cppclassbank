#ifndef  _DATE_H_
#define  _DATE_H_

class Date
{
//	int toTheFirstDay[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
	int year,month,day;
	int totalDays;//�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
public:
	Date(int year,int month,int day);
	int getYear()const;
	int getMonth()const;
	int getDay()const;
	void show()const;//�����ǰ����
	bool isLeapYear()const;//�жϵ����Ƿ�Ϊ����
	int distance(const Date&date)const;//���㵱ǰ������ָ������֮���������
};

#endif