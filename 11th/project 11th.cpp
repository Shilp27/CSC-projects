#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
struct lib
{
    int bookno;
    int sno;
    char aut[20];
    int bprice;
    char name[20];
    char stu[20];
    int gr;
};
void menu();
void searchbybookno(lib b[],int);
void searchbyname(lib b[],int);
void searchbyauthor(lib b[],int);
void display(lib b[],int);
void fine(lib b[],int);
void finepaid(lib b[],int);
void add(lib b[],int);
void del(lib b[],int);
void modify(lib b[],int);
void editbname(lib b[],int);
void editbno(lib b[],int);
void editsno(lib b[],int);
lib b[20];
int n;
int ch;
int main()
{
int ch;
int i;
int ab;
do
   {
    cout<<"Menu \n";
    cout<<"1 Admins provide details \n";
    cin>>ab;
   }while(ab!=1);

cout<<"\n Welcome to the Library \n"<<"Please enter the details \n";
cout<<"\n Enter the limit \n";
cin>>n;
cout<<"\n Enter the following details horizontally \n";
cout<<"Book No \n";
cout<<"Book name \n";
cout<<"Shelf no \n";
cout<<"Author \n";
cout<<"Book Price \n";
cout<<"student name \n";
cout<<"student GR NO \n";
for (i=0;i<n;i++)
    {
        cin>>b[i].bookno>>b[i].name>>b[i].sno>>b[i].aut>>b[i].bprice>>b[i].stu>>b[i].gr;
    }
do
 {
     cout<<"\n Menu";
     cout<<"\n 1 Admin";
     cout<<"\n Enter your choice \n";
     cin>>ch;
     switch (ch)
         {
         case 1:menu();break;
         }
 } while (ch<=1);
}
void menu()
{
    do
     {  cout<<"\n Menu";
        cout<<"\n 1 Search by BookNo";
        cout<<"\n 2 Search by Book Name";
        cout<<"\n 3 Search by Author";
        cout<<"\n 4 Display";
        cout<<"\n 5 Fine";
        cout<<"\n 6 Modify Book Details";
        cout<<"\n 7 Add a Book";
        cout<<"\n 8 Delete a Book";
        cout<<"\n 9 Exit";
        cout<<"\n Enter your preferred choice \n";
        int ch;
        cin>>ch;
        switch (ch)
        {
            case 1:searchbybookno(b,n);break;
            case 2:searchbyname(b,n);break;
            case 3:searchbyauthor(b,n);break;
            case 4:display(b,n);break;
            case 5:fine(b,n);break;
            case 6:modify(b,n);break;
            case 7:add(b,n);break;
            case 8:del(b,n);break;
            case 9:cout<<"Have a Great Day!";exit(0);break;
        }
     }while(ch<=9);
}
void searchbybookno(lib b[20],int n)
{
     int ano,found=0;
     cout<<"Enter the number to be searched \n";
     cin>>ano;
     for (int i=0;i<n;i++)
          if (b[i].bookno==ano)
             {
                 found=1;
                 cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
                 break;
             }
      if (found==0)
          cout<<"\n Unsuccessful Search \n";
}
void searchbyname(lib b[20],int n)
{
    char name[20];
    int found=0;
    cout<<"Enter book name to be searched \n";
    cin>>name;
    for (int i=0;i<n;i++)
        if (strcmpi(b[i].name,name)==0)
        {
        cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
        found=1;
        break;
        }
    if (found==0)
        cout<<"Unsuccessful Search \n";
}
void searchbyauthor(lib b[20],int n)
{
    char name[20];
    int found=0;
    cout<<"Enter author name to be searched \n";
    cin>>name;
    for (int i=0;i<n;i++)
        if (strcmpi(b[i].aut,name)==0)
        {
        cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
        found=1;
        }
    if (found==0)
        cout<<"Unsuccessful Search \n";
}
void fine(lib b[20],int n)
{
    int no;
    int fineamt=1;
    searchbyname(b,n);
    cout<<"Enter the number of days delayed \n";
    cin>>no;
    fineamt=2*no;
    cout<<"Fine amount is \t"<<fineamt<<endl;
    finepaid(b,n);
}
void finepaid(lib b[20],int n)
{
    char name[20];
    int found=0;
    int fineamt;
    cout<<"Enter student name to be searched \n";
    cin>>name;
    for (int i=0;i<n;i++)
        if (strcmpi(b[i].stu,name)==0)
        {
         cout<<"The book price is \t"<<b[i].bprice<<endl;
         cout<<"Enter the fine amount paid \n";
         cin>>fineamt;
         cout<<"Remaining amount left is \t"<<b[i].bprice-fineamt<<endl;
         found=1;
        }
    if (found==0)
        cout<<"Unsuccessful Search \n";
}
void modify(lib b[20],int n)
{
 do
   {
     cout<<"What kind of modification would you prefer \n";
     cout<<"\n 1 Add a Book";
     cout<<"\n 2 Delete a Book";
     cout<<"\n 3 Edit Book Name";
     cout<<"\n 4 Edit Book Number";
     cout<<"\n 5 Edit Student GR Number";
     cout<<"\n 6 Go back to Main Menu \n";
     int ch;
     cin>>ch;
     switch (ch)
        {
         case 1:add(b,n);break;
         case 2:del(b,n);break;
         case 3:editbname(b,n);break;
         case 4:editbno(b,n);break;
         case 5:editsno(b,n);break;
         case 6:menu();break;
        }
   }while(ch<=6);
}
void add(lib b[20],int n)
{
    int no;
    cout<<"Enter Book number to be added \n";
    cin>>no;
    for (int i=0;i<n;i++)
        if (b[i].bookno==no)
        {
         int j=i;
         i=n;
         for ( ;i>=j;i--)
             {
              b[i].bookno=b[i-1].bookno;
              strcpy(b[i].name,b[i-1].name);
              b[i].sno=b[i-1].sno;
              strcpy(b[i].aut,b[i-1].aut);
              b[i].bprice=b[i-1].bprice;
              strcpy(b[i].stu,b[i-1].stu);
              b[i].gr=b[i-1].gr;
              cout<<"Enter the New Book Details Horizontally \n";
              cout<<"Book No \n";
              cout<<"Book name \n";
              cout<<"Shelf no \n";
              cout<<"Author \n";
              cout<<"Book Price \n";
              cout<<"student name \n";
              cout<<"student GR NO \n";
              cin>>b[j].bookno>>b[j].name>>b[j].sno>>b[j].aut>>b[j].bprice>>b[j].stu>>b[j].gr;
              cout<<"Book Successfully Added \n";
              display(b,n);
              break;
             }
        }
}
void del(lib b[20],int n)
{
    char name[20];
    int found=0;
    cout<<"Enter name of book to be deleted \n";
    cin>>name;
    for (int i=0;i<n;i++)
        if (strcmpi(b[i].name,name)==0)
        {
         for ( ;i<n;i++)
             {
              b[i].bookno=b[i+1].bookno;
              strcpy(b[i].name,b[i+1].name);
              b[i].sno=b[i+1].sno;
              strcpy(b[i].aut,b[i+1].aut);
              b[i].bprice=b[i+1].bprice;
              strcpy(b[i].stu,b[i+1].stu);
              b[i].gr=b[i+1].gr;
             }
         cout<<"Book Successfully Deleted \n";
         found=1;
         display(b,n);
        }
    if (found==0)
        cout<<"No Book Found \n";
}
void editbname(lib b[20],int n)
{
    char name[20];
    int found=0;
    cout<<"Enter book name to be searched \n";
    cin>>name;
    for (int i=0;i<n;i++)
        if (strcmpi(b[i].name,name)==0)
        {
         cout<<"Enter the New Name of the Book \n";
         char bname[20];
         cin>>bname;
         strcpy(b[i].name,bname);
         cout<<"New Details Are \n";
         cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
         found=1;
        }
    if (found==0)
        cout<<"No Book Found\n";
}
void editbno(lib b[20],int n)
{
    int ano,found=0;
     cout<<"Enter the book number to be searched \n";
     cin>>ano;
     for (int i=0;i<n;i++)
          if (b[i].bookno==ano)
             {
                 cout<<"Enter the new book number \n";
                 int nno;
                 cin>>nno;
                 b[i].bookno=nno;
                 found=1;
                 cout<<"New Details Are \n";
                 cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
             }
      if (found==0)
          cout<<"\n No Book Found \n";
}
void editsno(lib b[20],int n)
{
     int found=0;
     cout<<"Enter the student name to be searched \n";
     char sname[20];
     cin>>sname;
     for (int i=0;i<n;i++)
          if (strcmpi(b[i].stu,sname==0))
             {
                 cout<<"Old student number \n";
                 cout<<b[i].gr<<"\n";
                 cout<<"Enter the new student number \n";
                 int nno;
                 cin>>nno;
                 b[i].gr=nno;
                 found=1;
                 cout<<"New Details Are \n";
                 cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
                 break;
             }
      if (found==0)
          cout<<"\n No Student Found \n";
}
void display(lib b[20],int n)
{   cout<<"Book and Student Details are \n";
    for (int i=0;i<n;i++)
        cout<<b[i].bookno<<" "<<b[i].name<<" "<<b[i].sno<<" "<<b[i].aut<<" "<<b[i].bprice<<" "<<b[i].stu<<" "<<b[i].gr<<endl;
}
