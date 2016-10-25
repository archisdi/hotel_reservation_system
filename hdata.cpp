#include "header.h"

addressk alokasik(infotypeK x)
{
    addressk p=(addressk)malloc(sizeof(elementkota));
    infok(p)=x;
    nextk(p)=nil;
    nexth(p)=nil;
    prevk(p)=nil;
    return p;
}

addressh alokasih(infotypeH x)
{
    addressh p=(addressh)malloc(sizeof(elementhotel));
    infoh(p)=x;
    nexth(p)=nil;
    nexts(p)=nil;
    return p;
}

addresss alokasis(infotypeS x)
{
    addresss p=(addresss)malloc(sizeof(elementsuite));
    infos(p)=x;
    nexts(p)=nil;
    nextr(p)=nil;
    return p;
}

addressr alokasir(infotypeR x)
{
    addressr p=(addressr)malloc(sizeof(elementroom));
    infor(p)=x;
    nextr(p)=nil;
    return p;
}

addressk cariK(multilist l,infotypeK a)
{
    addressk k=first(l);
    while(k!=nil)
    {
        if (strcmp(infok(k).kota,a.kota)==0)
            return k;
        k=nextk(k);
    }
    return nil;
}

addressh cariH(multilist l,addressk k,infotypeH b)
{
    addressh h=nexth(k);
    while(h!=nil)
    {
        if (strcmp(infoh(h).hotel,b.hotel)==0)
            return h;
        h=nexth(h);
    }
    return nil;
}

addresss cariS(multilist l,addressh h,infotypeS c)
{
    addresss s=nexts(h);
    while(s!=nil)
    {
        if (strcmp(infos(s).suite,c.suite)==0)
            return s;
        s=nexts(s);
    }
    return nil;
}

addressr cariR(multilist l,addresss s,infotypeR d)
{
    addressr r=nextr(s);
    while(r!=nil)
    {
        if (strcmp(infor(r).room,d.room)==0)
            return r;
        r=nextr(r);
    }
    return nil;
}

void InsertKota(multilist &l)
{
    infotypeK a;
    addressk k;

    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);

    if(k==nil)
    {
        a.hotels=0;

        k=alokasik(a);
        if(first(l)==nil)
        {
            first(l)=k;
            last(l)=k;
        }
        else
        {
            nextk(last(l))=k;
            prevk(k)=last(l);
            last(l)=k;
        }
        cout<<endl;
        cout<<"Kota "<<infok(k).kota<<" Ditambahkan"<<endl;
        getch();
    }
    else
    {
        cout<<endl;
        cout<<"Kota ada di List"<<endl;
        getch();
    }
}


void InsertHotel(multilist &l)
{
    infotypeH b;
    infotypeK a;
    addressk k;
    addressh h;

    ShowKota(l);
    cout<<endl;
    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);
    if(k==nil)
    {
        cout<<endl;
        cout<<"Kota Tidak Ditemukan";
        getch();
    }
    else
    {
        system("cls");
        ShowHotel(l,k);
        cout<<endl;
        cout<<"Masukkan Nama Hotel  : ";
        cin>>b.hotel;
        h=cariH(l,k,b);
        if(h==nil)
        {
            b.suites=0;

            h=alokasih(b);
            if(infok(k).hotels==0)
            {
                nexth(k)=h;
                infok(k).hotels=1;
                cout<<endl;
                cout<<"Hotel "<<infoh(h).hotel<<" Pada Kota "<<infok(k).kota<<" Ditambahkan !";
                getch();
            }
            else
            {
                addressh h1=nexth(k);
                while(nexth(h1)!=nil)
                    h1=nexth(h1);
                nexth(h1)=h;
                infok(k).hotels++;
                cout<<endl;
                cout<<"Hotel "<<infoh(nexth(h1)).hotel<<" Pada Kota "<<infok(k).kota<<" Ditambahkan !";
                getch();
            }

        }
        else
        {
            cout<<endl;
            cout<<"Hotel ada di List"<<endl;
            getch();
        }
    }
}

void InsertSuite(multilist&l)
{
    infotypeS c;
    infotypeH b;
    infotypeK a;
    addressk k;
    addressh h;
    addresss s;


    ShowKota(l);
    cout<<endl;
    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);
    if(k==nil)
    {
        cout<<endl;
        cout<<"Kota Tidak Ditemukan";
        getch();
    }
    else
    {
        system("cls");
        ShowHotel(l,k);
        cout<<endl;
        cout<<"Masukkan Nama Hotel  : ";
        cin>>b.hotel;
        h=cariH(l,k,b);
        if(h==nil)
        {
            cout<<endl;
            cout<<"Hotel Tidak Ditemukan";
            getch();
        }
        else
        {
            system("cls");
            ShowSuite(l,h);
            cout<<endl;
            cout<<"Masukkan Nama Suite  : ";
            cin>>c.suite;
            s=cariS(l,h,c);

            if(s==nil)
            {
                c.rooms=0;
                s=alokasis(c);
                if(infoh(h).suites==0)
                {
                    nexts(h)=s;
                    infoh(h).suites=1;
                    cout<<endl;
                    cout<<"Suite "<<infos(s).suite<<" Pada Hotel "<<infoh(h).hotel<<" Ditambahkan !";
                    getch();
                }
                else
                {
                    addresss s1=nexts(h);
                    while(nexts(s1)!=nil)
                        s1=nexts(s1);
                    nexts(s1)=s;
                    infoh(h).suites++;
                    cout<<endl;
                    cout<<"Suite "<<infos(nexts(s1)).suite<<" Pada Hotel "<<infoh(h).hotel<<" Ditambahkan !";
                    getch();
                }
            }
            else
            {
                cout<<endl;
                cout<<"Suite ada di List"<<endl;
                getch();
            }
        }
    }
}



void InsertRoom(multilist&l)
{
    infotypeR d;
    infotypeS c;
    infotypeH b;
    infotypeK a;
    addressk k;
    addressh h;
    addresss s;
    addressr r;

    system("cls");
    ShowKota(l);
    cout<<endl;
    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);

    if(k==nil)
    {
        cout<<endl;
        cout<<"Kota Tidak Ditemukan";
        getch();
    }
    else
    {
        system("cls");
        ShowHotel(l,k);
        cout<<endl;
        cout<<"Masukkan Nama Hotel  : ";
        cin>>b.hotel;
        h=cariH(l,k,b);

        if(h==nil)
        {
            cout<<endl;
            cout<<"Hotel Tidak Ditemukan";
            getch();
        }
        else
        {
            system("cls");
            ShowSuite(l,h);
            cout<<endl;
            cout<<"Masukkan Nama Suite  : ";
            cin>>c.suite;
            s=cariS(l,h,c);

            if(s==nil)
            {
                cout<<endl;
                cout<<"Suite Tidak Ditemukan";
                getch();
            }
            else
            {
                system("cls");
                ShowRoom(l,s);
                cout<<endl;
                cout<<"Masukkan Nomor Kamar  : ";
                cin>>d.room;
                cout<<"Masukkan Rate Kamar   : ";
                cin>>d.rate;
                r=cariR(l,s,d);
                if(r==nil)
                {
                    d.stats=false;
                    r=alokasir(d);

                    if(infos(s).rooms==0)
                    {
                        nextr(s)=r;
                        infos(s).rooms=1;
                        cout<<endl;
                        cout<<"Room "<<infor(r).room<<" Pada Suite "<<infos(s).suite<<" Ditambahkan !";
                        getch();
                    }
                    else
                    {
                        addressr r1=nextr(s);
                        while(nextr(r1)!=nil)
                            r1=nextr(r1);
                        nextr(r1)=r;
                        infos(s).rooms++;
                        cout<<endl;
                        cout<<"Room "<<infor(nextr(r1)).room<<" Pada Suite "<<infos(s).suite<<" Ditambahkan !";
                        getch();
                    }
                }
                else
                {
                    cout<<endl;
                    cout<<"Room ada di List"<<endl;
                    getch();
                }
            }
        }
    }
}

void DefaultData(multilist&l)
{
    infotypeR d;
    infotypeS c;
    infotypeH b;
    infotypeK a;

    addressk k;
    addressh h;
    addresss s;
    addressr r;

    a.kota[0]='M';
    a.kota[1]='a';
    a.kota[2]='k';
    a.kota[3]='a';
    a.kota[4]='s';
    a.kota[5]='s';
    a.kota[6]='a';
    a.kota[7]='r';
    a.hotels=1;

    b.hotel[0]='A';
    b.hotel[1]='s';
    b.hotel[2]='t';
    b.hotel[3]='o';
    b.hotel[4]='n';
    b.suites=1;

    c.suite[0]='D';
    c.suite[1]='e';
    c.suite[2]='l';
    c.suite[3]='u';
    c.suite[4]='x';
    c.suite[5]='e';
    c.rooms=1;

    d.room[0]='3';
    d.room[1]='0';
    d.room[2]='1';
    d.rate=500000;
    d.stats=false;

    k=alokasik(a);
    h=alokasih(b);
    s=alokasis(c);
    r=alokasir(d);

    first(l)=k;
    last(l)=k;
    nexth(k)=h;
    nexts(h)=s;
    nextr(s)=r;
}

void DefaultUser(userlist &m)
{
    infotypeU u;
    addressu z;

    u.user[0]='A';
    u.user[1]='r';
    u.user[2]='c';
    u.user[3]='h';
    u.user[4]='i';
    u.user[5]='e';

    u.pass[0]='a';
    u.pass[1]='r';
    u.pass[2]='a';
    u.books=0;

    z=alokasiU(u);
    first(m)=z;
    last(m)=z;
}
