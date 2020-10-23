#include <boost/version.hpp>
#include <boost/config.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <iostream>


int main(){
    std::cout<<BOOST_VERSION<<std::endl;

    boost::scoped_ptr<int> a(new int);
    *a = 1;
    *a.get() = 2;
    // a.reset(new int);
    std::cout<<"a = "<<*a<<std::endl;

    //array
    boost::shared_array<int> b(new int[2]);
    b[0] = 1;
    b[1] = 2;
    boost::shared_array<int> b1(b);
    std::cout<<b1[0]<<","<<b1[1]<<std::endl;

    //container vector
    boost::ptr_vector<int> v;
    v.push_back(new int(1));
    v.push_back(new int(2));

    std::cout<<"vector : "<<v[0]<<","<<v[1]<<std::endl;


}