#include "Factory.h"


namespace HXJ{

class ISplitter{
public:
    virtual void Split() = 0;
    virtual ~ISplitter();
};

class BinarySpliter : public ISplitter{

public:
    virtual void Split() override
    {
        //...
    }
    //...
};

class TxtSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    //...
};

class PictureSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    //...
};

class VideoSpliter : public ISplitter{
public:
    virtual void Split() override
    {
        //...
    }
    //...
};


//添加工厂类
//class SpliterFactor{
//public:
//    ISplitter* creatSpliter()
//    {
//        ISplitter* spliter = new BinarySpliter();
//        return spliter;
//        这样还是违背了依赖倒置原则的，因为还是依赖具体类
//    }
//};

class SpliterFactor{
public:
    virtual ISplitter* CreatSpliter() = 0; //改为接口
    virtual ~SpliterFactor();
};

//添加具体的factor
class BinarySpliterFactor : public SpliterFactor{

public:
    virtual ISplitter* CreatSpliter()
    {
        return new BinarySpliter();
    }
    //...
};

class TxtSpliterFactor : public SpliterFactor{
public:
    virtual ISplitter* CreatSpliter()
    {
        return new TxtSpliter();
    }
    //...
};

class PictureSpliterFactor : public SpliterFactor{
public:
    virtual ISplitter* CreatSpliter()
    {
        return new PictureSpliter();
    }
    //...
};

class VideoSpliterFactor : public SpliterFactor{
public:
    virtual ISplitter* CreatSpliter()
    {
        return new VideoSpliter();
    }
    //...
};


class MainForm{

private:
    SpliterFactor* m_factory;  //疑问： 既然构造的时候传递一个具体工厂，为啥不之间传入之前的具体ISplitter类

    //我意思是这里直接保持  ISplitter* spliter，不用factor
public:
    MainForm(SpliterFactor* factor)
        :m_factory(factor)
        //这里之间传对于的具体类，，反正针对于这里来说，也不会依赖具体类啊，，
    {

    }
    void onButton_clicked()
    {
        //....
//        ISplitter* spliter = new BinarySpliter();   //常规的做法
//        spliter->Split();

        ISplitter* spliter = m_factory->CreatSpliter();
        spliter->Split();
    }
};

//工厂实际不应该这样用，因为这样用实际直接传原始类没啥区别
//实际工厂类应该在整个应用程序为一个单例。。。。，

//如果工厂模式创建的时多个相关联的对象。那其实就是抽象工厂


}


