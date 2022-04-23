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
         printf("           |            欢迎光临学生成绩管理系统           |\n"); 
         printf("           |------------------------------------------------|\n"); 
         printf("           |       1  ==> 创建学生数据                  |\n"); 
         printf("           |       2  ==> 载入学生数据                  |\n"); 
         printf("           |       3  ==> 添加学生数据                  |\n"); 
         printf("           |       4  ==> 查询学生数据                  |\n"); 
         printf("           |       5  ==> 删除学生数据                  |\n"); 
         printf("           |       6  ==> 统计班级人数                 |\n"); 
         printf("           |       0  ==> 退出学生管理系统                  |\n"); 
         printf("           |------------------------------------------------|\n"); }  
struct student *init (int n) { 
    int i; 
    struct student *head,*p,*s;     for (i=1;i<=n;i++)     {  
        if (i==1)         { 
            printf("请输入第%d个学生信息:\n",i); 
            p=(struct student *)malloc (sizeof(struct student));            
			printf("学号\n");             
			scanf("%d",&p->num);             
			printf("姓名\n");            
			scanf("%s",&p->name);            
			printf("语文\n"); 
            scanf("%f",&p->chinese);            
			printf("数学\n");            
			scanf("%f",&p->math);            
			printf("英语\n"); 
            scanf("%f",&p->english);
			
            p->sum=p->chinese+p->math+p->english;            
			p->ave=p->sum/3;             
			head=p; 
            if (n==1)  p->next=Null;         }        
		     else         { 
            printf("请输入第%d个学生信息:\n",i); 
            s=(struct student *)malloc (sizeof(struct student));            
			printf("学号\n");             
			scanf("%d",&s->num);           
			printf("姓名\n");            
			scanf("%s",&s->name);          
			printf("语文\n"); 
            scanf("%f",&s->chinese);        
			printf("数学\n");            
			scanf("%f",&s->math);          
			printf("英语\n");
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
    printf ("请问要在哪个学生后面插入数据（输入学号）:");     
	scanf("%d",&xuehao); 
    pi=(struct student *)malloc (sizeof(struct student));    
	p=head; 
    printf("学号\n");     
	scanf("%d",&pi->num);     
	printf("姓名\n"); 
    scanf("%s",&pi->name);    
	printf("语文\n"); 
    scanf("%f",&pi->chinese);    
	printf("数学\n"); 
    scanf("%f",&pi->math);    
	printf("英语\n"); 
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
    printf("请输入要查找同学的学号:");  
	scanf("%d",&no);    
	while(p!=Null)      { 
      if(p->num==no)        { 
        printf("------------------学生成绩表----------------------\n"); 
		printf("===================================================\n"); 
        printf("%-5s%-8s%-8s%-8s%-8s%-8s%-8s\n","学号","姓名","语文","数学","英语","总分","平均分"); 
        printf("===================================================\n");          
        printf("%-5d%-8s%-8.1f%-8.1f%-8.1f%-8.1f%-8.1f\n",p->num,p->name,p->chinese,p->math,p->english,p->sum,p->ave); 
        printf("===================================================\n");   
		break;              } 
        p=p->next;      } 
	  }

struct student *del (struct student *head,int n) { 
    struct student *p,*q;     p=head; 
    if (head==Null)     { 
        printf("没有学生的资料要删除!\n");  
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
     printf("找不到相应的学生资料!\n");  
	return head;  }   
void list(struct student *head) { 
    int i=0; 
    struct student *p; 
	p=head; 
    printf("------------------学生成绩表----------------------\n");    
	printf("===================================================\n"); 
    printf("%-5s%-8s%-8s%-8s%-8s%-8s%-8s\n","学号","姓名","语文","数学","英语","总分","平均分"); 
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
  printf("班级总人数为：%d\n",i); 
   printf("班级语文平均分为a：%4.1f\n",chinese1/i);  
   printf("班级数学平均分为a：%4.1f\n",math1/i);   
   printf("班级英语平均分为a：%4.1f\n",english1/i);   
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
            printf("请问有多少个学生的资料要输入\n");    
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
              printf("请输入要删除学生的学号:\n");      
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
         printf("\n\n\t======>按Enter键返回主菜\n");       
		 fflush(stdin);      
		 c=getchar();     
		 system("cls");       
		 print();     } }
