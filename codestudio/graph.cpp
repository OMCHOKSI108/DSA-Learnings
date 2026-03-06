#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;

public:

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void AddEdge(int u,int v){

        if(u>=V || v>=V){
            cout<<"Invalid vertex: "<<u<<" "<<v<<endl;
            return;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void PrintAdjList(){

        for(int i=0;i<V;i++){
            cout<<i<<" -> ";
            for(int x:adj[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }

    }

    void DFSHelper(int node, vector<bool> &visited){

        visited[node] = true;
        cout<<node<<" ";

        for(int neighbor : adj[node]){

            if(!visited[neighbor]){
                DFSHelper(neighbor, visited);
            }

        }

    }

    void DFS(){

        vector<bool> visited(V,false);

        for(int i=0;i<V;i++){

            if(!visited[i]){
                DFSHelper(i,visited);
            }

        }

        cout<<endl;

    }


    
    void BFS(){

        vector<bool> visited(V,false);
        queue<int> Q;

        for(int i=0;i<V;i++){

            if(!visited[i]){

                Q.push(i);
                visited[i] = true;

                while(!Q.empty()){

                    int front = Q.front();
                    Q.pop();

                    cout<<front<<" ";

                    for(int neighbor : adj[front]){

                        if(!visited[neighbor]){

                            Q.push(neighbor);
                            visited[neighbor] = true;

                        }

                    }

                }

            }

        }

        cout<<endl;

    }

};

int main(){

    Graph g(10);

    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,0);

    g.AddEdge(5,9);

    cout<<"Adjacency List:"<<endl;
    g.PrintAdjList();

    cout<<"\nBFS : ";
    g.BFS();

    cout<<"DFS : ";
    g.DFS();

    return 0;
}