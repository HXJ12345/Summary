#include "Strategy.h"

namespace HXJ{

//第一种常规写法
enum TaxBase{
    CN_Tax,
    US_Tax,
    DF_Tas,
    FR_Tax      //如果加新需求：更改
};

class SalesOrder{
public:
    double CalculateTax(){
        //...
        if(CN_Tax == m_tax)
        {
            //CN...
        }
        else if(US_Tax == m_tax)
        {
            //US...
        }
        else if(DF_Tas == m_tax)
        {
            //DF...
        }
        //如果加新需求：更改
        //而且为了实现下面代码，还可能改变上面的代码结构，
        //不仅无法达到二进制层面的复用，而且代码上也可能改变原有本来不应该改变的
        else if(FR_Tax == m_tax)
        {
            //FR...
        }
        //...
        return 0.0;
    }

private:
    TaxBase m_tax;
};

//上述如果有新需求：
    //违背了开闭原则，代码会重新编译、测试
//代码复用： 是二进制层面的，编译后就可以不动的


//策略模式实现

class TaxStrategy{
public:
    virtual double Calculate() = 0;
    virtual ~TaxStrategy(){}
};

//具体的业务类，每个类其实是单独的文件
class CNTax : public TaxStrategy{
public:
    virtual double Calculate() override{
        //...
        return 0.0;
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate() override{
        //...
        return 0.0;
    }
};

class DFTax : public TaxStrategy{
public:
    virtual double Calculate() override{
        //...
        return 0.0;
    }
};

//新需求 ： 更改 （是一个新文件，不影响原有）
class FRTax : public TaxStrategy{
public:
    virtual double Calculate() override{
        //...
        return 0.0;
    }
};

class StrategyFactory;
class StrategySalesOrder{
private:
    TaxStrategy* m_strategy; //一定是一个基类指针

public:
    StrategySalesOrder(StrategyFactory* factory){
        //m_strategy = factory->newStrategy; //示例 一般使用工厂模式产生对应的算法
    }
    ~StrategySalesOrder(){
        delete m_strategy;
    }

public:
    double CalcuateTax(){
        //...
        //示例
        //HXJ::Context context();
        //double val = m_strategy->Calculate(context); //多态调用

        //....
    }
};

//新需求 ： StrategySalesOrder 稳定，不需要改变，达到了二进制层次的复用，也不会更改到原有的算法
//改变点： 在工厂类去了。。




}

