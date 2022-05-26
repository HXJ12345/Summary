#ifndef OBSERVER_H
#define OBSERVER_H

/**
* @filename         Observer.h
* @brief            观察者模式
* @author           HXJ
* @date             2022-05-25
**/

//动机
    //在软件构建中，有时需要为某些对象建立一种"通知依赖关系"--一个对象(目标对象)的状态改变，
    //所有依赖对象（观察者对象）都将得到通知。如果这样的依赖关系过于紧密，将使得软件不能很好的抵御变化

    //使用面向对象技术可以将这种依赖关系弱化，并形成一种稳定的依赖关系。从而实现软件结构的松耦合。

//定义
    //定义对象间的一种一对多（变化）的依赖关系，以便当一个对象的状态发生改变时，所有依赖它的对象都得到通知并自动更新
namespace HXJ{

template <typename Message>
class Observer{

public:
    Observer(){}
    ~Observer(){};

    virtual void Update(Message message) = 0;
};

}


#endif // OBSERVER_H













