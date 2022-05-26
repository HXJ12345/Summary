#include "Templatemethod.h"

namespace HXJ{

//第一种常规写法：

//程序库开发人员
class Library{


public:
    void step1(){
        //...
    }

    void step3(){
        //...
    }

    void step5(){
        //...
    }
};

//应用程序开发人员
class Application{
public:
    bool step2(){
        //...
        return true;
    }

    void step4(){
        //...
    }
};

//最终应用程序
void process(void) {
    Library lib;
    Application app;

    //一种固有步骤
    lib.step1();

    if(app.step2())
        lib.step3();

    app.step4();
    lib.step5();
}
// 这是典型的早绑定


//模板方式实现

//框架开发人员
class TemplateLibrary{
public:
    virtual ~TemplateLibrary(){ //虚基类一定要抒写虚析构函数

    }

protected: //一般都是内部使用，不会给外部使用，不用public
    void step1(){ //稳定
        //...
    }

    void step3(){ //稳定
        //...
    }

    void step5(){ //稳定
        //...
    }

    virtual bool step2() = 0; //变化
    virtual void step4() = 0; //变化

public:
    //有一种固有步骤（稳定），但是中间有
    void run(){
        step1();

        if(step2()) //支持变化==》虚函数的多态调用
            step3();

        step4();//支持变化==》虚函数的多态调用
        step5();
    }
};

//程序开发人员
class TemplateApplication : public TemplateLibrary{
protected:
    virtual bool step2() override {
        //...子类重写实现
        return true;
    }

    virtual void step4() override {
        //...子类重写实现
    }
};

//这是晚绑定


//最终应用程序
void templateProcess(void) {

    TemplateLibrary* lib = new TemplateApplication();
    lib->run(); //调用固定流程

}

}

