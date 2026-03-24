#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Kosaraju(int, vector<vector<int>>&);
void BFS(vector<bool>&, vector<vector<int>>, int, stack<int>&);
void ReverseBFS(vector<bool>&, vector<vector<int>>, int, int, vector<vector<int>>&);

int main()
{
    vector<vector<int>> graph;
    graph.push_back({ 1, 2, 3 }); // 0
    graph.push_back({ 2 }); // 1
    graph.push_back({ 0 }); // 2
    graph.push_back({ }); // 3
    graph.push_back({ 5 }); // 4
    graph.push_back({ 6 }); // 5
    graph.push_back({ 4 }); // 6
 
    Kosaraju(graph.size(), graph);
 
    return 0;
}

void Kosaraju(int v, vector<vector<int>>& adj)
{
    vector<vector<int>> reverse(v);
    for (int i = 0; i < v; i++)
        for (auto& next : adj[i])
            reverse[next].push_back(i);
    
    vector<bool> visited(v, false);
    stack<int> s;
    for (int i = 0; i < v; i++)
        BFS(visited, adj, i, s);
    
    vector<vector<int>> result(v);
    visited.clear();
    visited.resize(v, false);
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        ReverseBFS(visited, reverse, cur, cur, result);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i].empty())
            continue;
        
        cout << "[ ";
        for (auto value : result[i])
            cout << value << ' ';
        cout << " ]" << endl;
    }
}

void BFS(vector<bool>& visited, vector<vector<int>> graph, int cur, stack<int>& s)
{
    if (visited[cur])
        return;
    
    visited[cur] = true;
    for (auto next : graph[cur])
    {
        s.push(next);
        BFS(visited, graph, next, s);
    }
    s.push(cur);
}

void ReverseBFS(vector<bool>& visited, vector<vector<int>> graph, int idx, int cur, vector<vector<int>>& result)
{
    if (visited[cur])
        return;
    
    visited[cur] = true;
    result[idx].push_back(cur);
    for (auto next : graph[cur])
        ReverseBFS(visited, graph, idx, next, result);
}

/*
(방향은 생략)

    0
  / | \
 1--2  3

    4
   / \
  5---6

*/
