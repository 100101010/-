#include <iostream>
#include<windows.h>
#include<fstream>
#include<iomanip>
using namespace std;
class Time  //������¼ʱ��(��������ʱ�䣬��������)
{
private:
  int year;
  int month;
  int day;
public:
	Time(int a=0,int b=0,int c=0)
	{
	  year=a;
	  month=b;
	  day=c;
	}
	void set_time(int a=0,int b=0,int c=0)
	{
	  year=a;
	  month=b;
	  day=c;
	}
	void show_time()
	{
	  cout<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
	}
	bool is_leapyear()
	{
      if(year%400==0||year%100!=0&&year%4==0)
        return true;
      else
        return false;
	}
	friend int operator-(Time &time1,Time &time2);
};
//���������
int operator-(Time &time1,Time &time2)
{
    int sum=0;
    int a1[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
    int a2[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
    if(time1.year==time2.year){
        if(time1.is_leapyear()){
            if(time2.is_leapyear()){
                sum+=a2[time2.month]+time2.day-a2[time1.month]-time1.day;
                return sum;
            }
            else{
                sum+=a1[time2.month]+time2.day-a2[time1.month]-time1.day;
                return sum;
            }
        }
        else{
            if(time2.is_leapyear()){
                sum+=a2[time2.month]+time2.day-a1[time1.month]-time1.day;
                return sum;
            }
            else{
                sum+=a1[time2.month]+time2.day-a1[time1.month]-time1.day;
                return sum;
            }
        }
        }
    else if(time1.year+1==time2.year){
        if(time1.is_leapyear()){
            if(time2.is_leapyear()){
                sum+=a2[time2.month]+time2.day+(366-a2[time1.month]-time1.day);
                return sum;
            }
            else{
                sum+=a1[time2.month]+time2.day+(366-a2[time1.month]-time1.day);
                return sum;
            }
            }
        else{
            if(time2.is_leapyear()){
                sum+=a2[time2.month]+time2.day+(365-a1[time1.month]-time1.day);
                return sum;
            }
            else{
                sum+=a1[time2.month]+time2.day+(365-a1[time1.month]-time1.day);
                return sum;
            }
      }
    }
    else{
        int i;
        for(i=time1.year+1;i<=time2.year-1;i++){
            if(i%400==0||i%4==0&&i%100!=0)
                sum+=366;
            else
                sum+=365;
        }
        if(time1.is_leapyear()){
         if(time2.is_leapyear()){
            sum+=a2[time2.month]+time2.day+(366-a2[time1.month]-time1.day);
            return sum;
            }
         else{
            sum+=a1[time2.month]+time2.day+(366-a2[time1.month]-time1.day);
            return sum;
            }
        }
      else{
         if(time2.is_leapyear()){
            sum+=a2[time2.month]+time2.day+(365-a1[time1.month]-time1.day);
            return sum;
            }
         else{
            sum+=a1[time2.month]+time2.day+(365-a1[time1.month]-time1.day);
            return sum;
            }
      }
    }
}
class book_date
{
private:
    Time date;
	string book_name;
	string ISBN;
    string book_author;
    string publishing_company;
	int order;//���
	int count;//����
public:
    book_date(string s1="",string s2="",string s3="",string s4="",int order1=0,int count1=0,
              int year1=0,int month1=0,int day1=0)
	:date(year1,month1,day1)
	{
        book_name=s1;
        ISBN=s2;
        book_author=s3;
        publishing_company=s4;
        order=order1;
        count=count1;
	}
    void show_book_date_information()
	{
	  cout<<"����:"<<book_name<<endl;
	  cout<<"ISBN��:"<<ISBN<<endl;
	  cout<<"����:"<<book_author<<endl;
	  cout<<"������:"<<publishing_company<<endl;
	  cout<<"��������:";
	  date.show_time();
	  cout<<"��ͼ����ִ�����:"<<count<<endl;
	}
	void revise_book_date_name()
	{
	    string s1;
	    string s2;
	    for(;;){
           cout<<"�����뱾ͼ���������:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ������:";
	       cin>>s2;
	       if(s1!=s2)
               cerr<<"�����������ݲ���ͬ������������"<<endl;
           else
               break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_ISBN()
	{
	    string s1;
	    string s2;
	    for(;;){
            cout<<"�����뱾ͼ�����ISBN��:";
	        cin>>s1;
            cout<<"���ٴ�ȷ��ISBN��:";
            cin>>s2;
            if(s1!=s2)
                cerr<<"�����������ݲ���ͬ������������"<<endl;
            else
                break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_author()
	{
	    string s1;
	    string s2;
	    for(;;){
            cout<<"�����뱾ͼ�������������:";
            cin>>s1;
            cout<<"���ٴ�ȷ����������:";
            cin>>s2;
            if(s1!=s2)
                cerr<<"�����������ݲ���ͬ������������"<<endl;
            else
                break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_publishing_company()
	{
	    string s1;
	    string s2;
	    for(;;){
            cout<<"�����뱾ͼ����³�����:";
            cin>>s1;
            cout<<"���ٴ�ȷ�ϳ�����:";
            cin>>s2;
            if(s1!=s2)
                cerr<<"�����������ݲ���ͬ������������"<<endl;
            else
                break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_order()
	{
	    int s1;
	    int s2;
	    for(;;){
            cout<<"�����뱾ͼ����°��:";
            cin>>s1;
            cout<<"���ٴ�ȷ�ϰ��:";
            cin>>s2;
            if(s1!=s2)
                cerr<<"�����������ݲ���ͬ������������"<<endl;
            else
                break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_count()
	{
	    int s1;
	    int s2;
	    for(;;){
            cout<<"�����뱾ͼ���������:";
            cin>>s1;
            cout<<"���ٴ�ȷ������:";
            cin>>s2;
            if(s1!=s2)
                cerr<<"�����������ݲ���ͬ������������"<<endl;
            else
                break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
};
class book_location:public book_date
{
private:
    string classification;//���
    int book_shelf;//�����
    int storey;//����
public:
    book_location(string s1="",int book_shelf1=0,int storey1=0,string s2="",string s3="",string s4="",string s5="",
                  int order1=0,int count1=0,int year1=0,int month1=0,int day1=0)
    :book_date(s2,s3,s4,s5,order1,count1,year1,month1,day1)
    {
        classification=s1;
        book_shelf=book_shelf1;
        storey=storey1;
    }
    void set_book_location(string classification1="",int book_shelf1=0,int storey1=0)
    {
        classification=classification1;
        book_shelf=book_shelf1;
        storey=storey1;
    }
    void show_book_location_information()
    {
        cout<<"���:"<<classification<<endl;
        cout<<"�����:"<<book_shelf<<endl;
        cout<<"����:"<<storey<<endl;
    }
    void revise_book_location_classification()
	{
	    string s1;
	    string s2;
	    for(;;){
           cout<<"�����뱾ͼ��������:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ�����:";
	       cin>>s2;
	       if(s1!=s2)
               cerr<<"�����������ݲ���ͬ������������"<<endl;
           else
               break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_location_book_shelf()
	{
	    int s1;
	    int s2;
	    for(;;){
           cout<<"�����뱾ͼ����������:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ�ϵڼ����:";
	       cin>>s2;
	       if(s1!=s2)
               cerr<<"�����������ݲ���ͬ������������"<<endl;
           else
               break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_book_date_name()
	{
	    int s1;
	    int s2;
	    for(;;){
           cout<<"�����뱾ͼ����²���:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ�ϲ���:";
	       cin>>s2;
	       if(s1!=s2)
               cerr<<"�����������ݲ���ͬ������������"<<endl;
           else
               break;
	    }
	    cout<<"�޸ĳɹ�"<<endl;
	}
};
class borrow_return_book
{
private:
	Time borrow_time;
	Time return_time;
	book_date book[10];//һ������ʮ����
	int count;//������¼�û�����ı���
	bool return_yes_or_not;//������¼�û��Ƿ���,1�����ѹ黹����δ����
public:
	/*borrow_return_book()
	{
	  borrow_time.set_time(0,0,0);
	  return_time.set_time(0,0,0);
	  count=0;
	  return_yes_or_not=true;
	}*/
    borrow_return_book(int y1=0,int m1=0,int d1=0,int y2=0,int m2=0,int d2=0,int a=0,bool b=true)
	:borrow_time(y1,m1,d1),return_time(y2,m2,d2)
	{
	  count=a;
      return_yes_or_not=b;
	}
	void show_borrow_return_book_information()
	{
	  cout<<"����ʱ��:";
	  borrow_time.show_time();
	  cout<<"ͼ��״̬:";
	  if(return_yes_or_not==false){
	    cout<<"δ�黹"<<endl;
	  }
	  else{
	    cout<<"�ѹ黹"<<endl;
		cout<<"�黹ʱ��:";
		return_time.show_time();
	  }
	  int i;
	  cout<<"�����鼮:"<<endl;
	  for(i=0;i<count;i++)
		book[i].show_book_date_information();
	}
};
class student:public borrow_return_book
{
private:
	string name;
	string id_number;//���֤��
	string phone_number;
    string student_id;//ѧ��
    string password;
public:
	student(string s1="",string s2="",string s3="",string s4="",string s5="")
	:borrow_return_book()
	{
       name=s1;
	   id_number=s2;
	   password=s3;
	   phone_number=s4;
	   student_id=s5;
	}
	void show_student_information()
	{
	  cout<<"����:"<<name<<endl;
	  cout<<"���֤��:"<<id_number<<endl;
	  cout<<"�绰����:"<<phone_number<<endl;
	  cout<<"ѧ��:"<<student_id<<endl;
	}
	void revise_name()
	{
	  string s1,s2;
	  for(;;){
        cout<<"������������:"<<endl;
	    cin>>s1;
	    cout<<"���ٴ�ȷ�����������:"<<endl;
	    cin>>s2;
        if(s1!=s2)
          cerr<<"�����������ݲ���ͬ������������"<<endl;
        else
          break;
	  }
      cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_id_number()
	{
	  string s1,s2;
	  for(;;){
        cout<<"�����������֤��:"<<endl;
	    cin>>s1;
	    cout<<"���ٴ�ȷ��������֤��:"<<endl;
	    cin>>s2;
        if(s1!=s2)
          cerr<<"�����������ݲ���ͬ������������"<<endl;
        else
          break;
	  }
      cout<<"�޸ĳɹ�"<<endl;
	}
    void revise_phone_number()
	{
	  string s1,s2;
	  for(;;){
        cout<<"�������µ绰����:"<<endl;
	    cin>>s1;
	    cout<<"���ٴ�ȷ����ĵ绰����:"<<endl;
	    cin>>s2;
        if(s1!=s2)
          cerr<<"�����������ݲ���ͬ������������"<<endl;
        else
          break;
	  }
      cout<<"�޸ĳɹ�"<<endl;
	}
    void revise_student_id()
	{
	  string s1,s2;
	  for(;;){
        cout<<"��������ѧ��:"<<endl;
	    cin>>s1;
	    cout<<"���ٴ�ȷ�����ѧ��:"<<endl;
	    cin>>s2;
        if(s1!=s2)
          cerr<<"�����������ݲ���ͬ������������"<<endl;
        else
          break;
	  }
      cout<<"�޸ĳɹ�"<<endl;
	}
	void revise_password()
	{

	}
};
void menu();//�˵�
int user_choice();
void startcheck();
void input_book_information();
void seek_book_location();
void delete_book_infomation();
void borrow_book();
void return_book();
void count_book_information();
void check_borrow_information();
void revise_password();
void revise_book_information();
int main()
{
  system("color f0");
  //startcheck();
  while(1){
    if(user_choice()==10)
		break;
  }
  system("exit");
  return 0;
}
void menu()
{
  system("cls");
  system("title ���˵�-ͼ��������ϵͳ");
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         ͼ��������ϵͳ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         1   ����ͼ����Ϣ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         2   ����ͼ��λ��         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         3   ɾ��ͼ����Ϣ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         4     ����ͼ��           ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         5     �黹ͼ��           ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         6   ͳ��ͼ����Ϣ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         7   ��ѯ������Ϣ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         8   �޸ĵ�¼����         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         9   �޸�ͼ����Ϣ         ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
  cout<<"\t\t\t\t��         10    �˳�ϵͳ           ��\n";
  cout<<"\t\t\t\t������������������������������������������������������������������������\n";
}
int user_choice()
{   //�����
    menu();
    int n;
    cout<<"�밴��ѡ���Ӧ����:";
    cin>>n;
    switch(n){
    case 1:input_book_information();break;
    case 2:seek_book_location();break;
    case 3:delete_book_infomation();break;
    case 4:borrow_book();break;
    case 5:return_book();break;
    case 6:count_book_information();break;
    case 7:check_borrow_information();break;
    case 8:revise_password();break;
    case 9:revise_book_information();break;
    case 10:break;
    default:cerr<<"�޴˶�Ӧ����"<<endl;break;
    }
    return n;
}
void startcheck()
{   //�����
    system("title ��¼/ע����ҳ��");
    student one;ifstream in;ofstream out;
    string student_id1,phone_number1;string password1,id_number1,name1;
    cout<<"                 1:��¼"<<endl;
    cout<<"                 2:ע��"<<endl;
    int n;
    cout<<"              ���������ѡ��:";
    cin>>n;
    //cin.get();
    if(n==1){
        system("cls");
        for(;;){
            in.open("password.txt",ios_base::app);
            if(!in){
                cerr<<"�ļ���ʧ��(�ļ�������)�������������"<<endl;
                cin.get();cin.get();
                exit(0);
            }
            cout<<"                 ѧ��:";
            cin>>student_id1;
            student_id1+='/';
            char c;int flag=0;
            string password2,student_id2;
            while(!in.eof()){
                while(c!='/'&&!in.eof()){
                    in.get(c);
                    student_id2+=c;
                }
                while(c!='\n'&&!in.eof()){
                    in.get(c);
                    password2+=c;
                }
                //cout<<password2<<endl;
                int i=0,j=0;
                if(student_id1==student_id2){
                    for(i=0;i<3;i++){
                        cout<<"                 ����:";
                        cin>>password1;
                        password1+='\n';
                        flag=1;
                        if(password1==password2)
                            return;
                        else
                            cout<<"�������,����������"<<endl;
                    }
                    in.close();
                    if(i==3){
                        cout<<"���Ѿ���������δ������ȷ����,ϵͳ�����˳�"<<endl;
                        exit(0);
                    }
                }
            }
            if(flag==0){
                cout<<"ϵͳδ��⵽��ѧ��,��ȷ��ѧ���Ƿ���ȷ�����Ƿ�δע��"<<endl;
            }
        }
    }
    else if(n==2){
        system("cls");
        in.open("password.txt",ios_base::app);
        if(!in){
            cerr<<"�ļ���ʧ��(�ļ�������)�������������"<<endl;
            cin.get();cin.get();
            exit(0);
        }
        for(;;){
            cout<<"                 ѧ��:";cin>>student_id1;
            string password2,student_id2;
            char c;int flag=0;
            while(!in.eof()){
                while(c!='/'&&!in.eof()){
                    in.get(c);
                    student_id2+=c;
                    cout<<student_id2<<endl;
                }
                while(c!='\n'&&!in.eof()){
                    in.get(c);
                    password2+=c;
                }
                if(student_id2==student_id1){
                    flag=1;
                    cout<<"ϵͳ�Ѵ��ڴ�ѧ��,����ѧ���Ƿ�������ȷ�����Ƿ���ע��"<<endl;
                    break;
                }
            }
            if(flag==0){
                cout<<"                 ����:";cin>>name1;
                cout<<"                 ���֤��:";cin>>id_number1;
                cout<<"                 �绰����:";cin>>phone_number1;
                cout<<"                 ����:";cin>>password1;
                in.close();
                out.open("password.txt",ios_base::app);
                out<<student_id1<<"/"<<password1<<"\n";
                out.close();
                out.open("student.txt",ios_base::app);
                out<<id_number1<<"/"<<name1<<"/"<<phone_number1<<"/"<<student_id1<<"\n";
                out.close();
                break;
            }
        }
        cout<<"ע��ɹ�"<<endl;
        cin.get();
        cout<<"����������뱾ϵͳ"<<endl;
        cin.get();
        return;
    }
    else{
        cout<<"ѡ�����,ϵͳ�����˳�"<<endl;
        cin.get();
        exit(0);
    }
}
void input_book_information()
{   //�����
    system("cls");cin.get();
    ofstream out;int n;
    string book_author1,book_name1,publishing_company1,ISBN1,classification1;
    int count1,order1,book_shelf1,storey1;
    int year1,month1,day1;
    out.open("book.txt",ios_base::app);
    if(!out){
        cerr<<"�ļ���ʧ��(�ļ�������)�������������"<<endl;
        cin.get();
        return ;
    }
    for(;;){
        cout<<"����������:";cin>>book_author1;
        cout<<"����������:";cin>>book_name1;
        cout<<"������ISBN��:";cin>>ISBN1;
        cout<<"�����������:";cin>>publishing_company1;
        for(;;){
            cout<<"��������:";cin>>order1;
            if(order1<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
        for(;;){
            cout<<"����������:";cin>>count1;
            if(count1<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
        cout<<"������ͼ�����:";cin>>classification1;
        for(;;){
            cout<<"������ͼ���ڵڼ������:";cin>>book_shelf1;
            if(book_shelf1<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
        for(;;){
            cout<<"������ͼ��������ܵĲ���:";cin>>storey1;
            if(storey1<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        for(;;){
            cout<<"�������������(�������շֱ�����,�м��ÿո����):";
            cin>>year1>>month1>>day1;
            if(sys.wYear<year1||sys.wYear==year1&&sys.wMonth<month1||
               sys.wYear==year1&&sys.wMonth==month1&&sys.wDay<day1)
                cout<<"�����������,����������"<<endl;
            else
                break;
        }
        out<<book_name1<<"/"<<book_author1<<"/"<<count1<<"/"<<ISBN1<<"/"<<order1;
        out<<"/"<<publishing_company1<<"/"<<year1<<"/"<<month1<<"/";
        out<<day1<<"/"<<classification1<<"/"<<book_shelf1<<"/"<<storey1<<".\n";
        cout<<"������?(1/0)";
        cin>>n;
        if(n==0){
            out.close();break;
        }
    }
    cout<<"����ɹ�"<<endl;
    cin.get();
    cout<<"�����������"<<endl;
    cin.get();
}
void seek_book_location()
{   //�����
    system("cls");cin.get();
    string book_name1,book_name2,other_book_information;
    ifstream in;
    in.open("book.txt",ios_base::app);
    if(!in){
        cout<<"�ļ���ʧ��"<<endl;
        cin.get();
        return ;
    }
    cout<<"���������ѯλ�õ��鼮��:";cin>>book_name1;
    char c;int flag=0;
    while(!in.eof()){
        in.get(c);
        while(c!='/'){
            book_name2+=c;
            in.get(c);
        }
        //cout<<book_name2<<endl;
        //in.get(c);
        if(book_name1==book_name2){
            while(c!='.'){
                other_book_information+=c;
                in.get(c);
            }
            flag=1;
            cout<<"���ҵ�"<<endl;
            cout<<setw(10)<<"ͼ����"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"ISBN��"<<setw(10)<<"���";
            cout<<setw(10)<<"������"<<setw(10)<<"��������"<<setw(10)<<"���"<<setw(10)<<"�����"<<setw(10)<<"����"<<endl;
            //cout<<endl;
            cout<<setw(10)<<book_name1<<" "<<other_book_information<<endl;
            cin.get();
            in.close();
            break;
        }
    }
    if(flag==0){
        cout<<"ϵͳδ�ҵ����鼮,��ȷ���鼮���Ƿ���ȷ"<<endl;
    }
    cout<<"�����������"<<endl;
    cin.get();
}
void delete_book_infomation()
{   //�����
    system("cls");cin.get();
    string book_name1,book_name2,othor_book_information;
    cout<<"���������޸ĵ��鼮����:";cin>>book_name1;
    ofstream out;ifstream in;
    in.open("book.txt");
    if(!in||in.eof()){
        cerr<<"�ļ������ڻ�δ¼���κ��鼮��Ϣ"<<endl;
        cin.get();
        return ;
    }
    char c;
    while(in.peek()!=EOF){
        in.get(c);
        while(c!='/'){
            book_name2+=c;
            in.get(c);
        }
        while(c!='.'){
            othor_book_information+=c;
            in.get(c);
        }
        //cout<<book_name2<<endl;
        if(book_name1!=book_name2){
            out.open("book1.txt",ios_base::app);
            if(!out){
                cerr<<"�ļ���ʧ��"<<endl;
                cin.get();
                return ;
            }

            cout<<othor_book_information<<endl;
            out<<book_name2<<"/"<<othor_book_information<<".\n";
            out.close();
        }
    }
    in.close();
    out.open("book.txt",ios::trunc);
    in.open("book1.txt");
    while(in.peek()!=EOF){
        in.get(c);
        out<<c;
    }
    out.close();
    in.close();
    cout<<"ɾ���ɹ�"<<endl;
    cin.get();
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void borrow_book()
{   system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void return_book()
{   system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void count_book_information()
{   system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void check_borrow_information()
{   system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void revise_password()
{   system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void revise_book_information()
{
    system("cls");cin.get();
    cout<<"�˹�����δʵ��"<<endl;
    cout<<"��������������˵�"<<endl;
    cin.get();
}
