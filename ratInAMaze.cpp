#include<iostream>
using namespace std;

bool canMove(int** arr , int x , int y ,int n){
    if (x<n && y<n && arr[x][y]==1)
    {
        return  true;
    }
    return false;
    
}
bool RIM(int** arr, int x , int y, int n, int** outputArr){
    if (x == n-1 && y == n-1)
    {
        outputArr[x][y]=1;
        return true;
    }
    
    if (canMove(arr,x,y,n))
    {
        outputArr[x][y]=1;
        if (RIM(arr,x+1,y,n,outputArr))
        {
            return true;
        }
        if (RIM(arr,x,y+1,n,outputArr))
        {
            return true;
        }
        outputArr[x][y]=0;
        return false;
        
    }
    
}

int main()
{
    int n ;
    cin>>n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    int** ansArr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        ansArr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            ansArr[i][j]=0;
        }
        
    }
    if (RIM(arr,0,0,n,ansArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<ansArr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}