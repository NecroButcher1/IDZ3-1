#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#include<iostream>
template<class T>
class deque{
private:
    struct node{
        T data;
        node *next,*prev;
    };
    node *head,*tail;
    size_t size;
public:
    deque():head(NULL),tail(NULL),size(0){};
    deque(deque<T> *copy):size(copy->size){ // конструктор копирования
        this=copy;           // использования оператора =
    };
    deque operator=(deque *tmp){return tmp;}
    bool empty(){return ((!head)||(!tail))?true:false;}    // пуст ?
    void push_back(T _data){                                 // добавить в конец
        node *tmp=new node;
        size++;
        tmp->data=_data;
        tmp->next=NULL;
        tmp->prev=tail;
        if(tail)tail->next=tmp;
        tail=tmp;
        if(!head)head=tail;
    }
    void push_front(T _data){                          // добавить в начало
        node *tmp=new node;
        size++;
        tmp->data=_data;
        tmp->prev=NULL;
        tmp->next=head;
        if(head)head->prev=tmp;
        head=tmp;
        if(!tail)tail=head;
    }
    void pop_back(T &_data){                        //вернуть конец
        if(!empty()){
            _data=head->data;
            head=head->next;
            if(head)head->prev=NULL;
            else tail=NULL;
        }
    }
    void pop_front(T &_data){                      // вернуть начало
        if(!empty()){
            _data=tail->data;
            tail=tail->prev;
            if(tail)tail->next=NULL;
            else head=NULL;
        }
    }
    void pop_front(){
        if(!empty()){
            tail=tail->prev;
            if(tail)tail->next=NULL;
            else head=NULL;
        }
    }
    void pop_back(){
        if(!empty()){
            head=head->next;
            if(head)head->prev=NULL;
            else tail=NULL;
        }
    }
    T front(){return tail->data;}
    T back(){return head->data;}
    void doEmpty(){// сделать пустым
        while(!empty())head=head->next;
        tail=NULL;
    }
    ~deque(){doEmpty();}
};


#endif // DEQUE_H_INCLUDED
