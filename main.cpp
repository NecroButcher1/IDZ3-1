#include <iostream>
#include <string>
#include <cstdlib>
#include "merge.h"
#include "deque.h"
using namespace std;
void menu();
int main()
{
    deque<string> current;
    int ch=0;
    string value;
    while(ch!=4){
        menu();
        cin>>ch;
        while((ch<1)||(!cin)||(ch>3)){
            system("cls");
            cin.clear();
            cin.ignore(32767,'\n');
            menu();
            cin>>ch;
        }
        if(ch==1){
            system("cls");
            current.doEmpty();
            int size=0;
            cout<<"size :";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"size :";
                cin>>size;
            }
            for(size_t i=0;i<size;i++){
                cout<<"press ["<<i<<"] :";
                cin>>value;
                current.push_back(value);
            }
            ch=0;
        }
        if(ch==2){
             system("cls");
            if(current.empty())cout<<"deque is empty :("<<endl;
            else{
                deque<string> tmp(current);
                while(!tmp.empty()){
                    tmp.pop_front(value);
                    cout<<value<<endl;
                }
            }
            cout<<endl;
            ch=0;
        }
        if(ch==3){
            system("cls");
            deque<string> result;
            const char *check=merge(current,result);
            if(check)cout<<check<<endl;
            else{
                while(!result.empty()){
                    result.pop_back(value);
                    cout<<value<<" ";
                }
            }
            cout<<endl;
            ch=0;
        }
    }
    return 0;
}
void menu(){cout<<"1.fill from keyboard"<<endl<<"2.see deque"<<endl<<"3.merge"<<endl<<"4.exit"<<endl;}
