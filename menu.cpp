#include "header.h"

void Login(multilist &l,userlist &m)
{
    infotypeU x;
    addressu usr;

    system("cls");
    cout<<endl;
    cout<<"------------------ Login User ------------------"<<endl;
    cout<<"Username : ";
    cin>>x.user;
    cout<<"Password : ";
    cin>>x.pass;
    usr=CekUser(m,x);

    if(usr==nil)
    {
        cout<<endl;
        cout<<"login Failed, username or password invalid !"<<endl;
        getch();
    }
    else
    {
        UserMenu(usr,l,m);
    }

}

void LoginAdmin(multilist *l)
{
    infotypeAdm x;
    int valid;

    system("cls");
    cout<<endl;
    cout<<"------------------ Login Admin ------------------"<<endl;
    cout<<"Username : ";
    cin>>x.user;
    cout<<"Password : ";
    cin>>x.pass;
    valid=CekAdmin(x);

    if(valid==0)
    {

        AdminMenu(l);
    }
    else
    {
        cout<<endl;
        cout<<"Username or Password Invalid";
    }
    getch();

}

void UserMenu(addressu usr,multilist &l,userlist &m)
{
    int pil;


    system("cls");
    do
    {
        system("cls");
        cout<<endl;
        cout<<"------------------ You're Logged In As : '"<<infou(usr).user <<"' ------------------"<<endl;
        cout<<" 1. Book A Room"<<endl;
        cout<<" 2. My Books"<<endl;
        cout<<" 3. Exit"<<endl;
        cout<<endl;
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            Booking(usr,l,m);
            break;
        case 2:
            ShowBook(usr,m);
            break;
        case 3:
            break;
        case 9:
            cout<<infou(usr).books<<endl;
            cout<<infou(usr).user<<endl;
            cout<<infou(usr).pass<<endl;
            break;
        }
    }
    while(pil!=3);
}

void AdminMenu(multilist *l)
{
    int pil;
    do
    {
        system("cls");
        cout<<endl;
        cout<<"------------------ Welcome Admin ------------------"<<endl;
        cout<<" 1. Insert City"<<endl;
        cout<<" 2. Insert Hotel"<<endl;
        cout<<" 3. Insert Room Suite"<<endl;
        cout<<" 4. Insert Room"<<endl;
        cout<<" 5. View All Data"<<endl;
        cout<<" 6. Exit"<<endl;
        cout<<endl;
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            system("cls");
            InsertKota(*l);
            break;

        case 2:
            system("cls");
            InsertHotel(*l);
            break;

        case 3:
            system("cls");
            InsertSuite(*l);
            break;

        case 4:
            system("cls");
            InsertRoom(*l);
            break;

        case 5:
            ShowAllData(*l);
            getch();
            break;
        case 6:
            break;
        }
    }
    while(pil!=6);
}
