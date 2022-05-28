#include "Decorator.h"
#include <string>


using namespace std;


namespace HXJ{

//业务操作类
class MYStream{
public :
    virtual string Read() = 0;
    virtual void Seek(int pos) = 0;
    virtual void Write(char data) = 0;

    virtual ~MYStream(){}
};

//主体类
class FileStream: public MYStream{
public:
    virtual string Read(){
        //读文件流
        return string();
    }

    virtual void Seek(int pos){
        //定位
    }

    virtual void Write(char data){
        //写
    }
};

class NetWorkStream : public MYStream{
    virtual string Read(){
        //读网络流
         return string();
    }

    virtual void Seek(int pos){
        //定位
    }

    virtual void Write(char data){
        //写
    }
};

class MemoryStream : public MYStream{
    virtual string Read(){
        //读网络流...
        return string();
    }

    virtual void Seek(int pos){
        //定位...
    }

    virtual void Write(char data){
        //写...
    }
};

//中间基类
class DecoratorStream : public MYStream{
protected :
    MYStream* m_stream;

public:
    DecoratorStream(MYStream* stream){}
};

//当添加新需求： 需要加密的操作
//只需要一个类
class CryptoStream : public DecoratorStream{ //这里还是需要继承，是为了使得该类还是继承规范的接口
private:
    //使用用组合
    //MYStream* m_stream;  //运行使决定做哪种业务
    //该字段不同的类都用。重复，所以可以优化提到基类
    //直接提到MYStream 不好，因为具体的业务类实际不需要
    //所以可以提到一个中间类

public:
    CryptoStream(MYStream* s):DecoratorStream(s){}

    virtual string Read(){
        //额外的加密操作
        m_stream->Read();
        //...
        return string();
    }

    virtual void Seek(int pos){
        //加密
        m_stream->Seek(pos);
        //...
    }

    virtual void Write(char data){
        //加密
        m_stream->Write(data);
    }
};

//有新需求：需要做缓存处理，，甚至缓存加密操作
//同样都只用新增一个类
class BufferedStream: public DecoratorStream{
public:
    //....

};
//...

class CryptoBufferedStream: public DecoratorStream{
public:
    //....

};

void PerfectDecoratorProcess()
{
    //运行时装配
    {
        FileStream* fileStream = new FileStream();
        CryptoStream* cryptoStream = new CryptoStream(fileStream); //示例
        //...
    }
}


// 1 + n + 1 + m





}











