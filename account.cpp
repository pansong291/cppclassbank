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
void Account::show()const//����˻���Ϣ
{
	cout<<"�ʻ���"<<id<<endl;
	cout<<"��"<<balance<<endl;
}

/*********************  SavingsAccount  *********************/
SavingsAccount::SavingsAccount(Date date,int id,double rate):Account(id)
{
	lastDate=date;
	this->rate=rate;
	accumulation=0;
	cout<<getId()<<"�����գ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��\n  ��0\n  �����ʣ�"<<rate<<endl;
}
double SavingsAccount::accumulate(Date date)const//��õ�ָ������Ϊֹ�Ĵ����
{
	double x=getBalance()*lastDate.distance(date);
	cout<<getId()<<"�ʻ��ۻ���"<<accumulation+x<<endl;
	return x;
}
void SavingsAccount::deposit(Date date,double amount)//�����ֽ�
{
	cout<<getId()<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"�մ��룺"<<amount<<endl;
	bool isFirstDeposit=getBalance()<=0;//�Ƿ��һ�δ���
	if(!isFirstDeposit)accumulation+=accumulate(date);
	setBalance(getBalance()+amount);
	cout<<"  ��"<<getBalance()<<endl;
	setTotal(getTotal()+amount);
	lastDate=date;
}
void SavingsAccount::withdraw(Date date,double amount)//ȡ���ֽ�
{
	cout<<getId()<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��ȡ����"<<amount<<endl;
	if(amount>getBalance())
	{
		cout<<"  ����\n";
		return;
	}
	accumulation+=accumulate(date);
	setBalance(getBalance()-amount);
	cout<<"  ��"<<getBalance()<<endl;
	setTotal(getTotal()-amount);
	lastDate=date;
}
void SavingsAccount::settle(Date date)//������Ϣ
{
	double rje,lx;//�վ����Ϣ
	//�ж�ȥ���Ƿ�������
	int lastYear=date.getYear()-1;
	bool lastIsLeap=lastYear%4==0&&lastYear%100!=0||lastYear%400==0;
	cout<<getId()<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"�ս�����Ϣ\n";
	accumulation+=accumulate(date);
	//���ȥ�������꣬������ӦΪ366
	rje=accumulation/(lastIsLeap?366:365);
	lx=rje*rate;
	cout<<"  �վ��"<<rje<<endl;
	cout<<"  ��Ϣ��"<<lx<<endl;
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
	interest=0;
	credit=10000;
	cout<<getId()<<"�����գ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��\n  ��0\n  �����ʣ�"<<rate<<endl;
}
double CreditAccount::getDebt()const//���Ƿ���
{
	cout<<"  Ƿ��"<<getBalance()<<endl;
	return getBalance();
}
double CreditAccount::accumulate(Date date)const//�����ۻ���Ϣ
{
	return -getBalance()*(lastDate.distance(date))*rate;
}
void CreditAccount::withdraw(Date date,double amount)//ȡ���ֽ�
{
	cout<<getId()<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��ȡ����"<<amount<<endl;
	if(credit+getBalance()<=0||credit+getBalance()<amount)
	{
		cout<<"  ���ö�Ȳ���\n";
		return;
	}
	if(credit+getBalance()!=credit)interest+=accumulate(date);
	setBalance(getBalance()-amount);
	lastDate=date;
}
void CreditAccount::repayment(Date date,double amount)//����
{
	cout<<getId()<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"�ջ��"<<amount<<endl;
	if(getBalance()>=0)
	{
		cout<<"  ���軹��\n";
		return;
	}
	interest+=accumulate(date);
	cout<<"  ��Ϣ��"<<interest<<endl;
	if(amount+getDebt()<0)
	{
		cout<<"  �����\n";
		return;
	}
	setBalance(getBalance()+amount-interest);
	interest=0;
	lastDate=date;
}
double CreditAccount::getAvailableCredit()const//��ÿ������ö��
{
	cout<<"  �������ö�ȣ�"<<credit+getBalance()<<endl;
	return credit+getBalance();
}
