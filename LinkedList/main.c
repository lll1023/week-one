#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int init(){ 
    
   	int choice, confirm;
    	printf(
    
		"\n\t_________________单向链表ADT功能菜单_______________________\t\n"
		"\t|1:初始化链表                                             |\t\n"
		"\t|2:销毁链表                                               |\t\n"
		"\t|3:插入元素                                               |\t\n"
		"\t|4:展示链表元素                                           |\t\n"
		"\t|5:查找元素                                               |\t\n"
		"\t|6:反转链表                                               |\t\n"
	    "\t|7:检查链表是否成                                         |\t\n"
		"\t|8:查找中间节点                                           |\t\n"
		"\t|9:奇偶元素调换                                           |\t\n"
		"\t|10:退出程序                                              |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t请输入你想进行的操作：");
    
	//输入检测
   while(scanf(" %d", &choice)!=1){
    	printf("请输入供参考的选项：");
       fflush(stdin);
}
    
	while (choice<1||choice>10){//判断执行1-6，并且检测合法输入
		printf("\t您的输入: '%d' 有误!请重新输入：", choice);
		scanf(" %d", &choice); 
	}
    
	return choice;
}

int main(){ 
	int choice,num,flag=0;
      LinkedList L=NULL,lastNode=NULL,newNode=NULL,middle=NULL;
	while (1){ 
           choice=init();
        if(flag==0&&choice!=1){
	          printf("请先初始化链表");
         continue;
        }else if(flag==1&&choice==1){
	              printf("已初始化，请选择其他操作");
            continue;
        }
	   switch(choice){
	      case 1:InitList(&L);
                          flag=1;
                 break;
          case 2:DestroyList(&L);
                          flag=0;
                 break;
          case 3:lastNode=L;  
                while(lastNode->next){
	                       lastNode=lastNode->next;
                }
                        InsertList(lastNode,newNode);
                 break;
          case 4:TraverseList(L,visit);
                 break;
          case 5:printf("请输入你要查找的元素的值："); 
                 while(scanf(" %d", &num)!=1){
                        	printf("请输入整数：");
                            fflush(stdin);
                 }
                         SearchList(L,num); 
                break;
          case 6:ReverseList(&L);
                 break;
          case 7:IsLoopList(L);
                 break;
          case 8:middle= FindMidNode(&L);
                         printf("中间节点的值为：%d",middle->data);
                 break;
          case 9:ReverseEvenList(&L);
                 break;
          case 10:exit(0);
       }
	
    }

	

		//以下写你的判断代码
	
    //	system("pause");
}


