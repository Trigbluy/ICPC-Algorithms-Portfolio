#include <bits/stdc++.h>
#define maxn 
#define inf 0x3f3f3f3f

using namespace std;

typedef struct{
    int vertex, capacity, reverse;
}edge;

typedef vector<vector<edge>> vve;
typedef vector<int> vi;

vve residual_network;
queue <int> q;
vi parent, flow_parent, pos_parent;
int source, sink;

int get_minimal(){
    int current = sink;
    int flow = inf;
    while(current != source){
        flow = min(flow, flow_parent[current]);
        current = parent[current];
    }
    current = sink;
    while(current != source){
        residual_network[parent[current]][pos_parent[current]].capacity -= flow;
        residual_network[current][residual_network[parent[current]][pos_parent[current]].reverse].capacity += flow;
        current = parent[current];
    }
    return flow;
}

int augmenting_path(){
    int current, i;
    for(i=0;i<residual_network.size();i++) parent[i] = -1;
    while(!q.empty()) q.pop();
    q.push(source);
    parent[source] = source;
    while(!q.empty()){
        current = q.front();
        q.pop();
        if(current == sink){
            return get_minimal();
        }
        i=0;
        for(auto e: residual_network[current]){
            if(e.capacity>0 && parent[e.vertex]<0){
                parent[e.vertex] = current;
                pos_parent[e.vertex] = i;
                flow_parent[e.vertex] = e.capacity;
                q.push(e.vertex);
            }
            i++;
        }
    }
    return 0;
}

int find_max_flow(){
    int max_flow = 0;
    while(auto flow = augmenting_path())
        max_flow += flow;
    return max_flow;
}

int main(){
    int n, i, m, a, b, c;
    edge e;
    cin >> n >> m;
    parent = vi(n);
    pos_parent = vi(n);
    flow_parent = vi(n);
    residual_network = vve(n);
    source = 0;
    sink = 5;
    for(i=0;i<m;i++){
        cin >> a >> b >> c;

        e.capacity = 0;
        e.vertex = a;
        e.reverse = residual_network[a].size();
        residual_network[b].push_back(e);
        
        e.capacity = c;
        e.vertex = b;
        e.reverse = residual_network[b].size()-1;
        residual_network[a].push_back(e);
    }
    cout << find_max_flow();
    return (0);
}