#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

class Queue{
private:
	int item[SIZE],front,rear;
public:
	Queue(){
		front = -1;
		rear = -1;
	}
	
	bool isFull(){
		if(front==0 && rear == SIZE-1)
			return true;
		return false;	
	}	
	
	bool isEmpty(){
		return (front==-1)? true : false;
	}
	
	//enQueue,dequeue,display
	void enQueue(int x){
		if(isEmpty()){
			front++;
			//rear++;
			item[++rear] = x;
			printf("%d is inserted \n",x);
		}
		else if(isFull()){
			printf("overflow \n");
		}
		else{
			item[++rear] = x;
			printf("%d is inserted. \n",x);
		}
	}
	
	int deQueue(){
		int element;
		if(isEmpty()){
			printf("underflow \n");
			return -1;
		} 
		else{
			element = item[front];
			if(front>=rear){
				front = rear = -1;
			}
			else{
				front++;
			}
			
			printf("%d is deleted. \n",element);
			return element;
		}
	}
	
	void display(){
		if(isEmpty()){
			printf("The Queue is Empty.");
		}
		for(int i=front;i<=rear;i++){
			printf("%d, ",item[i]);
		}
		printf("\n");
	}
};
int main()
{
	Queue q;
	//deQueue is not possible on empty queue
    q.deQueue();
    
    //enQueue 5 elements
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    
    //6th element can't be added to queue because queue is full
    q.enQueue(6);
    
    q.display();
    
    //deQueue removes element entered first i.e. 1
    q.deQueue();
    
    //Now we have just 4 elements
    q.display();
    
    
	return 0;
}
