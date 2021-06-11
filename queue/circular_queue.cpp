#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

/* Circular Queue implementation. */

class Queue{
private:
	int front,rear;
	int item[SIZE];
public:
	Queue(){
		front = rear = -1;	
	}
	
	bool isFull(){
		if(front==0 && rear == SIZE-1){
			return true;
		}
		if(front==rear+1)
			return true;
		return false;	
	}
	
	bool isEmpty(){
		return (front==-1)? true:false;
	}
	
	
	void enQueue(int x){
		if(isFull())
			printf("Queue is full \n");
		else{
			if(isEmpty()) front = 0;
			rear = (rear+1)%SIZE;
			item[rear] = x;
			printf("%d is inserted. \n",x);
		}	
	}
	
	int deQueue(){
		int element;
		if(isEmpty()){
			printf("Queue is Empty. \n");
			return (-1);
		}	
		else{
			element = item[front];
			if(front == rear){
				front = rear = -1;
			}
			else
				front = (front+1)%SIZE;
			printf("%d is deserted. \n",element);
			return (element);
		}
	}
	
	void display(){
		/* Function to display the status of the circular queue. */
		int i;
		if(isEmpty())
			printf("Queue is empty. \n");
		else{
			/*
			 * Note: Here, the condition must be i!=rear
			 * because it's a circular queue.
			 * */
			for(i=front;i!=rear;i=(i+1)%SIZE){
				printf("%d ",item[i]);
			}
			printf("%d \n",item[i]);
		}	
	}
	

};

int main(){
	
	Queue q;
	
	q.deQueue();
    
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    
    // Fails to enqueue because front == 0 && rear == SIZE - 1
    q.enQueue(6);
    
    
    q.display();
    
    int elem = q.deQueue();
    
    if( elem != -1)
       cout << endl << "Deleted Element is " << elem<<endl;
    
    q.display();
    
    q.enQueue(7);
    
    q.display();
    
    // Fails to enqueue because front == rear + 1
    q.enQueue(8);
	
	return 0;
}
