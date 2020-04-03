#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "duLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int init(){ 
    
   	int choice, confirm;
    	printf(
    
		"\n\t_________________双向链表ADT功能菜单_______________________\t\n"
		"\t|1:初始化链表                                             |\t\n"
		"\t|2:销毁链表                                               |\t\n"
		"\t|3:插入元素                                               |\t\n"
		"\t|4:展示链表元素                                           |\t\n"
		"\t|5:退出程序                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t请输入你想进行的操作：");
    
	//输入检测
   while(scanf(" %d", &choice)!=1){
    	printf("请输入供参考的选项：");
       fflush(stdin);
}
    
	while (choice<1||choice>5){//判断执行1-6，并且检测合法输入
		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
		scanf(" %d", &choice); 
	}
    
	return choice;
}

int main(){ 
	int choice,num,flag=0;
      DuLinkedList L=NULL,lastNode=NULL,newNode=NULL;
	while (1){ 
           choice=init();
        if(flag==0&&choice!=1){
	             printf("请先初始化链表");
            continue;
        }else if(flag==1&&choice==1){
	             printf("已初始化，请选择其他操作\n");
           continue;
        }
	   switch(choice){
	      case 1:InitList_DuL(&L);
                         flag=1;
                 break;
          case 2:DestroyList_DuL(&L);
                          flag=0;
                 break;
          case 3:lastNode=L;  
                while(lastNode->next){
	                       lastNode=lastNode->next;
                }
                        printf("请输入要插入的整数");
                while(scanf(" %d", &num)!=1){
                    	printf("请输入整数");
                        fflush(stdin);
                } 
                        newNode=(DuLinkedList)malloc(sizeof(DuLNode));
                        newNode->data=num;
                        newNode->next=NULL;
                        InsertAfterList_DuL(lastNode,newNode);
                 break;
          case 4:TraverseList_DuL(L,visit);
                 break;
          case 5:exit(0);
       }
	
    }

	

		//以下写你的判断代码
	
    //	system("pause");
}


