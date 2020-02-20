include<iostream> 
#include<algorithm> // for heap  
#include<vector> 
using namespace std; 
  
// comparator function to make min heap 
struct greaters{ 
  bool operator()(const long& a,const long& b) const{ 
    return a>b; 
  } 
}; 
  
int main() 
{ 
    // initializing vector; 
    vector<int> vi = { 15, 6, 7, 9, 11, 45 }; 
      
    // using make_heap() to transform vector into 
    // a min heap 
    make_heap(vi.begin(),vi.end(), greaters()); 
	vi.push_back(5);
	push_heap(vi.begin(),vi.end(),greaters());
	pop_heap(vi.begin(),vi.end(),greaters());
	vi.pop_back();
	for (auto i = vi.begin();i!=vi.end();i++)
		cout<<*i<<" ";      
    // checking if heap using  
    // front() function
	cout<<endl; 
    cout << "The minimum element of heap is : "; 
    cout << vi.front() << endl; 
      
} 
