#include<iostream>
using namespace std;

bool bookAlloc(int boards[], int start, int end, int stu, int noOfBoards)
{
    if(start>end) return false;

    int painterCount = 1;

    int mid = (start+end)/2;

    int boardsToPainter = 0;

    for(int i=0;i<noOfBoards;i++)
    {
        if((boardsToPainter + boards[i])<=mid)
        {
            boardsToPainter += boards[i];
        }
        else
        {
            painterCount++;
            if(painterCount>stu || boards[i]>mid) 
            {
                return false;
            }
            boardsToPainter=boards[i];
        }
    }
    return true;
}


int bookAllocHelper(int boards[], int stu, int start, int end, int ans, int noOfboards)
{
    if(start>end) return ans;

    int mid = (start+end)/2;

    if(bookAlloc(boards,start,end,stu,noOfboards))
    {
        ans = mid;
        return bookAllocHelper(boards,stu,start,mid-1,ans,noOfboards);
    }
    else return bookAllocHelper(boards,stu,mid+1,end,ans,noOfboards);
}

int main()
{
    int noOfBoards,painters;
    cout<<"Enter number of boards and number of painters"<<endl;
    cin>>noOfBoards>>painters;

    int *boards = new int[noOfBoards];

    cout<<"Enter length of each board"<<endl;
    for(int i=0;i<noOfBoards;i++)
    {
        cin>>boards[i];
    }

    int sum = 0;
    for(int i=0;i<noOfBoards;i++)
    {
        sum += boards[i];
    }

    int ans=-1;

    cout<<"Minimum time = "<<bookAllocHelper(boards,painters,0,sum,ans,noOfBoards)<<endl;

    delete[] boards;
}