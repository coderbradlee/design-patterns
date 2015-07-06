//策略模式：定义一系列算法，将每一个算法封装起来，并让它们可以相互替换。策略
//模式让算法可以独立于使用它的客户变化

//策略模式3个角色
//1、Context(环境类)
//2、Strategy(抽象策略类)
//3、ConcreteStrategy(具体策略类)

//泡妞秘籍使用场景
//跟不同类型MM约会，要用不同的策略，有的请电影比较好，
//有的则去吃小吃效果不错，有的去海边浪漫最合适，但目的都是为了得到MM的芳心
//我们追MM锦囊中有好多Strategy哦


//软件使用场景
//1、一个系统需要动态地在几种算法选择一种
//2、避免使用难以维护的多重条件选择语句
//3、不希望客户端知道复杂的、与算法相关的数据结构，提高算法的保密性与安全性

//具体场景
//1、影院售票系统，在系统中需要为不同类型的用户提供不同的电影票打折方式
//2、xml、txt、dat、access四种格式的数据操作，读取，删除，修改

//优点：
//1、提供了对开闭原则的完美支持，用户可以在不修改原有系统的基础上选择算法或行为
//2、提供了管理相关的算法族方法
//3、提供了一种可以替换继承关系的办法
//4、可以避免多重条件选择语句
//5、提供了一种算法复用机制，不同的环境类可以方便地复用策略类

//缺点：
//1、客户端必须知道所有的策略类，并自行选择使用哪一个策略类
//2、将造成系统产生很多具体策略类
//3、无法同时在客户端使用多个策略类

#include<iostream>
#include<string>

using namespace std;

/**************策略基类****************************/

//主要定义了虚函数
class Strategy{
public:
	virtual void Interface() = 0;
	virtual ~Strategy(){}
};


/***************具体策略类***************************/

//负责对子类定义的虚函数进行具体实现
class ConcreteStrategyA : public Strategy{
public:
	void Interface(){
		cout << "ConcreteStrategyA::Interface..."<<endl;
	}
};

class ConcreteStrategyB: public Strategy{
public:
	void Interface(){
		cout << "ConcreteStrategyB:Interface..."<<endl;
	}
};

/*****************调度类********************************/
class Context{
public:
	Context(Strategy *stg)
	{
		stg_ = stg;
	}
	void DoAction()
	{
		stg_->Interface();
	}
private:
	Strategy *stg_;
};

int main()
{
	Strategy * pStrategyA = new ConcreteStrategyA();
	Context *pContextA = new Context(pStrategyA);
	
	pContextA->DoAction();

	Strategy * pStrategyB = new ConcreteStrategyB();
	Context *pContextB = new Context(pStrategyB);
	
	pContextB->DoAction();


	delete pContextA;
	delete pStrategyA;

	delete pContextB;
	delete pStrategyB;

	cin.get();

	return 0;
}

