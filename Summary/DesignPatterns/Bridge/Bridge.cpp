#include "Bridge.h"


namespace HXJ{

//将不同的函数拆分
class MYMessagerImp{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MYMessagerImp(){}

};

class MYMessager{
public:
    virtual void Login() = 0;
    virtual void SendMessage() = 0;
    virtual void SendPicture() = 0;


    virtual ~MYMessager(){}

protected:
    MYMessagerImp* m_messagerImp;
};



//不同平台实现 n
class PCMessageBase : public MYMessager{
public:
    virtual void PlaySound()
    {
        //...
    }
    virtual void DrawShape()
    {
        //...
    }
    virtual void WriteText()
    {
        //...
    }
    virtual void Connect()
    {
        //...
    };
};

class MobileMessageBase : public MYMessager{
public:
    virtual void PlaySound()
    {
        //...
    }
    virtual void DrawShape()
    {
        //...
    }
    virtual void WriteText()
    {
        //...
    }
    virtual void Connect()
    {
        //...
    };
};

//不同的业务抽象 m
class MessagerLite: public MYMessager{ //经典版

public:
    virtual void Login()
    {
        m_messagerImp->Connect();
        //...
    }
    virtual void SendMessage()
    {
        m_messagerImp->WriteText();
        //...
    }
    virtual void SendPicture()
    {
        m_messagerImp->DrawShape();
        //...
    }
};

class MessagerPerfect: public MYMessager { //完美版

public:
    virtual void Login()
    {
        m_messagerImp->PlaySound();
        m_messagerImp->Connect();
        //...
    }
    virtual void SendMessage()
    {
        m_messagerImp->PlaySound();
        m_messagerImp->WriteText();
        //...
    }
    virtual void SendPicture()
    {
        m_messagerImp->PlaySound();
        m_messagerImp->DrawShape();
        //...
    }
};

//类个数 1 + n + m












}

