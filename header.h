#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

#define nil NULL


#define infok(p) (p)->infok
#define infoh(p) (p)->infoh
#define infos(p) (p)->infos
#define infor(p) (p)->infor
#define infou(p) (p)->infou
#define infob(p) (p)->infob

#define nextk(p) (p)->nextk
#define prevk(p) (p)->prevk
#define nextu(p) (p)->nextu
#define prevu(p) (p)->prevu
#define nextb(p) (p)->nextb


#define nexth(p) (p)->nexth
#define nexts(p) (p)->nexts
#define nextr(p) (p)->nextr


#define first(l) ((l).first)
#define last(l) ((l).last)

using namespace std;

typedef struct
{
    char kota[10];
    int hotels;
} infotypeK;

typedef struct
{
    char hotel[10];
    int suites;
} infotypeH;

typedef struct
{
    char suite[10];
    int rooms;
} infotypeS;

typedef struct
{
    char room[10];
    int rate;
    bool stats;
} infotypeR;

typedef struct admin
{
    char user[10];
    char pass[10];
} infotypeAdm;

typedef struct user
{
    char user[20];
    char pass[20];
    int books;
} infotypeU;

typedef struct book
{
    char kota[10];
    char hotel[10];
    char suite[10];
    char room[10];
    int price;
} infotypeB;

typedef struct elek *addressk;
typedef struct eleh *addressh;
typedef struct eles *addresss;
typedef struct eler *addressr;

typedef struct eleu *addressu;
typedef struct eleb *addressb;


typedef struct elek
{
    infotypeK infok;
    addressk nextk;
    addressk prevk;
    addressh nexth;
} elementkota;

typedef struct eleh
{
    infotypeH infoh;
    addressh nexth;
    addresss nexts;
} elementhotel;

typedef struct eles
{
    infotypeS infos;
    addresss nexts;
    addressr nextr;
} elementsuite;

typedef struct eler
{
    infotypeR infor;
    addressr nextr;
} elementroom;

typedef struct eleu
{
    infotypeU infou;
    addressu nextu;
    addressu prevu;
    addressb nextb;
} elementuser;

typedef struct eleb
{
    infotypeB infob;
    addressb nextb;
} elementbook;

typedef struct
{
    addressk first;
    addressk last;
} multilist;

typedef struct
{
    addressu first;
    addressu last;
} userlist;


addressk alokasik(infotypeK x);
addressh alokasih(infotypeH x);
addresss alokasis(infotypeS x);
addressr alokasir(infotypeR x);
addressb alokasib(infotypeB x);


addressk cariK(multilist l, infotypeK a);
addressh cariH(multilist l,addressk k,infotypeH b);
addresss cariS(multilist l,addressh h,infotypeS c);
addressr cariR(multilist l,addresss s,infotypeR d);


void InsertKota(multilist &l);
void InsertHotel(multilist &l);
void InsertSuite(multilist&l);
void InsertRoom(multilist&l);
void DefaultData(multilist&l);
void DefaultUser(userlist&m);

void ShowAllData(multilist l);
void ShowKota(multilist l);
void ShowHotel(multilist l,addressk k);
void ShowSuite(multilist l,addressh h);
void ShowRoom(multilist l,addresss s);
void ShowBook(addressu usr,userlist m);



void Login(multilist &l,userlist &m);
void LoginAdmin(multilist *l);
void UserMenu(addressu usr,multilist &l,userlist &m);
void AdminMenu(multilist *l);
int CekAdmin(infotypeAdm a);

void Signup(userlist &m);
void ShowUser(userlist m);
addressu cariU(userlist m,infotypeU x);
addressu alokasiU(infotypeU x);


void CreateList(multilist *l,userlist *m);
addressu CekUser(userlist m,infotypeU x);

void Booking(addressu usr,multilist &l,userlist &m);
#endif
