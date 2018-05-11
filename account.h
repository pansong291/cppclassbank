#ifndef  _ACCOUNT_H_
#define  _ACCOUNT_H_

class SavingsAccount
{
	int id; //�ʺ�
	double balance;	//���
	double rate; //������
	int lastDate; //�ϴα����������
	double accumulation; //�����ۼ�֮��
	double accumulate(int date); //��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
public:
	SavingsAccount(int date,int id,double rate); //���캯��
	void deposit(int date,double amount); //�����ֽ�dateΪ���ڣ�amountΪ���
	void withdraw(int date,double amount); //ȡ���ֽ�
	void settle(int date); //������Ϣ��ÿ��1��1�յ���һ�θú���
	void show(); //����˻���Ϣ
	int getId();
	double getBalance();
	double getRate();
};

#endif