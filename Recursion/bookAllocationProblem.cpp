#include<iostream>
using namespace std;

bool bookAlloc(int pages[], int start, int end, int stu, int books)
{
    if(start>end) return false;

    int studentCount = 1;

    int mid = (start+end)/2;

    int pagesToStudent = 0;

    for(int i=0;i<books;i++)
    {
        if((pagesToStudent + pages[i])<=mid)
        {
            pagesToStudent += pages[i];
        }
        else
        {
            studentCount++;
            if(studentCount>stu || pages[i]>mid) 
            {
                return false;
            }
            pagesToStudent=pages[i];
        }
    }
    return true;
}


int bookAllocHelper(int pages[], int stu, int start, int end, int ans, int books)
{
    if(start>end) return ans;

    int mid = (start+end)/2;

    if(bookAlloc(pages,start,end,stu,books))
    {
        ans = mid;
        return bookAllocHelper(pages,stu,start,mid-1,ans,books);
    }
    else return bookAllocHelper(pages,stu,mid+1,end,ans,books);
}

int main()
{
    int books,stu;
    cout<<"Enter number of books and number of students"<<endl;
    cin>>books>>stu;

    int *pages = new int[books];

    cout<<"Enter number of pages in each book"<<endl;
    for(int i=0;i<books;i++)
    {
        cin>>pages[i];
    }

    int sum = 0;
    for(int i=0;i<books;i++)
    {
        sum += pages[i];
    }

    int ans=-1;

    cout<<"The maximum number of pages when the maximum number of pages assigned to a student is minimum = "<<bookAllocHelper(pages,stu,0,sum,ans,books)<<endl;

    delete[] pages;
}