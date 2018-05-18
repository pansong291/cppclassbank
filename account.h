#ifndef  _ACCOUNT_H_
#define  _ACCOUNT_H_
#include"date.h"

class SavingsAccount
{
	static double total;//�����˻����ܽ��
	int id;//�ʺ�
	double balance;//���
	double rate;//������
	Date lastDate;//�ϴα����������
	double accumulation;//�����ۼ�֮��
	double accumulate(Date date)const;//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
public:
	SavingsAccount(Date date,int id,double rate);//���캯��
	void deposit(Date date,double amount);//�����ֽ�dateΪ���ڣ�amountΪ���
	void withdraw(Date date,double amount);//ȡ���ֽ�
	void settle(Date date);//������Ϣ��ÿ��1��1�յ���һ�θú���
	void show()const;//����˻���Ϣ
	int getId()const;
	double getBalance()const;
	double getRate()const;
	static double getTotal();
};

#endif

