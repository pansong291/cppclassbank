#include<iostream.h>
#include"date.h"
#include"account.h"

void main()
{
// 	SavingsAccount s0(1,123,15e-3),s1(1,456,15e-3);
// 	s0.deposit(5,5000);
// 	s0.deposit(45,5500);
// 	s1.deposit(25,10000);
// 	s1.withdraw(60,4000);
// 	s0.settle(90);
// 	s1.settle(90);
// 	s0.show();
// 	s1.show();
	Date d1(2003,1,1),d2(2009,1,1);
	d1.show();
	d1.getOrdinalDays();
	d2.show();
	d2.getOrdinalDays();
	d1.distance(d2);
	d2.distance(d1);
}
