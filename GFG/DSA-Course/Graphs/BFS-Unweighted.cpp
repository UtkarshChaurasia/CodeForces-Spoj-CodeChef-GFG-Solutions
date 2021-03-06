/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Please note one can move from node i to node j only if there's an edge from i to j.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two 
lines. Description of testcases is as follows: The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices 
and no of edges respectively. The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the BFS of the graph starting from 0.

Note: The expected output button always produces BFS starting from node 0.

User Task:
You don't need to read input or print anything. Your task is to complete the function bfs() takes the Graph and the number of vertices as its input and 
returns a list containing the BFS traversal of the graph starting from the 0th vertex.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Example:
Input:
2
5 4
0 1 0 2 0 3 2 4
3 2
0 1 0 2

Output:
0 1 2 3 4    // BFS from node 0
0 1 2
*/


#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int V) {

    bool visited[V];
    vector<int> res;
    memset(visited, false, V);
    queue<int> q;
    int s = 0;
    q.push(s);
    visited[0] = true;
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        res.push_back(a);
        for(auto x : g[a])
        {
            if(visited[x]==false)
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }
    return res;
}
