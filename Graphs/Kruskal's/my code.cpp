#include<bits/stdc++.h>
using namespace std;


class edgeClass{
    
    public:
    int v1;
    int v2;
    int wgt;
    edgeClass()
    {
        
    }
    edgeClass(int v1,int v2,int wt): v1(v1),v2(v2),wgt(wt){
        
      
    }
    
};

bool compareEdges(edgeClass edge1, edgeClass edge2){
    
    return edge1.wgt<edge2.wgt;    
}

int findParent(int v,int ParentArr[]){
    int parent = ParentArr[v];
    
    
    while(parent!= v)
    {
        parent = ParentArr[parent];
        v = ParentArr[v];
        
        
    }
    
    return parent;
    
    
}

bool check(int v1, int v2,int ParentArr[]){
    
    int p1 = findParent(v1,ParentArr);
    int p2 = findParent(v2,ParentArr);
    
    return p1!=p2;
}

int main() {
    // Write your code here
    
    int n, edges;
    cin>>n>>edges;
    
    edgeClass arr[edges];
    
    for(int i = 0;i<edges;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        
        edgeClass edgeVar(v1,v2,wt);
        
        arr[i] = edgeVar;
    }
    
    sort(arr,arr+n, compareEdges);
    
    
    edgeClass MST[n-1];
    
    int parentArr[n];
    for(int i = 0;i<n;i++){
        
        parentArr[i] = i;
    }
    int j = 0;
    int count = 0;
    
    while(count<n-1){
        
      if(check(arr[j].v1,arr[j].v2,parentArr))
        {
          MST[count] = arr[j];
          
          parentArr[arr[j].v1] = arr[j].v2;
          count++;
          j++;
            
        }
        else
        {
            j++;
            
        }
        
        
    }
    
    for(int i = 0;i<n-1;i++){
        if(MST[i].v1<MST[i].v2){
            cout<<MST[i].v1<<" "<<MST[i].v2<<" "<<MST[i].wgt<<endl;
        }
        else
        {
             cout<<MST[i].v2<<" "<<MST[i].v1<<" "<<MST[i].wgt<<endl;
            
        }
        
        
        
    }
    
    return 0;
    
    
    
    
}
