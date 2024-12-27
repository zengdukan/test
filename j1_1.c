#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int _value;
    struct ListNode* _next;
} ListNode;

void list_print(ListNode* head)
{
    while (head != NULL)
    {
        printf("%d ", head->_value);
        head = head->_next;
    }
    printf("\n");
}

void list_print_reverse(ListNode* head)
{
    if (head != NULL)
    {
        list_print_reverse(head->_next);
        printf("%d\n", head->_value);
    }
}

void list_append(ListNode** head, int value)
{
    ListNode* node = (ListNode*)calloc(1, sizeof(ListNode));
    node->_value = value;
    node->_next = NULL;

    if (*head == NULL)
    {
        *head = node;
    }
    else
    {
        ListNode* tail = *head;
        while (tail->_next != NULL)
        {
            tail = tail->_next;
        }

        tail->_next = node;
    }
}

void list_free(ListNode* head)
{
    ListNode* next = NULL;
    while (head != NULL)
    {
        next = head->_next;
        free(head);
        head = next;
    }
}

void list_remove(ListNode** head, int target)
{
    ListNode* iter = *head;

    if (head == NULL || *head == NULL)
        return;

    if (iter->_value == target)
    {
        *head = iter->_next;
        free(iter);
        return;
    }

    ListNode* pre = iter;
    iter = iter->_next;
    ListNode* target_node = NULL;
    while (iter)
    {
        if (iter->_value == target)
        {
            target_node = iter;
            break;
        }

        pre = iter;
        iter = iter->_next;
    }

    if (target_node != NULL)
    {
        pre->_next = target_node->_next;
        free(target_node);
    }
}


int main(int argc, char* argv[])
{
    ListNode* list = NULL;

    int i = 0;
    for (i = 0; i < 10; i++)
        list_append(&list, i);
    list_print(list);

    // list_remove(&list, 0);
    // list_remove(&list, 9);
    // list_remove(&list, 5);
    // list_remove(&list, 15);
    list_print(list);

    list_print_reverse(list);

    list_free(list);

    return 0;
}