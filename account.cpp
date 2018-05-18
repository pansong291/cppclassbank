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
	cout<<id<<"�����գ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��\n  ��0\n  ���ʣ�"<<rate<<endl;
}
double SavingsAccount::accumulate(Date date)const//��õ�ָ������Ϊֹ�Ĵ����
{
	double x=balance*lastDate.distance(date);
	cout<<id<<"�ʻ��ۻ���"<<accumulation+x<<endl;
	lastDate=date;
	return x;
}
void SavingsAccount::deposit(Date date,double amount)//�����ֽ�
{
	cout<<id<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"�մ��룺"<<amount<<endl;
	bool isFirstDeposit=balance<=0;//�Ƿ��һ�δ���
	if(!isFirstDeposit)accumulation+=accumulate(date);
	balance+=amount;
	cout<<"  ��"<<balance<<endl;
	total+=amount;
}
void SavingsAccount::withdraw(Date date,double amount)//ȡ���ֽ�
{
	cout<<id<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"��ȡ����"<<amount<<endl;
	if(amount>balance)
	{
		cout<<"  ����\n";
		return;
	}
	accumulation+=accumulate(date);
	balance-=amount;
	cout<<"  ��"<<balance<<endl;
	total-=amount;
}
void SavingsAccount::settle(Date date)//������Ϣ
{
	double rje,lx;//�վ����Ϣ
	//�ж�ȥ���Ƿ�������
	int lastYear=date.getYear()-1;
	bool lastIsLeap=lastYear%4==0&&lastYear%100!=0||lastYear%400==0;
	cout<<id<<"�ʻ�"<<date.getYear()<<"��"<<date.getMonth()<<"��"
		<<date.getDay()<<"�ս�����Ϣ\n";
	accumulation+=accumulate(date);
	//���ȥ�������꣬������ӦΪ366
	rje=accumulation/(lastIsLeap?366:365);
	lx=rje*rate;
	cout<<"  �վ��"<<rje<<endl;
	cout<<"  ��Ϣ��"<<lx<<endl;
	balance+=lx;
	total+=lx;
	accumulation=0;
}
void SavingsAccount::show()const//����˻���Ϣ
{
	cout<<"�ʻ���"<<id<<endl;
	cout<<"��"<<balance<<endl;
}
int SavingsAccount::getId()const{return id;}
double SavingsAccount::getBalance()const{return balance;}
double SavingsAccount::getRate()const{return rate;}
double SavingsAccount::getTotal(){cout<<"����"<<total<<"Ԫ\n";return total;}
