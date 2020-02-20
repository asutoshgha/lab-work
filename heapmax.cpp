#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> heap={6,4,7,9,5,3,10};
	make_heap(heap.begin(),heap.end());
	for (auto i = heap.begin(); i != heap.end(); ++i)
        	cout << *i <<endl;
       	heap.push_back(50);
	push_heap(heap.begin(),heap.end());
	cout<<endl;
	for (auto i = heap.begin(); i != heap.end(); ++i)
        	cout << *i <<endl;	
	pop_heap(heap.begin(),heap.end());
	cout<<endl;
	for (auto i = heap.begin(); i != heap.end(); ++i)
        	cout << *i <<endl;
	heap.pop_back();
	for (auto i = heap.begin(); i != heap.end(); ++i)
        	cout << *i <<endl;
	
 		
}
