#include<bits/stdc++.h>
using namespace std;

template<typename T>
class mshared_ptr{
public:
    mshared_ptr(T* p=nullptr){
        _p=p;
        if(!_p) ++_mp[p];
    }
    ~mshared_ptr(){
        if(!(--_mp[_p])&&nullptr!=_p){
            _mp.erase(_mp.find(_p));
            delete _p;
            _p=nullptr;
        }
    }
    mshared_ptr(mshared_ptr<T> &src){
        _p=src._p;
        ++_mp[_p];
    }
    mshared_ptr<T>& operator=(mshared_ptr<T> &src){
        if(src._p!=_p){
            if(!(--_mp[_p])&&nullptr!=_p){
                _mp.erase(_mp.find(_p));
                delete _p;
            }
            _p=src._p;
            if(!_p) ++_mp[_p];
        }
        return *this;
    }
    T& operator *(){
        return *_p;
    }
    T* operator ->(){
        return _p;
    }
private:
    static map<T*,int> _mp;
    T* _p;
};

template<typename T>
map<T*,int> mshared_ptr<T>::_mp;


int main()
{
	int *p = new int(10);

	mshared_ptr<int> mshared_p1(p);
	mshared_ptr<int> mshared_p2(new int(20));
	cout << *mshared_p1 << endl;
	cout << *mshared_p2 << endl;
	system("pause");
	return 0;
}
