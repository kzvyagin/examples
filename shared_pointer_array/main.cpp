#include <iostream>
#include  <memory>
using namespace std;

struct A
{
     A(){ printf("A+\n"); }
    ~A(){ printf("~A\n"); }
    double  value;
};

int main(int argc, char *argv[])
{
    A  *a=new A[10];
    cout << "Here is no meam leak:" << endl;

    {

        auto p =  std::shared_ptr<A>( a  , []( A *a){ delete [] a; });
        p.get()[5].value=10;
        A  *y=p.get();
        (y++)->value=11;
    }

    cout << "Refill array" << endl;
    a=new A[10];
    cout << "Don't do like this:" << endl;

    {
        auto p =  std::shared_ptr<A>( a );
        p.get()[5].value=10;
        A  *y=p.get();
        (y++)->value=11;
    }

    return 0;
}

