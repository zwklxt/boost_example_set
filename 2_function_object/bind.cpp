#include <iostream>
#include <vector>
#include <algorithm>

#include <boost/bind/bind.hpp>

using namespace boost::placeholders;

void print1(int m){
    std::cout<<m<<std::endl;
}

void add1(int x, int y){
    std::cout<<x+y<<std::endl;
}


class add : public std::binary_function<int,int,void>{
    public:
        void operator()(int x,int y) const {
            std::cout<<x+y<<std::endl;
        }
};

bool compare(int x,int y){
    return x > y;
}

int main(){
    std::vector<int> v = {1,2,3,4,5};

    std::cout<<"-----------1---------------"<<std::endl;
    std::for_each(v.begin(),v.end(),print1);

    std::cout<<"-----------2---------------"<<std::endl;
    std::for_each(v.begin(),v.end(),std::bind1st(add(),10));

    std::cout<<"-----------3:boost::bind---------------"<<std::endl;   
    std::for_each(v.begin(),v.end(),boost::bind(add1,20,_1));

    std::cout<<"-----------4----------------"<<std::endl;
    std::sort(v.begin(),v.end(),compare);
    std::for_each(v.begin(),v.end(),print1);

    std::cout<<"-----------5----------------"<<std::endl;
    std::sort(v.begin(),v.end(),boost::bind(compare,_2,_1));
    std::for_each(v.begin(),v.end(),print1);

    return 0;
}