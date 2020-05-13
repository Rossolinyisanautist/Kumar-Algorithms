
#include <bits/stdc++.h> 
#include <time.h>
using namespace std; 

int travllingSalesmanProblem(int** graph, int s, int n) 
{ 
    vector<int> vertex; 
    for (int i = 0; i < n; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    int min_path = INT_MAX; 
    do { 
  
        int current_pathweight = 0; 
          
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += graph[k][s]; 
  
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 
  
int main() 
{ 
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of cities: \n");
    int** graph;
    graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("\nCalculating shortest path...\n");
    int s = 0; 
    int result = travllingSalesmanProblem(graph, s, n); 
    printf("Result: %d\n", result);
    return 0; 
} 
