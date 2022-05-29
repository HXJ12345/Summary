#include "Prototype.h"

namespace HXJ{


class ISplitter{
public:
    virtual void Split() = 0;
    virtual ISplitter* Clone() = 0;  //通过克隆创建自己

    virtual ~ISplitter();
};

class BinarySpliter : public ISplitter{

public:
    virtual void Split() override
    {
        //...
    }

    virtual ISplitter* Clone() override
    {
        return new BinarySpliter(*this);
    }
    //...
};

class TxtSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    virtual ISplitter* Clone() override
    {
        return new TxtSpliter(*this);
    }
    //...
};

class PictureSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    virtual ISplitter* Clone() override
    {
        return new PictureSpliter(*this);
    }
    //...
};

class VideoSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    virtual ISplitter* Clone() override
    {
        return new VideoSpliter(*this);
    }
    //...
};


class MainForm{

private:
    ISplitter* m_prototype;
public:
    MainForm(ISplitter* prototype)
        :m_prototype(prototype)
    {

    }

    void onButton_clicked()
    {
        //....
        ISplitter* spliter =  m_prototype->Clone();   //通过克隆原型得到新对象
        spliter->Split();

    }
};

}
