#include "header.h"

void Signup(userlist &m)
{
    infotypeU u;
    addressu usr;
    std::string f;

    system("cls");
    cout<<"-------------SIGNUP-------------"<<endl;
    cout<<"Enter Username    : ";
    cin>>u.user;
    cout<<"Enter Password    : ";
    cin>>u.pass;
    u.books=0;
    cout<<"Re-enter Password : ";cin>>f;
    if(u.pass == f){
    usr=cariU(m,u);
    if(usr==nil)
    {

        usr=alokasiU(u);
        if(first(m)==nil)
        {
            first(m)=usr;
            last(m)=usr;

            cout<<endl;
            cout<<"User : "<<infou(usr).user<<" Terdaftar"<<endl;
            getch();
        }
        else
        {
            nextu(last(m))=usr;
            prevu(usr)=last(m);
            last(m)=usr;

            cout<<endl;
            cout<<"User "<<infou(usr).user<<" Registered"<<endl;
            getch();
        }
           }else{
             cout<<endl;
           cout<<"User Already Exist";
         getch();
        }

    }
    else
    {
        cout<<endl;
        cout<<"Password Doesn't Match"<<endl;
        getch();
    }
}

addressu alokasiU(infotypeU x)
{
    addressu p=(addressu)malloc(sizeof(elementuser));
    infou(p)=x;
    nextu(p)=nil;
    prevu(p)=nil;
    return p;
}

addressu cariU(userlist m,infotypeU x)
{
    addressu u=first(m);
    while(u!=nil)
    {
        if (strcmp(infou(u).user,x.user)==0)
            return u;
        u=nextu(u);
    }
    return nil;
}

void ShowUser(userlist m)
{
    addressu p=first(m);
    if(p==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        cout<<endl;
        cout<<"------User------"<<endl;
        while(p!=nil)
        {
            cout<<"- "<<infou(p).user<<endl;
            cout<<"- "<<infou(p).pass<<endl;
            p=nextu(p);
        }
    }
}

addressu CekUser(userlist m,infotypeU x)
{
    addressu u=first(m);
    while(u!=nil)
    {
        if ((strcmp(infou(u).user,x.user)==0) && (strcmp(infou(u).pass,x.pass)==0))
            return u;
        u=nextu(u);
    }
    return nil;
}
