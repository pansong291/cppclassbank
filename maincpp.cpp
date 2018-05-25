#include<iostream.h>
#include"date.h"
#include"account.h"

void main()
{
	Date d0(2008,11,1),d11(2008,11,5),d12(2008,12,5),
		d21(2008,11,25),d22(2008,12,20),d3(2009,1,1),
		d4(2008,11,15),d5(2008,12,1);
	SavingsAccount s0(d0,123,15e-3),s1(d0,456,15e-3);
	CreditAccount c0(d0,789,5e-4);
	s0.deposit(d11,5000);
	s0.deposit(d12,5500);
	s0.settle(d3);
	s1.deposit(d21,10000);
	s1.withdraw(d22,4000);
	s1.settle(d3);
	c0.withdraw(d4,2000);
	c0.repayment(d5,2016);
	s0.show();
	s1.show();
	c0.show();
	cout<<"¹²¼Æ"<<Account::getTotal()<<"Ôª\n";
}

// 	Date d1(2003,2,4),d2(2004,1,1);
// 	d1.show();
// 	d1.getOrdinalDays();
// 	d2.show();
// 	d2.getOrdinalDays();
// 	d1.distance(d2);
// 	d2.distance(d1);