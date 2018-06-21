#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<map>
using namespace std;
bool check_time(int y,int m,int d)
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);//��ȡϵͳʱ��
    if(y>sys.wYear){
        return false;
    }
    else{
        if(sys.wYear==y&&sys.wMonth<m)
            return false;
        else{
            if(sys.wYear==y&&sys.wMonth==m&&sys.wDay<d)
                return false;
        }
    }//���ϼ���Ƿ�����Ϊδ������ʱ��
    //���������day�����Ƿ����ʵ��
    int flag=1;
    if(m>12||m<1)
        return false;
    if(y%400==0||(y%4==0&&y%100!=0))//���������
    {
        switch(m){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if(d>31)
                flag=0;break;
        case 4:case 6:case 9:case 11:
            if(d>30)
                flag=0;break;
        case 2:
            if(d>29)
                flag=0;break;
        }
    }
    else{
        switch(m){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            if(d>31)
                flag=0;break;
        case 4:case 6:case 9:case 11:
            if(d>30)
                flag=0;break;
        case 2:
            if(d>28)
                flag=0;break;
        }
    }
    if(flag==0)
        return false;
    else
        return true;
}
class Time
{
private:
    int year;
    int month;
    int day;
public:
    Time()
    {
        year=0;month=0;day=0;
    }
    void set_time(int y=0,int m=0,int d=0)
    {
        year=y;month=m;day=d;
    }
    void show_time()
    {
        cout<<year<<"��"<<month<<"��"<<day<<"��";
    }
    friend istream &operator>>(istream &in,Time &p)
    {
        in>>p.year>>p.month>>p.day;
        return in;
    }
    friend ostream &operator<<(ostream &out,const Time &p)
    {
        out<<p.year<<" "<<p.month<<" "<<p.day;
        return out;
    }
    bool is_leapyear()
    {
        if(year%400==0||(year%4==0&&year&100!=0))
           return true;
        else
           return false;
    }
    int get_year()
    {
        return year;
    }
    int get_month()
    {
        return month;
    }
    int get_day()
    {
        return day;
    }
    friend int operator-(Time &time1,Time &time2);
};
int operator-(Time &time2,Time &time1)//����-������õ�����ʱ��Ĳ�ֵ������ֵΪ����ʱ��
{                                     //��������,�������n������Ҫ�շ�
    int sum=0;
    int a1[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
    int a2[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
    if(time1.year==time2.year){//�������ʱ�����������ͬ��ֻ�����º�������
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
    else if(time1.year+1==time2.year){//���ǰ��һ��ʱ��������Ըպõ��ں���һ��
        if(time1.is_leapyear()){      //ʱ��������Լ�һ,������ͽ��������,ֻ����
            if(time2.is_leapyear()){  //�º������Ե����
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
class book_location
{
private:
    string classification;
    int book_shelf;
    int storey;
public:
    book_location()
    {
        book_shelf=0;
        storey=0;
    }
    void set_book_location()
    {
        cout<<"������ͼ�����:";cin>>classification;
        for(;;){
            cout<<"�����������:";cin>>book_shelf;
            if(book_shelf<1){
                cout<<"������������������ڵ���1"<<endl;
                cout<<"����������"<<endl;
            }
            else
                break;
        }
        for(;;){
            cout<<"���������:";cin>>storey;
            if(book_shelf<1){
                cout<<"������󣬲���������ڵ���1"<<endl;
                cout<<"����������"<<endl;
            }
            else
                break;
        }
    }
    void show_book_location()
    {
        cout<<"���:"<<classification<<endl;
        cout<<"�����:"<<book_shelf<<endl;
        cout<<"����:"<<storey<<endl;
    }
    virtual istream &input(istream& in){
        in>>classification;
        in>>book_shelf;
        in>>storey;
        return in;
    }
    friend istream &operator>>(istream &in,book_location &p)
    {
        return p.input(in);
    }
    friend ostream &operator <<(ostream &out,const book_location &book){
       return book.print(out);
    }
    virtual ostream &print(ostream& out)const{
       out<<classification<<" ";
       out<<book_shelf<<" ";
       out<<storey<<"\n";
       return out;
    }
    void revise_classification()
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
	    classification=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_book_shelf()
    {
        int s1;
	    int s2;
	    for(;;){
           cout<<"�����뱾ͼ����������:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ�ϵڼ����:";
	       cin>>s2;
	       if(s1!=s2||s1<1)
               cerr<<"�����������ݲ���ͬ�������������������"<<endl;
           else
               break;
	    }
	    book_shelf=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_storey()
    {
        int s1;
	    int s2;
	    for(;;){
           cout<<"�����뱾ͼ����²���:";
	       cin>>s1;
	       cout<<"���ٴ�ȷ�ϲ���:";
	       cin>>s2;
	       if(s1!=s2||s2<1)
               cerr<<"�����������ݲ���ͬ�������������������"<<endl;
           else
               break;
	    }
	    storey=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    string get_classification()
    {
        return classification;
    }
    int get_book_shelf()
    {
        return book_shelf;
    }
    int get_storey()
    {
        return storey;
    }
};
class book_date:public book_location
{
private:
    string book_name;
    string book_author;
    string publishing_company;
    string ISBN;
    Time publishing_date;
    int order;//���
    int amount;//����
public:
    book_date():book_location(),publishing_date()
    {
        //string���󴴽�ʱ�ǿ�string���󣬹ʲ����ٸ���ֵ
        amount=0;
        order=0;
    }
    void low_amount()
    {
        amount--;
    }
    void high_amount()
    {
        amount++;
    }
    string get_book_name()
    {
        return book_name;
    }
    string get_book_author()
    {
        return book_author;
    }
    string get_ISBN()
    {
        return ISBN;
    }
    string get_pubishing_company()
    {
        return publishing_company;
    }
    Time get_publishing_date()
    {
        return publishing_date;
    }
    int get_order()
    {
        return order;
    }
    int get_amount()
    {
        return amount;
    }
    virtual ostream &print(ostream& out)const{
        out<<book_name<<" ";
        out<<book_author<<" ";
        out<<publishing_company<<" ";
        out<<ISBN<<" ";
        out<<publishing_date<<" ";
        out<<order<<" ";
        out<<amount<<" ";
        book_location::print(out);
        return out;
    }
    void set_book_date()
    {
        cout<<"������ͼ������:";cin>>book_name;
        cout<<"������ͼ������:";cin>>book_author;
        cout<<"������ͼ�������:";cin>>publishing_company;
        cout<<"������ͼ��ISBN��:";cin>>ISBN;
        for(;;){
            cout<<"������ͼ����:";cin>>order;
            if(order<=0)
                cout<<"�������,��β���С�ڵ���1"<<endl;
            else
                break;
        }
        for(;;){
            cout<<"������ͼ������:";cin>>amount;
            if(amount<=0)
                cout<<"�������,��������С�ڵ���1"<<endl;
            else
                break;
        }
        int year1,month1,day1;
        for(;;){
            cout<<"�������������(�������շֱ�����,�м��ÿո����):";
            cin>>year1>>month1>>day1;
            if(!check_time(year1,month1,day1))
                cout<<"�����������,����������"<<endl;
            else
                break;
        }
        publishing_date.set_time(year1,month1,day1);
        set_book_location();
    }
    void show_book_date()
    {
        cout<<"����:"<<book_name<<endl;
        cout<<"����:"<<book_author<<endl;
        cout<<"������:"<<publishing_company<<endl;
        cout<<"ISBN��:"<<ISBN<<endl;
        cout<<"���:"<<order<<endl;
        cout<<"����:"<<amount<<endl;
        show_book_location();
    }
    virtual istream &input(istream &in)
    {
        in>>book_name;
        in>>book_author;
        in>>publishing_company;
        in>>ISBN;
        in>>publishing_date;
        in>>order;
        in>>amount;
        book_location::input(in);
        return in;
    }
    void revise_name()
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
	    book_name=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_author()
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
	    book_author=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_publishing_company()
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
	    publishing_company=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_ISBN()
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
	    ISBN=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_order()
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
	    order=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_amount()
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
	    amount=s1;
	    cout<<"�޸ĳɹ�"<<endl;
    }
    void revise_publishing_date()
    {
        int year1,month1,day1;
        for(;;){
            cout<<"�����������µĳ���ʱ��,�ÿո�ֿ�:";
            cin>>year1>>month1>>day1;
            if(!check_time(year1,month1,day1))
                cout<<"�����������,����������"<<endl;
            else
                break;
        }
        publishing_date.set_time(year1,month1,day1);
    }
};
class borrow_return_book
{
private:
    Time borrow_time;
    Time return_time;
    string book_name[10];//һ��������ʮ����
    int number;//����ı���
    bool return_y_n;//�Ƿ�黹
public:
    borrow_return_book():borrow_time(),return_time()
    {
        number=0;
        return_y_n=true;
    }
    void revise_return_y_n()
    {
        return_y_n=false;
    }
    int get_number()
    {
        return number;
    }
    string get_book_name(int i)
    {
        return book_name[i];
    }
    Time get_brtime()
    {
        return borrow_time;
    }
    Time get_rtime()
    {
        return return_time;
    }
    void show_brbook_information()
    {
        int i;
        cout<<"����"<<number<<"����"<<endl;
        cout<<"�����ֱ�Ϊ:";
        for(i=0;i<number;i++)
            cout<<book_name[i]<<" ";
        cout<<"����ʱ��:";
        borrow_time.show_time();cout<<endl;
        if(!return_y_n)
            cout<<"ͼ��״̬:δ�黹"<<endl;
        else{
            return_time.show_time();
            cout<<"ͼ��״̬:�ѹ黹"<<endl;
        }
    }
    void set_bbook_information(int number1,string book1[10])//���ɽ�����Ϣ
    {
        SYSTEMTIME sys;
        GetLocalTime(&sys);//��ȡϵͳʱ��
        borrow_time.set_time(sys.wYear,sys.wMonth,sys.wDay);
        number=number1;
        return_y_n=false;
        int i;
        for(i=0;i<number1;i++)
            book_name[i]=book1[i];
    }
    void revise_brbook_infomation(int number1,string book1[10])
    {
        number=number1;
        return_y_n=false;
        int i;
        for(i=0;i<number1;i++)
            book_name[i]=book1[i];
    }
    void set_rbook_information(int number1,string book[10])
    {
        SYSTEMTIME sys;
        GetLocalTime(&sys);//��ȡϵͳʱ��
        return_time.set_time(sys.wYear,sys.wMonth,sys.wDay);
        return_y_n=true;
        number=number1;
        int i;
        for(i=0;i<number1;i++)
            book_name[i]=book[i];
    }
    friend istream &operator>>(istream &in,borrow_return_book &p)
    {
        return p.input(in);
    }
    friend ostream &operator<<(ostream &out,const borrow_return_book &p)
    {
        return p.print(out);
    }
    virtual ostream &print(ostream &out)const
    {
        int i;
        for(i=0;i<number;i++)
            out<<book_name[i]<<" ";
        out<<borrow_time<<" ";
        out<<return_time<<" ";
        out<<number<<" ";
        out<<return_y_n<<"\n";
        return out;
    }
    virtual istream &input(istream &in)
    {
        int i;
        for(i=0;i<number;i++)
            in>>book_name[i];
        in>>borrow_time;
        in>>return_time;
        in>>number;
        in>>return_y_n;
        return in;
    }
};
class people:public borrow_return_book//ϵͳ�û�����ѧ��,��ʦ�͹���Ա,ͳ��Ϊ��
{
private:
    string name;
	string id_number;//���֤��
	string phone_number;
    string id;//ѧ��
    string password;
public:
    people():borrow_return_book()
    {

    }
    virtual ostream &print(ostream &out)const
    {
        out<<name<<" ";
        out<<id_number<<" ";
        out<<phone_number<<" ";
        out<<id<<" ";
        out<<borrow_return_book::print(out);
        return out;
    }
    string get_name()
    {
        return name;
    }
    string get_id()
    {
        return id;
    }
    void set_people(string s1,string s2,string s3,string s4,string s5)
    {
        name=s1;
        id_number=s2;
        phone_number=s3;
        id=s4;
        password=s5;
    }
    void show_people()
    {
        cout<<"����:"<<name<<endl;
        cout<<"���֤��:"<<id_number<<endl;
        cout<<"�绰����:"<<phone_number<<endl;
        cout<<"ѧ�Ż���:"<<id<<endl;
    }
    void revise_people_name()
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
        name=s1;
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
        phone_number=s1;
        cout<<"�޸ĳɹ�"<<endl;
	}
	virtual istream &input(istream& in)
	{
	    in>>name;
	    in>>id_number;
	    in>>phone_number;
	    in>>id;
	    borrow_return_book::input(in);
	    return in;
	}
};
void menu();//�˵�
int user_choice(people &person);
void input_book_information();//�����鼮��Ϣ
people startcheck();
void seek_book_location();
void delete_book_infomation();
void borrow_book(people &person);//����
void return_book(people &person);//����
void count_book_information();//ͳ��ͼ����Ϣ
void check_borrow_return_information();//��ѯ������Ϣ
void revise_personal_information(people &person);//�޸�����
void revise_book_information();//�޸�ͼ����Ϣ
int main()
{
    system("color f0");//���������óɰ�ɫ,��������Ϊ��ɫ
    people person=startcheck();//��¼ϵͳ֮ǰ���,������¼��ע��,ͬʱ��ȡѧ��
    while(1){
        if(user_choice(person)==10)//�û�ѡ���ϵͳ�Ĺ���,ͬʱ�����û���ѡ��,���Ϊ
		break;                      //10(�����˳�ϵͳ),�����ѭ��,���������˳�
    }
    system("exit");
    return 0;
}
people startcheck()
{
    people one;
    system("title ��¼/ע����ҳ��");
    ifstream in,ine;ofstream out;
    string id1,phone_number1,password1,id_number1,name1;
    cout<<"                 1:��¼"<<endl;
    cout<<"                 2:ע��"<<endl;
    int n;
    cout<<"                 ���������ѡ��:";
    cin>>n;
    if(n==1){
        system("cls");
        system("title ��¼");
        for(;;){
            in.open("password.txt",ios_base::app);
            if(!in){
                cerr<<"�ļ���ʧ��(�ļ�������)�������������"<<endl;
                cin.get();cin.get();
                exit(0);
            }
            cout<<"                 ѧ��:";
            cin>>id1;
            int flag=0;
            string password2,id2,id3;
            while(!in.eof()&&in.peek()!=EOF){//��ȡ�ļ��б�����˺ź�����
                in>>id2>>password2;
                int i=0;
                if(id1==id2){//�����⵽�û����˺�
                    for(i=0;i<3;i++){//�û���������������Ļ���
                        cout<<"                 ����:";
                        char s[21];int j=0;
                        while((s[j]=getch())!=13&&j!=20){
                            putch('*');
                            j++;
                        }
                        s[j]='\0';
                        password1=s;
                        flag=1;
                        if(password1==password2){
                            ine.open("student.txt",ios_base::app);
                            while(!in.eof()&&ine.peek()!=EOF){
                                ine>>id3>>name1>>phone_number1>>id_number1;
                                if(id2==id3){
                                    ine.close();
                                    one.set_people(name1,id_number1,phone_number1,id1,password1);
                                    return one;
                                }
                            }
                        }
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
        system("title ע��");
        in.open("password.txt",ios_base::app);
        if(!in){
            cerr<<"�ļ���ʧ��(�ļ�������)�������������"<<endl;
            cin.get();cin.get();
            exit(0);
        }
        for(;;){
            cout<<"                 ѧ�Ż��߱��:";cin>>id1;
            string password2,id2,password3;
            int flag=0;//���ϵͳ�Ƿ��Ѵ��ڴ�ѧ��
            while(in.peek()!=EOF&&in.eof()){
                in>>id2>>password2;
                if(id2==id1){
                    flag=1;
                    cout<<"ϵͳ�Ѵ��ڴ�ѧ��,����ѧ���Ƿ�������ȷ�����Ƿ���ע��"<<endl;
                    break;
                }
            }
            if(flag==0){
                cout<<"                 ����:";cin>>name1;
                cout<<"                 ���֤��:";cin>>id_number1;
                cout<<"                 �绰����:";cin>>phone_number1;
                for(;;){
                    cout<<"                 ����(���20λ):";
                    char s1[21];int j=0;
                    while((s1[j]=getch())!=13&&j!=20){
                        putch('*');
                        j++;
                    }
                    s1[j]='\0';
                    password1=s1;
                    j=0;
                    cout<<"���ٴ�ȷ������:";
                    char s2[21];
                    while((s2[j]=getch())!=13&&j!=20){
                        putch('*');
                        j++;
                    }
                    s2[j]='\0';
                    password3=s2;
                    if(password1==password3)
                        break;
                    else{
                        cout<<"�����������벻��ͬ,����������"<<endl;
                    }
                }
                in.close();
                out.open("password.txt",ios_base::app);
                out<<id1<<" "<<password1<<"\n";
                out.close();
                out.open("student.txt",ios_base::app);
                out<<id1<<" "<<name1<<" "<<phone_number1<<" "<<id_number1<<"\n";
                out.close();
                break;
            }
        }
        cout<<"ע��ɹ�"<<endl;
        cin.get();
        cout<<"����������뱾ϵͳ"<<endl;
        cin.get();//����һ����ʱ���󣬲����˶��󡰸�ֵ����person
        one.set_people(name1,id_number1,phone_number1,id1,password1);
        return one;
    }
    else{
        cout<<"ѡ�����,ϵͳ�����˳�"<<endl;
        cin.get();
        exit(0);
    }
}
void menu()
{
    system("cls");//����
    system("title ���˵�-ͼ��������ϵͳ");//������������Ϊ---
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
    cout<<"\t\t\t\t��         8   �޸ĸ�����Ϣ         ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��         9   �޸�ͼ����Ϣ         ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��         10    �˳�ϵͳ           ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
}
int user_choice(people &person)
{   //�����
    menu();
    int n;
    cout<<"�밴��ѡ���Ӧ����:";
    cin>>n;
    switch(n){
    case 1:input_book_information();break;
    case 2:seek_book_location();break;
    case 3:delete_book_infomation();break;
    case 4:borrow_book(person);break;
    case 5:return_book(person);break;
    case 6:count_book_information();break;
    case 7:check_borrow_return_information();break;
    case 8:revise_personal_information(person);break;
    case 9:revise_book_information();break;
    case 10:break;
    default:cerr<<"�޴˶�Ӧ����"<<endl;break;
    }
    return n;
}
void input_book_information()
{
    system("cls");system("title ����鼮��Ϣ");
    ofstream out;int n;
    for(;;){
        book_date book;
        book.set_book_date();
        out.open("book.txt",ios_base::app);
        if(!out){
            cerr<<"�ļ���ʧ��"<<endl;
            cin.get();
            return;
        }
        out<<book;
        cout<<"�Ƿ�������?"<<endl;
        cout<<"1 :yes"<<endl;
        cout<<"0 :no"<<endl;
        cin>>n;
        if(n==0)
            break;
    }
    out.close();
    cout<<"��ӳɹ�,��������������˵�"<<endl;
    cin.get();
}
void seek_book_location()
{
    system("cls");system("title ����ͼ����Ϣ");
    string book_name1;
    ifstream in;
    in.open("book.txt",ios_base::app);
    if(!in||in.eof()){
        cout<<"�ļ���ʧ�ܻ��ļ����鼮��Ϣ"<<endl;
        cin.get();
        return ;
    }
    int flag=0,n;
    for(;;){
        cout<<"���������ѯλ�õ��鼮��:";cin>>book_name1;
        int n;book_date book;
        while(in.peek()!=EOF){
            in>>book;
            if(book.get_book_name()==book_name1){
                cout<<"���ҵ�"<<endl;flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
            cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
            cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
            cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
            cout<<setw(10)<<"����"<<"��"<<endl;
            cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
            cout<<"��"<<setw(10)<<book.get_book_name()<<"��"<<setw(10)<<book.get_book_author()<<"��";
            cout<<setw(10)<<book.get_pubishing_company()<<"��"<<setw(10)<<book.get_ISBN()<<"��";
            cout<<setw(4)<<book.get_publishing_date().get_year()<<"."<<setw(2)<<book.get_publishing_date().get_month();
            cout<<"."<<setw(2)<<book.get_publishing_date().get_day()<<"��";
            cout<<setw(10)<<book.get_order()<<"��"<<setw(10)<<book.get_amount()<<"��";
            cout<<setw(10)<<book.get_classification()<<"��"<<setw(10)<<book.get_book_shelf()<<"��";
            cout<<setw(10)<<book.get_storey()<<"��"<<endl;
            cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
        }
        else{
            cout<<"ϵͳδ�ҵ����鼮��Ϣ"<<endl;cin.get();
        }
        cout<<"�Ƿ��������?"<<endl;
        cout<<"1 :yes"<<endl;
        cout<<"0 :no"<<endl;
        cin>>n;
        if(n==0)
            break;
    }
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void delete_book_infomation()
{
    system("cls");cin.get();
    string book_name1;
    book_date book;
    int m;
    for(;;){
        cout<<"��������ɾ�����鼮����:";cin>>book_name1;
        ofstream out;ifstream in;
        in.open("book.txt");
        if(!in||in.eof()){//����ļ�Ϊ�ջ����ļ���ʧ��
            cerr<<"�ļ������ڻ�δ¼���κ��鼮��Ϣ"<<endl;
            cin.get();
            return ;
        }
        int flag=0;int n=0;
        while(in.peek()!=EOF){
            in>>book;
            if(book.get_book_name()==book_name1){
                flag=1;
                in.close();break;
            }
        }
        if(flag==1){
            cout<<"ȷ��ɾ�������鼮��������Ϣ?(1:yes   2:no)"<<endl;
            cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
            cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
            cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
            cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
            cout<<setw(10)<<"����"<<"��"<<endl;
            cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
            cout<<"��"<<setw(10)<<book.get_book_name()<<"��"<<setw(10)<<book.get_book_author()<<"��";
            cout<<setw(10)<<book.get_pubishing_company()<<"��"<<setw(10)<<book.get_ISBN()<<"��";
            cout<<setw(4)<<book.get_publishing_date().get_year()<<"."<<setw(2)<<book.get_publishing_date().get_month();
            cout<<"."<<setw(2)<<book.get_publishing_date().get_day()<<"��";
            cout<<setw(10)<<book.get_order()<<"��"<<setw(10)<<book.get_amount()<<"��";
            cout<<setw(10)<<book.get_classification()<<"��"<<setw(10)<<book.get_book_shelf()<<"��";
            cout<<setw(10)<<book.get_storey()<<"��"<<endl;
            cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������\n"<<endl;
            cin>>n;
        }
        else{
            cout<<"ϵͳδ�ҵ����鼮�����Ϣ,�޷�ִ��ɾ������"<<endl;
            in.close();cin.get();
        }
        if(n==1){
            in.open("book.txt");
            out.open("book1.txt",ios_base::app);//�����������ɾ����������ͬ��������
            while(in.peek()!=EOF){//�������ļ��У�����ͬ�����뵽�����ļ���
                in>>book;
                if(book.get_book_name()!=book_name1)
                    out<<book;
            }
            in.close();out.close();
            out.open("book.txt",ios::trunc);//��book1.txt�е����ݡ����ơ���book.txt
            out.close();
            out.open("book.txt",ios_base::app);
            in.open("book1.txt");
            char c;
            while(in.peek()!=EOF){
                in.get(c);
                out<<c;
            }
            out.close();
            in.close();
            out.open("book1.txt",ios::trunc);
            out.close();//���book1.txt�ļ�������
            cout<<"ɾ���ɹ�"<<endl;
            cin.get();
        }
        cout<<"�Ƿ����ɾ��?(1:yes   0:no)"<<endl;
        cin>>m;
        if(m==0)
            break;
    }
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void borrow_book(people &person)
{
    system("cls");cin.get();
    system("title �����鼮");
    ifstream in;ofstream out;
    people person1;
    int brbook_number;//�����鼮����
    in.open("brbook.txt");int flag1=0;//����û�δ�黹�ı���
    while(in.peek()!=EOF){
        in>>person1;
        if(person1.get_name()==person.get_name()){
            flag1=1;break;
        }
    }
    in.close();
    if(flag1==1){
        cout<<"�����㻹��"<<person1.get_number()<<"����δ�黹"<<endl;
        cout<<"��������ֻ��������"<<10-person1.get_number()<<"����"<<endl;
        for(;;){
            cout<<"��������ı���:";cin>>brbook_number;
            if(brbook_number>10-person1.get_number()||brbook_number<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
    }
    else{
        for(;;){
            cout<<"��������ı���(������ʮ��):";cin>>brbook_number;
            if(brbook_number>10||brbook_number<=0)
                cout<<"�������,����������"<<endl;
            else
                break;
        }
    }
    string book[10];
    int i;
    for(i=0;i<brbook_number;i++){
        cout<<"�������"<<i+1<<"��������:";
        cin>>book[i];
    }
    int n=0,flag;
    book_date book1,book2[10];//����Ƿ���ڴ��鼮��Ϣ
    for(i=0;i<brbook_number;i++){
        flag=0;
        in.open("book.txt");
        while(in.peek()!=EOF){
            in>>book1;
            if(book1.get_book_name()==book[i]){
                in.close();book2[n]=book1;flag=1;++n;break;
            }
        }
        if(flag==0){
            in.close();
            cout<<"ϵͳδ�ҵ����鼮,���鼮δ��¼"<<endl;
            cin.get();
        }
    }
    brbook_number=n;
    for(i=0;i<n;i++)
        book[i]=book2[i].get_book_name();
    cout<<"ȷ�Ͻ��������鼮?(1:yes   2:no)"<<endl;
    int m;
    cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
    cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
    cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
    cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
    cout<<setw(10)<<"����"<<"��"<<endl;
    for(i=0;i<brbook_number;i++){
        cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
        cout<<"��"<<setw(10)<<book2[i].get_book_name()<<"��"<<setw(10)<<book2[i].get_book_author()<<"��";
        cout<<setw(10)<<book2[i].get_pubishing_company()<<"��"<<setw(10)<<book2[i].get_ISBN()<<"��";
        cout<<setw(4)<<book2[i].get_publishing_date().get_year()<<"."<<setw(2)<<book2[i].get_publishing_date().get_month();
        cout<<"."<<setw(2)<<book2[i].get_publishing_date().get_day()<<"��";
        cout<<setw(10)<<book2[i].get_order()<<"��"<<setw(10)<<book2[i].get_amount()<<"��";
        cout<<setw(10)<<book2[i].get_classification()<<"��"<<setw(10)<<book2[i].get_book_shelf()<<"��";
        cout<<setw(10)<<book2[i].get_storey()<<"��"<<endl;
    }
    cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������\n"<<endl;
    cin>>m;
    if(m==1){
        people person2;int flag2=0;
        in.open("brbook.txt");
        while(in.peek()!=EOF){
            in>>person2;flag2=0;
            if(person2.get_name()==person.get_name()){
                int j;
                for(j=0;j<person2.get_number();j++){
                    book[n]=person2.get_book_name(j);n++;
                }
                flag2=1;
            }
            if(flag2==1)
                break;
        }
        in.close();
        person.set_bbook_information(n,book);//����û�������δ�黹���鼮��Ϣ
        if(flag2==1){
            out.open("brbook.txt",ios_base::app);
            out<<person;
            out.close();
        }//����û�����δ�黹���鼮��Ϣ
        else{
            in.open("brbook.txt");
            out.open("brbook1.txt",ios_base::app);
            while(in.peek()!=EOF){
                in>>person2;
                if(person2.get_name()==person.get_name())
                    out<<person;
                else
                    out<<person2;
            }
            in.close();out.close();
            char c;
            out.open("brbook.txt",ios::trunc);
            out.close();
            out.open("brbook.txt",ios_base::app);
            in.open("brbook1.txt");
            while(in.peek()!=EOF){
                in.get(c);
                out<<c;
            }
            out.close();
            in.close();
            out.open("brbook1.txt",ios::trunc);
            out.close();//��brbook1�ļ����������
        }
        cout<<"���ĳɹ�"<<endl;
        for(i=0;i<brbook_number;i++){//�����ĵ��鼮������1
            in.open("book.txt");
            out.open("book1.txt",ios_base::app);
            while(in.peek()!=EOF){
                in>>book1;
                if(book1.get_book_name()==book[i])
                    out<<book1;
                else{
                    book1.low_amount();
                    out<<book1;
                }
            }
        }
        in.close();out.close();
        char c;
        out.open("book.txt",ios::trunc);
        out.close();
        out.open("book.txt",ios_base::app);
        in.open("book1.txt");
        while(in.peek()!=EOF){
            in.get(c);
            out<<c;
        }
        out.close();
        in.close();
        out.open("book1.txt",ios::trunc);
        out.close();//��book1�ļ����������
    }
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void return_book(people &person)
{
    system("cls");cin.get();
    system("title �黹�鼮");
    int rbook_number;ifstream in;
    ofstream out;
    book_date book1;
    cout<<"������黹���鼮����(�����������鼮������):";
    cin>>rbook_number;
    string book[10];
    int i;
    for(i=0;i<rbook_number;i++){
        cout<<"��������黹�ĵ�"<<i+1<<"��������:";
        cin>>book[i];
    }
    int n=0;
    people person1;//����Ƿ���δ�黹���鼮
    for(i=0;i<rbook_number;i++){
        in.open("brbook.txt");int flag=0;
        while(in.peek()!=EOF){
            cin>>person1;
            if(person1.get_name()==person.get_name()){
                int j;
                for(j=0;j<person1.get_number();j++){
                    if(person1.get_book_name(j)==book[i]){
                        flag=1;n++;break;
                    }
                }
                if(flag==1){
                    in.close();break;
                }
                else{
                    cout<<"��δ����"<<book[i]<<"���鼮"<<endl;
                    cin.get();in.close();break;
                }
            }
        }
    }
    rbook_number=n;
    out.open("rbook.txt");
    person.set_rbook_information(rbook_number,book);
    out<<person;
    out.close();//���黹ʱ���Ƿ񳬹�Ԥ��ʱ��
    Time time1=person.get_brtime();
    Time time2=person.get_rtime();
    int time;
    time=time2-time1;
    if(time>30){
        cout<<"�黹ʱ�䳬���涨ʱ��"<<endl;
        cout<<"����Ҫ����"<<0.1*(time-30)<<"Ԫ"<<endl;
        cin.get();
    }
    cout<<"�黹�ɹ�"<<endl;
    for(i=0;i<rbook_number;i++){//���黹���鼮������1
        in.open("book.txt");
        out.open("book1.txt",ios_base::app);
        while(in.peek()!=EOF){
            in>>book1;
            if(book1.get_book_name()==book[i])
                out<<book1;
            else{
                book1.low_amount();
                out<<book1;
            }
        }
    }
    in.close();out.close();
    char c;
    out.open("book.txt",ios::trunc);
    out.close();
    out.open("book.txt",ios_base::app);
    in.open("book1.txt");
    while(in.peek()!=EOF){
        in.get(c);
        out<<c;
    }
    out.close();
    in.close();
    out.open("book1.txt",ios::trunc);
    out.close();//��book1�ļ����������
    in.open("brbook.txt");//����brbook.txt�Ľ�����Ϣ
    out.open("brbook1.txt",ios_base::app);
    int j,k=0;string book3[10];
    while(in.peek()!=EOF){
        in>>person1;
        if(person1.get_name()==person.get_name()){
            for(i=0;i<person1.get_number();i++){
                int flag=0;
                for(j=0;j<person.get_number();j++){
                    if(person1.get_book_name(i)==person.get_book_name(j)){
                        flag=1;break;
                    }
                }
                if(flag==0){
                    book3[k]=person1.get_book_name(i);k++;
                }
            }//���δȫ���黹
            if(k>0){
                person1.revise_brbook_infomation(k,book3);
                out<<person1;
            }
        }
        else{
            out<<person1;
        }
    }
    in.close();out.close();
    out.open("brbook.txt",ios::trunc);
    out.close();
    out.open("brbook.txt",ios_base::app);
    in.open("brbook1.txt");
    while(in.peek()!=EOF){
        in.get(c);
        out<<c;
    }
    out.close();
    in.close();
    out.open("brbook1.txt",ios::trunc);
    out.close();//��brbook1.txt�ļ����������
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void count_book_information()
{
    system("cls");cin.get();
    system("title ͳ���鼮��Ϣ");
    ifstream in;int n,m;
    for(;;){
        system("cls");
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��         ͼ��������ϵͳ         ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��         1   ͳ���ܲ���           ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��         2   ͳ�����             ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"���������ѡ��:";cin>>n;
        if(n==1){
            int sum=0;int k;
            book_date book;
            in.open("book.txt");
            while(in.peek()!=EOF){
               in>>book;
               sum++;
            }
            in.close();sum--;
            cout<<"��ͼ��ݹ�����"<<sum<<"��"<<endl;
            cout<<"�Ƿ������������鼮��Ϣ?(1:yes    0:no):";
            cin>>k;
            if(k==1){
                cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
                cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
                cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
                cout<<setw(10)<<"����"<<"��"<<endl;
                in.open("book.txt");//�˴�Ԥ�����һ�����з������ļ�����
                while(in.peek()!=EOF&&sum){
                    in>>book;
                    cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                    cout<<"��"<<setw(10)<<book.get_book_name()<<"��"<<setw(10)<<book.get_book_author()<<"��";
                    cout<<setw(10)<<book.get_pubishing_company()<<"��"<<setw(10)<<book.get_ISBN()<<"��";
                    cout<<setw(4)<<book.get_publishing_date().get_year()<<"."<<setw(2)<<book.get_publishing_date().get_month();
                    cout<<"."<<setw(2)<<book.get_publishing_date().get_day()<<"��";
                    cout<<setw(10)<<book.get_order()<<"��"<<setw(10)<<book.get_amount()<<"��";
                    cout<<setw(10)<<book.get_classification()<<"��"<<setw(10)<<book.get_book_shelf()<<"��";
                    cout<<setw(10)<<book.get_storey()<<"��"<<endl;
                    sum--;
                }
                in.close();
               cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
            }
        }
        else if(n==2){
            map<string,int>mymap;
            in.open("book.txt");//��map¼���鼮���
            book_date book;int j=1;//map���Խ���ͬ��keyֵ(��ʹvalue��ֵ��ͬ)���Ե�
            while(in.peek()!=EOF){//���ؼ��ֲ����ظ�����
                in>>book;//�����ͱ�֤��ͳ��ʱ�������������ͬ�����
                mymap.insert(pair<string,int>(book.get_classification(),1));
            }//��ʱ�临�Ӷ�ΪO(1);
            in.close();//ͬʱmapҲ���ò���
            auto it=mymap.begin();//Ψһ��ȱ�����õ���C++11�ĵ�����
            int sum=0;//������֧��C++11�ı���������
            for(it;it!=mymap.end();it++){
                sum++;
                it->second=j;j++;
            }
            cout<<"���ռ�"<<sum<<"���鼮"<<endl;
            int k,w;
            it=mymap.begin();
            cout<<"�Ƿ��ѯ��������鼮?(1:yes  0:no):";cin>>k;
            if(k==1){
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��         �鼮����ѯѡ��         ��\n";
                for(it;it!=mymap.end();it++){
                    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                    cout<<"\t\t\t\t��        "<<setw(2)<<it->second<<":"<<setw(10)<<it->first<<"             "<<"��\n";
                }
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"���������ѡ��:";cin>>w;
                int flag=0;it=mymap.begin();
                for(it;it!=mymap.end();it++){
                    if(it->second==w){
                        flag=1;break;
                    }
                }
                if(flag==1){
                    in.open("book.txt");
                    cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
                    cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
                    cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
                    cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
                    cout<<setw(10)<<"����"<<"��"<<endl;
                    while(in.peek()!=EOF){
                        in>>book;
                        if(book.get_classification()==it->first){
                            cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                            cout<<"��"<<setw(10)<<book.get_book_name()<<"��"<<setw(10)<<book.get_book_author()<<"��";
                            cout<<setw(10)<<book.get_pubishing_company()<<"��"<<setw(10)<<book.get_ISBN()<<"��";
                            cout<<setw(4)<<book.get_publishing_date().get_year()<<"."<<setw(2)<<book.get_publishing_date().get_month();
                            cout<<"."<<setw(2)<<book.get_publishing_date().get_day()<<"��";
                            cout<<setw(10)<<book.get_order()<<"��"<<setw(10)<<book.get_amount()<<"��";
                            cout<<setw(10)<<book.get_classification()<<"��"<<setw(10)<<book.get_book_shelf()<<"��";
                            cout<<setw(10)<<book.get_storey()<<"��"<<endl;
                        }
                    }
                    in.close();
                    cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
                }
                else
                    cout<<"ѡ�����"<<endl;
            }
        }
        else{
            cout<<"ѡ�����"<<endl;
        }
        cout<<"�Ƿ����ͳ��?(1:yes    0:no):";
        cin>>m;
        if(m==0)
            break;
    }
    cin.get();
}
void check_borrow_return_information()
{
    system("cls");cin.get();
    system("title ��ѯ������Ϣ");
    people person;int i;
    ifstream in;int n,m;//m��ʾѡѡ��,n��ʾ�Ƿ����
    for(;;){
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��              ����ѡ��            ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��        1   �������˲�ѯ          ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��        2   �������鼮��ѯ        ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��        3   ������ʱ���ѯ        ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cout<<"\t\t\t\t��        4   ���Ƿ�黹��ѯ        ��\n";
        cout<<"\t\t\t\t������������������������������������������������������������������������\n";
        cin>>m;
        if(m==1){
            system("cls");
            string brbook_name;
            cout<<"����������˵�����:"<<endl;cin>>brbook_name;
            in.open("brbook.txt");
            int flag=0;
            while(in.peek()!=EOF){
                in>>person;
                if(person.get_name()==brbook_name){
                    flag=1;break;
                }
            }
            in.close();
            int flag1=0;
            if(flag==0){
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;
                    if(person.get_name()==brbook_name){
                        flag1=1;break;
                    }
                }
            }
            in.close();
            if(flag==0&&flag1==0){
                cout<<"�޴��˵��κν�����Ϣ"<<endl;
            }
            else{
                in.open("brbook.txt");
                cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"��������"<<"��"<<setw(10)<<"����ʱ��"<<"��";
                cout<<setw(10)<<"�黹ʱ��"<<"��"<<setw(10)<<"�Ƿ�黹"<<"��"<<endl;
                while(in.peek()!=EOF){
                    in>>person;
                    if(person.get_name()==brbook_name){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(10)<<person.get_book_name(0);
                        cout<<"��"<<setw(4)<<person.get_brtime().get_year()<<"."<<setw(2)<<person.get_brtime().get_month();
                        cout<<"."<<setw(2)<<person.get_brtime().get_day()<<"��"<<setw(10)<<" "<<"��";
                        cout<<setw(10)<<"δ�黹"<<"��"<<endl;
                        for(i=1;i<person.get_number();i++){
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<person.get_book_name(i);
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<endl;
                        }
                    }
                }
                in.close();
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;
                    if(person.get_name()==brbook_name){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(10)<<person.get_book_name(0);
                        cout<<"��"<<setw(4)<<person.get_brtime().get_year()<<"."<<setw(2)<<person.get_brtime().get_month();
              cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"��������"<<"��"<<setw(10)<<"����ʱ��"<<"��";
                cout<<setw(10)<<"�黹ʱ��"<<"��"<<setw(10)<<"�Ƿ�黹"<<"��"<<endl;          cout<<"."<<setw(2)<<person.get_brtime().get_day()<<"��";
                        cout<<setw(4)<<person.get_rtime().get_year()<<"."<<setw(2)<<person.get_rtime().get_month();
                        cout<<"."<<setw(2)<<person.get_rtime().get_day()<"��";
                        cout<<setw(10)<<"�ѹ黹"<<"��"<<endl;
                        for(i=1;i<person.get_number();i++){
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<person.get_book_name(i);
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<endl;
                        }
                    }
                }
                in.close();
                cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
            }
        }//�������鼮��ѯ
        else if(m==2){
            system("cls");
            string book_name1;
            people person;int i;
            cout<<"��������Ҫ��ѯ���鼮����:";cin>>book_name1;
            in.open("brbook.txt");
            int flag=0;
            while(in.peek()!=EOF){
                in>>person;
                if(person.get_name()==book_name1){
                    flag=1;break;
                }
            }
            in.close();
            int flag1=0;
            if(flag==0){
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;
                    if(person.get_name()==book_name1){
                        flag1=1;break;
                    }
                }
            }
            in.close();int flag2;
            if(flag==0&&flag1==0){
                cout<<"�޴��鼮���κν�����Ϣ"<<endl;
            }
            else{
                cout<<"�����������������������ש��������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"������"<<"��"<<setw(10)<<"����ʱ��"<<"��";
                cout<<setw(10)<<"�黹ʱ��"<<"��"<<setw(10)<<"�Ƿ�黹"<<"��"<<endl;
                in.open("brbook.txt");
                while(in.peek()!=EOF){
                    in>>person;flag2=0;
                    for(i=0;i<person.get_number();i++){
                        if(person.get_book_name(i)==book_name1){
                            flag2=1;break;
                        }
                    }
                    if(flag2==1){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(4)<<person.get_brtime().get_year();
                        cout<<"."<<setw(2)<<person.get_brtime().get_month()<<".";
                        cout<<setw(2)<<person.get_brtime().get_day()<<"��"<<setw(10)<<" "<<"��";
                        cout<<setw(10)<<"δ�黹"<<endl;
                    }
                }
                in.close();
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;flag2=0;
                    for(i=0;i<person.get_number();i++){
                        if(person.get_book_name(i)==book_name1){
                            flag2=1;break;
                        }
                    }
                    if(flag2==1){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(4)<<person.get_brtime().get_year();
                        cout<<"."<<setw(2)<<person.get_brtime().get_month()<<".";
                        cout<<setw(2)<<person.get_brtime().get_day()<<"��";
                        cout<<setw(4)<<person.get_rtime().get_year()<<"."<<setw(2)<<person.get_rtime().get_month();
                        cout<<"."<<setw(2)<<person.get_rtime().get_day()<<"��"<<setw(10)<<"�ѹ黹"<<"��"<<endl;
                    }
                }
                in.close();
                cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
            }
        }
        else if(m==3){
            system("cls");
            int year1,month1,day1,year2,month2,day2;
            for(;;){
                cout<<"�������ѯ����ʼʱ��(����������������,�м��ÿո�ֿ�):";
                cin>>year1>>month1>>day1;
                if(!check_time(year1,month1,day1))
                    cout<<"�����������,����������"<<endl;
                else
                    break;
            }
            for(;;){
                cout<<"�������ѯ�Ľ�ֹʱ��(����������������,�м��ÿո�ֿ�):";
                cin>>year2>>month2>>day2;
                if(!check_time(year2,month2,day2))
                    cout<<"�����������,����������"<<endl;
                else
                    break;
            }
            Time time1,time2;
            time1.set_time(year1,month1,day1);
            time2.set_time(year2,month2,day2);
            int time_date=time2-time1;
            in.open("brbook.txt");
            int flag=0;
            while(in.peek()!=EOF){
                in>>person;
                Time time3=person.get_brtime();
                int time_date2=time3-time1;
                if(time_date2<=time_date){
                    flag=1;break;
                }
            }
            in.close();
            int flag1=0;
            if(flag==0){
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;
                    Time time3=person.get_brtime();
                    int time_date2=time3-time1;
                    if(time_date2<=time_date){
                        flag1=1;break;
                    }
                }
            }
            in.close();
            if(flag==0&&flag1==0){
                cout<<"��ʱ����κν�����Ϣ"<<endl;
            }
            else{
                in.open("brbook.txt");
                cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"��������"<<"��"<<setw(10)<<"����ʱ��"<<"��";
                cout<<setw(10)<<"�黹ʱ��"<<"��"<<setw(10)<<"�Ƿ�黹"<<"��"<<endl;
                while(in.peek()!=EOF){
                    in>>person;
                    Time time3=person.get_brtime();
                    int time_date1=time3-time1;
                    if(time_date1<=time_date){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(10)<<person.get_book_name(0);
                        cout<<"��"<<setw(4)<<person.get_brtime().get_year()<<"."<<setw(2)<<person.get_brtime().get_month();
                        cout<<"."<<setw(2)<<person.get_brtime().get_day()<<"��"<<setw(10)<<" "<<"��";
                        cout<<setw(10)<<"δ�黹"<<"��"<<endl;
                        for(i=1;i<person.get_number();i++){
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<person.get_book_name(i);
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<endl;
                        }
                    }
                }
                in.close();
                in.open("rbook.txt");
                while(in.peek()!=EOF){
                    in>>person;
                    Time time3=person.get_brtime();
                    int time_date1=time3-time1;
                    if(time_date1<=time_date){
                        cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
                        cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(10)<<person.get_book_name(0);
                        cout<<"��"<<setw(4)<<person.get_brtime().get_year()<<"."<<setw(2)<<person.get_brtime().get_month();
                        cout<<"."<<setw(2)<<person.get_brtime().get_day()<<"��";
                        cout<<setw(4)<<person.get_rtime().get_year()<<"."<<setw(2)<<person.get_rtime().get_month();
                        cout<<"."<<setw(2)<<person.get_rtime().get_day()<"��";
                        cout<<setw(10)<<"�ѹ黹"<<"��"<<endl;
                        for(i=1;i<person.get_number();i++){
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<person.get_book_name(i);
                            cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<" "<<"��"<<endl;
                        }
                    }
                }
                in.close();
                cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������"<<endl;
            }
        }
        else if(m==4){
            system("cls");
            in.open("rbook.txt");
            if(!in||in.eof()){
                cout<<"���κν�����Ϣ"<<endl;
                cin.get();
            }
            else{
                cout<<"�����������������������ש��������������������ש���������������������"<<endl;
                cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"��������"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<endl;
                while(in.peek()!=EOF){
                    in>>person;
                    cout<<"�ǩ��������������������贈�������������������贈��������������������"<<endl;
                    cout<<"��"<<setw(10)<<person.get_name()<<"��"<<setw(10)<<person.get_book_name(0);
                    cout<<"��"<<setw(4)<<person.get_brtime().get_year()<<"."<<setw(2)<<person.get_brtime().get_month();
                    cout<<"."<<setw(2)<<person.get_brtime().get_day()<<"��"<<endl;
                    for(i=1;i<person.get_number();i++){
                        cout<<"��"<<setw(10)<<" "<<"��"<<setw(10)<<person.get_book_name(i);
                        cout<<setw(10)<<" "<<"��"<<endl;
                    }
                }
                in.close();
                cout<<"�����������������������ߩ��������������������ߩ���������������������"<<endl;
            }
        }
        else{
            cout<<"ѡ�����"<<endl;cin.get();
        }
        cout<<"�Ƿ������ѯ?(1:yes   0:no)"<<endl;
        cin>>n;
        if(n==0)
            break;
    }
    cin.get();
}
void revise_personal_information(people &person)
{
    system("cls");cin.get();
    system("title �޸ĸ�����Ϣ");
    cout<<"��ĸ�����Ϣ����(����������)"<<endl;
    person.show_people();
    int n;
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��              �޸�ѡ��            ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��        1   �޸�����              ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��        2   �޸ĵ绰����          ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��        3   �޸�����              ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"\t\t\t\t��        4   �������˵�            ��\n";
    cout<<"\t\t\t\t������������������������������������������������������������������������\n";
    cout<<"���������ѡ��:";cin>>n;
    if(n==1){
        person.revise_people_name();
    }
    else if(n==2){
        person.revise_phone_number();
    }
    else if(n==3){
        string password1,id,password2,password3,password4;
        ifstream in;ofstream out;
        in.open("password.txt");
        while(in.peek()!=EOF){
            in>>id>>password2;
            if(id==person.get_id()){
                in.close();break;
            }
        }
        int i;
        for(i=0;i<3;i++){
            cout<<"������ԭ����:";
            char s[21];int j=0;
            while((s[j]=getch())!=13&&j!=20){
                putch('*');
                j++;
            }
            s[j]='\0';
            password1=s;
            int n;
            if(password1==password2){
                for(;;){
                    cout<<"������������:";
                    char s1[21];int j=0;
                    while((s1[j]=getch())!=13&&j!=20){
                        putch('*');
                        j++;
                    }
                    s1[j]='\0';
                    password3=s1;
                    cout<<"���ٴ�ȷ��������:";
                    char s2[21];
                    j=0;
                    while((s2[j]=getch())!=13&&j!=20){
                        putch('*');
                        j++;
                    }
                    s2[j]='\0';
                    password4=s2;
                    if(password3==password4)
                        break;
                    else{
                        cout<<"�������벻ͬ,����������"<<endl;
                    }
                }
            cout<<"ȷ�Ͻ������޸�Ϊ:"<<password3<<"?(1:yes   2:no)"<<endl;
            cin>>n;
            if(n==1){
                in.open("password.txt");
                out.open("password1.txt",ios_base::app);
                while(in.peek()!=EOF){
                    in>>id>>password1;
                    if(id==person.get_id())
                        out<<id<<" "<<password3<<"\n";
                    else
                        out<<id<<" "<<password1<<"\n";
                }
                in.close();
                out.close();//��password1.txt�ļ��е����ݸ������ơ���password.txt
                out.open("password.txt",ios::trunc);
                out.close();
                out.open("password.txt",ios_base::app);
                in.open("password1.txt");
                char c;
                while(in.peek()!=EOF){
                    in.get(c);
                    out<<c;
                }
                out.close();
                in.close();
                out.open("password1.txt",ios::trunc);
                out.close();//��password1�ļ����������
            }
        }
        else{
            if(i<2)
                cout<<"ԭ�����������,����������"<<endl;
        }
    }
    if(i==3){
        cout<<"�����������������������,���ܼ����޸�����"<<endl;
    }
    else
        cout<<"�����޸ĳɹ�"<<endl;
    }
    else if(n==4){
        return;
    }
    else
        cout<<"ѡ�����"<<endl;
    if(n==1&&n==2){
        ifstream in;ofstream out;
        string id1,name1,phone_number1,id_number1;
        in.open("student.txt");
        out.open("student1.txt",ios_base::app);
        while(in.peek()!=EOF){
            in>>id1>>name1>>phone_number1>>id_number1;
            if(person.get_id()==id1)
                out<<person;
            else
                out<<id1<<" "<<name1<<" "<<phone_number1<<" "<<id_number1<<"\n";
        }
        in.close();
        out.close();
        out.open("student.txt",ios::trunc);
        out.close();
        out.open("student.txt",ios_base::app);
        in.open("student1.txt");
        char c;
        while(in.peek()!=EOF){
            in.get(c);
            out<<c;
        }
        out.close();
        in.close();
        out.open("student1.txt",ios::trunc);
        out.close();//��student1�ļ����������
    }
    cin.get();
    cout<<"��������������˵�"<<endl;
    cin.get();
}
void revise_book_information()
{
    system("cls");cin.get();
    system("title �޸��鼮��Ϣ");
    ifstream in,ine;ofstream out;
    int n;
    string book_name1;
    book_date book;
    for(;;){
        system("cls");
        cout<<"�����������޸���Ϣ���鼮��:";cin>>book_name1;
        ine.open("book.txt");int flag=0;
        while(ine.peek()!=EOF){
            ine>>book;
            if(book.get_book_name()==book_name1){
                flag=1;ine.close();break;
            }
        }
        int m,choice;
        if(flag==1){
            cout<<"ȷ���޸������鼮�������Ϣ?(1:yes  0:no)"<<endl;
            cout<<"�����������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש��������������������ש���������������������"<<endl;
            cout<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"����"<<"��"<<setw(10)<<"������"<<"��";
            cout<<setw(10)<<"ISBN"<<"��"<<setw(10)<<"����ʱ��"<<"��"<<setw(10)<<"���"<<"��";
            cout<<setw(10)<<"����"<<"��"<<setw(10)<<"���"<<"��"<<setw(10)<<"�����"<<"��";
            cout<<setw(10)<<"����"<<"��"<<endl;
            cout<<"�ǩ��������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈�������������������贈��������������������"<<endl;
            cout<<"��"<<setw(10)<<book.get_book_name()<<"��"<<setw(10)<<book.get_book_author()<<"��";
            cout<<setw(10)<<book.get_pubishing_company()<<"��"<<setw(10)<<book.get_ISBN()<<"��";
            cout<<setw(4)<<book.get_publishing_date().get_year()<<"."<<setw(2)<<book.get_publishing_date().get_month();
            cout<<"."<<setw(2)<<book.get_publishing_date().get_day()<<"��";
            cout<<setw(10)<<book.get_order()<<"��"<<setw(10)<<book.get_amount()<<"��";
            cout<<setw(10)<<book.get_classification()<<"��"<<setw(10)<<book.get_book_shelf()<<"��";
            cout<<setw(10)<<book.get_storey()<<"��"<<endl;
            cout<<"�����������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ��������������������ߩ���������������������\n"<<endl;
            cin>>m;
            if(m==1){
                system("cls");
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��      ��ѡ������Ҫ�޸ĵ�����      ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              1   ����            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              2   ����            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              3   ISBN��          ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              4   ������          ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              5   ����ʱ��        ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              6   ���            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              7   ����            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              8   ���            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              9   �����          ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cout<<"\t\t\t\t��              10  ����            ��\n";
                cout<<"\t\t\t\t������������������������������������������������������������������������\n";
                cin>>choice;
                switch(n){
                    case 1:book.revise_name();
                    case 2:book.revise_author();
                    case 3:book.revise_ISBN();
                    case 4:book.revise_publishing_company();
                    case 5:book.revise_publishing_date();
                    case 6:book.revise_order();
                    case 7:book.revise_amount();
                    case 8:book.revise_classification();
                    case 9:book.revise_book_shelf();
                    case 10:book.revise_storey();
                    default:cout<<"ѡ�����"<<endl;break;
                }
                in.open("book.txt");
                book_date book1;
                out.open("book1.txt",ios_base::app);
                while(in.peek()!=EOF){
                    cin>>book1;
                    if(book1.get_book_name()!=book.get_book_name())
                        out<<book1;
                    else
                        out<<book;
                }
                in.close();
                out.close();
                out.open("book.txt",ios::trunc);
                out.close();
                out.open("book.txt",ios_base::app);
                in.open("book1.txt");
                char c;
                while(in.peek()!=EOF){
                    in.get(c);
                    out<<c;
                }
                out.close();
                in.close();
                out.open("book1.txt",ios::trunc);
                out.close();//��book1�ļ����������
                cout<<"�޸ĳɹ�"<<endl;
                cin.get();
            }
        }
        else{
            ine.close();
            cout<<"δ�ҵ����鼮��Ϣ"<<endl;
            cout<<"��ȷ���鼮��Ϣ�Ƿ�������ȷ"<<endl;cin.get();
        }
        cout<<"�Ƿ�����޸�?(1:yes   2:no)"<<endl;
        cin>>n;
        if(n==0)
            break;
    }
    cout<<"��������������˵�"<<endl;
    cin.get();
}
