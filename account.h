#ifndef  _ACCOUNT_H_
#define  _ACCOUNT_H_
#include"date.h"

class Account
{
	int id;//�ʺ�
	static double total;//�����˻����ܽ��
	double balance;//���
public:
	Account(int id);//���캯��
	virtual void deposit(Date date,double amount)=0;//�����ֽ�
	virtual void withdraw(Date date,double amount)=0;//ȡ���ֽ�
	virtual void settle(Date date)=0;
	virtual void show()const=0;//����ʺ���Ϣ
	int getId()const;
	void setBalance(double balance);
	double getBalance()const;
	static void setTotal(double total);
	static double getTotal();
};

class SavingsAccount:public Account
{
	double rate;//������
	Date lastDate;//�ϴα����������
	double accumulation;//�����ۼ�֮��
	double accumulate(Date date)const;//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
public:
	SavingsAccount(Date date,int id,double rate);//���캯��
	void deposit(Date date,double amount);//�����ֽ�dateΪ���ڣ�amountΪ���
	void withdraw(Date date,double amount);//ȡ���ֽ�
	void settle(Date date);//������Ϣ��ÿ��1��1�յ���һ�θú���
	double getRate()const;
	void show()const;
};

class CreditAccount:public Account
{
	double allCredit;//�����ö��
	double credit;//���ö��
	double rate;//Ƿ���������
	double fee;//���ÿ����
	double interest;//��������Ϣ
	Date lastDate;
	double accumulate(Date date)const;//�����ۻ���Ϣ
	double getDebt()const;//���Ƿ���
public:
	CreditAccount(Date date,int id,double rate);
	double getAvailableCredit()const;//��ÿ������ö��
	void deposit(Date date,double amount);//�����ֽ�
	void withdraw(Date date,double amount);//ȡ���ֽ�
	//void repayment(Date date,double amount);//����
	void settle(Date date);//������Ϣ��ÿ��1�յ���һ�θú���
	void show()const;
};

#endif

