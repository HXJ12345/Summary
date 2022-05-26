#include <string>
#include <list>
using namespace std;

namespace HXJ{

//一种不好的设计
class FileSplitter{
public:
    FileSplitter(string filePath, int num, string bar)
        :m_filePath(filePath)
        ,m_fileNumber(num)
        ,m_progressBar(bar)
    {}

    void split(){
        //1.读取大文件

        //2.分批次向小文件写入
        for(int i=0; i<m_fileNumber; i++){
            //...

            //需求：添加进度条反应分割进度
            //m_progressBar = "i"; //模拟更新
        }
    }

private:
    string m_filePath;
    int m_fileNumber;

    //需求：添加进度条反应分割进度
    string m_progressBar;//模拟进度条控件；具体的通知空间

};

class Mainfrom{ //模拟一个界面
    string m_txtFilePath; //模拟一个文本输入框
    string m_txtFileNumber; //模拟一个文本输入框

    //需求：添加进度条反应分割进度
    string m_progressBar;//模拟进度条控件

public:
    void ButtonClick(){
        string filePath = m_txtFilePath; //模拟获取输入框内容
        int number = atoi(m_txtFileNumber.c_str());

        FileSplitter splitter(filePath, number, m_progressBar);
        splitter.split();
    }

};

//上面的问题：
    //违背了依赖倒置原则： 高层不能依赖低层模块，都应该依赖抽象
    //FileSplitter 就依赖了ProgressBar， 进度条是一种实现细节
    //因为需求可能改变，进度可以采用其他方式展示：比如直接打印

//思考：
    //可不可将ProgressBar 替换为一种抽象基类
    //问题：这个抽象需要实现什么函数？？因为需求不同，不同控件的函数不同，问题无法解决
    //分析： ProgressBar 实际是一种观察者，进度实际是一种通知

//重构获得观察者
class IProgress{ //通知抽象
public:
    virtual void DoProgress(float value) = 0;
    ~IProgress();
};

class SubjectFileSplitter{
public:
    SubjectFileSplitter(string filePath, int num /*, IProgress* p*/)
        :m_filePath(filePath)
        ,m_fileNumber(num)
        //,m_progressBar(bar)
        //,m_iProgress(p) //优化
    {}

    //优化
    void addProgress(IProgress* p)
    {
        m_iProgress.push_back(p);
    }
    void removeProgress(IProgress* p)
    {
        m_iProgress.remove(p);
    }

    void split(){
        //1.读取大文件

        //2.分批次向小文件写入
        for(int i=0; i<m_fileNumber; i++){
            //...

            //需求：添加进度条反应分割进度
            //m_progressBar = "i"; //模拟更新
            //m_iProgress->DoProgress(i); //使用抽象更新
            for(auto p : m_iProgress) //优化
            {
                p->DoProgress(i);
            }
        }
    }

private:
    string m_filePath;
    int m_fileNumber;

    //需求：添加进度条反应分割进度
    //string m_progressBar;//模拟进度条控件；具体的通知控件
    //IProgress* m_iProgress; //抽象通知机制
    list<IProgress*> m_iProgress; //优化
};


class ObserverMainfrom : public IProgress{ //模拟一个界面
    string m_txtFilePath; //模拟一个文本输入框
    string m_txtFileNumber; //模拟一个文本输入框

    //需求：添加进度条反应分割进度
    string m_progressBar;//模拟进度条控件

public:
    void ButtonClick(){
        string filePath = m_txtFilePath; //模拟获取输入框内容
        int number = atoi(m_txtFileNumber.c_str());

        SubjectFileSplitter splitter(filePath, number);
        splitter.addProgress(this);
        //...这里可以添加更多的观察者
        splitter.split();
    }

    virtual void DoProgress(float value)override{
        m_progressBar = "value";
    }
};

//SubjectFileSplitter 不再依赖具体的控件实现，解耦了




}





