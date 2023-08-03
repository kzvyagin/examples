#include <iostream>
#include <vector>

using namespace std;

static int counter=0;
struct A{
    int number;
    A():number(counter++){
        cout <<number<<"+" <<endl;
    }
    ~A(){
        cout <<number<< "~" <<endl;
    }
    A( const A &a){
        number=a.number;
        cout <<number<< "=" <<endl;
    }
};


void example1()
{
    cout<<"Example 1 starts"<<endl;

    vector<A> arr;
    cout<<"Reserve memory for two elements"<<endl;
    arr.reserve(2); // reserve, not resize
    cout<<"Add two elements"<<endl;
    arr.push_back(A());
    arr.push_back(A());
    cout<<"Add one more element. Thats calls reallocation. Let's see how..."<<endl;
    arr.push_back(A());
    cout<<"Done with first example "<<endl;

    cout<<"Example 1, end of example1 scope... calling destructors."<<endl;
}

void example2()
{
    cout<<"Example 2 starts"<<endl;
    vector<A> arr;
    arr.resize(2); // resize will call constructors
    cout<<"Delete one(first) element from vector"<<endl;
    arr.erase(arr.begin()); //don,t reallocate array
    cout<<"Add element to vector"<<endl;
    arr.push_back( A() );   //don,t reallocate array
    cout<<"Add element ower the vector current size, lets watch how it works..."<<endl;
    arr.push_back( A() );
    cout<<"Example 2, end of example1 scope... calling destructors."<<endl;
}

int main()
{

    example1();
    example2();

    return 0;
}
