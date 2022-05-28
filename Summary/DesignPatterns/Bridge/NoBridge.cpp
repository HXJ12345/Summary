

namespace HXJ{

class MYMessager{
public:
    virtual void Login() = 0;
    virtual void SendMessage() = 0;
    virtual void SendPicture() = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MYMessager(){}

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
class PCMessagerLite : public PCMessageBase{ //经典版
public:
    virtual void Login()
    {
        PCMessageBase::Connect();
        //...
    }
    virtual void SendMessage()
    {
        PCMessageBase::WriteText();
        //...
    }
    virtual void SendPicture()
    {
        PCMessageBase::DrawShape();
        //...
    }
};

class PCMessagerPerfect : public PCMessageBase{ //完美版
public:
    virtual void Login()
    {
        PCMessageBase::PlaySound();
        PCMessageBase::Connect();
        //...
    }
    virtual void SendMessage()
    {
        PCMessageBase::PlaySound();
        PCMessageBase::WriteText();
        //...
    }
    virtual void SendPicture()
    {
        PCMessageBase::PlaySound();
        PCMessageBase::DrawShape();
        //...
    }
};

class MobileMessagerLite : public MobileMessageBase{ //经典版
    //...
};

class MobileMessagerPerfect : public MobileMessageBase{ //经典版
public:
    virtual void Login()
    {
        MobileMessageBase::PlaySound();
        MobileMessageBase::Connect();
        //...
    }
    virtual void SendMessage()
    {
        MobileMessageBase::PlaySound();
        MobileMessageBase::WriteText();
        //...
    }
    virtual void SendPicture()
    {
        MobileMessageBase::PlaySound();
        MobileMessageBase::DrawShape();
        //...
    }
};


//类个数 1 + n + n*m

//不同平台的同样的业务：各个函数的实现即有相同也有不同


}

