#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<string> intro;

    intro.push("Hey ");
    intro.push("its ");
    intro.push("me ");
    intro.push("Komal ");

    cout<<"Size before pop - "<<intro.size()<<endl;
    cout<<"First element - "<<intro.front()<<endl;
    intro.pop();
    cout<<"Next element - "<<intro.front()<<endl;
    cout<<"Size after pop - "<<intro.size()<<endl;
}