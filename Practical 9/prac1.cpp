#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

void dfs(int start,vector<int>adj[], int vertex){

    vector <bool>visited(vertex,false);

    stack<int>st;

    st.push(start);

    while(!st.empty()){

        int node=st.top();
        st.pop();

        if(visited[node]){
            continue;
        }
        visited[node]=true;

        cout<<node<<" ";

        for(int neibour: adj[node]){
            if(!visited[neibour]){
            st.push(neibour);
            }
        }


    }
}

void bfs(int start, vector<int> adj[], int vertex){
   
    vector<bool>visited(vertex,false);
   
    queue<int>q;

    q.push(start);
    visited[start]= true;

    while(!q.empty()){
       int node=q.front();
       q.pop();

       cout<<node<<" ";

       for( int neibour:adj[node]){
         if(!visited[neibour]){

            visited[neibour]= true;
            q.push(neibour);
            }

        }
    }
}

int main(){
  int vertex,edge;
  cout<<"\n Enter no of vertex and edges in map:";
  cin>>vertex>>edge;

  vector<int> adj[vertex];

  int u,v;

  cout<<"\nEnter connected nodes:\n";

  for(int i=0;i<edge;i++){

    cin>>u>>v;

   adj[u].push_back(v);
    adj[v].push_back(u);

  }

    
    int start;
    cout<<"\n Enter node for start traversal:";
    cin>>start;

    cout<<"DFS \n ";
    dfs(start,adj,vertex);

    cout<<"\n BFS\n";
    bfs(start,adj,vertex);

  }