#include<iostream>
#include<cmath>
#include<string>

using namespace std;


class CashSuper
{
public:
	virtual double acceptMoney(double money)=0;//抽象类，收钱的纯虚函数
};

class CashNormal:public CashSuper
{
public:
	double acceptMoney(double money)//正常收钱
	{
		return money;
	}
};

class CashRebate: public CashSuper //打折
{
private:
	double discount;
public:
	CashRebate(double dis)//折扣
	{
		discount = dis;
	}

	double acceptMoney(double money)//收钱
	{
		return money*discount;//折扣
	}

};

class CashReturn :public CashSuper
{
private:
	double moneyCondition;
	double moneyReturn;

public:
	CashReturn(double mc, double mr) //花多少钱，返回多少钱
	{
		moneyCondition = mc;
		moneyReturn = mr;
	}

	double acceptMoney(double money) //收钱，返款
	{
		double result = money;
		if(money >= moneyCondition)
		{
			result = money - floor(money /moneyCondition)*moneyReturn;
		}
		return result;
	}
};

class CashContext
{
private:
	CashSuper *cs;

public:
	CashContext(string str) //设置策略
	{
		if( str == "正常收费")
		{
			cs = new CashNormal();
		}
		else if( str == "打9折")
		{
			cs = new CashRebate(0.9);
		}
		else if( str == "满1000送200")
		{
			cs = new CashReturn(1000,200);
		}
	}

	double getResult(double money)
	{
		return cs->acceptMoney(money);
	}
};

int main()
{
	double money = 1000;
	CashContext *cc = new CashContext("正常收费");
	cout << cc->getResult(money);
	cin.get();
	return 0;
}


