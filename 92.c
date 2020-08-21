//problem => Reverse a linked list from position m to n.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//reverse first ~ nth node. (after this nth node is head)
struct ListNode *reverse(struct ListNode *head, int n){
    //n>=2 임을 가정하고 시작합니다. 당연히 전체 노드 개수도 2개 이상
    struct ListNode *a=head;
    struct ListNode *b=a->next;
    struct ListNode *tmp;
    struct ListNode **tail = &(a->next);
    
    int i;
    for(i=0; i<n; i++){
        tmp = b->next;
        b->next = a;
        a = b;
        b = tmp;
    }

    head = a;  //newhead;
    (*tail) = b;

    return head;
}

//reverse nodes between mth ~ nth.
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if(m==n) return head;
    
    if(m==1) return reverse(head, n-m);
    
    struct ListNode *before_rev = head;
    for(int i=0; i<m-2; i++){
        before_rev = before_rev->next;
    }
    
    struct ListNode *rev_head = before_rev -> next;
    before_rev->next = reverse(rev_head, n-m);
    
    return head;
}
