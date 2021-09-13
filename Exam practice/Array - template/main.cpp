#include <iostream>

namespace oop{

  template<typename T>
  class Array{
    public:
    Array(T x): _arr(new T[x]), _size(0), _maxsize(x) {}

    typedef T value_type;

    auto& insert(char x){
      if(_size<_maxsize){
        _arr[_size] = x;
        _size++; 
      }
      return *this;
    }

    Array& operator+(const T& a){
      return insert(a);
    }

    T& operator[](unsigned x){
      return _arr[x];
    }

    int operator~()const{
      return _maxsize;
    }


    private:
      T *_arr;
      int _size;
      int _maxsize;
  };

}

int main() {
    typedef oop::Array<char> type;
    type a(rand() % 10 + 6);

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3); 

    for(unsigned i = 0; i != ~a; i++) {
        std::cout << a[i] << (i+1 != ~a ? "" : "\n");
    }

    return 0;
};
