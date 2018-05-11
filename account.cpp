#include"account.h"
#include<iostream.h>

SavingsAccount::SavingsAccount(int date,int id,double rate)
{
	lastDate=date;
	this->id=id;
	this->rate=rate;
	balance=0;
	accumulation=0;
	cout<<id<<"开户日："<<date<<"\n  余额：0\n  利率："<<rate<<endl;
}
double SavingsAccount::accumulate(int date)//获得到指定日期为止的存款金额
{
	accumulation+=balance*(date-lastDate);
	cout<<id<<"帐户累积金额："<<accumulation<<endl;
	return accumulation;
}
void SavingsAccount::deposit(int date,double amount)//存入现金
{
	cout<<id<<"帐户"<<date<<"日存入："<<amount<<endl;
	bool isFirstDeposit=balance<=0;
	if(!isFirstDeposit)accumulate(date);
	balance+=amount;
	cout<<"  余额："<<balance<<endl;
	lastDate=date;
}
void SavingsAccount::withdraw(int date,double amount)//取出现金
{
	cout<<id<<"帐户"<<date<<"日取出："<<amount<<endl;
	if(amount>balance)
	{
		cout<<"  余额不足\n";
		return;
	}
	accumulate(date);
	balance-=amount;
	cout<<"  余额："<<balance<<endl;
	lastDate=date;
}
void SavingsAccount::settle(int date)//结算利息
{
	double rje,lx;
	cout<<id<<"帐户"<<date<<"日结算利息\n";
	accumulate(date);
	rje=accumulation/date;
	lx=rje*rate;
	cout<<"  日均额："<<rje<<endl;
	cout<<"  利息："<<lx<<endl;
	balance+=lx;
}
void SavingsAccount::show()//输出账户信息
{
	cout<<"帐户："<<id<<endl;
	cout<<"余额："<<balance<<endl;
}
int SavingsAccount::getId(){return id;}
double SavingsAccount::getBalance(){return balance;}
double SavingsAccount::getRate(){return rate;}