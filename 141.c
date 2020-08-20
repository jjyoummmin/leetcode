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
