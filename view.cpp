#include "header.h"

void ShowAllData(multilist l)
{
    addressk k=first(l);
    if(k==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        while(k!=nil)
        {
            cout<<endl;
            cout<<"--------------------"<<infok(k).kota<<"--------------------";
            if(infok(k).hotels>0)
            {
                addressh h=nexth(k);
                while(h!=nil)
                {
                    cout<<endl;
                    cout<<"\t"<<infoh(h).hotel<<endl;
                    if(infoh(h).suites>0)
                    {
                        addresss s=nexts(h);
                        while(s!=nil)
                        {
                            cout<<endl;
                            cout<<"\t\t"<<infos(s).suite<<endl;
                            if(infos(s).rooms>0)
                            {
                                addressr r=nextr(s);
                                while(r!=nil)
                                {
                                    cout<<endl;
                                    cout<<"\t\t\t"<<infor(r).room<<endl;
                                    r=nextr(r);
                                }
                            }
                            s=nexts(s);
                        }
                    }
                    h=nexth(h);
                }
            }
            k=nextk(k);
        }
    }
}

void ShowKota(multilist l)
{
    addressk p=first(l);
    if(p==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        cout<<endl;
        cout<<"------KOTA------"<<endl;
        while(p!=nil)
        {
            cout<<"- "<<infok(p).kota<<endl;
            p=nextk(p);
        }
    }
}

void ShowHotel(multilist l, addressk k)
{

    if(infok(k).hotels>0)
    {
        addressh h=nexth(k);
        cout<<endl;
        cout<<"------"<<infok(k).kota<<"------"<<endl;
        while(h!=nil)
        {
            cout<<"- "<<infoh(h).hotel<<endl;
            h=nexth(h);
        }
    }
}



void ShowSuite(multilist l,addressh h)
{

    if(infoh(h).suites>0)
    {
        addresss s=nexts(h);
        cout<<endl;
        cout<<"------"<<infoh(h).hotel<<"------"<<endl;
        while(s!=nil)
        {
            cout<<"- "<<infos(s).suite<<endl;
            s=nexts(s);
        }
    }
}

void ShowRoom(multilist l,addresss s)
{

    if(infos(s).rooms>0)
    {
        addressr r=nextr(s);
        cout<<endl;
        cout<<"------"<<infos(s).suite<<"------"<<endl;
        while(r!=nil)
        {
            if(infor(r).stats==false)
                cout<<"- "<<infor(r).room<<endl;

            r=nextr(r);
        }
    }
}

void ShowBook(addressu usr,userlist m)
{
    if(infou(usr).books>0)
    {
        addressb b=nextb(usr);
        cout<<endl;
        cout<<"------Booked Hotel Room------"<<endl;
        while(b!=nil)
        {
            cout<<"Kota  : "<<infob(b).kota<<endl;
            cout<<"Hotel : "<<infob(b).hotel<<endl;
            cout<<"Suite : "<<infob(b).suite<<endl;
            cout<<"Room  : "<<infob(b).room<<endl;
            b=nextb(b);
        }
    }
    else
    {
        cout<<endl;
        cout<<"------No Booked Data Found------"<<endl;

    }
    getch();
}
