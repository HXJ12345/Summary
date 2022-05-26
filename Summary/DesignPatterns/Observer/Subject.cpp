#include "Subject.h"

namespace HXJ {

template <typename Message>
void Subject<Message>::Attach(Observer<Message> *observer)
{
    if(observer != nullptr)
    {
        m_observers.push_back(observer);
    }
}

template <typename Message>
void Subject<Message>::Detach(Observer<Message> *observer)
{
    for(auto itr=m_observers.begin(); itr!=m_observers.end(); itr++)
    {
        if(*itr == observer)
        {
            itr = m_observers.erase(itr);
        }
    }

}

template <typename Message>
void Subject<Message>::Notify(Message message)
{
    for(typename std::list<Observer<Message> * >::iterator Iter=m_observers.begin();Iter!=m_observers.end();++Iter)
    {
        (*Iter)->OnChange(message);
    }
}

}
