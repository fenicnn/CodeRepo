#include<bits/stdc++.h>

class Delete{
public:
    template<typename T>
    void operator()(T *p) const {
        if(p!=nullptr)
            std::cout<<*p<<"回收成功"<<std::endl;
        delete p;
    }
};
template<typename T, typename D=Delete>
class unique_ptr{
public:
    explicit unique_ptr(T *p=nullptr, const D &dd= D())
        :un_ptr(p),del(dd){}
    ~unique_ptr(){
        del(un_ptr);
    }
    //不支持拷贝与赋值
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    //移动拷贝与移动赋值函数
    unique_ptr(unique_ptr&& rval):un_ptr(rval.un_ptr),del(std::move(rval.del)){
        rval.un_ptr=nullptr;
    }
    unique_ptr& operator=(unique_ptr&& rval)noexcept{
        if(this!=&rval){
            un_ptr=rval.un_ptr;
            rval.un_ptr=nullptr;
            del=std::move(rval.del);
        }
        return *this;
    }
    T& operator*(){ return *un_ptr; }
    T* operator->(){ return un_ptr; }
private:
    T *un_ptr=nullptr;
    D del;
};

int main(){
    unique_ptr<std::string> p(new std::string("CNN"));
    unique_ptr<std::string> p2=std::move(p);
    return 0;
}
