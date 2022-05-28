// Using vector
#include <bits/stdc++.h>
using namespace std;
#define Max 10000
class Stack
{
    public:
        vector<int>v;
        bool push(int x);
        int pop();
        int peek();
        bool is_Empty();
};
bool Stack::push(int x)
{
    if (v.size()<Max)
    {
        v.push_back(x);
        return true;
    }
    else
    {
        return false;
    }
}
int Stack::pop()
{
    if(v.size()==0)
    {
        return -1;
    }
    else{
        int q=v[v.size()-1];
        v.pop_back();
        return q;
    }
}
bool Stack::is_Empty()
{
    return v.size()==0;
}
int Stack::peek()
{
    if(v.size()==0)
    {
        return -1;
    }
    return v[v.size()-1];
}
int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50); 
    s.push(60);
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
    s.pop();
    cout<<s.peek()<<" ";
}
// Using array
#include <bits/stdc++.h>
using namespace std;
#define Max 10000
class Stack
{
    int top;
    public:
        int arr[Max];
        Stack(){top=-1;}
        bool push(int x);
        int peek();
        int pop();
        bool is_Empty();
};
bool Stack::push(int x)
{
    if(top<Max-1)
    {
        arr[++top]=x;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::peek()
{
    if(top==-1)
    {
        return -1;
    }
    else{
        return arr[top];
    }
}
int Stack::pop()
{
    if(top==-1)
    {
        return -1;
    }
    int q=arr[top--];
    return q;
}
bool Stack::is_Empty()
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout<<"Elements present in stack : ";
    while(!s.is_Empty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
    return 0;
}
