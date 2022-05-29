
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


class MainForm{

public:
    void onButton_clicked()
    {
        //....
        ISplitter* spliter = new BinarySpliter();   //常规的做法
        spliter->Split();
        //这里还是违背了依赖倒置原则，依赖了具体的实现类
    }
};




}


