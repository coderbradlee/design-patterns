//备忘录模式：备忘录对象是一个用来存储另外一个对象内部状态快照的对象。
//备忘录模式的用意是在不破坏封装的条件下，将一个对象的状态捉住，
//并外部化，存储起来，从而可以在将来合适的时候把这个对象还原到存储起来的状态。
//设计备忘录三大步骤：
//1、设计记录的结点，存储记录
//2、设计记录的存储，vector,list,map,set,链表,图,数组,树
//3、操作记录的类，记录结点状态，设置结点状态，显示状态

//泡妞秘籍使用场景
//同时跟几个MM聊天时，一定要记清楚刚刚跟MM说了些什么话
//不然MM发现了会不高兴，幸亏有个备忘录，刚才与哪个MM说
//了什么话我都拷贝一份放到备忘录里面保存，这样可以随时
//查看以前的记录啦

//软件使用场景
//需要回放的软件，记录一下事件的状态
//1、数据库备份
//2、文档的编辑，撤销，恢复
//3、象棋的悔棋
//4、保存游戏进度

//优点：
//1、提供了一种状态恢复的实现机制，使得用户可以方便地回到一个特定的历史步骤
//2、实现了对信息的封装，一个备忘录对象是一个原对象状态的表示，不会被其他代码改动

//缺点：
//1、资源消耗过大，如果需要保存的原发器类的成员变量太多，就不可避免需要占用大量
//的存储空间，每保存一次对象的状态都需要消耗一定的系统资源

#include<iostream>
#include<string>
#include<vector>
using namespace std;

//备忘录的节点
class Memento
{
private:
	string state_;
public:	
	Memento(const string& state) //记录当前的状态
	{
		this->state_ = state;
	}
	
	string getState()
	{
		return state_;
	}

	void setState(const string& state)
	{
		this->state_ = state;
	}
};

//负责创建一个备忘录Memento，用以记录当前
//时刻它的内部状态，并可使用备忘录恢复内部状态
class Originator
{
private:
	string state_;
	Memento *pMemento_;
public:
	void setState(const string& state)
	{
		state_ = state;
	}

	Memento* createMemento()
	{
		return new Memento(state_);
	}

	void getState()
	{
		cout << state_ <<endl;
	}

	void restoreMemento(Memento* pMemento)
	{
		this->setState(pMemento->getState());
	}

};

//负责保存好备忘录
class Caretaker
{
public:
	vector<Memento*> memento_;
	void save(Memento* pMemento)
	{
		(this->memento_).push_back(pMemento);
	}
	Memento* getState(int i)
	{
		return memento_[i];
	}
};


int main()
{
	Originator * og = new Originator();
	Caretaker *ct = new Caretaker();

	og->setState("状态1");
	og->getState();
	ct->save(og->createMemento());

	og->setState("状态2");
	og->getState();
	ct->save(og->createMemento());

	og->setState("状态3");
	og->getState();
	ct->save(og->createMemento());

	og->restoreMemento(ct->getState(1));
	og->getState();

	og->restoreMemento(ct->getState(2));
	og->getState();
	
	og->restoreMemento(ct->getState(0));
	og->getState();	
  
  cin.get();

	return 0;
}

