#include <QCoreApplication>
#include <QVector>
#include <QLinkedList>
#include <QList>
#include <vector>
#include <list>
#include <chrono>
#include <iostream>

#include <unordered_map>
#include <map>

using namespace std;
typedef void (*callable_function)(void) ;
typedef std::map<std::string , callable_function> Collection;
static int SIZE=1000000;
static int ADD_REMOVE_MAX=10;
static int ADD_REMOVE_SIZE=1000;

void testStdVector()
{
    vector<int> vec;
    for(int i=0; i<SIZE ; i++){
        vec.push_back(i+2);
    }
}
void testQtVector()
{
    QVector<int> vec;
    for(int i=0; i<SIZE ; i++){
        vec.push_back(i+2);
    }
}
void testQtList()
{
    QList<int> vec;
    for(int i=0; i<SIZE ; i++){
        vec.push_back(i+2);
    }
}

void testQtLinkedList()
{
    QLinkedList<int> vec;
    for(int i=0; i<SIZE ; i++){
        vec.push_back(i+2);
    }
}

void testStdList()
{
    list<int> vec;
    for(int i=0; i<SIZE ; i++){
        vec.push_back(i+2);
    }
}



void testAddAndRemoveQtVector()
{
    QVector<int> vec;

    for(int i=0; i<ADD_REMOVE_MAX; i++){
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.push_back(k+2);
        }
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.erase(vec.begin());
        }
    }
}

void testAddAndRemoveStdVector()
{
    std::vector<int> vec;

    for(int i=0; i<ADD_REMOVE_MAX; i++){
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.push_back(k+2);
        }
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.erase(vec.begin());
        }
    }
}

void testAddAndRemoveQtList()
{
    QList<int> vec;
    for(int i=0; i<ADD_REMOVE_MAX; i++){
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.push_back(k+2);
        }
        for(int k=0; k<ADD_REMOVE_SIZE ; k++){
            vec.erase(vec.begin());
        }
    }
}

void testAddAndRemoveStdList()
{
    std::list<int> vec;
    for(int i=0; i<ADD_REMOVE_MAX; i++){
        for(int k=0; k<SIZE ; k++){
            vec.push_back(k+2);
        }
        for(int k=0; k<SIZE ; k++){
            vec.erase(vec.begin());
        }
    }
}

int main(int argc, char *argv[])
{
    Collection dict;
    dict.emplace("std vector",&testStdVector);
    dict.emplace("std list", &testStdList);
    dict.emplace("Qt vector", &testQtVector);
    dict.emplace("Qt linked list", &testQtLinkedList);
    dict.emplace("Qt list", &testQtList);

    dict.emplace("Add and remove  Qt vector",  &testAddAndRemoveQtVector);
    dict.emplace("Add and remove  std vector", &testAddAndRemoveStdVector);
    dict.emplace("Add and remove  Qt list", &testAddAndRemoveQtList);
    dict.emplace("Add and remove  std list", &testAddAndRemoveStdList);


    for( const auto & element : dict ){
            auto started = std::chrono::high_resolution_clock::now();
            (*element.second)();
            auto done = std::chrono::high_resolution_clock::now();
            auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
            std::cout << "Test \"" <<element.first<<"\", takes: "<<duration<< " milliseconds."<<std::endl;
    }


    return 0;
}
