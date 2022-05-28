#include <bits/stdc++.h>
using namespace std;
#define Max 10000
class Stack
{
    int top;
    int front;
    public:
        int arr[Max];
        Stack(){top=0;front=0;}
        // Stack(){}
        bool push(int x);
        int peek();
        int pop();
        bool is_Empty();
};
bool Stack::push(int x)
{
    if(top<Max)
    {
        arr[top%Max]=x;
        top++;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Stack::peek()
{
    if(front==top)
    {
        return -1;
    }
    else{
        return arr[front%Max];
    }
}
int Stack::pop()
{
    if(top==front)
    {
        return -1;
    }
    int q=arr[front];
    front++;
    return q;
}
bool Stack::is_Empty()
{
    if(front==top)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    class Stack q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
 
    cout << q.pop()
         << " dequeued from queue\n";
 
    cout << "Front item is "
         << q.peek() << endl;
             cout << q.pop()
         << " dequeued from queue\n";
 
    cout << "Front item is "
         << q.peek() << endl;
             cout << q.pop()
         << " dequeued from queue\n";
 
    cout << "Front item is "
         << q.peek() << endl;
             cout << q.pop()
         << " dequeued from queue\n";
 
    cout << "Front item is "
         << q.peek() << endl;
    return 0;
}
