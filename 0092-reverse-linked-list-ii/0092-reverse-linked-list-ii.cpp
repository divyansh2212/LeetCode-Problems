// Jai Shree Babosa!

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *reverse(ListNode *head, ListNode *tail)
    {
        ListNode *prevptr = NULL, *currptr = head, *nextptr;

        while (currptr != tail)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }

        head->next = tail;

        return prevptr;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int l = 0;
        ListNode *temp = head;
        ListNode *newHead = head;
        ListNode *newTail = NULL;
        ListNode *leftptr = NULL;

        while (temp != NULL)
        {
            l++;
            if (l == left - 1)
                leftptr = temp;
            if (l == left)
                newHead = temp;
            if (l == right + 1)
                newTail = temp;
            temp = temp->next;
        }

        if (leftptr != NULL)
            leftptr->next = reverse(newHead, newTail);
        else
            head = reverse(newHead, newTail);

        return head;
    }
};