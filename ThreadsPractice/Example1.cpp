#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <future>

using namespace std::chrono;
std::condition_variable cv;

class Bank{

public:

  int& operator()(int &myMoney, std::mutex &m){
    myMoney = 0;
    std::cout << "CRACK!!! All money lost\n";
    return myMoney;
  }

};


void depositeMoney(int &myMoney,std::mutex &m, int money){
  
  std::cout << "But first, deposite!\n";
  std::lock_guard<std::mutex> temp(m);

  myMoney += money;
  std::cout << "Money deposited, now you have " << myMoney << "\n";
  cv.notify_one();

}

void withdrawMoney(int &myMoney,std::mutex &m, int money){

  std::cout << "Started withdrawing\n";
  std::unique_lock<std::mutex> tmp(m);
  cv.wait(tmp, [&myMoney]{return (myMoney!=0)? 1 : 0; });

  if(myMoney>0){
    std::cout << "Money withdrawed -> " << money << std::endl;
    myMoney -= money;
  }else{
    std::cout << "You have no money :(\n";
  }

  std::cout << "Your Balance is: " << myMoney << std::endl;
}


int main() {

  int myMoney = 0;
  std::mutex m;

  std::thread t1(withdrawMoney,std::ref(myMoney),std::ref(m), 1200);
  std::this_thread::sleep_for(std::chrono::seconds(3));
  std::thread t2(depositeMoney,std::ref(myMoney),std::ref(m), 2900);
  
  t1.join();
  t2.join();

  std::this_thread::sleep_for(std::chrono::seconds(2));
  ///practice using functor as a arg of async
  Bank *bank = new Bank();
  auto x = std::async(std::ref(*bank),std::ref(myMoney),std::ref(m));
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "Now your balance is " << x.get() << std::endl;

  return 0;
 
}