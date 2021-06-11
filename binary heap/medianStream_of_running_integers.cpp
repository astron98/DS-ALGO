#include<iostream>

// for implementing inbuild priority_queue.
#include<queue>
using namespace std;

// Time complexity = O(n*Log n)
// Space complexity = O(n)

void printMedians(double arr[],int n)
{
	
	//maxHeap
	priority_queue<double> smaller;
	
	//minHeap
	priority_queue<double,vector<double>,greater<double>> larger;
	
	double med = arr[0];
	
	cout << med <<"\n";
	
	smaller.push(med);
	
	//reading elements from the array one by one.
	for(int i=1;i<n;i++)
	{
		double x = arr[i];
		
		//case1(left-side heap has more elements) 
		if(smaller.size() > larger.size())
		{
			if(x < med)
			{
				larger.push(smaller.top());
				smaller.pop();
				smaller.push(x);
			}
			else
				larger.push(x);
			med = (smaller.top() + larger.top())/2.0;	
		}
		
		//case 2: (right-side heap has more elements)
		else if(smaller.size() < larger.size())
		{
			if(x > med)
			{
				smaller.push(larger.top());
				larger.pop();
				larger.push(x);
			}
			else 
				smaller.push(x);
			
			med = (smaller.top() + larger.top())/2.0;	
		}
		
		//case 3:(If both the minHeap and maxHeap are of equal size
		//(i.e. they are balanced)
		else 
		{
			if(x>med)
			{
				larger.push(x);
				med = larger.top();
			}		
			else
			{
				smaller.push(x);
				med = smaller.top();
			} 
		}
		
		cout << med <<"\n";
	}
	
}

int main()
{
	// stream of integers 
    double arr[] = {5, 15, 10, 20, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printMedians(arr,n);
	
	return 0;
}
