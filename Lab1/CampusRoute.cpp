#include<iostream>
#include<vector>
#include<queue>
//needed for reverse of the visited path
#include<algorithm>
using namespace std;

void BFS(vector<vector<int>>& graph, int start, int destination, vector<string>& buildings) {

    vector<bool> visited(6,false);
    vector<int> parent(6,-1);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == destination) {
            break;
        }
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;

                q.push(neighbor);
            }
        }
    }
    // Reconstruct shortest path
    vector<int> path;

    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    //reverse the path back into the correct order
    reverse(path.begin(),path.end());

    // Display path
    cout << "\nShortest Route (BFS):" << endl;

    for (int i = 0; i < path.size(); i++) {
        cout << buildings[path[i]];

        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
    cout << "Number of Edges: " << path.size() - 1 << endl;
}


void DFS(vector<vector<int>>& graph, vector<bool>& visited, int current, vector<string>& buildings) {
    visited[current] = true;
    
    cout << buildings[current] << " -> ";

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            DFS(graph, visited, neighbor, buildings);
        }
    }
}



int main () {

    vector<string> buildings = { 
        "Library", "Gym", "LS", "Hall Moody", "Dorm", "Cafe"
    };

    //6 buckets for 6 buildings and a vector within to list connections to other buildings
    vector<vector<int>> graph(6);
    

    //connecting each location
    //Library = 0
    graph[0].push_back(1); // gym
    //Gym = 1
    graph[1].push_back(0); // library
    graph[1].push_back(2); // ls
    graph[1].push_back(4); // dorm
    //LS = 2
    graph[2].push_back(1); // gym
    graph[2].push_back(3); // hall moody
    //Hall Moody = 3
    graph[3].push_back(2); // ls
    graph[3].push_back(4); // dorm
    //Dorm = 4
    graph[4].push_back(1); // gym
    graph[4].push_back(3); // hall moody
    graph[4].push_back(5); // cafe
    //Cafe = 5
    graph[5].push_back(4);

    //starting point and end point
    int start = 0; //library
    int destination = 4; //dorm

    cout << "Starting Building: " << buildings[start] << endl;
    cout << "Destination: " << buildings[destination] << endl;
    
    BFS(graph, start, destination, buildings);

    vector<bool> visited(6, false);

    cout << endl;
    cout << "DFS Traversal: ";

    DFS(graph, visited, start, buildings);

    cout << endl;

}