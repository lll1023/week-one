#include "linkedList.h"
#include <malloc.h>
#include <stdio.h>
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L=(LinkedList)malloc(sizeof(LNode));
    if(!(*L)){
    	printf("�����ʼ��ʧ��\n");
     return ERROR ;
    }
    (*L)->next=NULL;
      printf("�����ʼ���ɹ�\n"); 
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    if(*L==NULL){
	    printf("������Ϊ�գ���������\n");
     return;
    }
      LinkedList head=*L;
      LinkedList freeNode=NULL;
    while(head->next){
       	  freeNode=head;
          head=head->next;
          free(freeNode);

    }
      free(head);
      head=NULL;
      printf("�������ٳɹ�\n");
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	int num;
   	 printf("��������Ҫ�����ֵ��");
    while(scanf(" %d", &num)!=1){
           	printf("������������");
            fflush(stdin);
    }
    if(p==NULL){
    	printf("pָ��Ϊ��,����ʧ��\n");
      return ERROR;
    }else{
          q=(LNode*)malloc(sizeof(LNode));
          q->next=NULL;
          q->data=num;
          p->next=q;
       printf("����ɹ�");
    return SUCCESS;
    }
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(p==NULL){
	    printf("pָ��Ϊ��\n");
      return ERROR;
    }else if(p->next==NULL){
	    printf("p����һ�ڵ�Ϊ�գ��޷���ֵ��e\n");
      return ERROR;
    }else{
	    LNode *deleteNode=p->next;
      *e=deleteNode->data;
         p->next=deleteNode->next;
         free(deleteNode);
      return SUCCESS;
    }
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
    if(L==NULL){
	    return;
    }
      LinkedList head=L->next;
      printf("����Ԫ���У�");
    while(head){
	       visit(head->data);
           head=head->next;
    }

}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    if(L==NULL){
	    printf("LΪ��\n");
     return ERROR;
    }
      LinkedList head=L->next;
    int num=1;
    while(head){
	   if(head->data==e){
	        printf("ֵΪ%d�Ľڵ��ڽڵ�%d\n",e,num);
        return SUCCESS;
       }
           head=head->next;
           num++;
    }
      printf("������ֵΪ%d�Ľڵ�\n",e);
    return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status

 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList head=*L;
   if(L==NULL){
    	printf("����L Ϊ��\n");
     return ERROR;
   }else if(head->next==NULL){
	        printf("ֻ��һ���ڵ㣬�޷���ת\n");
      	return ERROR;
   }else{
    	LinkedList now=head->next;
        LinkedList p=NULL,q=NULL;
     while(now->next){
	      q=now->next;
          now->next=p; 
          p=now;
          now=q;  
     }
        now->next=p;
        head->next=now;
        printf("����ת�ɹ�\n");
    }
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L){
   if(L==NULL){
	  printf("LΪ��\n");
    return ERROR;
   }
    LinkedList slow=L,fast=L;
   while(fast&&fast->next){
   	    slow=slow->next;
        fast=fast->next->next;
     if(slow==fast){
	        printf("����ɻ�\n");
	    return SUCCESS;
     }
   }
     printf("�����ɻ�\n");
   return ERROR;  
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LinkedList head=*L;
   if(head==NULL){
	     printf("ͷָ��Ϊ��\n"); 
   }else if(head->next->next){
    	 head=head->next;
       LinkedList odd=head,even=NULL,store=NULL;
     (*L)->next=odd->next;
    while(odd&&odd->next){
       even=odd->next; 
       store=even->next;
       even->next=odd;
       odd->next=store;
       odd=store;
   }
   	  printf("��������ż�����ɹ�\n");
   }
   return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    if(*L==NULL){
    	   printf("����LΪ�գ�û���м�ڵ�\n");
       return NULL;
    }
      LinkedList  slow=*L,fast=*L;
    while(fast&&fast->next){
	    slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


void visit(ElemType e){
	printf("%d\t",e);
}


