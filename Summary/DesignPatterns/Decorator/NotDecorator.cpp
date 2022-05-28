#include <string>

using namespace std;

namespace HXJ{

//一种不好的设计

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
class CryptoFileStream: public FileStream{
public:
    virtual string Read(){
        //额外的加密操作
        FileStream::Read();
        //...
        return string();
    }

    virtual void Seek(int pos){
        //加密
        FileStream::Seek(pos);
        //...
    }

    virtual void Write(char data){
        //加密
        FileStream::Write(data);
    }
};

//其他类一样需要新增子类
//...
//同样的加密操作，但是不同的种类都要编写不同的类。。。

//有新需求：需要做缓存处理，，甚至缓存加密操作
class BufferedFileStream: public FileStream{
public:
    //....

};
//...

class CryptoBufferedFileStream: public FileStream{
public:
    //....

};
//...

//总之，新增一种功能（对所有的业务都一样），就会使得子类个数成阶数的增加
//加密、缓存、、等这些功能针对不同的业务都是一样的，但是代码被大量的重复
//继承的不良使用
//子类个数 1 + n + n*m!/2

void NoDecoratorProcess()
{
    //编译时装配
    {
        CryptoFileStream* cryptoFileStream = new CryptoFileStream();
        CryptoBufferedFileStream* cryptoBufferedFileStream = new CryptoBufferedFileStream();
        //...
    }
}

}




















