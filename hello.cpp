#include<iostream>


struct ListNode {
    struct ListNode	*pLast,
                    *pNext;
};

struct List {
    struct ListNode	*pHead,
                    *pTail;
};

bool RemoveListNode(List* pList, ListNode* pRemove) {
    if(pRemove != NULL && pLast != NULL && pList->pHead != NULL){
        ListNode* curr = pList->pHead;
        while(curr){
            if(curr == pRemove){
                if(curr->pLast == NULL){
                    // head node
                    ListNode* next = curr->pNext;
                    if(next != NULL){
                        // more than one node
                        next->pLast = NULL;
                        curr->pNext = NULL;
                    }else{
                        // one node list
                        pLast->pHead = NULL;
                        pLast->pTail = NULL;
                    }
                    if(curr) 
                        delete curr;
                    pRemove = NULL;
                }else if(curr->pNext == NULL){
                   // last node 
                   ListNode* last = curr->pLast
                   if(last != NULL){
                       last->pNext = NULL;
                       curr->pLast = NULL;
                   }
                   if(curr)
                       delete curr;
                   pRemove = NULL;
                }else{
                    ListNode* last = curr->pLast;
                    ListNode* next = curr->pNext;
                    last->pNext = next;
                    next->pLast = last;
                    curr->pNext = NULL;
                    curr->pLast = NULL;
                }
                
            }else{
                curr = curr->pNext;
            }
        }
    }
    return true;
}

int main()
{
    char str[] = "dog";
    printf("%s", str); 
    char *pt = NULL;
    printf("[%s]", pt); 
}

