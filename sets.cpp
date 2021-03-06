#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <unordered_map>
#define MAX_N 1000001
using namespace std;
typedef long long lld;
int numComponents;
struct Node
{
    int parent;
    int rank;
};
unordered_map<int,Node> DSU;


inline void MakeSet(int x)
{
    DSU[x].parent = x;
    DSU[x].rank = 0;
}

inline int Find(int x)
{
    if (DSU[x].parent == x) return x;
    DSU[x].parent = Find(DSU[x].parent);
    return DSU[x].parent;
}

inline void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if (xRoot == yRoot) return;
    numComponents--;
    if (DSU[xRoot].rank < DSU[yRoot].rank)
    {
        DSU[xRoot].parent = yRoot;
    }
    else if (DSU[xRoot].rank > DSU[yRoot].rank)
    {
        DSU[yRoot].parent = xRoot;
    }
    else
    {
        DSU[yRoot].parent = xRoot;
        DSU[xRoot].rank++;
    }
}

int main()
{
    numComponents = 4, m = 8;
   
    MakeSet(1);
    MakeSet(2);
    MakeSet(3);
    MakeSet(4);
    
    Union(1, 2);
    Union(2, 1);
    Union(2, 3);
    Union(1, 3);
    Union(1,2);
	int res=Find(2);
	printf("%d",res);
    printf("%d\n",numComponents);
    
    return 0;
}
