#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "duLinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int init(){ 
    
   	int choice, confirm;
    	printf(
    
		"\n\t_________________˫������ADT���ܲ˵�_______________________\t\n"
		"\t|1:��ʼ������                                             |\t\n"
		"\t|2:��������                                               |\t\n"
		"\t|3:����Ԫ��                                               |\t\n"
		"\t|4:չʾ����Ԫ��                                           |\t\n"
		"\t|5:�˳�����                                               |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t������������еĲ�����");
    
	//������
   while(scanf(" %d", &choice)!=1){
    	printf("�����빩�ο���ѡ�");
       fflush(stdin);
}
    
	while (choice<1||choice>5){//�ж�ִ��1-6�����Ҽ��Ϸ�����
		printf("\t��������: '%d' ����!���������룺", choice);
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
	             printf("���ȳ�ʼ������");
            continue;
        }else if(flag==1&&choice==1){
	             printf("�ѳ�ʼ������ѡ����������\n");
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
                        printf("������Ҫ���������");
                while(scanf(" %d", &num)!=1){
                    	printf("����������");
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

	

		//����д����жϴ���
	
    //	system("pause");
}


