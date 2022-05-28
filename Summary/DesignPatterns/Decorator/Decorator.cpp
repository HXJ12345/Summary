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


//当添加新需求： 需要加密的操作
//只需要一个类
class CryptoStream : public MYStream{ //这里还是需要继承，是为了使得该类还是继承规范的接口
private:
    //使用用组合
    MYStream* m_stream;  //运行使决定做哪种业务

public:
    CryptoStream(MYStream* s){}

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
class BufferedStream: public MYStream{
public:
    //....

};
//...

class CryptoBufferedStream: public MYStream{
public:
    //....

};

void DecoratorProcess()
{
    //运行时装配
    {
        FileStream* fileStream = new FileStream();
        CryptoStream* cryptoStream = new CryptoStream(fileStream); //示例
        //...
    }
}








}











