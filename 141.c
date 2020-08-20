/*
problem => Given a linked list, determine if it has a cycle in it.
solution =>
link visited node to a trap node.
if there is no cycle, the traverse of linked list will end
else, fall into trap node
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    struct ListNode *trap = malloc(sizeof(struct ListNode));
    trap->val = -999;
    trap->next = NULL;
    struct ListNode *tmp;
    
    while(true){
        if(!head) return false;
        else if(head->next == trap) return true;
        
        tmp = head->next;
        head->next = trap;
        head = tmp;   
    }    
}
