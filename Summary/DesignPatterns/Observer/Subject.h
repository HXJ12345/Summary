#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
#include "Observer.h"
using namespace std;
/**
* @filename         Subject.h
* @brief            观察者目标对象
* @author           HXJ
* @date             2022-05-25
**/



namespace HXJ {

template <typename Message>
class Subject
{
public:
    Subject();

    //添加观察者
    void Attach(Observer<Message>* observer);
    //删除观察者
    void Detach(Observer<Message>* observer);
    //通知
    void Notify(Message message);
private:
    list<Observer<Message>*> m_observers;

};

}

#endif // SUBJECT_H
