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
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;

        ListNode *oddList = new ListNode(mod);
        ListNode *oddtemp = oddList;

        ListNode *evenList = new ListNode(mod);
        ListNode *eventemp = evenList;

        int l = 1;
        ListNode *temp = head;
        while (temp)
        {
            if (l % 2)
            {
                oddtemp->next = temp;
                oddtemp = oddtemp->next;
            }
            else
            {
                eventemp->next = temp;
                eventemp = eventemp->next;
            }
            l++;
            temp = temp->next;
        }
        l--;

        if (l % 2)
            eventemp->next = NULL;
        else
            oddtemp->next = NULL;

        oddtemp->next = evenList->next;

        return oddList->next;
    }
};