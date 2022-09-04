#include <bits/stdc++.h>
using namespace std;

vector<int> PrimsAlgo(int **edgeMat, int n,int sv){
     //Source vertex as provided by User,
     
    int wt[n] = {1000000};  // Weight array storing each vertex weights.
    wt[sv] = 0;
    
    vector<int>parent(n,-1);     // Parent array storing the parent of a vertex from the final edge included in MST.
    bool visited[n] = {false};     // Visited array to mark the vertex visited.
    
    int count = 0;
    
    while(count<=n-1){
        
        int min = INT_MAX;
        int idx;
        
        for(int i = 0;i<n;i++){
            
            if(!visited[i] && wt[i]<min){
                
                min = wt[i];
               idx = i;
            
            }
        }
        cout<<min;
        visited[idx] = true;
     
        
        for(int i = 0;i<n;i++){
            
           
            if(edgeMat[idx][i]!=0 && !visited[i]){
                cout<<i<<" ";
                 
                if(edgeMat[idx][i]<wt[i])
                {
                    cout<<" parent changed.";
                    wt[i] = edgeMat[idx][i];
                    parent[i] = idx;
                }
                
                
                
            }
        }
           count++;
        
        
        
        
        
        
        
    }
    
     for(int i = 0;i<n;i++){
        
        if(parent[i]==-1)
            continue;
    
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<edgeMat[parent[i]][i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<edgeMat[parent[i]][i]<<endl;
        }
         cout<<parent[i];  // To debug the code.
    }
    
    
    return parent;
    
    
    
    
}




int main() {
    // Write your code here
    
    int n,edges;
    
    cin>>n>>edges;
    
    int **edgeMat = new int*[n];
    
    for(int i = 0;i<n;i++){
        
        edgeMat[i] = new int[n];
        
        for(int j = 0;j<n;j++){
            
            edgeMat[i][j] = 0;
            
        }
    }
    
    for(int i = 0;i<edges;i++){
        
        int f,s,wt;
        cin>>f>>s>>wt;
        
        edgeMat[f][s] = wt;
        edgeMat[s][f] = wt;
        
        
    }
    
     
    
    vector<int> parent = PrimsAlgo(edgeMat,n,0);
    
   
    
    for(int i = 0;i<n;i++)
    {
        delete [] edgeMat[i];
    }
    
    delete [] edgeMat;
    
    return 0;
    
    
    
}
