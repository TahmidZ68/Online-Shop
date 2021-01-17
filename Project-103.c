#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define ERROR puts("\n\t\t\t\t\t\t    =================\n\t\t\t\t\t\t   |  \a   ERROR!	   |  \n\t\t\t\t\t\t   =================")
//display tags functions
void TITLE();
int comptag(int);
void CUSTOMERPANEL();
void ADMINPANEL();
int stpur(int);
//STORE Purchase function
int Purchase();
//Admin database
void Adminpermit();

FILE *fptr;
//Password verifier
int Access();
//Adminpermit functions
void Add();
void Edit();
void Delete();
void Search();
void View();
//global structure declaration
struct store
{
    char ProductId[100];
    char ProductName[100];
    int quantity;
    int  want;
    float price;
} ;

int addition=1;
int count;
int cas=0;


//start of progProductName
int main()
{
    struct store STORE;
    int choice;
    int acc;
    TITLE();
    comptag(0);
    system("color A");
    puts("\n\n\t\t\t\t\tWhat would you like to do?");
    puts("	\n\t\t\t\t\t1. Wish to purchase as a Customer:");
    puts("	\t\t\t\t2. Login as Authorized Administrator");
    puts("	\t\t\t\t3. Exit");
    printf("\n\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1 :
    {
        Purchase();
        break;
    }
    case 2 :
    {
        system("color B");
        acc=Access();
        if(acc==1)
            Adminpermit();
        else
        {
            getch();
            main();
        }
    }
    default :
    {
        comptag(0);
        system("color D");
        puts("\n\n\n\n\n\n\t\t\t\t\t\t  Thank you!!!");
        puts("\n\t\t\t\t\tVisit Again in our On-line Shop");
        fclose(fptr);
        getch();
        exit(0);
    }
    }
}
void Adminpermit()
{
    system("color E");
    int choice1;
    fptr=fopen("informationfile.txt","ab+");
    fseek(fptr,0,0);
    comptag(0);
    ADMINPANEL();
    printf("\t\t\t\t\t\t1. Add new product");
    printf("\n\t\t\t\t\t\t2. View available products");
    printf("\n\t\t\t\t\t\t3. Edit existing product");
    printf("\n\t\t\t\t\t\t4. Search for an product");
    printf("\n\t\t\t\t\t\t5. Delete any product ");
    printf("\n\t\t\t\t\t\t6. Return to previous screen\n");
    printf("\n\n\t\t\t\t\t\tEnter a choice: ");
    scanf("%d",&choice1);
    switch (choice1)
    {
    case 1 :
        Add();
    case 2 :
        View();
    case 3 :
        Edit();
    case 4 :
        Search();
    case 5 :
        Delete();
    case 6 :
        main();
    }
}
void Add()
{
    struct store STORE;
    int offset;
    comptag(0);
    char id1[100];
    char id2[100];
    ADMINPANEL();
    printf("\n\t\t\t         ***** Current Selection: Addition of new stock *****");
    printf("\n\t\t\t   ");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    fflush(stdin);


    printf("\n\n\t\t\t\t\t\t     Product Id: ");
    gets(id1);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        if(((strcmpi(STORE.ProductId,id1))==0))
        {


            ERROR;
            printf("\n\t\t\t\t\t   Sorry. This product already exists.\n");
            printf("\n\t\t\t\t    Press any key to start adding another product...\n");
            getch();
            Add();
        }
    }
    strcpy(STORE.ProductId,id1);


    printf("\n\t\t\t\t\t\t     Product name: ");
    gets(id2);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        if(((strcmpi(STORE.ProductName,id2))==0))
        {

            printf("\nSame product name with different id added. \n");

            getch();
            Add();
        }
    }
    strcpy(STORE.ProductName,id2);


    printf("\n\t\t\t\t\t\t     Quantity: ");
    scanf("%d",&STORE.quantity);
    printf("\n\t\t\t\t\t\t     Price: ");
    scanf("%f",&STORE.price);
    //offset=(addition-1)*sizeof(STORE);
    //fseek(fptr,offset,0);
    fwrite(&STORE,sizeof(STORE),1,fptr);
    //addition++;
    printf("\n\t\t\t\t    Press any key to return in main menu...\n");
    getch();
    //if(addmore=='Y' || addmore=='y') {fclose(fptr); Add();}
    //else {
    fclose(fptr);
    Adminpermit();
}
void View()
{
    struct store STORE;
    comptag(0);
    ADMINPANEL();
    printf("\n\t\t\t         ***** Current Selection: Viewing available stock *****");
    printf("\n\t\t\t   ");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    rewind(fptr);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        printf("\n\t\t");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

        printf("\n\t\t\t\t\t\tProduct Id: ");
        puts(STORE.ProductId);
        printf("\t\t\t\t\t\tProductName: ");
        puts(STORE.ProductName);


        printf("\t\t\t\t\t\tQuantity: ");
        printf("%d",STORE.quantity-cas);
        printf("\n\t\t\t\t\t\tPrice: ");
        printf("%.3fTk",STORE.price);
    }
    printf("\n\t\t\t\t    Press any key to return main menu...\n");
    getch();
    system("cls");
    fclose(fptr);
    Adminpermit();
}

void Edit()
{
    struct store STORE;
    fflush(stdin);
    comptag(0);
    ADMINPANEL();
    FILE *tptr;
    printf("\n\t\t\t\t     ***** Current selection: Modify your products *****");
    printf("\n\t\t\t   ");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    char id[30];
    int a=0;
    char option[100];

    printf("\n\n\t\t\t\t\t       I want to search and edit by : ");
    gets(option);

    if(strcmpi(option,"Id")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {


            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t       Enter product id to Edit: ");
            gets(id);
            tptr=fopen("temporary.txt","wb");
            rewind(fptr);
            int flag=0, flag1=0, flag2;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductId,id)==0)
                {
                    flag1++;
                    flag2=1;
                    fflush(stdin);
                    printf("\n\t\t\t\t\t         \"%s\" exists in database!\n",id);
                    flag=10;
                    printf("\n\t\t\t\t\t           New Product Id : ");
                    gets(STORE.ProductId);

                    printf("\n\n\t\t\t\t\t           New Product Name : ");
                    gets(STORE.ProductName);


                    printf("\n\t\t\t\t\t           New Quantity: ");
                    scanf("%d",&STORE.quantity);
                    printf("\n\t\t\t\t\t           Price: ");
                    scanf("%f",&STORE.price);
                    if(flag1==1 && flag2==1)
                    {
                        fseek(tptr,0,0);
                    }
                    else
                    {
                        fseek(tptr,(flag1-1)*sizeof(STORE),0);
                    }
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else
                {
                    flag1++;
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }

            }
            if(flag!=10)
            {
                ERROR;
                puts("\n\t\t\t\t\t          No such record exists!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("informationfile.txt");
            rename("temporary.txt","informationfile.txt");
            fptr=fopen("informationfile.txt","ab+");
            printf("\n\t\t\t\t\t        Edit another product? (Y/N)? ");
            fflush(stdin);
            another = getche();
        }
    }


    else if(strcmpi(option,"Name")==0)
    {
        char another='y';
        while(another=='y' || another=='Y')
        {


            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t       Enter product Name to Edit: ");
            gets(id);
            tptr=fopen("temporary.txt","wb");
            rewind(fptr);
            int flag=0, flag1=0, flag2;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductName,id)==0)
                {
                    flag1++;
                    flag2=1;
                    fflush(stdin);
                    printf("\n\t\t\t\t\t         \"%s\" exists in database!\n",id);
                    flag=10;
                    printf("\n\t\t\t\t\t           New Product Id : ");
                    gets(STORE.ProductId);

                    printf("\n\n\t\t\t\t\t           New Product Name : ");
                    gets(STORE.ProductName);


                    printf("\n\t\t\t\t\t           New Quantity: ");
                    scanf("%d",&STORE.quantity);
                    printf("\n\t\t\t\t\t           Price: ");
                    scanf("%f",&STORE.price);
                    if(flag1==1 && flag2==1)
                    {
                        fseek(tptr,0,0);
                    }
                    else
                    {
                        fseek(tptr,(flag1-1)*sizeof(STORE),0);
                    }
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else
                {
                    flag1++;
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }

            }
            if(flag!=10)
            {
                ERROR;
                puts("\n\t\t\t\t\t          No such record exists!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("informationfile.txt");
            rename("temporary.txt","informationfile.txt");
            fptr=fopen("informationfile.txt","ab+");
            printf("\n\t\t\t\t\t        Edit another product? (Y/N)? ");
            fflush(stdin);
            another = getche();
        }
    }
    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    fclose(fptr);
    Adminpermit();
}
void Search()
{
    struct store STORE;
    int a=0;
    char id[30];
    comptag(0);
    ADMINPANEL();
    fptr=fopen("informationfile.txt","ab+");
    fflush(stdin);

    printf("\n\t\t\t\t     ***** Current selection: Search in available stock *****");
    printf("\n\t\t\t   ");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

    char option[100];

    printf("\n\n\t\t\t\t\t       I want to search by : ");
    gets(option);

    if(strcmpi(option,"Id")==0)
    {


        printf("\n\n\n\t\t\t\t\t      Enter product id to search: ");
        gets(id);


        while(fread(&STORE,sizeof(STORE),1,fptr)==1)
        {
            if(strcmpi(STORE.ProductId,id)==0)
            {
                puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\t    SEARCH QUERY MATCHED \n\t\t\t\t     -------------------------------------------------\n");
                printf("\n\n\t\t\t\t\t           Product Id: ");
                puts(STORE.ProductId);

                printf("\n\t\t\t\t\t           ProductName: ");
                puts(STORE.ProductName);


                printf("\n\t\t\t\t\t           Quantity: ");
                printf("%d",STORE.quantity);
                printf("\n\n\t\t\t\t\t           Price: ");
                printf("%.3fTk",STORE.price);
                a=1;
            }
        }
    }



    else if(strcmpi(option,"Name")==0)
    {
        printf("\n\n\n\t\t\t\t\t      Enter product Name to search: ");
        gets(id);

        while(fread(&STORE,sizeof(STORE),1,fptr)==1)
        {
            if(strcmpi(STORE.ProductName,id)==0)
            {
                puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\t    SEARCH QUERY MATCHED \n\t\t\t\t     -------------------------------------------------\n");
                printf("\n\n\t\t\t\t\t           Product Id: ");
                puts(STORE.ProductId);

                printf("\n\t\t\t\t\t           ProductName: ");
                puts(STORE.ProductName);


                printf("\n\t\t\t\t\t           Quantity: ");
                printf("%d",STORE.quantity);
                printf("\n\n\t\t\t\t\t           Price: ");
                printf("%.3fTk",STORE.price);
                a=1;
            }
        }
    }
    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    if (a!=1)
    {
        ERROR;
        printf("\n\t\t\t\t\t      %s doesn't exist in the database!\n",id);
    }
    printf("\n\t\t\t\t         Press any key to continue to previous menu...");
    getch();
    system("cls");
    fclose(fptr);
    Adminpermit();
}
void Delete()
{
    struct store STORE;
    fflush(stdin);
    comptag(0);
    ADMINPANEL();
    FILE *tptr;

    printf("\n\t\t\t\t     ***** Current selection: Deletion of existing products *****");
    printf("\n\t\t\t   ");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    char id[30];
    int a=0;
    char option[100];

    printf("\n\n\t\t\t\t\t       I want to delete by : ");
    gets(option);

    if(strcmpi(option,"Id")==0)
    {


        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t      Enter product id to delete: ");
            gets(id);
            tptr=fopen("tempdel.txt","wb");
            rewind(fptr);
            int flag=0;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {

                if(strcmpi(STORE.ProductId,id)!=0)
                {
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else if(strcmpi(STORE.ProductId,id)==0)
                {
                    puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\tProduct is successfully deleted \n\t\t\t\t     -------------------------------------------------\n");

                    flag=10;
                }
            }
            if(flag!=10)
            {
                ERROR;
                puts("\n\t\t\t\t\t         No such record exists!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("informationfile.txt");
            rename("tempdel.txt","informationfile.txt");
            fptr=fopen("informationfile.txt","ab+");
            printf("\n\t\t\t\t\tDelete another product out of stock? (Y/N)? ");
            fflush(stdin);
            another = getch();
        }
    }


    else if(strcmpi(option,"Name")==0)
    {


        char another='y';
        while(another=='y' || another=='Y')
        {
            fflush(stdin);
            printf("\n\n\n\t\t\t\t\t      Enter product Name to delete: ");
            gets(id);
            tptr=fopen("tempdel.txt","wb");
            rewind(fptr);
            int flag=0;
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {

                if(strcmpi(STORE.ProductName,id)!=0)
                {
                    fwrite(&STORE,sizeof(STORE),1,tptr);
                }
                else if(strcmpi(STORE.ProductName,id)==0)
                {
                    puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\tProduct is successfully deleted \n\t\t\t\t     -------------------------------------------------\n");

                    flag=10;
                }
            }
            if(flag!=10)
            {
                ERROR;
                puts("\n\t\t\t\t\t         No such record exists!");
            }
            fclose(fptr);
            fclose(tptr);
            remove("informationfile.txt");
            rename("tempdel.txt","informationfile.txt");
            fptr=fopen("informationfile.txt","ab+");
            printf("\n\t\t\t\t\tDelete another product out of stock? (Y/N)? ");
            fflush(stdin);
            another = getch();
        }
    }

    else
    {

        printf("\n\t\t\t\t\t     Enter Valid searching form");
    }
    fclose(fptr);
    Adminpermit();
}
void TITLE()
{
    system("cls");
    system("color E");
    printf("\n\n\n\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");



    printf("\n\n\n\t\t\t\t\t      On-line Shop Management System\n");
    printf("\n\t\t\t\t\t\t       Created by \n");
    printf("\n\t\t\t\t\t                 Tahmid\n");


    printf("\n\n\n\t\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
    puts("\n\t\t\t\t\t        Press any key to continue");
    getch();
}
int comptag(int bal)
{
    system("cls");
    printf("\n   =================================================================================================================\n");
    printf("\n\t\t\t\t\t\t   FTT On-line Shop \n");
    printf("\t\t\t\t\t    Your needs in your finger tips\n");
    printf("\n\n\t\t\t    Shop more than 500 tk to get Standard Deal(100 tk less) Discount!!!");
    printf("\n\n\n\t\t\t     Shop more than 2000 tk to get Mega Deal(500 tk less) Discount!!!");
    printf("\n\n\n\t\t\t    Shop more than 3000 tk and get free home delivery anywhere in Bangladesh!!!");
      printf("\n\n\n\t\t\t\t         Delivery Charge inside Dhaka is 60Tk!!!");
        printf("\n\n\n\t\t\t\t         Delivery Charge outside Dhaka is 100Tk!!!");
    printf("\n   =================================================================================================================\n");
}
int stpur(int bal)
{
    system("cls");
    printf("\n=================================================================================================================\n");
    printf("\n\t\t\t\t\t\tFTT On-line Shop \n");
    printf("\t\t\t\t\t  Your needs in your finger tips\n");
    printf("\n=================================================================================================================\n");
}
int Access()
{
    fflush(stdin);
    char admin[30];
    static char password[5];
    int a;
    printf("\n\t\t\t\tEnter Admin username: ");
    scanf("%s",&admin);
    if(strcmpi(admin,"DAWR")==0 || strcmpi(admin,"Fardin")==0 || strcmpi(admin,"Tahmid")==0)
    {
        puts("\n\n\t\t\t\tAdmin identity verified!");
        printf("\n\t\t\t\tEnter 3-digit database password: ");
        for(int i=0; i<3; i++)
        {
            password[i]=getch();
            if(password[i]=='\r')

            {
                break;
            }
            else
                printf("*");
        }
        if(strcmp(password,"103")==0)
        {
            puts("\a\n\n\n\t\t\t\t\tACCESS GRANTED");
            getch();
            a=1;
        }
        else
        {
            puts("\a\n\n\n\t\t\t\t\tACCESS DENIED!");
            a=0;
        }
    }
    else
    {
        comptag(0);
        puts("\a\n\n\n\t\t\t\t\t\t  UNKNOWN IDENTITY");
        a=0;
    }
    return a;
}
int Purchase()
{
    struct store STORE;
    system("color B");
    comptag(0);
    char product[100];
    float total=0,gtotal=0;
    CUSTOMERPANEL();
    fptr=fopen("informationfile.txt","ab+");
    puts("\n\n\n\t\t\t\t\t           Available products: \n\n");
    rewind(fptr);
    while(fread(&STORE,sizeof(STORE),1,fptr)==1)
    {
        printf("\n\t\t");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");


        printf("\n\n\t\t\t\t\t           Product Id: ");
        puts(STORE.ProductId);
        printf("\t\t\t\t\t           ProductName: ");
        puts(STORE.ProductName);
        printf("\t\t\t\t\t           Quantity: ");
        printf("%d",STORE.quantity-cas);
        printf("\n\t\t\t\t\t           Price: ");
        printf("%.3fTk",STORE.price);
        printf("\n");
    }
    puts("\n\n\t\t\t\t\t  Press any key to continue purchase");
    getch();
    comptag(0);



    while(1)
    {
        count++;

        fflush(stdin);

        char option[100];

        printf("\n\n\t\t\t\t\t       I want to Shop by : ");
        gets(option);

        if(strcmpi(option,"Id")==0)
        {

            printf("\n\n\t\t\t\t\t   Type 'Show Bill' if you are done with shopping");
            printf("\n\n\n\n\n\t\t\t\t\t   Enter the product id you want to buy: ");
            gets(product);

            if(strcmpi(product,"Show Bill")==0)
            {

            }
            //else if(strcmpi(STORE.ProductId,product)!=0){

            //}

            else
            {
                printf("\n\n\n\n\n\t\t\t\t\t   Enter the quantity of the product: ");

                scanf("%d",&STORE.want);

                cas=STORE.want;



            }
            comptag(0);
            rewind(fptr);
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductId,product)==0)
                {

                    if(STORE.quantity>=cas)
                    {

                        puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\t     YOU Have SELECTED \n\t\t\t\t     -------------------------------------------------\n");

                        total= cas*STORE.price;
                        printf("\n\n\t\t\t\t\t           Product Id: ");
                        puts(STORE.ProductId);
                        printf("\t\t\t\t\t           ProductName: ");
                        puts(STORE.ProductName);




                        printf("\t\t\t\t\t           Quantity: ");
                        printf("%d",cas);

                        printf("\n\t\t\t\t\t           Price: ");
                        printf("%.3fTk",STORE.price);

                        gtotal=gtotal+total;
                    }

                    else
                    {
                        system("color C");
                        printf("\n\n\t\t\t\t\t     Sorry, Our Product Is Out Of Stock");
                        printf("\n\n\t\t\t\t\t           Select other products");
                    }
                }

                else if(strcmpi(product,"Show Bill")==0)
                {
                    break;
                }

                /*  else
                  {
                      puts("\n\t\t\t\t\t              Not available!\n           \t\t\t\t\tPress any key to continue!");
                      getch();
                      Purchase();
                  }*/


            }

        }


        else if(strcmpi(option,"Name")==0)
        {

            printf("\n\n\t\t\t\t\t   Type 'Show Bill' if you are done with shopping");
            printf("\n\n\n\n\n\t\t\t\t\t   Enter the product Name you want to buy: ");
            gets(product);

            if(strcmpi(product,"Show Bill")==0)
            {

            }
            //else if(strcmpi(STORE.ProductId,product)!=0){

            //}

            else
            {
                printf("\n\n\n\n\n\t\t\t\t\t   Enter the quantity of the product: ");

                scanf("%d",&cas);



            }
            comptag(0);
            rewind(fptr);
            while(fread(&STORE,sizeof(STORE),1,fptr)==1)
            {
                if(strcmpi(STORE.ProductName,product)==0)
                {

                    if(STORE.quantity>=cas)
                    {

                        puts("\n\t\t\t\t     -------------------------------------------------\n\t\t\t\t\t\t     YOU Have SELECTED \n\t\t\t\t     -------------------------------------------------\n");

                        total= cas*STORE.price;
                        printf("\n\n\t\t\t\t\t           Product Id: ");
                        puts(STORE.ProductId);
                        printf("\t\t\t\t\t           ProductName: ");
                        puts(STORE.ProductName);




                        printf("\t\t\t\t\t           Quantity: ");
                        printf("%d",cas);

                        printf("\n\t\t\t\t\t           Price: ");
                        printf("%.3fTk",STORE.price);

                        gtotal=gtotal+total;
                    }

                    else
                    {
                        system("color C");
                        printf("\n\n\t\t\t\t\t     Sorry, Our Product Is Out Of Stock");
                        printf("\n\n\t\t\t\t\t           Select other products");
                    }
                }

                else if(strcmpi(product,"Show Bill")==0)
                {
                    break;
                }

                /*  else
                  {
                      puts("\n\t\t\t\t\t              Not available!\n           \t\t\t\t\tPress any key to continue!");
                      getch();
                      Purchase();
                  }*/


            }

        }

        else
        {

            printf("\n\t\t\t\t\t     Enter Valid searching form");
        }

        if((strcmpi(product,"Show Bill")==0) && gtotal!=0)

        {


           printf("\n\t\t");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\t\t\t\t\t\t\t\t\t ------------ Bill Receipt ------------");
            printf("\n\t\t");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

            printf("\n\t\        Product Id\t Product Name\t Ordered Quantity\t Price per Product\t Total Price ");
            printf("\n");


            printf("\n\t\             %s\t           %s\t            %d\t               %.3fTk\t           %.3fTk",STORE.ProductId,STORE.ProductName, cas,STORE.price,(STORE.price* cas));



            if(gtotal>=500 && gtotal<2000)
            {

                printf("\n\n\t\t\t\t\t\t  YOUR TOTAL BILL: %.3fTk",gtotal);
                float y=(gtotal-100);
                printf("\n\n\t\t\t\t\t     YOUR TOTAL BILL After Standard Deal Discount: %.3fTk",y);

                char coupon[100];
                printf("\n\n\t\t\t\t\t---Press enter if you do not have coupon code---");
                printf("\n\n\t\t\t\t\tEnter the Coupon Code to get 45Percent Discount:  ");
                gets(coupon);


                if((strcmpi(coupon,"Reza Sir")==0))
                {

                    float x =(y-(y*0.45));

                     printf("\n\n\t\t\t\t\tYOUR TOTAL BILL After Coupon Code Discount: %.3fTk",x);

                    char location[100];
                    printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);

                    if((strcmpi(location,"Dhaka")==0))
                    {

                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge: %.3fTk",x);
                        }
                        else
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge: %.3fTk",x+60);
                        }

                    }

                    else if((strcmpi(location,"Dhaka")!=0))
                    {
                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge(Outside Dhaka): %.3fTk",x);
                        }
                        else
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge(Outside Dhaka): %.3fTk",x+100);
                        }
                    }

                }
                else
                {
                    printf("\n\t\t\t\t\t\t       Wrong Coupon Code!!!");
                }
            }
            else if(gtotal>=2000)
            {

                printf("\n\n\t\t\t\t\t\t  YOUR TOTAL BILL: %.3fTk",gtotal);
                float y=(gtotal-500);
                printf("\n\n\t\t\t\t     YOUR TOTAL BILL After Mega Deal Discount: %.3fTk",y);

                char coupon[100];
                printf("\n\n\t\t\t\t\t---Press enter if you do not have coupon code---");
                printf("\n\n\t\t\t\t\tEnter the Coupon Code to get 45 Percent Discount:  ");
                gets(coupon);


                if((strcmpi(coupon,"Reza Sir")==0))
                {

                    float x =(y-(y*0.45));
                printf("\n\n\t\t\t\t\tYOUR TOTAL BILL After Coupon Code Discount: %.3fTk",x);
                    char location[100];
                    printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);

                    if((strcmpi(location,"Dhaka")==0))
                    {
                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge: %.3fTk",x);
                        }
                        else
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge: %.3fTk",x+60);
                        }
                    }

                    else if((strcmpi(location,"Dhaka")!=0))
                    {
                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge(Outside Dhaka): %.3fTk",x);
                        }
                        else
                        {

                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge(Outside Dhaka): %.3fTk",x+100);
                        }
                    }

                }
                else
                {
                    printf("\n\t\t\t\t\t\t       Wrong Coupon Code!!!");
                }
            }

            else
            {

                printf("\n\n\t\t\t\t\t\tYOUR TOTAL BILL: %.3fTk",gtotal);

                char coupon[100];
                printf("\n\n\t\t\t\t\t---Press enter if you do not have coupon code---");
                printf("\n\n\t\t\t\t\tEnter the Coupon Code to get 45 Percent Discount:  ");

                gets(coupon);


                if((strcmpi(coupon,"Reza Sir")==0))
                {
 printf("\n\n\t\t\t\t\tYOUR TOTAL BILL After Coupon Code Discount: %.3fTk",(gtotal-(gtotal*0.45)));
                    char location[100];
               printf("\n\n\t\t\t\t\t\tEnter your location: ");
                    gets(location);

                    if((strcmpi(location,"Dhaka")==0))
                    {

                        printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge: %.3fTk",(gtotal-(gtotal*0.45))+60);


                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge: %.3fTk",(gtotal-(gtotal*0.45)));
                        }
                        else
                        {

                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge: %.3fTk",(gtotal-(gtotal*0.45))+60);
                        }

                    }

                    else if((strcmpi(location,"Dhaka")!=0))
                    {

                        if(gtotal>=3000)
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with free delivery charge(Outside Dhaka): %.3fTk",(gtotal-(gtotal*0.45)));
                        }
                        else
                        {


                            printf("\n\n\t\t\t\t\tYOUR TOTAL BILL with delivery charge(Outside Dhaka): %.3fTk",(gtotal-(gtotal*0.45))+100);
                        }

                    }

                }
                else
                {
                    printf("\n\t\t\t\t\t\t       Wrong Coupon Code!!!");
                }

            }












            printf("\n\n\n\t\t\t\t\t      Press \"1\" to return to main screen");
            printf("\n\n\t\t\t\t   Opps!!! Forget to buy something? Press enter to buy again.");
            char afterpurchase;
            afterpurchase=getche();
            if (afterpurchase=='1')
            {
                fclose(fptr);
                main();
            }
        }
        else if((strcmpi(product,"Show Bill")==0) && gtotal==0)
        {

            printf("\n\n\t\t\t\t\tYou did not buy anything, your cart is empty");

            printf("\n\n\n\t\t\t\t\t      Press \"1\" to return to main screen");
            printf("\n\n\t\t\t\t   Opps!!! Forget to buy something? Press enter to buy again.");
            char afterpurchase;
            afterpurchase=getche();
            if (afterpurchase=='1')
            {
                fclose(fptr);
                main();
            }
        }


    }



}

void ADMINPANEL()
{
    printf("\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t\t\t\t\t    ADMIN PANEL\n");
    printf("\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
}
void CUSTOMERPANEL()
{
    printf("\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\n\t\t\t\t\t\t    CUSTOMER PURCHASE\n");
    printf("\t\t");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\n");
}


