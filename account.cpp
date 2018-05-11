#include"account.h"
#include<iostream.h>

SavingsAccount::SavingsAccount(int date,int id,double rate)
{
	lastDate=date;
	this->id=id;
	this->rate=rate;
	balance=0;
	accumulation=0;
	cout<<id<<"�����գ�"<<date<<"\n  ��0\n  ���ʣ�"<<rate<<endl;
}
double SavingsAccount::accumulate(int date)//��õ�ָ������Ϊֹ�Ĵ����
{
	accumulation+=balance*(date-lastDate);
	cout<<id<<"�ʻ��ۻ���"<<accumulation<<endl;
	return accumulation;
}
void SavingsAccount::deposit(int date,double amount)//�����ֽ�
{
	cout<<id<<"�ʻ�"<<date<<"�մ��룺"<<amount<<endl;
	bool isFirstDeposit=balance<=0;
	if(!isFirstDeposit)accumulate(date);
	balance+=amount;
	cout<<"  ��"<<balance<<endl;
	lastDate=date;
}
void SavingsAccount::withdraw(int date,double amount)//ȡ���ֽ�
{
	cout<<id<<"�ʻ�"<<date<<"��ȡ����"<<amount<<endl;
	if(amount>balance)
	{
		cout<<"  ����\n";
		return;
	}
	accumulate(date);
	balance-=amount;
	cout<<"  ��"<<balance<<endl;
	lastDate=date;
}
void SavingsAccount::settle(int date)//������Ϣ
{
	double rje,lx;
	cout<<id<<"�ʻ�"<<date<<"�ս�����Ϣ\n";
	accumulate(date);
	rje=accumulation/date;
	lx=rje*rate;
	cout<<"  �վ��"<<rje<<endl;
	cout<<"  ��Ϣ��"<<lx<<endl;
	balance+=lx;
}
void SavingsAccount::show()//����˻���Ϣ
{
	cout<<"�ʻ���"<<id<<endl;
	cout<<"��"<<balance<<endl;
}
int SavingsAccount::getId(){return id;}
double SavingsAccount::getBalance(){return balance;}
double SavingsAccount::getRate(){return rate;}