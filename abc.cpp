#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
class A
{
protected:
string dob,bg;
char name[20];
};
class B
{
protected:

    int ht,wt;
};
class C
{
    protected:
        string ipno,ca;
};
class D:public A,protected B,public C
{
    string tn,dln;
public:
    static int count;
    void getdata();
    void mtable();
    void specific(char*);
    void del(char*);
    void edit (char*);
    int search(char*);
}o[10],O;
int D::count;
void D::specific(char a[])
{
    int i,y=0;
    for(i=0;i<O.count;i++)
    {
         if(strcmp(o[i].name,a)==0)
            {
                o[i].mtable();
                y=1;
            }
    }
    if(y==0)
    {
        cout<<"The name is not found in data . \n";
    }
}
void D::del(char a[])
{
    int i,y=0,j,k;
    for(i=0;i<O.count;i++)
    {
         if(strcmp(o[i].name,a)==0)
            {
                for(k=i,j=k+1;k<O.count;k++)
                    o[k]=o[j];
                    y=1;
                    O.count--;
                    cout<<"Entry DELETED successfully !!!\n";
            }
    }
    if(y==0)
    {
        cout<<"The name is not found in data . \n";
    }
}
void D::edit(char a[])
{
    int i,y=0,j,k,m;
    for(i=0;i<O.count;i++)
    {
         if(strcmp(o[i].name,a)==0)
            {
                do{
                     cout<<"Name is found in data . Which field do you want to edit :";
                cout<<"1.DOB\n2.Blood group\n3.Height\n4.Weight\n5.Insurance Policy no.\n6.Contact address\n7.Telephone no.\n8.Driving license no.\n";
                int h;
                cin>>h;
                switch(h)
                {
                    case 1: cin>>o[i].dob;
                    break;
                    case 2: cin>>o[i].bg;
                    break;
                    case 3: cin>>o[i].ht;
                    break;
                    case 4: cin>>o[i].wt;
                    break;
                    case 5: cin>>o[i].ipno;
                    break;
                    case 6: cin>>o[i].ca;
                    break;
                    case 7: cin>>o[i].tn;
                    break;
                    case 8: cin>>o[i].dln;
                    break;
                    default:cout<<"Wrong choice !!\n";
                }
                cout<<"Do you want to continue\n1.YES\n2.NO\n";
                cin>>m;
                }while(m==1);
                    y=1;
            }
    }
    if(y==0)
    {
        cout<<"The name is not found in data . \n";
    }
}
int D::search(char a[])
{
        int i,y=0;
    for(i=0;i<O.count;i++)
    {
         if(strcmp(o[i].name,a)==0)
            {
                y=1;
            }
    }
   return y;
}
int main()
{
    int n,i,m=1,choice;
   char a[20],b[20];
    cout<<"Enter number of entry's you want to add : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter details of person "<<i+1<<endl;
        o[i].getdata();
    }
        do
        {
            cout<<"Program to maintain  database : \n"<<"1.Build a master table\n2.Display specific data\n3.Insert a new entry\n4.Delete an entry\n5.Edit\n6.Search record\n";
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1:  for(i=0;i<O.count;i++)
                        {
                            cout<<endl<<"--------------------------------------------------------------------------------";
                            o[i].mtable();
                            cout<<endl<<"--------------------------------------------------------------------------------";
                        }
                        break;
                case 2:
                       int x;
                       cout<<"Enter the name of person to display data :";
                       cin>>a;
                          cout<<endl<<"--------------------------------------------------------------------------------";
                          O.specific(a);
                          cout<<endl<<"--------------------------------------------------------------------------------";
                        break;
                case 3:int g;
                        cout<<"How many entry's do you want to insert : ";
                        cin>>g;
                        int p;
                       p =O.count ;
                        for(i=p;i<p+g;i++)
                        {
                            cout<<"Enter details of person  "<<i+1<<endl;
                             o[i].getdata();
                        }
                        cout<<endl<<"--------------------------------------------------------------------------------";
                        break;
                case 4:cout<<"Enter the name which you want to delete : ";
                       cin>>a;
                       O.del(a);
                       cout<<endl<<"--------------------------------------------------------------------------------";
                       break;
                case 5 :cout<<"Enter the name ,whose data you want to edit : \n ";
                        cin>>a;
                        O.edit(a);
                         cout<<endl<<"--------------------------------------------------------------------------------";
                        break;
                case 6: cout<<"Enter the name to search : ";
                        cin>>a;
                        int v;
                        v=O.search(a);
                        if (v==1)
                            cout<<"Name found in data .\n";
                        else
                            cout<<"Name is NOT found in data .\n";
                        cout<<endl<<"--------------------------------------------------------------------------------";
                        break;
                default:cout<<"ERROR!!\n";
                break;
            }
            cout<<endl<<"--------------------------------------------------------------------------------";
            cout<<"Do you want to continue :\n1.YES\n2.NO";
            cin>>m;
        }while(m==1);
      return 0;
}
void D::getdata()
{
    cout<<"Enter name : ";
    cin>>name;
    cout<<endl;
     cout<<"Enter Date of birth : ";
    cin>>dob;
    cout<<endl;
     cout<<"Enter Blood group : ";
    cin>>bg;
    cout<<endl;
     cout<<"Enter Height(in cms) : ";
    cin>>ht;
    cout<<endl;
     cout<<"Enter Weight (in kg's) : ";
    cin>>wt;
    cout<<endl;
     cout<<"Enter Insurance poliicy no. : ";
    cin>>ipno;
    cout<<endl;
     cout<<"Enter Contact address : ";
    cin>>ca;
    cout<<endl;
     cout<<"Enter Telephone number  : ";
    cin>>tn;
    cout<<endl;
     cout<<"Enter Driving license number : ";
    cin>>dln;
    cout<<endl;
    O.count++;
}
void D::mtable()
{
    cout<<"Name...........= "<<name<<endl;
    cout<<"DOB............= "<<dob<<endl;
    cout<<"Blood group....= "<<bg<<endl;
    cout<<"Height.........= "<<ht<<endl;
    cout<<"Weight.........= "<<wt<<endl;
    cout<<"Ins.Policy no..= "<<ipno<<endl;
    cout<<"Contact add....= "<<ca<<endl;
    cout<<"Telephone no...= "<<tn<<endl;
    cout<<"D.L no.........= "<<dln<<endl;
}
