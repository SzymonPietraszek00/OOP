#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <future>




void findSumOfEven(std::promise<int> &&sumOf, std::vector<int> &v){

  std::this_thread::sleep_for(std::chrono::seconds(2));
  int sum = 0;
  for(auto &a : v){
    if(a%2==0){
      sum +=a;
    }
  }

  sumOf.set_value(sum);
}

void recursion(int &result, std::recursive_mutex &m,char c, int loopFor){

  if(loopFor<=0)
    return;


  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  m.lock();
  std::cout << c << " " << result++ << std::endl;
  recursion(result,m,c,--loopFor);
  m.unlock();
}


int main(){

  std::vector<int> v {1,2,3,4,5,6,7,8,9,10};
  
  {
    // ----- PROMISE AND FUTURE ----- //

    std::promise<int> sumOfEven;
    std::future<int> futureSum = sumOfEven.get_future();

    std::cout << "Create thread!\n";
    std::thread t1(findSumOfEven, std::move(sumOfEven), std::ref(v));

    std::cout << "Waiting for result!\n";

    std::cout << "Result : " << futureSum.get() << std::endl;

    std::cout << "Thread completed\n";

    t1.join();

  }

  std::cout << "\nFirst scope completed\n\n";

  {
    // ----- RECURSIVE MUTEX ----- //

    std::cout << "Second scope\n";
    
    std::recursive_mutex m;
    int result = 1;
    std::thread t1(recursion,std::ref(result),std::ref(m),'1', 10);
    std::thread t2(recursion,std::ref(result),std::ref(m),'2', 10);

    t1.join();
    t2.join();


  }
}