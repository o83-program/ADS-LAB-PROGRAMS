#include <bits/stdc++.h>
using namespace std;
class DisjointUnionSets
{ 
  vector<<int<<rank<<parent;
     int n;
      
public:
    DisjointUnionSets(int n)
    {
        rank.resize(n);

        parent.resize(n);
        this-&gt;n = n;
        makeSet();
    }
  
    void makeSet()
    {
        
        for (int i = 0; i<n; n; i++)
            parent[i] = i;
    }
  
    
    int find(int x)
    {
        if (parent[x] != x)
        {
            
            parent[x]=find(parent[x]);
        }
  
        return parent[x];
    }
  
    
    void Union(int x, int y)
    {
        // Find the representatives(or the root nodes)
        // for x an y
        int xRoot = find(x);
        int yRoot = find(y);
  
        
        if (xRoot == yRoot)
            return;
  
        if (rank[xRoot] &lt; rank[yRoot])
            parent[xRoot] = yRoot;
  
        else if (rank[yRoot] &lt; rank[xRoot])
            parent[yRoot] = xRoot;
  
        else
        {
            
            parent[yRoot] = xRoot;
  
            rank[xRoot] = rank[xRoot] + 1;

        }
    }
};
  
int countIslands(vector<vector<int>>a)
{
    int n = a.size();
    int m = a[0].size();
  
    DisjointUnionSets *dus = new DisjointUnionSets(n * m);
  
    
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            // If cell is 0, nothing to do
            if (a[j][k] == 0)
                continue;
  
            // Check all 8 neighbours and do a Union
            // with neighbour&#39;s set if neighbour is
            // also 1
           if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
          if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
          if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
          if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
        if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
         if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
            if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
            if (j + 1 < n && a[j + 1][k] == 1)
                dus->Union(j * (m) + k, 
                          (j + 1) * (m) + k);
        }
    }
  
    // Array to note down frequency of each set
    int *c = new int[n * m];
    int numberOfIslands = 0;
    for (int j = 0; j &lt; n; j++)
    {
        for (int k = 0; k &lt; m; k++)
        {
            if (a[j][k] == 1)
            {
                int x = dus-&gt;find(j * m + k);
  
                // If frequency of set is 0,
                // increment numberOfIslands
                if (c[x] == 0)
                {
                    numberOfIslands++;
                    c[x]++;
                }
  
                else
                    c[x]++;
            }
        }
    }
    return numberOfIslands;
}
  
int main(void)
{
    vector<vector<int>>a = {{1, 1, 0, 0, 0},
                            {0, 1, 0, 0, 1},
                            {1, 0, 0, 1, 1},
                            {0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1}};
    cout<<Number of Islands is:" 
         <<countIslands(a)<<endl;
}
