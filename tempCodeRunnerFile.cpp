#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int src_x, int src_y, int new_x, int new_y, int maze[][4], int row, int col, vector<vector<bool>> &visited){
    if((new_x>=0 && new_x<row) && (new_y>=0 && new_y<col) && maze[new_x][new_y]==1 && visited[new_x][new_y]==false){
        return true;
    }
    else {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int src_x, int src_y, string &output, vector<vector<bool>> &visited){
    //BC
    if(src_x=row-1 && src_y==col-1){
        cout<<output<<endl;
        return;
    }
    //recurssion
    //up
    int new_x = src_x-1;
    int new_y = src_y;
    if(isSafe(src_x, src_y, new_x, new_y, maze, row, col, visited)) {
        visited[new_x][new_y]=true;
        output.push_back('U');
        printAllPath(maze, row, col, new_x, new_y, output, visited);
        output.pop_back();
        visited[new_x][new_y]=false;
    }
    //right
    new_x = src_x;
    new_y = src_y+1;
    if(isSafe(src_x, src_y, new_x, new_y, maze, row, col, visited)) {
        visited[new_x][new_y]=true;
        output.push_back('R');
        printAllPath(maze, row, col, new_x, new_y, output, visited);
        output.pop_back();;
        visited[new_x][new_y]=false;
    }
    //down
    new_x = src_x+1;
    new_y = src_y;
    if(isSafe(src_x, src_y, new_x, new_y, maze, row, col, visited)) {
        visited[new_x][new_y]=true;
        output.push_back('D');
        printAllPath(maze, row, col, new_x, new_y, output, visited);
        output.pop_back();
        visited[new_x][new_y]=false;
    }
    //left
    new_x = src_x;
    new_y = src_y-1;
    if(isSafe(src_x, src_y, new_x, new_y, maze, row, col, visited)) {
        visited[new_x][new_y]=true;
        output.push_back('L');
        printAllPath(maze, row, col, new_x, new_y, output, visited);
        output.pop_back();
        visited[new_x][new_y]=false;
    }
    
}

int main(){
    int maze[4][4]={
        {1,0,0,0},
        {1,1,0,0},
        {1,1,0,0},
        {1,1,1,1}
    };
    int row=4;
    int col=4;
    int src_x=0;
    int src_y=0;
    string output="";
    vector<vector<bool>>visited(row,vector<bool>(col,false));
    if(maze[0][0]==0){
        cout<<"No path exists"<<endl;
    }
    else{
        visited[src_x][src_y]==true;
    printAllPath(maze, row, col, src_x, src_y, output, visited);
    }
}