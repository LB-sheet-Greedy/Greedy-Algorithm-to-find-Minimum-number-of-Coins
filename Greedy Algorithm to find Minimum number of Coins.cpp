/*
Greedy approach is that we choose denomination closest to V always in order ti minimize the total count
*/

#include<iostream>
   
using namespace std;

//decides which denomination to choose next
int NextDenomination(int denomination[],int V_rem,int n)
{
	int decision=0;
	
	int low=denomination[0];
	int high=denomination[n-1];
	int mid;
	
	//use binary search to reduce search time from O(n) to O(logn)
	while(low<=high)
	{
		mid=low+(high-low)/2;
		
		//if max possible denomination mila to break
		if(denomination[mid]<=V_rem && denomination[mid+1]>V_rem)
		{
			decision=denomination[mid];
			break;
		}
		else if(denomination[mid]>V_rem)   //iterate left
		{
			high=denomination[mid-1];
		}
		else if(denomination[mid]<V_rem)   //iterate right
		{
			low=denomination[mid+1];
		}
	}
	cout<<"\ndecision => "<<decision;
	return decision;
}

int Num_of_curr_taken(int denomination[],int V,int n)
{
	int count=0,decision=0;
	int V_rem=V;
	while(V_rem>0)
	{
		//decide denomination to be used
		decision=NextDenomination(denomination,V_rem,n);
		
		//update count (har baar ek hi den use hora)
		count++;
		
		//Update V
		V_rem=V_rem-decision;
	}
	
	return count;
}

int main()
{
	//Static inputs
	int n=10;
	int denomination[n]={1,2,5,10,20,50,100,200,500,2000};
	
	int V=70;
	
	cout<<"\nNumber of denominations used (MINIMUM) => "<<Num_of_curr_taken(denomination,V,n);
	
	return 0;
}
