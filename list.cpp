#include<iostream>
#include<iomanip>
using namespace std;
struct people{
  int number;
  int year;
  int month;
  int day;
  char name[11];
  char ID[20]; //���֤����
  struct people *next;
};
typedef struct people people;
people *create_NULL_link_list(); //����һ��������
people *create_link_list(people *head); //����һ������������
void show_link_list(people *head);
people *addinformation_in_link_list(people *head); //���������Ϣ
people *delpeopleinformation_in_link_list(people *head);//ɾ��������Ϣ
int main()
{
  people *head;
  head=create_NULL_link_list();
  head=create_link_list(head);
  show_link_list(head);
  /*cout<<"����������Ϣ"<<endl;
  head=addinformation_in_link_list(head);
  show_link_list(head);*/
  cout<<"ɾ��������Ϣ"<<endl;
  delpeopleinformation_in_link_list(head);
  show_link_list(head);
  return 0;
}
people *create_NULL_link_list()
{
  people *head;
  head=new people;
  head->next=NULL;
  return head;
}
people *create_link_list(people *head)
{
  people *p1,*p2; 
  char ch='y';
  p2=head;
  while(ch=='y'||ch=='Y'){
	p1=new people;
	cout<<"�������������;";cin>>p1->number;
    cout<<"����������:";cin>>p1->name;
	cout<<"���������֤����:";cin>>p1->ID;
	cout<<"���������������:";cin>>p1->year>>p1->month>>p1->day;
	p2->next=p1;
	p2=p1;
	cout<<"DO YOU WANT TO CONTINUE?(Y/N)";cin>>ch;
  }
  p2->next=NULL; 
  return head;
}
void show_link_list(people *head)
{
  people *p;
  p=head;
  if(head->next==NULL)
	  cout<<"��Ϣ��δ¼��"<<endl;
  else{
	  cout<<setw(10)<<"���"<<setw(10)<<"����"<<setw(10)<<"֤����";
	  cout<<setw(10)<<"��"<<setw(10)<<"��"<<setw(10)<<"��"<<endl;
     while(p->next!=NULL){
		 p=p->next;
         cout<<setw(10)<<p->number<<setw(10)<<p->name<<setw(10)<<p->ID;
		 cout<<setw(10)<<p->year<<setw(10)<<p->month<<setw(10)<<p->day<<endl;	     
	   }
  }
}
people *addinformation_in_link_list(people *head)
{
  people *p0,*p1,*p2;
  p1=new people;
  cout<<"�������������;";cin>>p1->number;
  cout<<"����������:";cin>>p1->name;
  cout<<"���������֤����:";cin>>p1->ID;
  cout<<"���������������:";cin>>p1->year>>p1->month>>p1->day;
  p0=head->next;
  if(p0->number>p1->number){
	  head->next=p1;
	  p1->next=p0;
  }
  else{
	  while(p0->number<=p1->number&&p0->next!=NULL){
	    p2=p0;p0=p0->next;
	  }
	  if(p0->number>p1->number){
	    p2->next=p1;p1->next=p0;
	  }
	  else{
	    p0->next=p1;p1->next=NULL;
	  }
  }
  return head;
}
people *delpeopleinformation_in_link_list(people *head)
{
	if(head->next==NULL){
	  cout<<"��������Ϣ,�޷�ִ�д˲���"<<endl;
	}
	else{
       people *p1,*p2;
	   char a[11];
       cout<<"����������ɾ������������:";cin>>a;
       p1=head->next;
	   if(strcmp(p1->name,a)==0){  //ɾ����Ϊͷ���
	     head->next=p1->next;
		 delete p1;  //�ͷ�p1ָ����ڴ�ռ�
		 cout<<"ɾ���ɹ�"<<endl;
	   }
	   else{
           while(strcmp(p1->name,a)!=0&&p1->next!=NULL){
             p2=p1;p1=p1->next;
		   }
           if(strcmp(p1->name,a)==0){
              if(p1->next==NULL) //ɾ����ĩ���
                  p2->next=NULL;
			  else
				  p2->next=p1->next;
			  delete p1;
			  cout<<"ɾ���ɹ�"<<endl;
		   }
           else
             cout<<"δ�ҵ�����,�޷�ִ��ɾ������"<<endl;
	   }
	   }
    return head;
}
//δ���