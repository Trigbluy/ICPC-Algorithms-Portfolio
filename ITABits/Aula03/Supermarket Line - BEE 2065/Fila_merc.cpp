#include <iostream>
#include <queue>
#include <utility>
using namespace std;

priority_queue<pair<int,pair<int,int>>> workers;
queue<int> clients;
int n,m;
int tempo = 0;

int main ()
{
    cin >> n;
    cin >> m;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        workers.push(make_pair(0,make_pair(-i,a)));
    }

    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        clients.push(a);
    }
    
    for(int i = 0; i < m;i++)
    {
        workers.push({workers.top().first - clients.front() * workers.top().second.second,workers.top().second});
        tempo = tempo > -(workers.top().first - clients.front() * workers.top().second.second)? tempo : -(workers.top().first - clients.front() * workers.top().second.second);
        workers.pop();
        clients.pop();
    }
    
    cout << tempo << endl;

    return 0;

}