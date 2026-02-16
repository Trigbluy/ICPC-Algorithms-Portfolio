#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
typedef long long ll;
using namespace std;

const int NMAX = 1e6 + 10;
const int INF  = numeric_limits<int> :: max();
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
    int flow = INF;
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

int main () {
    fastio;
    int n, s, e_, i, a, b, c, m;
    edge e;

    cin >> n >> s >> e_;
    // cout << "Li 3" << endl;

    parent = vi(210);
    pos_parent = vi(210);
    flow_parent = vi(210);
    residual_network = vve(210);
    source = 0;
    sink = 205;

    for (i=1;i<=n;i++){
        e.capacity = 0;
        e.vertex = i;
        e.reverse = residual_network[i].size();
        residual_network[i+101].push_back(e);
        
        e.capacity = 1;
        e.vertex = i+101;
        e.reverse = residual_network[i+101].size()-1;
        residual_network[i].push_back(e);
    }

    for(i=0;i<s;i++){
        cin >> a;

        e.capacity = 0;
        e.vertex = 0;
        e.reverse = residual_network[0].size();
        residual_network[a].push_back(e);
        
        e.capacity = 1;
        e.vertex = a;
        e.reverse = residual_network[a].size()-1;
        residual_network[0].push_back(e);
    }
    // cout << "li s" << endl;
    for(i=0;i<e_;i++){
        cin >> a;

        e.capacity = 0;
        e.vertex = a + 101;
        e.reverse = residual_network[a + 101].size();
        residual_network[sink].push_back(e);
        
        e.capacity = 1;
        e.vertex = sink;
        e.reverse = residual_network[sink].size()-1;
        residual_network[a + 101].push_back(e);
    }

    cin >> m;
    // cout << "Li m" << endl;
    for(i=0;i<m;i++){
        cin >> a >> b;

        e.capacity = 0;
        e.vertex = a + 101;
        e.reverse = residual_network[a + 101].size();
        residual_network[b].push_back(e);
        
        e.capacity = 1;
        e.vertex = b;
        e.reverse = residual_network[b].size()-1;
        residual_network[a + 101].push_back(e);
    }

    cout << find_max_flow() << endl;
    

    return 0;
}