#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <iterator>

bool porownanie(int x, int y){
  return x>y ? x : y;
}

int main() {
  std::cout << "EXAM PRACTICE!!!\n";

  std::vector<int> vect{1,2,3,4,5,6,7,8,9,10};

  std::copy(vect.begin(), vect.end(), std::ostream_iterator<int>(std::cout," , " ));
  std::cout << std::endl;

  std::for_each(vect.begin(),vect.end(), [](int x){
    std::cout << x << " ";
  } );

  std::cout << std::endl;

  std::cout << "std::accumulate SUMA: " << std::accumulate(vect.begin(), vect.end(), 0.0) << std::endl;



  std::sort(vect.begin(),vect.end(), porownanie);

  for(auto &x: vect){
    std::cout << x << " ";
  }

  std::cout << std::endl;

  auto x = std::find(vect.begin(),vect.end(), 5);

  if(x != vect.end()){
    std::cout<< "Znaleziono! " << *x << std::endl;
  }else{
    std::cout<< "Nie znaleziono :(" << std::endl;
  }

  auto y = std::find_if(vect.begin(),vect.end(), [](int val){
    return val==7;
  });

  if(y != vect.end()){
    std::cout<< "Znaleziono! " << *y << std::endl;
  }else{
    std::cout<< "Nie znaleziono :(" << std::endl;
  }

  std::pair<int,int> para = {5,6};

  std::cout << "PARA" << std::endl;
  std::cout << para.first << " " << para.second << std::endl;


  std::swap(para.first,para.second);
  std::cout << "PARA PO ZAMIANIE" << std::endl;
  std::cout << para.first << " " << para.second << std::endl;

  vect.push_back(15);

  for(auto &x: vect){
    std::cout << x << " ";
  }

  std::cout << std::endl;

  
  std::sort(vect.begin(),vect.end(), std::greater<int>());

  for(auto &x: vect){
    std::cout << x << " ";
  }

  std::cout << std::endl;

  
  using namespace std::placeholders;  // for _1, _2, _3...
    std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
 
    int num_items3 = std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), _1, 8));
    std::cout << "number bigger then 8: " << num_items3 << '\n';

    int num_items4 = std::count_if(v.begin(), v.end(), std::bind(std::less<int>(), _1, 8));
    std::cout << "number less then 8: " << num_items4 << '\n';

    std::vector<std::string> doseta{"Tomek", "Jan", "Koko", "Jacek", "Wiesiek", "Ron", "Zbyszek", "Gacek"};

    std::set<std::string> set_help (doseta.begin(),doseta.end());

    for(auto&x : set_help){
      std::cout << x << " " << std::count(doseta.begin(),doseta.end(),x) << std::endl;
    }


    auto znal = std::find_if(doseta.begin(), doseta.end(),[](std::string name){
      return name == "Gacek";
    });

    if(znal!=doseta.end()){
      std::cout << " jest";
    }else{
      std::cout<<"nie ma";
    }

    std::cout<<std::endl;

    std::map<std::string, int> mapka;

    mapka["Placek"] = 5;
    mapka["Jan"] = 2;

    std::map<std::string, int>::iterator it;
    for(it=mapka.begin(); it!=mapka.end(); ++it){
      std::cout << it->first << " => " << it->second << '\n';
   }

}