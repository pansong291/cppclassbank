#ifndef  _ACCOUNT_H_
#define  _ACCOUNT_H_
#include"date.h"

class Account
{
	int id;//帐号
	static double total;//所有账户的总金额
	double balance;//余额
public:
	Account(int id);//构造函数
	virtual void deposit(Date date,double amount)=0;//存入现金
	virtual void withdraw(Date date,double amount)=0;//取出现金
	virtual void settle(Date date)=0;
	virtual void show()const=0;//输出帐号信息
	int getId()const;
	void setBalance(double balance);
	double getBalance()const;
	static void setTotal(double total);
	static double getTotal();
};

class SavingsAccount:public Account
{
	double rate;//年利率
	Date lastDate;//上次变更余额的日期
	double accumulation;//余额按日累加之和
	double accumulate(Date date)const;//获得到指定日期为止的存款金额按日累积值
public:
	SavingsAccount(Date date,int id,double rate);//构造函数
	void deposit(Date date,double amount);//存入现金，date为日期，amount为金额
	void withdraw(Date date,double amount);//取出现金
	void settle(Date date);//结算利息，每年1月1日调用一次该函数
	double getRate()const;
	void show()const;
};

class CreditAccount:public Account
{
	double allCredit;//总信用额度
	double credit;//信用额度
	double rate;//欠款的日利率
	double fee;//信用卡年费
	double interest;//产生的利息
	Date lastDate;
	double accumulate(Date date)const;//计算累积利息
	double getDebt()const;//获得欠款额
public:
	CreditAccount(Date date,int id,double rate);
	double getAvailableCredit()const;//获得可用信用额度
	void deposit(Date date,double amount);//存入现金
	void withdraw(Date date,double amount);//取出现金
	//void repayment(Date date,double amount);//还款
	void settle(Date date);//结算利息，每月1日调用一次该函数
	void show()const;
};

#endif

