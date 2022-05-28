#ifndef DECORATOR_H
#define DECORATOR_H

/**
* @filename         Decorator.h
* @brief            装饰模式
* @author           HXJ
* @date             2022-05-26
**/

namespace HXJ{

//动机
    //在某些情况下我们可能会"过度地使用继承来扩展对象的功能"，由于继承为类型引入的静态特质，使得这种扩展缺乏灵活性；
    //并且随着子类的增多（扩展功能的增多），各种子类的组合（扩展功能的组合）会导致更多子类的膨胀。

    //如何使对象功能的扩展能根据需要动态的实现？同时避免扩展功能的增多带来的子类膨胀问题？

//定义
    //动态（组合）地给一个对象增加一个额外的职责。就增加功能而言，Decorator 模式比生成子类（继承）更灵活
    //消除重复代码与减少子类个数

//总结
    //通过组合而非继承的方式，Decorator模式实现了在运行时动态的扩展对象功能的能力，而可以根据需要扩展多个功能。
    //避免了使用继承带来的灵活性差、子类多的问题

    //DecoratorStream 类在接口上表现为 is-a MYStream 的继承关系，即DecoratorStream继承了MYStream类所具有的接口
    //但在实现上又表现为 has-a MYStream的组合关系。

    //Decorator模式目的并非解决多子类衍生的多继承问题
    //应用要点在于解决主体类在多个方向上的相同扩展功能，是为装饰

}

#endif // DECORATOR_H
