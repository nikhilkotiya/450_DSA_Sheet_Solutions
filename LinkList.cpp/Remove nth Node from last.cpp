// 1->2->3->4->5->6->7->8
// delete 2 node
// 1->2->3->4->5->6->8


// Brute force sol
// Time complexity - O(N+N+n) N->length of list,nth node to delete.
// Space complexity - O(1)

class Solution {
public:
    // reversing the given list
    // 8->7->6->5->4->3->2->1
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            ListNode* next = temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head=reverse(head);//reverse 
        ListNode* q=head;
        // After reversing we just need to delete n from starting .
        if(n==1)
        {
            ListNode* prev=head->next;
            head=NULL;
            prev=reverse(prev);
            return prev;
        }
        int count=1;
        ListNode* prev=NULL;
        while(count!=n)
        {
            prev=head;
            head=head->next;
            count++;    
        }
        prev->next=head->next;
        return reverse(q);
    }
};

// Optimised approch 
// here we use topoys method 
// here we are using two pointers fast and slow 
// for n=2
// step 1-> we iterate fast poniter till it not equal to n (0 to n-1)
// after loop is completed our fast is at 2nd Node and slow at 1 after that we iteate both the slow and fast 
// pointer in link list until fast not reaches to end.
// Let take the length os the list is N and we need to delete 2 node
// so after step 1 our fast is at 2 and slow is at 1
// at the moment fast reaches null its mean that it iterates N node from list and over slow is 1 time smaller
// so fast is At N and slow is at N-1 and we need to delete N-1 Node  


// Time complexity - O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            return head->next;    
        }
        while(fast->next!=NULL && fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};