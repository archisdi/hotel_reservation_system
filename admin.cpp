#include "header.h"

int CekAdmin(infotypeAdm a)
{
    int user, pass, valid;

    user=strcmp("admin",a.user);
    pass=strcmp("ara",a.pass);

    if(user==0 && pass==0)
    {
        valid=0;
    }
    else
    {
        valid=1;
    }

    return valid;
}

void CreateList(multilist *l,userlist *m)
{
    first(*l)=nil;
    last(*l)=nil;

    first(*m)=nil;
    last(*m)=nil;
}
