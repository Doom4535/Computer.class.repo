#include <iostream>  //  For I/O
#include <vector>    //  For visited set used by the traversal algorithms
#include <queue>     //  Used in the breadth-first search traversal
#include <stack>     //  Used in the depth-first search traversal

using namespace std;

//  Create a nicer name for our 2-D vector representing an
//   adjacency matrix.
typedef vector<vector<int>> AdjacencyMatrix;


//  Here we simply will print the vertex label
void process(int v) {
	cout << v << ' ';
}

//  Breadth-first search
void bfs(const AdjacencyMatrix& A, int start) {
	int n = A.size();           //  Number of vertices in the graph
	vector<int> visited(n, 0);  //  All nodes initially unvisited
	queue<int> Q;               //  Start with an empty queue
	visited[start] = 1;         //  Mark start vertex visited
	Q.push(start);              //  Enqueue the start vertex
	while (!Q.empty()) {        //  While the queue is not empty
		int v = Q.front();      //  Dequeue a vertex
		Q.pop();
		process(v);             //  Process the vertex
		for (int w = 0; w < n; w++) {         //  Consider all unvisited
			if (A[v][w] && !visited[w]) {     //  neighbors
				visited[w] = 1;      //  Mark the neighbor visited       
				Q.push(w);           //  Enqueue the neighbor
			}
		}
	}
}

//  Iterative depth-first search that uses an explicit stack.
void dfs(const AdjacencyMatrix& A, int start) {
	int n = A.size();  //  Number of vertices in the graph
	vector<int> visited(n, 0);  //  All vertices initially unvisited
	stack<int> S;               //  Stack initially empty
	S.push(start);              //  Push the start vertex
	while (!S.empty()) {        //  While the stack is not empty
		int v = S.top();        //  Pop a vertex off of the stack
		S.pop();
		if (!visited[v]) {      //  If the vertex is unvisited,
			process(v);         //  process it, and
			visited[v] = 1;     //  mark it visited
			for (int w = 0; w < n; w++)  //  Push all neighbors
				if (A[v][w])             //  onto the stack
					S.push(w);
		}
	}
}

//  Recursive depth-first search.  
void dfs_rec_helper(const AdjacencyMatrix& A, int v, vector<int>& visited) {
	int n = A.size();  //  Number of vertices in the graph
	visited[v] = 1;    //  Mark the vertex visited
	process(v);        //  Process the vertex
	//  Visit the neighbors in reverse to get the same order
	//  as the iterative, explicit stack version
	for (int w = n - 1; w >= 0; w--)
		if (A[v][w] && !visited[w])         //  Recursively call the DFS function
			dfs_rec_helper(A, w, visited);  //  on all unvisited neighbors
}

//  Calls the recursive DFS traversal function.  Sets up the
//  visited set used by the helper function/
void dfs_rec(const AdjacencyMatrix& A, int start) {
	int n = A.size();                   //  Number of vertices in the graph
	vector<int> visited(n, 0);          //  All vertices initially unvisited
	dfs_rec_helper(A, start, visited);  //  The helper function does the work
}


int main() {
	//  Define a simple graph
	AdjacencyMatrix A = { { 0, 1, 0, 1, 1, 1, 0 },
		                  { 1, 0, 0, 0, 0, 1, 1 },
		                  { 0, 0, 0, 0, 1, 0, 0 },
		                  { 1, 0, 0, 0, 1, 0, 1 },
		                  { 1, 0, 1, 1, 0, 1, 0 },
		                  { 1, 1, 0, 0, 1, 0, 0 },
		                  { 0, 1, 0, 1, 0, 0, 0 } };

<<<<<<< HEAD
	bfs(A, 3);      //  Breadth-first search
	cout << endl;
	dfs(A, 3);      //  Iterative, explicit-stack-based depth-first search
	cout << endl;
	dfs_rec(A, 3);  //  Recursive depth-first search
	cout << endl;
}
=======
	bfs(A, 6);      //  Breadth-first search
	cout << endl;
	dfs(A, 6);      //  Iterative, explicit-stack-based depth-first search
	cout << endl;
	dfs_rec(A, 6);  //  Recursive depth-first search
	cout << endl;
}
>>>>>>> slave
