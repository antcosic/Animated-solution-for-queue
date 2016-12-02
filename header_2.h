#include<iostream>
using namespace std;
struct rec{
    elementtype e;
    rec *next;
};
struct queue{
    rec *front, *rear;
};
typedef rec *element;

void Init(queue &Q){
    element zaglavlje=new rec;
    zaglavlje->next=NULL;
    Q.front=zaglavlje;
    Q.rear=zaglavlje; 
}

void Enqueue(queue &Q,elementtype x){
    rec *novi=new rec;
    novi->e=x;
    novi->next=NULL;
    Q.rear->next=novi;
    Q.rear=novi;
}
bool IsEmpty(queue &Q){
     if (Q.front==Q.rear) return true;
     else return false;   
}
void Dequeue(queue &Q){
    if (IsEmpty(Q)) 
        cout<<"Red je prazan."<<endl;
	else {
	    rec *pom=new rec;
	    pom=Q.front;
	    Q.front=Q.front->next;
	    delete pom;
     }
}

elementtype Front(queue &Q){
     if(IsEmpty(Q)) 
         cout<<"Red je prazan."<<endl;
     else return Q.front->next->e;
}

