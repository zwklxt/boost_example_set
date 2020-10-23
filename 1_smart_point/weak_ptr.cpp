#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

using namespace boost;

//use enable shared_from_this
class self_shared : public enable_shared_from_this<self_shared>{
  public:
    self_shared(int n):x(n){}
    int x;
    void print(){
        std::cout<<"self_shared: "<< x <<std::endl;
    }

};


int main(){
    // auto sp = boost::make_shared<self_shared>(312);
    boost::shared_ptr<self_shared> sp(new self_shared(211));
    sp->print();

    boost::shared_ptr<self_shared> p = sp->shared_from_this(); //p = this for self_shared
    p->x = 100;
    p->print();


}



