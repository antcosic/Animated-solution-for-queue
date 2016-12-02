#include<iostream>
using namespace std;
struct queue{
    elementtype e[1000];
    int front,rear;
    bool lastop;
};
int AddOne(int x){
    return(x+1)%1000; 
}
void Init(queue &Q){ 
    Q.front=0;
    Q.rear=999; 
    Q.lastop=false; 
}
void Enqueue(queue &Q,elementtype x){ 
      if (AddOne(Q.rear)==Q.front && Q.lastop==true) 
          cout<<"Red je pun."<<endl;
      else
         Q.rear=AddOne(Q.rear); 
         Q.e[Q.rear]=x; 
         Q.lastop=true;
}
void Dequeue(queue &Q){ 
     if (AddOne(Q.rear)==Q.front && Q.lastop==false) 
         cout<<"Red je prazan."<<endl;
     else 
         Q.front=AddOne(Q.front);
         Q.lastop=false; 
}
elementtype Front(queue &Q){ 
    if (AddOne(Q.rear)==Q.front && Q.lastop==false) {
        cout<<"Red je prazan."<<endl;
        return false;
    }
    else 
        return Q.e[Q.front];
}

bool IsEmpty(queue &Q){ 
     if (AddOne(Q.rear)==Q.front && Q.lastop==false) return true;
     else return false;
}
