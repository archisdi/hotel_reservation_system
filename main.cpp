#include "header.h"

int main()
{

    int pil;
    multilist l;
    userlist m;
    CreateList(&l,&m);
    DefaultData(l);
    DefaultUser(m);

    do
    {
        system("cls");
        cout<<endl;
        cout<<"------------------ Online Hotel Reservation ------------------"<<endl;
        cout<<" 1. Login"<<endl;
        cout<<" 2. Signup"<<endl;
        cout<<" 3. Hotels"<<endl;
        cout<<" 4. Exit"<<endl;
        cout<<"--------------"<<endl;
        cout<<" 0. Admin"<<endl;
        cout<<endl;
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            Login(l,m);
            break;
        case 2:
            Signup(m);
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            LoginAdmin(&l);
            break;
        case 8:
            ShowUser(m);
            getch();
            break;
        case 9:
            ShowAllData(l);
            getch();
            break;
        default :
            cout<<"input not valid";
            getch();
            break;
        }
    }
    while(pil!=4);
    getch();
}
