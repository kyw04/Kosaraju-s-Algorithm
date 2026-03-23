#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Kosaraju(int, vector<vector<int>>&);
void BFS(vector<bool>&, vector<vector<int>>&, stack<int>&, int);

int main()
{
    vector<vector<int>> graph;
    graph.push_back({ 1, 2, 3 }); // 0
    graph.push_back({ 2 }); // 1
    graph.push_back({ }); // 2
    graph.push_back({ }); // 3
    graph.push_back({ 5 }); // 4
    graph.push_back({ 6 }); // 5
    graph.push_back({ }); // 6
 
    Kosaraju(graph.size(), graph);
 
    return 0;
}

void Kosaraju(int v, vector<vector<int>>& adj)
{
    vector<bool> visited(v, false);
    stack<int> s;
    
    vector<vector<int>> reverse(v);
    for (int i = 0; i < v; i++)
    {
        for (auto& next : adj[i])
        {
            reverse[next].push_back(i);
        }
    }
    
    for (int i = 0; i < v; i++)
    {
        BFS(visited, adj, s, i);
    }
    
}

void BFS(vvector<bool>& visited, vector<vector<int>>& graph, stack<int>& s = NULL, int cur)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    
    
    for (auto& next : graph[cur])
    {
        BFS(visited, graph, cur);
    }
    
    s.push(cur);
}

/*
(방향은 생략)

    0
  / | \
 1--2  3

    4
   /
  5--6

*/
