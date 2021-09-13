#include <iostream>
#include <deque>


template<typename T = int, template<class P = T, class Alloc = std::allocator<P>> class StorageType = std::deque>
class fifo{
public:

  fifo(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
  }


  void push(T x){
    _arr.push_back(x);
  }

  auto get(){
    T element = _arr.front();
    _arr.pop_front();
    
    return element;
  }

  auto size()const{
    return _arr.size();
  }

  typedef StorageType<T> storage_type;


  auto begin()const{
    return _arr.begin();
  }

  auto end()const{
    return _arr.end();
  }
private:

  StorageType <T> _arr;
};

int main()
{
    fifo<> ft;
    for(int i: {0,1,2,3,4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << std::endl;
    std::cout << f.size();
    std::cout << std::endl;
    

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
// Wynik:
// fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
// 0
// 4
// 1,2,3,4,
