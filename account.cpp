#include"account.h"
#include"date.h"
#include<iostream.h>

double SavingsAccount::total=0;
SavingsAccount::SavingsAccount(Date date,int id,double rate)
{
	lastDate=date;
	this->id=id;
	this->rate=rate;
	balance=0;
	accumulation=0;
	cout<<id<<"开户日："<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日\n  余额：0\n  利率："<<rate<<endl;
}
double SavingsAccount::accumulate(Date date)const//获得到指定日期为止的存款金额
{
	double x=balance*lastDate.distance(date);
	cout<<id<<"帐户累积金额："<<accumulation+x<<endl;
	lastDate=date;
	return x;
}
void SavingsAccount::deposit(Date date,double amount)//存入现金
{
	cout<<id<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日存入："<<amount<<endl;
	bool isFirstDeposit=balance<=0;//是否第一次存入
	if(!isFirstDeposit)accumulation+=accumulate(date);
	balance+=amount;
	cout<<"  余额："<<balance<<endl;
	total+=amount;
}
void SavingsAccount::withdraw(Date date,double amount)//取出现金
{
	cout<<id<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日取出："<<amount<<endl;
	if(amount>balance)
	{
		cout<<"  余额不足\n";
		return;
	}
	accumulation+=accumulate(date);
	balance-=amount;
	cout<<"  余额："<<balance<<endl;
	total-=amount;
}
void SavingsAccount::settle(Date date)//结算利息
{
	double rje,lx;//日均额，利息
	//判断去年是否是闰年
	int lastYear=date.getYear()-1;
	bool lastIsLeap=lastYear%4==0&&lastYear%100!=0||lastYear%400==0;
	cout<<id<<"帐户"<<date.getYear()<<"年"<<date.getMonth()<<"月"
		<<date.getDay()<<"日结算利息\n";
	accumulation+=accumulate(date);
	//如果去年是闰年，则天数应为366
	rje=accumulation/(lastIsLeap?366:365);
	lx=rje*rate;
	cout<<"  日均额："<<rje<<endl;
	cout<<"  利息："<<lx<<endl;
	balance+=lx;
	total+=lx;
	accumulation=0;
}
void SavingsAccount::show()const//输出账户信息
{
	cout<<"帐户："<<id<<endl;
	cout<<"余额："<<balance<<endl;
}
int SavingsAccount::getId()const{return id;}
double SavingsAccount::getBalance()const{return balance;}
double SavingsAccount::getRate()const{return rate;}
double SavingsAccount::getTotal(){cout<<"共计"<<total<<"元\n";return total;}
