#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define Null 0    
struct student { 
    int num; 
    char name[20]; 
    float  chinese,math,english,ave,sum;  
	struct student *next; }; 
  
void print () { 
            printf("           |------------------------------------------------|\n"); 
         printf("           |            ��ӭ����ѧ���ɼ�����ϵͳ           |\n"); 
         printf("           |------------------------------------------------|\n"); 
         printf("           |       1  ==> ����ѧ������                  |\n"); 
         printf("           |       2  ==> ����ѧ������                  |\n"); 
         printf("           |       3  ==> ���ѧ������                  |\n"); 
         printf("           |       4  ==> ��ѯѧ������                  |\n"); 
         printf("           |       5  ==> ɾ��ѧ������                  |\n"); 
         printf("           |       6  ==> ͳ�ư༶����                 |\n"); 
         printf("           |       0  ==> �˳�ѧ������ϵͳ                  |\n"); 
         printf("           |------------------------------------------------|\n"); }  
struct student *init (int n) { 
    int i; 
    struct student *head,*p,*s;     for (i=1;i<=n;i++)     {  
        if (i==1)         { 
            printf("�������%d��ѧ����Ϣ:\n",i); 
            p=(struct student *)malloc (sizeof(struct student));            
			printf("ѧ��\n");             
			scanf("%d",&p->num);             
			printf("����\n");            
			scanf("%s",&p->name);            
			printf("����\n"); 
            scanf("%f",&p->chinese);            
			printf("��ѧ\n");            
			scanf("%f",&p->math);            
			printf("Ӣ��\n"); 
            scanf("%f",&p->english);
			
            p->sum=p->chinese+p->math+p->english;            
			p->ave=p->sum/3;             
			head=p; 
            if (n==1)  p->next=Null;         }        
		     else         { 
            printf("�������%d��ѧ����Ϣ:\n",i); 
            s=(struct student *)malloc (sizeof(struct student));            
			printf("ѧ��\n");             
			scanf("%d",&s->num);           
			printf("����\n");            
			scanf("%s",&s->name);          
			printf("����\n"); 
            scanf("%f",&s->chinese);        
			printf("��ѧ\n");            
			scanf("%f",&s->math);          
			printf("Ӣ��\n");
            scanf("%f",&s->english); 
            s->sum=s->chinese+s->math+s->english;           
			s->ave=s->sum/3;           
			p->next=s;             
			p=s; 
            s->next=Null;         }     
	}  
    return head; 
}  
void insert (struct student *head) { 
    struct student *p,*pi;     
	int xuehao; 
    printf ("����Ҫ���ĸ�ѧ������������ݣ�����ѧ�ţ�:");     
	scanf("%d",&xuehao); 
    pi=(struct student *)malloc (sizeof(struct student));    
	p=head; 
    printf("ѧ��\n");     
	scanf("%d",&pi->num);     
	printf("����\n"); 
    scanf("%s",&pi->name);    
	printf("����\n"); 
    scanf("%f",&pi->chinese);    
	printf("��ѧ\n"); 
    scanf("%f",&pi->math);    
	printf("Ӣ��\n"); 
    scanf("%f",&pi->english); 
    pi->sum=pi->chinese+pi->math+pi->english;
	pi->ave=pi->sum/3;
	if (head==Null)     { 
        head=pi; 
        pi->next=Null;     }     
	else     { 
        while ((p->num!=xuehao)&&(p->next!=Null))
		{  p=p->next;         } 
        if (p->next!=Null){ 
            pi->next=p->next;
			p->next=pi; 
			              }         
		else{
            p->next=pi;            
			pi->next=Null; }    
	          } 
}  


void search (struct student *head) { 
     int no; 
     struct student *p;      
	 p=head;   
    printf("������Ҫ����ͬѧ��ѧ��:");  
	scanf("%d",&no);    
	while(p!=Null)      { 
      if(p->num==no)        { 
        printf("------------------ѧ���ɼ���----------------------\n"); 
		printf("===================================================\n"); 
        printf("%-5s%-8s%-8s%-8s%-8s%-8s%-8s\n","ѧ��","����","����","��ѧ","Ӣ��","�ܷ�","ƽ����"); 
        printf("===================================================\n");          
        printf("%-5d%-8s%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",p->num,p->name,p->chinese,p->math,p->english,p->sum,p->ave); 
        printf("===================================================\n");   
		break;              } 
        p=p->next;      } 
	  }

struct student *del (struct student *head,int n) { 
    struct student *p,*q;     p=head; 
    if (head==Null)     { 
        printf("û��ѧ��������Ҫɾ��!\n");  
		return head;     }  
	while (p->num!=n&&p->next!=Null) { 
        q=p; 
        p=p->next;                }  
    if (p->num==n)     { 
        if (p==head)  
			head=p->next;  
		else 
         q->next=p->next;     
		free (p);     }  
	else 
     printf("�Ҳ�����Ӧ��ѧ������!\n");  
	return head;  }   
void list(struct student *head) { 
    int i=0; 
    struct student *p; 
	p=head; 
    printf("------------------ѧ���ɼ���----------------------\n");    
	printf("===================================================\n"); 
    printf("%-5s%-8s%-8s%-8s%-8s%-8s%-8s\n","ѧ��","����","����","��ѧ","Ӣ��","�ܷ�","ƽ����"); 
    printf("===================================================\n");  
	while (p!=Null)     {         
    printf("%-5d%-8s%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",p->num,p->name,p->chinese,p->math,p->english,p->sum,p->ave); 
     p=p->next;     } 
      printf("===================================================\n");   
	  printf("\n\n"); }   

void tongji (struct student *head) { 
   int i=0; 
   struct student *p; 
   float chinese1=0,math1=0,english1=0,dawu1=0,shudian1=0;   
   p=head; 
   while(p!=Null)   { 
   i=i+1; 
   chinese1=chinese1+p->chinese;   
   math1=math1+p->math; 
   english1=english1+p->english;  
   p=p->next;   }  
  printf("�༶������Ϊ��%d\n",i); 
   printf("�༶����ƽ����Ϊa��%4.1f\n",chinese1/i);  
   printf("�༶��ѧƽ����Ϊa��%4.1f\n",math1/i);   
   printf("�༶Ӣ��ƽ����Ϊa��%4.1f\n",english1/i);   
   printf("\n"); }   


void save(struct student *head) { 
  int i,j;  
  FILE *fp;
  student *p;  
  p=head; 
  char c;  
  if((fp=fopen("d:\\stu.list","wb"))==NULL) { 
    printf("Cannot open file strike any key exit!");   
	getch();  
	exit(0);    } 
while(p){ 
    fwrite(p,sizeof(student),1,fp);    
	p=p->next; } 
      fclose(fp); 
}  


struct student* read() { 
  int i=0,j;    FILE *fp; 
  struct student *p;   
  student *last,*head;  
  head=(student*)malloc(sizeof(student));  
  last=head; 
  if((fp=fopen("d:\\stu.list","rb"))==NULL)  { 
    printf("Cannot open file strike any key exit!");   
	getch();    
	exit(0);    } 
    while(!feof(fp))     { 
        p=(student*)malloc(sizeof(student));  
	if(fread(p,sizeof(student),1,fp)==1)       
		{ 
            last->next=p;      
			last=last->next;         } 
		 } 
      fclose(fp); 
    return head=head->next; }   


int main() { 
    FILE *fp;
	char ch,c;    
	int n=0; 
    struct student *head,*r;    
	print(); 
    while((ch=tolower(getchar()))!='0') { 
        switch(ch)         { 
            case '1':           { 
            printf("�����ж��ٸ�ѧ��������Ҫ����\n");    
			scanf("%d",&n);       
			head=init(n);         
			list(head);     
			save(head);       
			break;           }  
           case '2':           { 
             head=read();         
			 list(head);     
			 break;           }  
          case '3':           { 
              insert(head);     
			  list (head);      
			  save(head);      
			  break;           }  
          case '4':           { 
          search(head);      
		  break;           }  
          case '5':           { 
              int num; 
              printf("������Ҫɾ��ѧ����ѧ��:\n");      
			  scanf("%d",&num);           
			  head=del(head,num);       
			  list (head);           
			  save(head);          
			  break;         
							  } 
		  case '6':            { 
               tongji(head);       
			   break;            }  
       
          default:break;         } 
         printf("\n\n\t======>��Enter����������\n");       
		 fflush(stdin);      
		 c=getchar();     
		 system("cls");       
		 print();     } }
