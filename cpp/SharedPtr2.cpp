#include<bits/stdc++.h>

template<typename> class shared_ptr;
template<typename T>
void swap(shared_ptr<T>& lhs, shared_ptr<T>& rhs)noexcept{
    lhs.swap(rhs);
}

template<typename T>
class shared_ptr{
    using DelFuncPtr = void (*)(T*);
public:
    shared_ptr():m_ptr(nullptr),count_ptr(new size_t(0)),del(nullptr){}
    explicit shared_ptr(T *m_ptr,DelFuncPtr del):
        m_ptr(m_ptr),count_ptr(new size_t(1)),del(del){
    }
    shared_ptr(const shared_ptr& s_ptr):
        m_ptr(s_ptr.m_ptr),count_ptr(s_ptr.count_ptr),del(s_ptr.del){
        ++(*count_ptr);
    }
    shared_ptr& operator=(shared_ptr s_ptr){
        swap(*this,s_ptr);
        return *this;
    }
    ~shared_ptr(){
        if(*count_ptr>0) --(*count_ptr);
        if(*count_ptr==0){
            del?del(m_ptr):(delete m_ptr);
            delete count_ptr;
        }
        m_ptr=nullptr;
        count_ptr=nullptr;
    }
    T& operator*(){ return *m_ptr; }
    T* operator->(){ return m_ptr; }

    void swap(shared_ptr& s_ptr){
        using std::swap;
        swap(m_ptr,s_ptr.m_ptr);
        swap(count_ptr,s_ptr.count_ptr);
        swap(del,s_ptr.del);
    }
private:
    T* m_ptr=nullptr;
    size_t* count_ptr=nullptr;
    DelFuncPtr del;
};

int main(){
    auto del=[](int *p){
        std::cout<<"deletor from lambda"<<std::endl;
        delete p;
    };
    shared_ptr<int> x(new int(10086),del);
    shared_ptr<int> x2=x;
    std::cout<<*x<<std::endl;
    return 0;
}
