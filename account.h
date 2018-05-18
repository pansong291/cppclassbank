#ifndef  _ACCOUNT_H_
#define  _ACCOUNT_H_
#include"date.h"

class SavingsAccount
{
	static double total;//所有账户的总金额
	int id;//帐号
	double balance;//余额
	double rate;//年利率
	Date lastDate;//上次变更余额的日期
	double accumulation;//余额按日累加之和
	double accumulate(Date date)const;//获得到指定日期为止的存款金额按日累积值
public:
	SavingsAccount(Date date,int id,double rate);//构造函数
	void deposit(Date date,double amount);//存入现金，date为日期，amount为金额
	void withdraw(Date date,double amount);//取出现金
	void settle(Date date);//结算利息，每年1月1日调用一次该函数
	void show()const;//输出账户信息
	int getId()const;
	double getBalance()const;
	double getRate()const;
	static double getTotal();
};

#endif

