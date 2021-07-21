#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <windows.h>
using namespace std;

class airport
{
int tno;
char pname[20];
public:
       char ftype[20];
       char classtype[20];
       int bag;
       float price;
       char from[20];
       char dest[20];
       void getdata()
       {
        cout<<"Enter the passenger's ticket number, name, class , food category, departure and destination \n";
        cin>>tno>>pname>>classtype>>ftype>>from>>dest;
       }
        void putdata()
       {
        cout<<"Ticket Number : "<<tno<<endl;
        cout<<"Name : "<<pname<<endl;
        cout<<"Class Type : "<<classtype<<endl;
        cout<<"Baggage Allowance : "<<bag<<endl;
        cout<<"Departure : "<<from<<endl;
        cout<<"Destination : "<<dest<<endl;
        cout<<"Ticket Cost : "<<price<<endl;
        cout<<"Food Category : "<<ftype<<endl;
       }
        int gettno()
       {
        return (tno);
       }
};
void searchpas();
void delpas();
void updatepas();
void create();
void addpas();
void display();
void displayb();
void displaye();
void upgradepas();
void degradepas();
void baggage();
airport p;
int main()
{
 int ch;
 do
   {
    cout<<"\n_______________________________________________";
    cout<<"\n| Welcome to Emirates administrative services |";
    cout<<"\n| 1 - Buy Ticket                              |";
    cout<<"\n| 2 - Display All Passenger Details           |";
    cout<<"\n| 3 - Display Business Class Passengers       |";
    cout<<"\n| 4 - Display Economy Class Passengers        |";
    cout<<"\n| 5 - Search A Passenger                      |";
    cout<<"\n| 6 - Extra Baggage Allowance                 |";
    cout<<"\n| 7 - Update                                  |";
    cout<<"\n| 8 - Add Passengers                          |";
    cout<<"\n| 9 - Cancel Ticket                           |";
    cout<<"\n| 10 - Upgrade from Economy to Business Class |";
    cout<<"\n| 11 - Degrade from Business to Economy Class |";
    cout<<"\n| 12 - Log Off                                |";
    cout<<"\n_______________________________________________";
    cout<<"\n Enter your desired choice \n";
    cin>>ch;
    switch (ch)
   {
    case 1: create();break;
    case 2: display();break;
    case 3: displayb();break;
    case 4: displaye();break;
    case 5: searchpas();break;
    case 6: baggage();break;
    case 7: updatepas();break;
    case 8: addpas();break;
    case 9: delpas();break;
    case 10: upgradepas();break;
    case 11: degradepas();break;
    case 12: cout<<"Thank you for using our services. Have a nice day!";
            exit (0);break;
   }
   }while(ch<=12);
}

void create()
{
 int n;
 fstream fp("airpo.dat",ios::binary|ios::out);
 cout<<"\n Enter the number of passengers\n";
 cin>>n;
 cout<<"\n Enter the passenger details \n";
 for (int i=0;i<n;i++)
    {
     p.getdata();
       if (strcmpi (p.classtype,"business")==0)
        {
            p.price=15000;
            p.bag=50;
        }
     else if (strcmpi (p.classtype,"economy")==0)
        {
            p.price=10000;
            p.bag=30;
        }
       if (strcmpi (p.ftype,"veg"==0))
        p.price+=500;
       else if (strcmpi (p.ftype,"nonveg"==0))
        p.price+=1000;
     fp.write((char*)&p,sizeof(p));
    }
}

void display()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 cout<<"\n The passenger details are \n";
 while(fp.read((char*)&p,sizeof(p)))
       { p.putdata();
         cout<<endl;
       }
 fp.close();
}

void searchpas()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 int no,found=0;
 cout<<"\n Enter the ticket number to be searched\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
       if (p.gettno()==no)
          {
           found=1;
           p.putdata();
           cout<<endl;
           break;
          }
 if (found==0)
    cout<<"No such passenger with ticket number "<<no<<" found \n";
 fp.close();
}

void delpas()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 fstream ft("tempo.dat",ios::binary|ios::out);
 int no;
 cout<<"\n Enter the ticket number to deleted\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
      if (p.gettno()!=no)
         ft.write((char*)&p,sizeof(p));
 fp.close();
 ft.close();
 remove ("airpo.dat");
 rename ("tempo.dat","airpo.dat");
}

void updatepas()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 fstream ft("tempo.dat",ios::binary|ios::out);
 int no;
 cout<<"\n Enter the ticket number of the passenger to be updated\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
      {
       if (p.gettno()==no)
          {
           cout<<"\n Enter the new passenger details \n";
           p.getdata();
           ft.write((char*)&p,sizeof(p));
          }
       else ft.write((char*)&p,sizeof(p));
      }
 fp.close();
 ft.close();
 remove ("airpo.dat");
 rename ("tempo.dat","airpo.dat");
}

void upgradepas()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 fstream ft("tempo.dat",ios::binary|ios::out);
 int no;
 cout<<"\n Enter the ticket number of the passenger to be upgraded to business class\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
      {
       if (p.gettno()==no)
          {
           strcpy (p.classtype,"business");
           {
               p.price+=5000;
               p.bag=50;
           }
           ft.write((char*)&p,sizeof(p));
          }
       else ft.write((char*)&p,sizeof(p));
      }
 Sleep(1000);
 cout<<"\n The passenger has been upgraded to Business Class \n";
 fp.close();
 ft.close();
 remove ("airpo.dat");
 rename ("tempo.dat","airpo.dat");
}

void degradepas()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 fstream ft("tempo.dat",ios::binary|ios::out);
 int no;
 cout<<"\n Enter the ticket number of the passenger to be degraded from Business Class to Economy Class\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
      {
       if (p.gettno()==no)
          {
           strcpy (p.classtype,"economy");
           {
               p.price-=5000;
               p.bag=30;
           }
           ft.write((char*)&p,sizeof(p));
          }
       else ft.write((char*)&p,sizeof(p));
      }
 Sleep(1000);
 cout<<"\n The passenger has been transferred to Economy Class \n";
 fp.close();
 ft.close();
 remove ("airpo.dat");
 rename ("tempo.dat","airpo.dat");
}
void addpas()
{
 fstream fp("airpo.dat",ios::binary|ios::app);
 cout<<"\n Enter the number of passengers\n";
 int n;
 cin>>n;
 cout<<"\n Enter the passenger details \n";
 for (int i=0;i<n;i++)
    {
     p.getdata();
       if (strcmpi (p.classtype,"business")==0)
        {
            p.price=15000;
            p.bag=50;
        }
     else if (strcmpi (p.classtype,"economy")==0)
        {
            p.price=10000;
            p.bag=30;
        }
       if (strcmpi (p.ftype,"veg")==0)
        p.price+=500;
       else if (strcmpi (p.ftype,"nonveg")==0)
        p.price+=1000;
     fp.write((char*)&p,sizeof(p));
    }
}
void baggage()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 fstream ft("tempo.dat",ios::binary|ios::out);
 int no;
 cout<<"\n Enter your ticket number\n";
 cin>>no;
 while(fp.read((char*)&p,sizeof(p)))
      {
          if (p.gettno()==no)
          {
           cout<<"\n Enter how many kilos you want to add to your baggage allowance \n";
           int kilo;
           cin>>kilo;
           p.bag+=kilo;
           p.price+=kilo*0.4;
           ft.write((char*)&p,sizeof(p));
           cout<<endl;
          }
        else ft.write((char*)&p,sizeof(p));
      }
 fp.close();
 ft.close();
 remove ("airpo.dat");
 rename ("tempo.dat","airpo.dat");
}
void displayb()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 cout<<"\n The Business Class Passenger Details are \n";
 while(fp.read((char*)&p,sizeof(p)))
       {
         if (strcmpi (p.classtype,"business")==0)
         {
             p.putdata();
             cout<<endl;
         }
       }
 fp.close();
}
void displaye()
{
 fstream fp("airpo.dat",ios::binary|ios::in);
 cout<<"\n The Economy Class Passenger Details are \n";
 while(fp.read((char*)&p,sizeof(p)))
       {
         if (strcmpi (p.classtype,"economy")==0)
         {
             p.putdata();
             cout<<endl;
         }
       }
 fp.close();
}
