#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int init(){ 
    
   	int choice, confirm;
    	printf(
    
		"\n\t_________________��������ADT���ܲ˵�_______________________\t\n"
		"\t|1:��ʼ������                                             |\t\n"
		"\t|2:��������                                               |\t\n"
		"\t|3:����Ԫ��                                               |\t\n"
		"\t|4:չʾ����Ԫ��                                           |\t\n"
		"\t|5:����Ԫ��                                               |\t\n"
		"\t|6:��ת����                                               |\t\n"
	    "\t|7:��������Ƿ��                                         |\t\n"
		"\t|8:�����м�ڵ�                                           |\t\n"
		"\t|9:��żԪ�ص���                                           |\t\n"
		"\t|10:�˳�����                                              |\t\n"
		"\t|_________________________________________________________|\t\n\n"
	);
    	printf("\t������������еĲ�����");
    
	//������
   while(scanf(" %d", &choice)!=1){
    	printf("�����빩�ο���ѡ�");
       fflush(stdin);
}
    
	while (choice<1||choice>10){//�ж�ִ��1-6�����Ҽ��Ϸ�����
		printf("\t��������: '%d' ����!���������룺", choice);
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
	          printf("���ȳ�ʼ������");
         continue;
        }else if(flag==1&&choice==1){
	              printf("�ѳ�ʼ������ѡ����������");
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
          case 5:printf("��������Ҫ���ҵ�Ԫ�ص�ֵ��"); 
                 while(scanf(" %d", &num)!=1){
                        	printf("������������");
                            fflush(stdin);
                 }
                         SearchList(L,num); 
                break;
          case 6:ReverseList(&L);
                 break;
          case 7:IsLoopList(L);
                 break;
          case 8:middle= FindMidNode(&L);
                         printf("�м�ڵ��ֵΪ��%d",middle->data);
                 break;
          case 9:ReverseEvenList(&L);
                 break;
          case 10:exit(0);
       }
	
    }

	

		//����д����жϴ���
	
    //	system("pause");
}


