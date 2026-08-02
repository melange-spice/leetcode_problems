#include <iostream>
using namespace std;

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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    ListNode *head;
    // linked list on heap
    void insert(int x)
    {

        if (head == nullptr)
        {
            head = new ListNode{x, nullptr};
        }
        else
        {
            ListNode *tmp = head;
            while (tmp->next != nullptr)
            {
                tmp = tmp->next;
            }

            tmp->next = new ListNode{x, nullptr};
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int result = 0;

        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        while (tmp1 != nullptr && tmp2 != nullptr)
        {
            result += tmp1->val + tmp2->val;
            insert(result % 10);
            result /= 10;

            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        while (tmp1 != nullptr && tmp2 == nullptr)
        {
            result += tmp1->val;
            insert(result % 10);
            result /= 10;

            tmp1 = tmp1->next;
        }
        while (tmp1 == nullptr && tmp2 != nullptr)
        {
            result += tmp2->val;
            insert(result % 10);
            result /= 10;

            tmp2 = tmp2->next;
        }

        if (result!=0)
        {
            insert(result);
        }
        

        return head;
    }
};

// linked list on heap
void insert(int x, ListNode *head)
{

    if (head == nullptr)
    {
        head = new ListNode{x, nullptr};
    }
    else
    {
        ListNode *tmp = head;
        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
        }

        tmp->next = new ListNode{x, nullptr};
    }
}

int main()
{

    ListNode l1{9};
    insert(9,&l1);
    insert(9,&l1);
    insert(9,&l1);
    insert(9,&l1);
    insert(9,&l1);
    insert(9,&l1);

    ListNode l2{9};
    insert(9,&l2);
    insert(9,&l2);
    insert(9,&l2);
    

    Solution s;

    ListNode *l3 = s.addTwoNumbers(&l1, &l2);

    return 0;
}