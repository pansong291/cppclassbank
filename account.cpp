#include"account.h"
#include"date.h"
#include<iostream.h>
/*********************  Account  *********************/
double Account::total=0;
Account::Account(int id)
{
	this->id=id;
	balance=0;
}
int Account::getId()const
{
	return id;
}
void Account::setBalance(double balance)
{
	this->balance=balance;
}
double Account::getBalance()const{return balance;}
void Account::setTotal(double total)
{
	Account::total=total;
}
double Account::getTotal(){return total;}
void Account::show()const//输出账户信息
{
	cout<<"帐户："<<id<<endl;
	cout<<"余额："<<balance<<endl;
}

/*********************  SavingsAccount  *********************/
SavingsAccount::SavingsAccount(Date date,int id,double rate):Account(id)
{
	lastDate=date;
	this->rate=rate;
	accumulation=0;
	cout<<getId()<<"开户日："<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日\n  余额：0\n  年利率："<<rate<<endl;
}
double SavingsAccount::accumulate(Date date)const//获得到指定日期为止的存款金额
{
	double x=getBalance()*lastDate.distance(date);
	cout<<getId()<<"帐户累积金额："<<accumulation+x<<endl;
	return x;
}
void SavingsAccount::deposit(Date date,double amount)//存入现金
{
	cout<<getId()<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日存入："<<amount<<endl;
	bool isFirstDeposit=getBalance()<=0;//是否第一次存入
	if(!isFirstDeposit)accumulation+=accumulate(date);
	setBalance(getBalance()+amount);
	cout<<"  余额："<<getBalance()<<endl;
	setTotal(getTotal()+amount);
	lastDate=date;
}
void SavingsAccount::withdraw(Date date,double amount)//取出现金
{
	cout<<getId()<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日取出："<<amount<<endl;
	if(amount>getBalance())
	{
		cout<<"  余额不足\n";
		return;
	}
	accumulation+=accumulate(date);
	setBalance(getBalance()-amount);
	cout<<"  余额："<<getBalance()<<endl;
	setTotal(getTotal()-amount);
	lastDate=date;
}
void SavingsAccount::settle(Date date)//结算利息
{
	double rje,lx;//日均额，利息
	//判断去年是否是闰年
	int lastYear=date.getYear()-1;
	bool lastIsLeap=lastYear%4==0&&lastYear%100!=0||lastYear%400==0;
	cout<<getId()<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日结算利息\n";
	accumulation+=accumulate(date);
	//如果去年是闰年，则天数应为366
	rje=accumulation/(lastIsLeap?366:365);
	lx=rje*rate;
	cout<<"  日均额："<<rje<<endl;
	cout<<"  利息："<<lx<<endl;
	setBalance(getBalance()+lx);
	setTotal(getTotal()+lx);
	accumulation=0;
	lastDate=date;
}
double SavingsAccount::getRate()const{return rate;}

/*********************  CreditAccount  *********************/
CreditAccount::CreditAccount(Date date,int id,double rate):Account(id)
{
	lastDate=date;
	this->rate=rate;
	allCredit=10000;
	credit=allCredit;
	cout<<getId()<<"开户日："<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日\n  余额：0\n  日利率："<<rate<<endl;
}
double CreditAccount::getDebt()const//获得欠款额
{
	double x=allCredit-credit+interest;
	return x;
}
void CreditAccount::accumulate(Date date)//计算累积利息
{
	interest+=(allCredit-credit)*(lastDate.distance(date))*rate;
}
void CreditAccount::withdraw(Date date,double amount)//取出现金
{
	if(credit<=0||credit<amount)
	{
		cout<<"信用额度不足\n";
		return;
	}
	if(credit!=allCredit)accumulate(date);
	credit-=amount;
	lastDate=date;
}
void CreditAccount::repayment(Date date,double amount)//还款
{
	if(credit==allCredit)
	{
		cout<<"无需还款\n";
		return;
	}
	accumulate(date);
	credit+=amount;
	lastDate=date;
}
double CreditAccount::getAvailableCredit()const//获得可用信用额度
{
	return credit;
}