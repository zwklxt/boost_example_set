#include <vector>
#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>



template <typename T>
T *create(){
    return new T;
}

int main(){
    boost::ptr_vector<int> v;
    v.push_back(create<int>());
    v[0] = 1;
    std::cout<<v[0]<<std::endl;
    return;

}

