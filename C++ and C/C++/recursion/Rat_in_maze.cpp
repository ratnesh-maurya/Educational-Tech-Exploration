##include <bits/stdc++.h>
using namespace std;

void solveRatMaze(vector<vector<int>>&m, int n, vector<string> &ans, int x, int y,
                  vector<vector<int>> visited, string path) {
	//base case
	if (x == n - 1 and y == n - 1) {
		ans.push_back(path);
		return;
	}

	//make cell visited
	visited[x][y] = 1;

	//check for all 4 directions
	//4 case - D L R U

	//down
	int newx = x + 1;
	int newy = y;
	if (isSafe(newx, newy, n, visited, m)) {
		path.push_back('D');
		solveRatMaze(m, n, ans, newx, newy, visited, path);
		path.pop_back();
	}

	//left
	newx = x;
	newy = y - 1;
	if (isSafe(newx, newy, n, visited, m)) {
		path.push_back('L');
		solveRatMaze(m, n, ans, newx, newy, visited, path);
		path.pop_back();
	}

	//right
	newx = x;
	newy = y + 1;
	if (isSafe(newx, newy, n, visited, m)) {
		path.push_back('R');
		solveRatMaze(m, n, ans, newx, newy, visited, path);
		path.pop_back();
	}

	//up
	newx = x - 1;
	newy = y;
	if (isSafe(newx, newy, n, visited, m)) {
		path.push_back('U');
		solveRatMaze(m, n, ans, newx, newy, visited, path);
		path.pop_back();
	}
}
vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here
	vector<string>ans;
	if (m[0][0] == 0) {
		return ans;
	}
	vector<vector<int>>visited = m;
	int srcx = 0, srcy = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
	string path = "";
	solveRatMaze(m, n, ans, srcx, srcy, visited, path);
	return ans;
}
int main()
{
    
    int n; cin>>n;
    vector<vector<int>>m(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>m[i][j];
        }
    }
    vector<string>ans = findPath(m, n);
    if(ans.size() == 0) {
        cout<<"-1";
    }
    else {
        for(auto x: ans) {
            cout<<x<<" ";
        }
    }
    return 0;
}