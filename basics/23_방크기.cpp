#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const char wall = '+';

bool isInRange(int i, int j, int n, int m);
void bfs(vector<vector<bool>>& visited, vector<int>& room_num, int n, int m);
int main(void) {
    int m, n;
    cin >> m >> n;

    vector<string> v(n);
    vector<vector<bool>> visited(n, vector<bool> (m,false));
    vector<int> room_num;
    
    //입력이 n줄의 string이라 1d string vector에 입력받아야 함
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==wall) visited[i][j] = true;
        }
    }
    
    bfs(visited, room_num, n,m);
    sort(room_num.begin(),room_num.end());
    
    for(auto i = room_num.rbegin();i!=room_num.rend();i++) cout<<*i<<" ";
    
    return 0;
}

void bfs(vector<vector<bool>>& visited, vector<int>& room_num, int n, int m){
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {1,0,-1,0};
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) {
                q.push(make_pair(i,j));
                visited[i][j]=true;
                int x,y, roomCnt=1;

                while(!q.empty()){
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    
                    for(int i=0;i<4;i++){
                        if(isInRange(x+dx[i],y+dy[i],n,m) && !visited[x+dx[i]][y+dy[i]]) {
                            visited[x+dx[i]][y+dy[i]]=true;
                            q.push(make_pair(x+dx[i],y+dy[i]));
                            roomCnt++;
                        }
                    }
                }
                room_num.push_back(roomCnt);
            }
        }
    }
    
}

//범위 체크
bool isInRange(int i, int j, int n, int m){
    if(i==-1 || i==n || j==-1 || j==m) return false;
    return true;
}
