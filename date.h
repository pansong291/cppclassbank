#ifndef _DATE_H_
#define _DATE_H_

class Date
{
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
	int getOrdinalDays()const;//�õ���ǰ�����Ǹ���ĵڼ���
};

#endif