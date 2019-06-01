#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED
#include "deque.h"
#include <iostream>
#include <string>
template<class T>
const char* merge(deque<T> buff,deque<T> &res){
    deque<T> tmp=buff;
    res.doEmpty();
    const char *out=NULL;
    T value;
    if(tmp.empty())out="empty deque";
    else{
        while(!tmp.empty()){
            tmp.pop_back(value);
            res.push_back(value);
            if(!tmp.empty()){
                tmp.pop_front(value);
                res.push_front(value);
            }
        }
    }
    return out;
}

#endif // MERGE_H_INCLUDED
