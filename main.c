#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
}
sys;
typedef struct
{
    int day,mon,year;
}
 form;
typedef struct
{
    char build[100];
    char sreet[100];
    char city[100];
}
Address;
typedef struct
{
    char first[100];
    char last[100];
}
NAME;
typedef struct
{
    char author[100],publisher[100],isbn[100],title[100],category[100];
    int tc,ac;
    form date;
}
books;
typedef struct
{
    NAME name;
    int id;
    Address address;
    char phnum[100];
    int age;
    char email[100];
}
members;
typedef struct
{
    char isbn[100];
    int id;
    form  isd,rd,rded;
}
borr;

void deleter(books*,int*);
void insert (books* d,int* a);
void RemoveSpaces(char* source);
void decap(char* t);
void SFB(books *det,int a);
void ac(books *det,int a);
void deleter(books* d,int* q);
void borrow(borr* b,int* o,members* m,int* c,books* d,int* a);
int CFI(books* d,int* a);
void Ret(borr* b,int* o,members* m,int* w,books* d,int* a);
void clearScreen();
void registertaion(members* mem,int* counter);
void Leave(borr* b,int* o,members* m,int* w);
void overdue(borr* b,int *w,books* d,int *o);
void Popular(borr* b,int* w,books* d,int* a);
void Read_Books(books* det,int* a);
void Print_Books(books* det,int* a);
void Read_Members(members* mem,int* mcounter);
void Print_Members(members* mem,int* mcounter);
void Read_Borrows(borr* bor,int* bcounter);
void Print_Borrows(borr* bor,int* bcounter);

int main()
{
    borr bor[100];
    members mem[100];
    books det[100];
    int  mcounter=0,bcounter=0,a=0,o=3,i=0,count=0;
    char x,y,z;

   Read_Books(det,&a);

   Read_Members(mem,&mcounter);

   Read_Borrows(bor,&bcounter);

    sys str_t;
    GetSystemTime(&str_t);

    do
    {
        printf("Today's Date:%d/%d/%d \n\n\n",str_t.wDay,str_t.wMonth,str_t.wYear);
        printf("(1)Book Management\n\n");
        printf("(2)Members Management\n\n");
        printf("(3)Borrow Management \n\n");
        printf("(4)Administrative Actions \n\n");
        printf("(5)Save Changes \n\n");
        printf("(6)Exit \n\n");
        printf("(7)Print Files\n\n");
        printf("(8)Clear Screen\n\n");
        printf("Enter Command: ");
        x=getch();


        if(x==49)
        {system("CLS");
        printf("*****************BOOK MANAGMENT*****************\n");
            printf("(1)Insert a new book \n\n");
            printf("(2)Search \n\n");
            printf("(3)Add new copies\n\n");
            printf("(4)Delete\n\n");
            printf("(0)Return to main menu\n\n");
            printf("Enter Command: ");
            z=getch();

            system("CLS");


            if(z==48)
                y=z;
            if(z==49)
                {insert(det,&a);
                 system("CLS");
                 printf("Book Added Successfully.\n\n");
                }
            if(z==50)
            {
                o=a;
                SFB(det,o);
            }
            if(z==51)
            {o=a;
                ac(det,o);
                }
            if(z==52)
                deleter(det,&a);
                printf("\n\n");
                 y=48;
        }
        if(x==50)
        {   system("CLS");
        printf("*****************Member MANAGMENT*****************\n");
            printf("(1)Register a New Member\n\n");
            printf("(2)Remove Member\n\n");
            printf("(0)Return to Main Menu\n\n");
            printf("Enter Command: ");
            z=getch();
             system("CLS");
            if(z==49){

            registertaion(mem,&mcounter);
               y=48;
             printf("\n\n");

            }

            if (z==50)
            {

                Leave(bor,&bcounter,mem,&mcounter);
                y=48;

            }

            if(z==48)
                y=z;

        }
        if(x==51)
        {   system("CLS");
        printf("*****************BORROW MANAGMENT*****************\n");
            printf("(1)Borrow\n\n");
            printf("(2)Return a book\n\n");
            printf("(0)Return to main menu\n\n");
            printf("Enter Command: ");
            z=getch();
             system("CLS");
            if(z==48)
                y=z;
            if(z==49)
                borrow(bor,&bcounter,mem,&mcounter,det,&a);
                y=48;
            if(z==50)
                Ret(bor,&bcounter,mem,&mcounter,det,&a);
                y=48;
                  printf("\n\n");
        }
        if(x==52)
        {   system("CLS");
        printf("*****************ADMENSTRATIVE MANAGMENT*****************\n");
            printf("(1)Overdue\n\n");
            printf("(2)Popular\n\n");
            printf("(0)Return to main menu\n");
            printf("Enter Command: ");
            z=getch();
            system("CLS");
            if(z==48)
                y=z;
                 system("CLS");
            if(z==49)
                overdue(bor,&bcounter,det,&a);
                y=48;

            if (z==50)
                Popular(bor,&bcounter,det,&a);
                printf("\n\n");
                y=48;


        }
        if(x==53)
        { system("CLS");
              save_book(det,&a);
              save_member(mem,&mcounter);
              save_borrow(bor,&bcounter);
              printf("Saved successfully \n\n\n");
              y=48;

        }
        if(x==54)
        {   system("CLS");
            printf("*****************Exit*****************\n");
            printf("(1)Save and Exit\n\n");
            printf("(2)Exit without saving\n\n");
            printf("(0)Return to main menu\n\n");
            printf("Enter Command: ");
            z=getch();
             system("CLS");
            if(z==48)
                y=z;
            if(z==49){
              save_book(det,&a);
              save_member(mem,&mcounter);
              save_borrow(bor,&bcounter);
              break;
            }
                if(z==50)
                break;
        }
        if (x==56)
             system("CLS");
             y=48;
        if(x==55)
        {
           system("CLS");
        printf("*************PRINT FILES*************");
        printf("\n(1)Print books\n");
        printf("(2)Print members\n");
        printf("(3)print borrows\n");
        printf("(0)Return to main menu\n");
        printf("Enter command:");
        z=getch();
           system("CLS");
        if(z==49)
        Print_Books(det,&a);
        printf("\n");
        if(z==50)
         Print_Members(mem,&mcounter);
        if(z==51)
        Print_Borrows(bor,&bcounter);
        if(z==48)
         y=z;

        }

    }
    while(y==48);


    return 0;
}
void insert (books* d,int* a)
{
    system("CLS");
    int f,t;
    int flag=0;
    int check[10];

    printf("Enter the Book name: ");
    scanf("%[^\n]s",d[*a].title);
    printf("enter the author name: ");
    scanf(" %[^\n]s",d[*a].author);
    printf("Enter the publisher name: ");
    scanf(" %[^\n]s",d[*a].publisher);
    printf("Enter the ISBN (International Standard Book Number) : ");
    scanf(" %[^\n]s",d[*a].isbn);
    f=CFI(d,a);
    while(!f)
    {
        printf("Error Non-Numerical Values\n\n");
        printf("Enter The ISBN Again: ");
        scanf(" %[^\n]s",d[*a].isbn);
        f=CFI(d,a);
    }
    printf("Enter the number of copies will be added: ");
    scanf("%d",&d[*a].tc);
    d[*a].ac=d[*a].tc;
    printf("Enter the date of publishing in this form day/month/year \n");
    scanf("%d/%d/%d",&d[*a].date.day,&d[*a].date.mon,&d[*a].date.year);
    printf("confirmation of the date entered\n");
     do
            {
                printf("Enter the DAY only: ");
                scanf("%d",&check[0]);
            }
            while (check[0]>31 || check[0]<0 || check[0]==0);
            do
            {
                printf("Enter the Month only: ");
                scanf("%d",&check[1]);
            }
            while (check[1]>12 || check[1]<0 || check[1]==0  );
            do
            {
                printf("Enter the Year only: ");
                scanf("%d",&check[2]);
            }
            while(check[2]>2017 || check[2]<1960);
    while(!flag)
    {
        if (check[0]==d[*a].date.day && check[1]==d[*a].date.mon && check[2]==d[*a].date.year)
        {
            printf("Confirmed");
            flag=1;
        }
        else
        {
            printf("\nNot Matched\n\n");
            printf("Enter the date of publishing in this form day/month/year \n");
            scanf("%d/%d/%d",&d[*a].date.day,&d[*a].date.mon,&d[*a].date.year);
            printf("CONFIRMATION of the Date Entered:\n");
            do
            {
                printf("Enter the DAY only: ");
                scanf("%d",&check[0]);
            }
            while (check[0]>31 || check[0]<0);
            do
            {
                printf("Enter the Month only: ");
                scanf("%d",&check[1]);
            }
            while (check[1]>12 || check[1]<0);
            do
            {
                printf("Enter the Year only: ");
                scanf("%d",&check[2]);
            }
            while(check[2]>2017 || check[2]<0);
        }
    }
    printf("\nEnter the Category of the Book: ");
    scanf(" %[^\n]s",d[*a].category);
    *a=*a+1;
}
void RemoveSpaces(char* source)
{
    char* i = source;
    char* j = source;
    while(*j != 0)
    {
        *i = *j++;
        if(*i != ' ')
            i++;
    }
    *i = 0;
}
void decap(char* t)
{
    int i;
    for(i=0; i<=strlen(t); i++)
    {
        if(t[i]>=65 && t[i]<=92)
        {
            t[i]=t[i]+32;
        }
    }
}
void SFB(books *det,int a)
{
    system("CLS");
    int i,f=0,x;
    char t[100],stepnd[100][100];
    printf("Search by:\n\n(1)Name\n\n(2)ISBN\n\n(3)Category\n\n(4)Author Name\n\n Enter: ");
    x=getch();
    if(x==49)
    {
        printf("Books name please -->  ");
        scanf(" %[^\n]s",t);
        decap(t);
        RemoveSpaces(t);
        for(i=0; i<a; i++)
        {
            strcpy(stepnd[i],det[i].title);
            RemoveSpaces(stepnd[i]);
        }
        for(i=0; i<a; i++)
        {
            if(strstr(stepnd[i],t)!=0)
            {
                printf("%s\n",det[i].title);
                f=1;
            }
        }
        if(f!=1)
            printf("Not found ");
    }
    else if(x==50)
    {
        printf("ISBN Please --> ");
        scanf(" %[^\n]s",t);
        RemoveSpaces(t);
        for(i=0; i<a; i++)
        {
            strcpy(stepnd[i],det[i].isbn);
            RemoveSpaces(stepnd[i]);
        }
        for(i=0; i<a; i++)
        {
            if(strcmp(stepnd[i],t)==0)
            {
                printf("%s\n",det[i].title);
                f=1;
            }
        }
        if(f!=1)
            printf("Not found ");
    }
    else if(x==51)
    {
        printf("Category Please --> ");
        scanf(" %[^\n]s",t);
        RemoveSpaces(t);
        for(i=0; i<a; i++)
        {
            strcpy(stepnd[i],det[i].category);
            RemoveSpaces(stepnd[i]);
        }
        for(i=0; i<a; i++)
        {
            if(strstr(stepnd[i],t)!=0)
            {
                printf("%s\n",det[i].title);
                f=1;
            }
        }
        if(f!=1)
            printf("Not found ");
    }
    else if (x==52)
    {
        printf("Author Please --> ");
        scanf(" %[^\n]s",t);
        RemoveSpaces(t);
        for(i=0; i<a; i++)
        {
            strcpy(stepnd[i],det[i].author);
            RemoveSpaces(stepnd[i]);
        }
        for(i=0; i<a; i++)
        {
            if(strstr(stepnd[i],t)!=0)
            {
                printf("%s\n",det[i].title);
                f=1;
            }
        }
        if(f!=1)
            printf("Not found ");
    }

}
void ac(books *det,int a)
{
    system("CLS");
    char i[50];
    int q,f,s,n;
    printf("enter the book ISBN: ");
    scanf(" %[^\n]s",i);
    for(q=0; q<a; q++)
    {
        if (strcmp(det[q].isbn,i)==0)
        {
            n=q;
            f=1;
        }
    }
    if (f==1)
    {
        printf("Enter the Number of Copies addded : \n");
        scanf("%d",&s);
        printf("Current copies : %d\n",det[n].tc);
        printf("Added Copies: %d\n",s);
        det[n].tc=det[n].tc+s;
        det[n].ac=det[n].ac+s;
        printf("New Number of copies: %d\n",det[n].tc);
        printf("Number of Available copies: %d\n",det[n].ac);
    }
    else
    {
        printf("Not Found");
    }
}
void deleter(books* d,int* q)
{
    system("CLS");
    char u[30];
    int c,y,x,f,i;
    y=*q;
    printf("Enter the ISBN:    ");
    scanf(" %[^\n]s",u);
    for(i=0; i<y; i++)
    {
        if (strstr(d[i].isbn,u)!=0)
        {
            f=1;
            x=i;
        }
    }
    if(f==1)
    {
        printf("Delete this Book (%s)?!\n(1) Yes\n(2) No\n",d[x].title);
        c=getch();
        if(c==49)
        {
            strcpy(d[x].title,d[y-1].title);
            strcpy(d[x].isbn,d[y-1].isbn);
            strcpy(d[x].author,d[y-1].author);
            strcpy(d[x].publisher,d[y-1].publisher);
            strcpy(d[x].category,d[y-1].category);
            d[x].ac=d[y-1].ac;
            d[x].tc=d[y-1].tc;
            d[x].date.day=d[y-1].date.day;
            d[x].date.mon=d[y-1].date.day;
            d[x].date.year=d[y-1].date.day;
            y=y-1;
            *q=y;
        }
    }
    else
    {
        printf("the Book is not found");
    }
}
void borrow(borr* b,int* o,members* m,int* c,books* d,int* a)
{
    system("CLS");
    int qq=0,check[5],count=0,i,fl=0,flag=0,id,v=0,x,y,z;
    char isbn[100];
    x=*a;
    y=*o;
    z=*c;
    printf("number of Borrows Before %d",*o);
    printf("\nEnter the ISBN: \n");
    scanf("%s",isbn);
    for (i=0; i<x; i++)
    {
        if (strcmp(d[i].isbn,isbn)==0 )
        {
            flag=1;
            v=i;
        }
    }
    if(flag)
    {
        printf("Book is Found");
        if(d[v].ac>0)
            printf(" And Available\n");
        else
            printf(" but Not Available");

        printf("\nEnter the ID: ");
        scanf("%d",&id);
        while (id<5000)
        {
            printf("Wrong ID\nEnter the ID: ");
            scanf("%d",&id);
        }
        for (i=0; i<y; i++)
        {
            if(id==b[i].id && b[i].rded.day==0)
                count++;
        }
        if(count<3)
        {
            strcpy(b[y].isbn,isbn);
            b[y].id=id;
            sys str_t;
            GetSystemTime(&str_t);
            b[y].isd.day=str_t.wDay;
            b[y].isd.mon=str_t.wMonth;
            b[y].isd.year=str_t.wYear;
            b[y].rd.day=str_t.wDay;

            if(str_t.wMonth==12)
            {
                b[y].rd.mon=1;
                b[y].rd.year=str_t.wYear + 1;
            }
            else
            {
                b[y].rd.mon =str_t.wMonth + 1;
                b[y].rd.year=str_t.wYear;
            }

            b[y].rded.day=0;
            b[y].rded.mon=0;
            b[y].rded.year=0;
            d[v].ac--;


            printf("\nMember is allowed to Borrow\nThe Borrowed Book name: %s\nBorrowed Date %d/%d/%d\nReturn Date %d/%d/%d\n",d[v].title,str_t.wDay,str_t.wMonth,str_t.wYear,b[y].rd.day,b[y].rd.mon,b[y].rd.year);
            y++;
            *o=y;
            printf("total borrows %d",*o);
        }
        else
            printf("\nMember Exceeded Limit of Borrowing ");

    }
    else
        printf("Book Not found\n");

}
int CFI(books* d,int* a)
{
    int i,f;
    char ph[20];
    strcpy(ph,d[*a].isbn);
    for (i=0; i<a; i++)
    {
        if(ph[i]>47 && ph[i]<58)
            f=1;
        else
            f=0;
        return f;

    }

}
void Ret(borr* b,int* o,members* m,int* w,books* d,int* a)
{
    system("CLS");
    sys str_t;
    GetSystemTime(&str_t);
    int x,i,f,v,q,z,id;
    char   t[100];
    printf("\nEnter the ISBN --> ");
    scanf("%s",t);
    printf("Enter the Member's ID --> ");
    scanf("%d",&id);
    for(i=0; i<*o; i++)
    {
        if(strcmp(b[i].isbn,t)==0 && id==b[i].id)
        {
            v=i;
            f=1;
        }

    }

    if (f==1)
    {
        b[v].rded.day=str_t.wDay;
        b[v].rded.mon=str_t.wMonth;
        b[v].rded.year=str_t.wYear;

        for(i=0; i<*a; i++)
        {
            if(strcmp(d[i].isbn,t)==0)
            {
                q=i;
            }

        }

        x=b[v].id;
        for(i=0; i<*w; i++)
        {
            if(m[i].id==x)
            {
                z=i;

            }

        }

        d[q].ac++;
        printf("The Book (%s) is Returned by %s %s, Taken %d/%d/%d ,Today %d/%d/%d \n",d[q].title,m[z].name.first,m[z].name.last,b[v].rd.day,b[v].rd.mon,b[v].rd.year,b[v].rded.day,b[v].rded.mon,b[v].rded.year);
        printf("%s,%d,%d/%d/%d,%d/%d/%d,%d/%d/%d",b[v].isbn,b[v].id,b[v].isd.day,b[v].isd.mon,b[v].isd.year,b[v].rd.day,b[v].rd.mon,b[v].rd.year,b[v].rded.day,b[v].rded.mon,b[v].rded.year);
    }
    else printf("not found");


}
void clearScreen()
{

    if (system("CLS")) system("clear");

}
void registertaion(members* mem,int* counter)
{
   system("CLS");

    int i;
    printf("Enter The Last Name: ");
    scanf("%s",mem[*counter].name.last);
    printf("Enter The first Name: ");
    scanf("%s",mem[*counter].name.first);
    printf("Enter The address {\n");
    printf("building number : ");
    scanf("%s",mem[*counter].address.build);
    printf("street name : ");
    scanf(" %[^\n]s",mem[*counter].address.sreet);
    printf("city : ");
    scanf("%s",mem[*counter].address.city);
    printf("Enter the phone number : ");
    scanf("%s",mem[*counter].phnum);
    printf("Enter the age :");
    scanf("%d",&mem[*counter].age);
    printf("Enter the email address: ");
    scanf("%s",mem[*counter].email);
    mem[*counter].id=5000+ *counter;
    printf("Id %d",mem[*counter].id);
    *counter=*counter +1;
}
void Leave(borr* b,int* o,members* m,int* w)
{
    system("CLS");
    int id,i,v,f=0,flag=0;
    char s,y,n;
    printf("Member ID --> ");
    scanf("%d",&id);
    while (id<5000 || id>5999)
    {
        printf("Wrong ID\nEnter the ID: ");
        scanf("%d",&id);
    }
    for (i=0; i<*w; i++)
    {
        if(id==m[i].id)
            flag=1;
        v=i;
    }
    if (flag==1)
    {
        for (i=0; i<*o; i++)
        {
            if(id==b[i].id)
            {


                if(b[i].rded.day==0)
                    f=1;
            }
        }
        if(f==1)
        {
            printf("There is UnReturned Books\n\n Return the Books first Then You can leave");
        }
        else
        {
            printf("%s %s %d %s %s %s %s %s %d",m[v].name.last,m[v].name.first,m[v].age,m[v].address.build,m[v].address.sreet,m[v].address.city,m[v].phnum,m[v].email,m[v].id);
            printf("\nAre you sure you want to delete this member ? [Y][N]\n");
            s=getch();
            if(s==121){
            strcpy(m[v].name.first,"0");
            strcpy(m[v].email,"0");
            strcpy(m[v].phnum,"0");
            strcpy(m[v].name.last,"0");
            strcpy(m[v].address.sreet,"0");
            strcpy(m[v].address.city,"0");
            strcpy(m[v].address.build,"0");
            m[v].age=0;
            m[v].id=0;
            printf(" This Member is DELETED\n\n");
                     }
                     if(s==110)
                         system("CLS");

        }
    }
    else
        printf("Member not found\n\n");

}
void overdue(borr* b,int *w,books* d,int *o)
{
    system("CLS");
    int f,i,q,counter=1;
    sys str_t;
    GetSystemTime(&str_t);
    for (i=0; i<*w; i++)
    {

        if(b[i].rd.day>str_t.wDay)
        {
            for(q=0; q<*o; q++)
            {
                f=1;
                if(strcmp(b[i].isbn,d[q].isbn)==0)
                {
                    printf("%d)%s\n",counter,d[q].title);
                    counter++;
                }
            }
        }
    }
    if (f!=1)
        printf("No OverDue Books");

}
void Popular(borr* b,int* w,books* d,int* a)
{
    system("CLS");
    int i,q,counter=0,top[5][5]= {0};
    for(i=0; i<*a; i++)
    {
        counter=0;
        for(q=0; q<*w; q++)
        {
            if(strcmp(b[q].isbn,d[i].isbn)==0)
                counter++;
        }

        if(top[4][1]<counter)
        {
            if(top[3][1]<counter)
            {
                if(top[2][1]<counter)
                {
                    if(top[1][1]<counter)
                    {
                        if(top[0][1]<counter)
                        {
                            top[4][0]=top[3][0];
                            top[4][1]=top[3][1];
                            top[3][0]=top[2][0];
                            top[3][1]=top[2][1];
                            top[2][0]=top[1][0];
                            top[2][1]=top[1][1];
                            top[1][0]=top[0][0];
                            top[1][1]=top[0][1];
                            top[0][1]=counter;
                            top[0][0]=i;
                        }
                        else
                        {
                            top[4][0]=top[3][0];
                            top[4][1]=top[3][1];
                            top[3][0]=top[2][0];
                            top[3][1]=top[2][1];
                            top[2][0]=top[1][0];
                            top[2][1]=top[1][1];
                            top[1][1]=counter;
                            top[1][0]=i;
                        }
                    }
                    else
                    {
                        top[4][0]=top[3][0];
                        top[4][1]=top[3][1];
                        top[3][0]=top[2][0];
                        top[3][1]=top[2][1];
                        top[2][1]=counter;
                        top[2][0]=i;

                    }
                }
                else
                {
                    top[4][0]=top[3][0];
                    top[4][1]=top[3][1];
                    top[3][1]=counter;
                    top[3][0]=i;


                }

            }
            else
            {
                top[4][0]=counter;
                top[4][1]=i;

            }

        }

    }
    printf("*****************Most Popular*****************\n");
    for (i=0; i<5; i++)
    {
        printf("%d)%s\n\n",i+1,d[top[i][0]].title);
    }
}
void Read_Books(books* det,int* a)
{
     FILE* fbook;
   *a=0;
 fbook=fopen("books.txt","r");
    if(fbook !=NULL)
    {
        while(!feof(fbook))
        {
            fscanf(fbook,"%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%s",det[*a].title,det[*a].author,det[*a].publisher,det[*a].isbn,&det[*a].date.day,&det[*a].date.mon,&det[*a].date.year,&det[*a].tc,&det[*a].ac,det[*a].category);
            fscanf(fbook,"\n");
            *a=*a+1;
        }
    }
    else
    {
        printf("File Not Found");
    }
    fclose(fbook);


}
void Print_Books(books* det,int* a)
{
    int i;
    for(i=0;i<*a;i++)
printf("Book %d)%s,%s,%s,%s,%d/%d/%d,%d,%d,%s\n\n",i+1,det[i].title,det[i].author,det[i].publisher,det[i].isbn,det[i].date.day,det[i].date.mon,det[i].date.year,det[i].tc,det[i].ac,det[i].category);

}
void Read_Members(members* mem,int* mcounter)
{
    FILE* fbook;

fbook=fopen("members.txt","r");
    if(fbook !=NULL)
    {
        while(!feof(fbook))
        {
            fscanf(fbook,"%[^,],%[^,],%d,%d,%[^,],%[^,],%[^,],%[^,],%s",mem[*mcounter].name.last,mem[*mcounter].name.first,&mem[*mcounter].id,&mem[*mcounter].age,mem[*mcounter].address.build,mem[*mcounter].address.sreet,mem[*mcounter].address.city,mem[*mcounter].phnum,mem[*mcounter].email);
            fscanf(fbook,"\n");
            *mcounter=*mcounter+1;
        }
    }
    else
    {
        printf("File Not Found");
    }
    fclose(fbook);

}
void Print_Members(members* mem,int* mcounter)
{
    int i,v=0;
    for(i=0;i<*mcounter;i++)
    if(strcmp(mem[i].phnum,"0")!=0)
    {printf("\nMember %d) %s,%s,%d,%s,%s,%s,%s,%d,%s \n\n",i+1-v,mem[i].name.last,mem[i].name.first,mem[i].id,mem[i].address.build,mem[i].address.sreet,mem[i].address.city,mem[i].phnum,mem[i].age,mem[i].email);
}
else
{
    v++;
}
}
void Read_Borrows(borr* bor,int* bcounter)
{
    FILE* fbook;

    fbook=fopen("borrows.txt","r");
    if(fbook !=NULL)
    {
        while(!feof(fbook))
        {
            fscanf(fbook,"%[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",bor[*bcounter].isbn,&bor[*bcounter].id,&bor[*bcounter].isd.day,&bor[*bcounter].isd.mon,&bor[*bcounter].isd.year,&bor[*bcounter].rd.day,&bor[*bcounter].rd.mon,&bor[*bcounter].rd.year,&bor[*bcounter].rded.day,&bor[*bcounter].rded.mon,&bor[*bcounter].rded.year);
            fscanf(fbook,"\n");
            *bcounter=*bcounter+1;
        }
    }
    else
    {
        printf("File Not Found");
    }
    fclose(fbook);

}
void Print_Borrows(borr* bor,int* bcounter)
{
    int i;

    for(i=0;i<*bcounter;i++)
    printf("\nBorrow %d) %s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",i+1,bor[i].isbn,bor[i].id,bor[i].isd.day,bor[i].isd.mon,bor[i].isd.year,bor[i].rd.day,bor[i].rd.mon,bor[i].rd.year,bor[i].rded.day,bor[i].rded.mon,bor[i].rded.year);

}

void save_book(books *det,int* a){
    FILE* fbook;
    fbook=fopen("books.txt","w");
    int i;
    for(i=0;i<*a;i++)
    {
fprintf(fbook,"%s,%s,%s,%s,%d,%d,%d,%d,%d,%s\n",det[i].title,det[i].author,det[i].publisher,det[i].isbn,det[i].date.day,det[i].date.mon,det[i].date.year,det[i].tc,det[i].ac,det[i].category);
}
fclose(fbook);
}
void save_member(members* mem,int* mcounter){
FILE* fmem;
fmem=fopen("members.txt","w");
int i;
for(i=0;i<*mcounter;i++){
    fprintf(fmem,"%s,%s,%d,%d,%s,%s,%s,%s,%s\n",mem[i].name.last,mem[i].name.first,mem[i].id,mem[i].age,mem[i].address.build,mem[i].address.sreet,mem[i].address.city,mem[i].phnum,mem[i].email);
}
fclose(fmem);
}
void save_borrow(borr* bor,int* bcounter){
FILE* fborrow;
fborrow=fopen("borrows.txt","w");
int i;
for(i=0;i<*bcounter;i++){
    fprintf(fborrow,"%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",bor[i].isbn,bor[i].id,bor[i].isd.day,bor[i].isd.mon,bor[i].isd.year,bor[i].rd.day,bor[i].rd.mon,bor[i].rd.year,bor[i].rded.day,bor[i].rded.mon,bor[i].rded.year);
}
}
