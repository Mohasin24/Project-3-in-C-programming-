/**
 * @file mainmk.c
 * @author Mohasin Patel
 * @brief
 * @version 0.1
 * @date 2022-08-01
 *
 * @problem statement :- Library managment system
 *
 */

#include <stdio.h>
#include <windows.h> // Sleep method for windows
#include <stdlib.h>  // system()
#include <conio.h>
#include <stdint.h>
#pragma pack(1)

// #include<unistd.h>  //Sleep method for linux

// ### Declarations
void loginPanel();    // done
void adminPanel();    // done
void consumerPanel(); // done

//////////////////
void addBook(int);       // done
void deleteBook(int);    // done
void searchBook(int);    // done
void issuedBooks(int);   // done
void bookList(int, int); // done
void editRecord(int);    // done
void borrowBook(int);    // done
void returnBook(int);    // done
void returnedBooksList(int);
int getData();    // done
int checkID(int); // done
void bookID(int); // done
int checkLogin(); // done
/////////////////////////
int close(); // done

// FILES

FILE *fBook, *fTemp, *fIss, *fRet; // Temporary file , issued data file, return book file and main file

// Global Array

char cat[][30] = {"Computer", "Information Technology", "Electronics", "Electrical", "Civil", "Mechanical"};

// GLOBAL VARIABLES
int notCall = 0; // This is for if book list function is not call by delete book function
int iChoice = 0;
int logRet = 0;
char findbook = '\0';

// GLOBAL ARRAY
// default
char User[] = "Mohasin";
char Pass[] = "Pass";

// user entered

char userIn[15];
char passIn[15];

// GLOBAL

struct bookInfo
{
    char *Category;

    int quantity;
    int bookID;
    int rackNo;

    float price;

    char bookName[100];
    char authorName[50];
    char stName[50];
};

struct bookInfo bobj; // structure object

//##################################################################
int main()
{
    loginPanel();

    return 0;
}
//##################################################################

void loginPanel()
{
    system("cls");
    printf("\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t\t\t  LIBRARY MANAGMENT SYSTEM\t\t\t\n");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n");

    printf("\t\t\xDB\xB2 1. Admin Login\n\n");
    printf("\t\t\xDB\xB2 2. Consumer Login\n\n");
    printf("\t\t\xDB\xB2 0. Close The Application\n\n");

    printf("\n\t\tEnter your choice :=\t");

    switch (getch())
    {
    case '1':
        adminPanel();
        break;
    case '2':
        consumerPanel();
        break;
    case '0':
        if (close() == 0)
        {
            loginPanel();
        }
        break;
    default:
        getch();
        system("cls");
        printf("\n\n\n\n\t\t\tEnter valid choice!\n");
        Sleep(1000);
        loginPanel();
        break;
    }
}

void adminPanel()
{
    int adminPanelID = 1; // to tell a function in which panel to return

    if (logRet == 1 || checkLogin() == 0)
    {
        if (logRet != 1)
        {
            system("cls");
            printf("\n\n\n\n\n\t\t\t\tLogin Successfull !!!!");
            Sleep(1000);
        }

        logRet = 0;

        system("cls");
        printf("\n\t\t\t\tADMIN PANEL\t\t\t\n");
        printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

        printf("\n");
        printf("\t\t\xDB\xB2 1. Add Books\n\n");

        printf("\t\t\xDB\xB2 2. Delete Book\n\n");
        printf("\t\t\xDB\xB2 3. Search Book\n\n");
        printf("\t\t\xDB\xB2 4. Issued Books\n\n");
        printf("\t\t\xDB\xB2 5. View Book List\n\n");
        printf("\t\t\xDB\xB2 6. Edit Book Record\n\n");
        printf("\t\t\xDB\xB2 7. View Returned Book List\n\n");
        printf("\t\t\xDB\xB2 8. Back to Login Panel\n\n");
        printf("\t\t\xDB\xB2 0. Close the application\n\n");

        printf("\t\t\t Enter your choice :=\t");
        fflush(stdin);   //******************************
        switch (getch()) // here getch() is used which immedietly take input without wating to press enter
        {
        case '1':
            logRet = 1;
            addBook(adminPanelID);
            break;
        case '2':
            logRet = 1;
            deleteBook(adminPanelID);
            break;
        case '3':
            logRet = 1;
            searchBook(adminPanelID);
            break;
        case '4':
            logRet = 1;
            issuedBooks(adminPanelID);
            break;
        case '5':
            logRet = 1;
            bookList(adminPanelID, notCall); // not called by deleteBook()
            break;
        case '6':
            logRet = 1;
            editRecord(adminPanelID);
            break;
        case '7':
            logRet = 1;
            returnedBooksList(adminPanelID);
        case '8':
            loginPanel(adminPanelID);
            break;
        case '0':
            if (close() == 0)
            {
                logRet = 1;
                adminPanel();
            }
            break;
        default:
            system("cls");
            printf("\n\n\n\n\t\t\tEnter valid choice!\n");
            Sleep(1000);
            adminPanel();
        }
    }
    else
    {
        system("cls");
        printf("\n\n\n\n\t\t\t\t\t Login Error !!!!!");
        Sleep(1000);
        loginPanel();
    }
}

int checkLogin()
{
    while (1)
    {
        system("cls");

        printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Enter Login Details \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
        printf("\n\t\t\xDB\xB2 USERNAME :=  ");
        scanf("%s", userIn);
        printf("\n\t\t\xDB\xB2 PASSWORD :=  ");
        scanf("%s", passIn);
        if (strcmp(User, userIn) == 0 && strcmp(Pass, passIn) == 0)
        {
            printf("done\n");
            break;
        }
        else
        {
            system("cls");
            printf("\n\n\n\t\t\tPlease enter correct UserName and Password !!!");
            Sleep(1000);

            printf("\n\n\n\t\t\t\tWant to exit ? (Y/N) ");
            switch (getch())
            {
            case 'y':
                loginPanel();
                break;
            case 'n':
                continue;
            }
        }
    }
    return 0;
}

void consumerPanel()
{
    int conPanelID = 2;

    system("cls");
    printf("\n\t\t\t\tCONSUMER PANEL\t\t\t\n");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n");
    printf("\t\t\xDB\xB2 1. Search Book\n\n");
    printf("\t\t\xDB\xB2 2. Borrow Book\n\n");
    printf("\t\t\xDB\xB2 3. View All Books\n\n");
    printf("\t\t\xDB\xB2 4. Return Book\n\n");
    printf("\t\t\xDB\xB2 5. Back to Login Panel\n\n");
    printf("\t\t\xDB\xB2 0. Close the application\n\n");

    fflush(stdin);

    printf("\t\t\t Enter your choice :=\t");

    switch (getch()) // here getch() is used which immedietly take input without wating to press enter
    {
    case '1':
        searchBook(conPanelID);
        break;
    case '2':
        borrowBook(conPanelID);
        break;
    case '3':
        bookList(conPanelID, notCall); // here not call by deletebook()
        break;
    case '4':
        returnBook(conPanelID);
        break;
    case '5':
        loginPanel();
        break;
    case '0':
        if (close() == 0)
        {
            consumerPanel();
        }
        break;
    default:
        getch();
        system("cls");
        printf("\n\n\n\n\t\t\tEnter valid choice!\n");
        Sleep(1000);
        consumerPanel();
    }
}

void addBook(int ID)
{
    system("cls");

    printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Select Catogories \xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\t\t\xDB\xB2 1. Computer\n\n");
    printf("\t\t\xDB\xB2 2. Information Technology\n\n");
    printf("\t\t\xDB\xB2 3. Electronics\n\n");
    printf("\t\t\xDB\xB2 4. Electrical\n\n");
    printf("\t\t\xDB\xB2 5. Civil\n\n");
    printf("\t\t\xDB\xB2 6. Mechanical\n\n");
    printf("\t\t\xDB\xB2 7. Back to MAIN MENU\n\n");
    printf("\t\t\xDB\xB2 0. Close the Application\n\n");

    printf("\t\t\t Enter your choice :=\t");
    scanf("%d", &iChoice);

    if (iChoice > 7)
    {
        printf("\n\t\t\t Enter valid choice!\n");
        printf("\n\t\t\t Please press 'ENTER' to continue.\n");

        if (getch())
        {
            addBook(ID); // recursion
        }
    }

    if (iChoice == 7)
    {
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
    }

    if (iChoice == 0)
    {
        if (close() == 0)
        {
            addBook(ID);
        }
    }

    fBook = fopen("data.dat", "ab+");
    if (getData() == 1)
    {
        system("cls");
        bobj.Category = cat[iChoice - 1];
        fseek(fBook, 0, SEEK_END);
        fwrite(&bobj, sizeof(bobj), 1, fBook);
        fclose(fBook);

        printf("\n\n\t\t\t Record saved successfully !!!!\n\n\n");

        printf("\t\t\t Want add another book? (Y/N) :=");

        if (getch() == 'n')
        {
            if (ID == 1)
            {
                adminPanel();
            }
            else if (ID == 2)
            {
                consumerPanel();
            }
        }
        else
        {
            system("cls");
            addBook(ID);
        }
    }
}

int getData()
{
    int t = 0;

    system("cls");
    printf("\n\t\t\tPlease fill the below information :-\n\n");

    printf("Category :=  %s\n", cat[iChoice - 1]);

    printf("Book ID :=  ");
    scanf("%d", &t);

    if (t <= 0)
    {
        system("cls");
        printf("\n\n\n\n\t\t\t Please enter valid Book ID !!!!!!!\n");
        Sleep(1000);
        getData();
    }
    else
    {
        if (checkID(t) == 1)
        {
            printf("Book already exists with ID = %d\nPlease enter details again\n", t);
            getch();

            getData();
        }
        else
        {
            bobj.bookID = t;
            printf("Book Name :=  ");
            scanf("%s", bobj.bookName);

            printf("Author :=  ");
            scanf("%s", bobj.authorName);

            printf("Quantity :=  ");
            scanf("%d", &bobj.quantity);

            printf("Price :=  ");
            scanf("%f", &bobj.price);

            printf("Rack No. :=  ");
            scanf("%d", &bobj.rackNo);
        }
    }

    // printf("%d\n",bobj.bookID);
    // printf("%s\n",bobj.bookName);
    // printf("%s\n",bobj.authorName);
    // printf("%d\n",bobj.quantity);
    // printf("%0.2f\n",bobj.price);
    // printf("%d\n",bobj.rackNo);

    return 1;
}

int checkID(int n)
{
    rewind(fBook);
    while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
    {
        if (bobj.bookID == n)
        {
            return 1; // checking if book with same ID present or not
        }
    }

    return 0;
}

void bookList(int ID, int cID) // cID is a caller ID used in deleteBook method to call bookList method
{
    int total = 0;

    system("cls");
    fBook = fopen("data.dat", "rb");

    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOK's LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n");
    while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
    {
        printf("\t\t>  Category :=  %s\n", bobj.Category);
        printf("\t\t>        ID :=  %d\n", bobj.bookID);
        printf("\t\t> Book Name :=  %s\n", bobj.bookName);
        printf("\t\t>    Author :=  %s\n", bobj.authorName);
        printf("\t\t>  Quantity :=  %d\n", bobj.quantity);
        printf("\t\t>     Price :=  %0.2f\n", bobj.price);
        printf("\t\t>   Rack No.:=  %d\n", bobj.rackNo);
        printf("\n\t\t\t*****************************\n");

        total = total + bobj.quantity;
    }

    fclose(fBook);
    printf("\t\t\tTotal quantity of books :=  %d\n", total);
    if (cID == 0)
    {
        printf("\n\t\t\t Please press 'ENTER' to go back :=\t");
        if (getchar() == '\n')
        {
            if (ID == 1)
            {
                adminPanel();
            }
            else if (ID == 2)
            {
                consumerPanel();
            }
        }
        else
        {
            system("cls");

            printf("\n\n\n\t\t\t Please use 'ENTER' key !!!!\n");
            Sleep(1000);
            fflush(stdin);
            bookList(ID, cID);
        }
    }
}

void searchBook(int ID)
{
    findbook = '\0';
    int bkID = 0;
    char bkname[50];
    int present = 0;

    system("cls");
    printf("\n\n\t\t**************************** Search Book ****************************\n");

    printf("\n\n\t\t\t\xb2\xb2 1. Search By ID\n\n");
    printf("\t\t\t\xb2\xb2 2. Search By Book Name\n\n");
    printf("\t\t\t\xb2\xb2 3. Go back\n\n");

    fBook = fopen("data.dat", "rb+");
    rewind(fBook);

    printf("\n\n\t\t\tEnter your choice :=  ");

    switch (getch())
    {
    //////////////////////////////////////////////////////////////
    case '1':
        //////////////////////////////////////////////////////////////
        system("cls");
        printf("\n\n\t\t**************************** Search By ID ****************************\n");
        fflush(stdin);
        printf("\n\n\t\t\xb2 Enter book ID :=  ");
        scanf("%d", &bkID);

        printf("\n\n\t\tSearching.........\n");
        Sleep(1000);

        while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
        {
            if (bobj.bookID == bkID)
            {
                system("cls");
                printf("\n\n\t\t**************************** Search By ID ****************************\n");

                printf("\n\n\t\t\t Book record is available !!!\n\n");

                printf("\t\t>  Category :=  %s\n", bobj.Category);
                printf("\t\t>        ID :=  %d\n", bobj.bookID);
                printf("\t\t> Book Name :=  %s\n", bobj.bookName);
                printf("\t\t>    Author :=  %s\n", bobj.authorName);
                printf("\t\t>  Quantity :=  %d\n", bobj.quantity);
                printf("\t\t>     Price :=  %0.2f\n", bobj.price);
                printf("\t\t>   Rack No.:=  %d\n", bobj.rackNo);

                printf("\n\t\t\t*****************************\n");
                findbook = 'p';
            }
        }

        if (findbook != 'p')
        {
            printf("\n\n\t\t\t Book record is not available !!!\n");
        }

        printf("\n\t\t\t Try another search? (Y/N) := ");

        if (getch() == 'y')
        {
            searchBook(ID);
        }
        else
        {
            if (ID == 1)
            {
                adminPanel();
            }
            else if (ID == 2)
            {
                consumerPanel();
            }
        }
        break;
    //////////////////////////////////////////////////////////////
    case '2':
        //////////////////////////////////////////////////////////////
        system("cls");
        printf("\n\n\t\t********************** Search By Book Name **********************\n");
        rewind(fBook);

        printf("\n\n\t\t\xb2 Enter book name :=  ");
        scanf("%s", &bkname);

        while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
        {
            if (strcmp(bobj.bookName, bkname) == 0)
            {
                // system("cls");
                printf("\n\n\t\t********************** Search By Book Name **********************\n");

                printf("\n\n\t\t\t Book record is available !!!\n\n");

                printf("\t\t>  Category :=  %s\n", bobj.Category);
                printf("\t\t>        ID :=  %d\n", bobj.bookID);
                printf("\t\t> Book Name :=  %s\n", bobj.bookName);
                printf("\t\t>    Author :=  %s\n", bobj.authorName);
                printf("\t\t>  Quantity :=  %d\n", bobj.quantity);
                printf("\t\t>     Price :=  %0.2f\n", bobj.price);
                printf("\t\t>   Rack No.:=  %d\n", bobj.rackNo);

                printf("\n\t\t\t*****************************\n");
                present++;
            }
        }

        if (present == 0)
        {
            printf("\n\n\t\t\t Book record is not available !!!\n");
        }

        printf("\n\t\t\t Try another search? (Y/N) := ");

        if (getch() == 'y')
        {
            searchBook(ID);
        }
        else
        {
            if (ID == 1)
            {
                adminPanel();
            }
            else if (ID == 2)
            {
                consumerPanel();
            }
        }

        break;
    //////////////////////////////////////////////////////////////
    case '3':
        //////////////////////////////////////////////////////////////
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
        break;
    //////////////////////////////////////////////////////////////
    default:
        //////////////////////////////////////////////////////////////
        getch();
        system("cls");
        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
        Sleep(1000);
        searchBook(ID);
    }
    //////////////////////////////////////////////////////////////
    fclose(fBook);
    //////////////////////////////////////////////////////////////
}

void deleteBook(int ID)
{
    findbook = '\0';
    int iRet = ID;  // ID to tell bookList function where to return
    int bkID = 0;   // book ID to be delete
    int called = 1; // to tell the bookList is called by deleteBook()

    system("cls");

    printf("\n\n\t**************************** Delete Book ****************************\n");

    printf("\n\n\t\t\t\xb2\xb2 1. Delete book by ID \n\n");
    printf("\t\t\t\xb2\xb2 2. View book list\n\n");
    printf("\t\t\t\xb2\xb2 3. Go back\n\n");
    printf("\n\t\tEnter your choice :=\t");

    switch (getch())
    {
    /////////////////////////////////////////////////////////////////
    case '1':
        /////////////////////////////////////////////////////////////////
        fBook = fopen("data.dat", "rb+");

        rewind(fBook);

        system("cls");
        printf("\n\n\t\t****************** Delete book by ID ******************\n");
        printf("\n\n\t\t\xb2 Enter book ID :=  ");
        scanf("%d", &bkID);

        if (fBook == NULL)
        {
            printf("File error !!!!\n");
        }
        else
        {

            while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
            {

                if (bobj.bookID == bkID)
                {
                    system("cls");
                    printf("\n\n\t\t****************** Delete book by ID ******************\n");

                    printf("\n\n\t\t~~~~~~~~ Book ID is present ~~~~~~~~\n");
                    printf("\n\t\t-> Book ID       :=  %d\n", bobj.bookID);
                    printf("\n\t\t-> Book Name     :=  %s\n", bobj.bookName);
                    printf("\n\t\t-> Book Quantity :=  %d\n", bobj.quantity);

                    findbook = 'p';

                    printf("\n\n\n\t\t Want to delete this book? (Y/N) :=  ");

                    if (getch() == 'y')
                    {
                        bookID(bkID);

                        printf("\n\n\t\t\t-> The record is sucessfully deleted !!!!!\n");
                        printf("\n\n\n\n\t\t\t-> Delete another record?(Y/N) :=  ");

                        if (getch() == 'y')
                        {
                            deleteBook(ID);
                            fclose(fBook);
                        }
                        else
                        {
                            if (ID == 1)
                            {
                                adminPanel();
                            }
                            else if (ID == 2)
                            {
                                consumerPanel();
                            }
                        }
                    }
                    else
                    {
                        deleteBook(ID);
                    }
                }
            }
        }
        if (findbook != 'p' || bobj.quantity == 0)
        {
            system("cls");

            printf("\n\n\t\t****************** Delete book by ID ******************\n");
            printf("\n\n\t\t\t No record found !!!!!!\n");
            Sleep(1000);
            deleteBook(ID);
        }

        break;
    /////////////////////////////////////////////////////////////////
    case '2':
        /////////////////////////////////////////////////////////////////

        bookList(iRet, called); // called by delete method

        printf("\n\n\t\t Want to delete book? (Y/N) :=  ");
        if (getch() == 'y')
        {
            fBook = fopen("data.dat", "rb+");

            rewind(fBook);

            printf("\n\n\t\t\xb2 Enter book ID :=  ");
            scanf("%d", &bkID);

            if (fBook == NULL)
            {
                printf("File error !!!!\n");
            }
            else
            {

                while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
                {

                    if (bobj.bookID == bkID)
                    {
                        system("cls");
                        printf("\n\n\t\t****************** Delete book by ID ******************\n");

                        printf("\n\n\t\t~~~~~~~~ Book ID is present ~~~~~~~~\n");
                        printf("\n\t\t-> Book ID       :=  %d\n", bobj.bookID);
                        printf("\n\t\t-> Book Name     :=  %s\n", bobj.bookName);
                        printf("\n\t\t-> Book Quantity :=  %d\n", bobj.quantity);

                        findbook = 'p';

                        printf("\n\n\n\t\t Want to delete this book? (Y/N) :=  ");

                        if (getch() == 'y')
                        {
                            bookID(bkID);

                            printf("\n\n\t\t\t-> The record is sucessfully deleted !!!!!\n");
                            printf("\n\n\n\n\t\t\t-> Delete another record?(Y/N) :=  ");

                            if (getch() == 'y')
                            {
                                deleteBook(ID);
                                fclose(fBook);
                            }
                            else
                            {
                                if (ID == 1)
                                {
                                    adminPanel();
                                }
                                else if (ID == 2)
                                {
                                    consumerPanel();
                                }
                            }
                        }
                        else
                        {
                            deleteBook(ID);
                        }
                    }
                }
            }
            if (findbook != 'p' || bobj.quantity == 0)
            {
                system("cls");

                printf("\n\n\t\t****************** Delete book by ID ******************\n");
                printf("\n\n\t\t\t No record found !!!!!!\n");
                Sleep(1000);
                deleteBook(ID);
            }
        }
        if (getch() == 'n')
        {
            deleteBook(ID);
        }
        break;
    /////////////////////////////////////////////////////////////////
    case '3':
        /////////////////////////////////////////////////////////////////
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
        break;
    /////////////////////////////////////////////////////////////////
    default:
        /////////////////////////////////////////////////////////////////
        getch();
        system("cls");
        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
        Sleep(1000);
        deleteBook(ID);
    }
}

void bookID(int bkID)
{
    system("cls");

    fTemp = fopen("temp.dat", "wb+");
    rewind(fBook);

    while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
    {
        if (bobj.bookID != bkID)
        {
            fseek(fTemp, 0, SEEK_CUR);
            fwrite(&bobj, sizeof(bobj), 1, fTemp);
        }
    }

    fclose(fTemp);
    fclose(fBook);
    remove("data.dat");
    rename("temp.dat", "data.dat");
    // fBook = fopen("data.dat", "rb+");
}

void editRecord(int ID)
{
    findbook = '\0';
    int bkID = 0;

    fBook = fopen("data.dat", "rb+");

    rewind(fBook);

    system("cls");
    printf("\n\n\t\t\t*************** Edit Book Record ***************\n");

    printf("\n\n\t\t\t\xB2 Enter Book ID to edit record :=  ");
    scanf("%d", &bkID);

    printf("\n\n\t\t\tSearching...............\n");
    Sleep(1000);

    while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
    {
        if (bobj.bookID == bkID)
        {
            system("cls");
            printf("\n\t\t\t~~~~~~~~ Book is available ~~~~~~~~\n");
            printf("\n\t\t\t-> Category      :=  %s\n", bobj.Category);
            printf("\t\t\t-> Book ID       :=  %d\n", bobj.bookID);
            printf("\t\t\t-> Book Name     :=  %s\n", bobj.bookName);
            printf("\t\t\t-> Author Name   :=  %s\n", bobj.authorName);
            printf("\t\t\t-> Book Quantity :=  %d\n", bobj.quantity);
            printf("\t\t\t-> Book Price    :=  %0.2f\n", bobj.price);
            printf("\t\t\t-> Book Rack no. :=  %d\n", bobj.rackNo);

            findbook = 'p';

            fflush(stdin);

            printf("\n\n\t\t\t\xB2 Want to edit this book's record ? (Y/N) :=  ");

            if (getch() == 'y')
            {

                printf("\n\t\t\t Enter below details :=\n");
                printf("\n\t\t\t-> Category      :=  %s\n", bobj.Category);
                printf("\t\t\t-> Book ID       :=  %d\n\n", bobj.bookID);

                printf("\t\t\t-> Enter New Book Name     :=  ");
                scanf("%s", bobj.bookName);

                printf("\t\t\t-> Enter New Author Name   :=  ");
                scanf("%s", bobj.authorName);

                printf("\t\t\t-> Enter New Book Quantity :=  ");
                scanf("%d", &bobj.quantity);

                printf("\t\t\t-> Enter New Book Price    :=  ");
                scanf("%f", &bobj.price);

                printf("\t\t\t-> Enter New Book Rack no. :=  ");
                scanf("%d", &bobj.rackNo);

                printf("\n\n\t\t\t Record modified successfully !!!!!");

                fseek(fBook, ftell(fBook) - sizeof(bobj), 0);
                fwrite(&bobj, sizeof(bobj), 1, fBook);

                fclose(fBook);

                printf("\n\n\t\t\tWant to modify another record ? (Y/N) :=  ");

                if (getch() == 'y')
                {
                    editRecord(ID);
                }
                if (getch() == 'n')
                {
                    if (ID == 1)
                    {
                        adminPanel();
                    }
                    else if (ID == 2)
                    {
                        consumerPanel();
                    }
                }
            }
            if (getch() == 'n')
            {
                if (ID == 1)
                {
                    adminPanel();
                }
                else if (ID == 2)
                {
                    consumerPanel();
                }
            }
        }
    }

    if (findbook != 'p')
    {
        system("cls");

        printf("\n\n\t\t\t*************** Edit Book Record ***************\n");
        printf("\n\n\t\t\t No record found !!!!!!\n");

        printf("\n\n\t\t\t Want to try again ? (Y/N) :=  ");

        if (getch() == 'y')
        {
            fclose(fBook);
            editRecord(ID);
        }
        else
        {
            fclose(fBook);

            if (ID == 1)
            {
                adminPanel();
            }
            else if (ID == 2)
            {
                consumerPanel();
            }
        }
    }
}

void borrowBook(int ID)
{
    findbook = '\0';
    int iRet = 0;
    int bkID = 0;
    int qan = 0;
    system("cls");
    printf("\n\n\t\t\t*************** Borrow a Book ***************\n");

    printf("\n\n\t\t\t\xB2 1. Borrow Book");
    printf("\n\n\t\t\t\xB2 2. Go Back");

    printf("\n\n\n\t\t\tEnter your choice :=\t");

    switch (getch())
    {
    //*********************************************************************************
    case '1':
        //*********************************************************************************

        fBook = fopen("data.dat", "rb+");
        rewind(fBook);
        system("cls");
        printf("\n\n\t\t\t*************** Borrow a Book ***************\n");

        printf("\n\n\t\t\t\xB2 Enter Book ID :=  ");
        scanf("%d", &bkID);

        printf("\n\n\t\t\tSearching...............\n");
        Sleep(1000);

        while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
        {
            if (bobj.bookID == bkID)
            {
                system("cls");
                printf("\n\t\t\t~~~~~~~~ Book is available ~~~~~~~~\n\n");
                printf("\t\t\t-> Category      :=  %s\n", bobj.Category);
                printf("\t\t\t-> Book ID       :=  %d\n", bobj.bookID);
                printf("\t\t\t-> Book Name     :=  %s\n", bobj.bookName);
                printf("\t\t\t-> Author Name   :=  %s\n", bobj.authorName);
                printf("\t\t\t-> Book Quantity :=  %d\n", bobj.quantity);
                printf("\t\t\t-> Book Price    :=  %0.2f\n", bobj.price);
                printf("\t\t\t-> Book Rack no. :=  %d\n", bobj.rackNo);

                printf("\n\n\t\t\t Want to borrow this book ? (Y/N) :=  ");

                switch (getch())
                {
                //*********************************************************************************
                case 'y':
                    //*********************************************************************************
                    iRet = 1;

                    fIss = fopen("issue.dat", "ab+");
                    rewind(fIss);

                    system("cls");
                    printf("\n\n\t\t\t*************** Borrow a Book ***************\n");

                    printf("\n\n\t\t\t\xB2 Enter Consumer Name :=  ");
                    scanf("%s", bobj.stName);

                    fflush(stdin);

                    printf("\n\n\t\t\t\xB2 Enter quantity to borrow :=  ");
                    scanf("%d", &qan);

                    while (qan > bobj.quantity || qan <= 0)
                    {
                        system("cls");
                        printf("\n\n\t\t\t\xB2 Unable to allocate the quantity you entered !!!!!\n");

                        Sleep(1000);

                        system("cls");
                        printf("\n\n\t\t\t\xB2 Enter quantity to borrow :=  ");
                        scanf("%d", &qan);

                        if (qan < bobj.quantity && qan > 0)
                        {
                            break;
                        }
                    }
                    bobj.quantity = qan;      // borrowed book quantity
                    fseek(fIss, 0, SEEK_END); // appending data in brr.dat file
                    fwrite(&bobj, sizeof(bobj), 1, fIss);
                    fclose(fIss);
                    fclose(fBook);

                    //////////////////////////////// UPDATION ////////////////////////

                    if (iRet == 1) // updation of quantity in data.dat file
                    {
                        fTemp = fopen("temp.dat", "wb+");
                        fBook = fopen("data.dat", "rb+");

                        rewind(fBook);

                        while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
                        {
                            if (bobj.bookID == bkID)
                            {
                                bobj.quantity = bobj.quantity - qan;
                            }

                            fseek(fTemp, 0, SEEK_CUR);
                            fwrite(&bobj, sizeof(bobj), 1, fTemp);
                        }

                        fclose(fTemp);
                        fclose(fBook);
                        remove("data.dat");
                        rename("temp.dat", "data.dat");
                    }
                    fclose(fIss);
                    fclose(fBook);
                    fclose(fTemp);
                    system("cls");
                    printf("\n\n\n\n\t\t\t\t\tSuccessfull !!!!\n");
                    Sleep(1000);

                    //////////////////////////////////////////////////////////////////////

                    printf("\n\n\t\t\t Want to borrow another book ? (Y/N) :=  ");

                    switch (getch())
                    {
                    //*********************************************************************************
                    case 'y':
                        //*********************************************************************************
                        fclose(fBook);
                        fclose(fIss); /// ccccccccccccccccccccccccccc
                        borrowBook(ID);
                        break;
                    //*********************************************************************************
                    case 'n':
                        //*********************************************************************************
                        fclose(fBook);
                        fclose(fIss); /// cccccccccccccccc
                        if (ID == 1)
                        {
                            adminPanel();
                        }
                        else if (ID == 2)
                        {
                            consumerPanel();
                        }
                        break;
                    //*********************************************************************************
                    default:
                        //*********************************************************************************
                        getch();
                        system("cls");
                        fclose(fBook);
                        fclose(fIss); /// ccccccccccccccccccccccc
                        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
                        Sleep(1000);
                        borrowBook(ID);

                        break;
                    }

                    break;
                //*********************************************************************************
                case 'n':
                    //*********************************************************************************

                    fclose(fBook);
                    fclose(fIss); /// ccccccccccccccccccccccc

                    if (ID == 1)
                    {
                        adminPanel();
                    }
                    else if (ID == 2)
                    {
                        consumerPanel();
                    }
                    break;
                //*********************************************************************************
                default:
                    //*********************************************************************************
                    getch();

                    fclose(fBook);
                    fclose(fIss); /// ccccccccccccccccccccccc

                    system("cls");
                    printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
                    Sleep(1000);

                    borrowBook(ID);

                    break;
                }

                findbook = 'p';
            }
        }
        ////////////////////////// NO RECORD FOUND /////////////////////////////////////////////////
        if (findbook != 'p')
        {
            system("cls");

            printf("\n\n\t\t\t*************** Borrow a Book ***************\n");
            printf("\n\n\t\t\t No record found !!!!!!\n");

            printf("\n\n\t\t\t Want to try again ? (Y/N) :=  ");

            if (getch() == 'y')
            {
                fclose(fBook);
                borrowBook(ID);
            }
            else
            {
                fclose(fBook);

                if (ID == 1)
                {
                    adminPanel();
                }
                else if (ID == 2)
                {
                    consumerPanel();
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////////////////
        break;
    //*********************************************************************************
    case '2':
        //*********************************************************************************
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
    //*********************************************************************************
    default:
        //*********************************************************************************
        getch();

        system("cls");
        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
        Sleep(1000);

        borrowBook(ID);
    }
}

void issuedBooks(int ID)
{
    int total = 0;
    fIss = fopen("issue.dat", "rb+");
    rewind(fIss);
    system("cls");
    printf("\n\t\t*********************** List Of Issued Book's ***********************\n\n");

    while (fread(&bobj, sizeof(bobj), 1, fIss) == 1)
    {
        printf("\t\t-> Student Name      :=  %s\n", bobj.stName);
        printf("\t\t-> Book Category     :=  %s\n", bobj.Category);
        printf("\t\t-> Book ID           :=  %d\n", bobj.bookID);
        printf("\t\t-> Book Name         :=  %s\n", bobj.bookName);
        printf("\t\t-> Book Author       :=  %s\n", bobj.authorName);
        printf("\t\t-> Issued Quantity   :=  %d\n", bobj.quantity);
        printf("\t\t-> Book Price        :=  %0.2f\n", bobj.price);
        printf("\t\t-> Rack No.          :=  %d\n", bobj.rackNo);
        printf("\n\t\t\t*****************************\n");

        total = total + bobj.quantity;
    }

    fclose(fIss);

    printf("\t\t\tTotal quantity of issued books :=  %d\n", total);

    printf("\n\t\t\t Please press 'ENTER' to go back :=\t");
    if (getchar() == '\n')
    {
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
    }
    else
    {
        system("cls");

        printf("\n\n\n\t\t\t Please use 'ENTER' key !!!!\n");
        Sleep(1000);
        fflush(stdin);
        issuedBooks(ID);
    }
}

void returnBook(int ID)
{
    findbook = '\0';
    int total = 0;
    int bkID = 0;
    int ret = 0;
    int retQan = 0;

    system("cls");
    printf("\n\t\t*********************** Return Book's ***********************");

    printf("\n\n\t\t\t\xB2 1. Return a book");
    printf("\n\n\t\t\t\xB2 2. Borrowed book list");
    printf("\n\n\t\t\t\xB2 3. Go Back");

    printf("\n\n\n\t\t\t\tEnter your choice :=  ");

    switch (getch())
    {
    //*********************************************************************************
    case '1':
        //*********************************************************************************

        fIss = fopen("issue.dat", "rb+");
        rewind(fIss);

        system("cls");
        printf("\n\t\t*********************** Return Book's ***********************");

        printf("\n\n\t\t\t\xB2 Enter book ID :=  ");
        scanf("%d", &bkID);

        while (fread(&bobj, sizeof(bobj), 1, fIss) == 1)
        {
            if (bobj.bookID == bkID)
            {
                findbook = 'p';
                retQan = bobj.quantity;
                printf("\n\n\t\t\t~~~~~~~~~~~~~~ Book Details ~~~~~~~~~~~~~~\n\n");
                printf("\t\t\t-> Student Name      :=  %s\n", bobj.stName);
                printf("\t\t\t-> Book Category     :=  %s\n", bobj.Category);
                printf("\t\t\t-> Book ID           :=  %d\n", bobj.bookID);
                printf("\t\t\t-> Book Name         :=  %s\n", bobj.bookName);
                printf("\t\t\t-> Book Author       :=  %s\n", bobj.authorName);
                printf("\t\t\t-> Issued Quantity   :=  %d\n", bobj.quantity);
                printf("\t\t\t-> Book Price        :=  %0.2f\n", bobj.price);
                printf("\t\t\t-> Rack No.          :=  %d\n", bobj.rackNo);
                printf("\n\t\t\t*****************************\n");
            }
        }
        if (findbook != 'p')
        {
            system("cls");

            printf("\n\n\t\t\t No record found !!!!!!\n");

            printf("\n\n\t\t\t Want to try again ? (Y/N) :=  ");

            switch (getch())
            {
            case 'y':
                fclose(fIss);
                returnBook(ID);
                break;
            case 'n':
                fclose(fIss);

                if (ID == 1)
                {
                    adminPanel();
                }
                else if (ID == 2)
                {
                    consumerPanel();
                }
                break;
            default:
                getch();
                fclose(fIss);
                system("cls");
                printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
                Sleep(1000);

                returnBook(ID);
            }
        }
        else
        {
            printf("\n\n\t\t\tWant to return this book ? (Y/N)");

            switch (getch())
            {
            case 'y':
                rewind(fIss);

                fTemp = fopen("temp.dat", "wb+");
                // rewind(fTemp);

                fRet = fopen("ret.dat", "ab+");
                rewind(fRet);

                while (fread(&bobj, sizeof(bobj), 1, fIss))
                {
                    if (bobj.bookID == bkID)
                    {
                        fseek(fRet, 0, SEEK_END);
                        fwrite(&bobj, sizeof(bobj), 1, fRet);

                        ret = 1;
                    }
                    else if (bobj.bookID != bkID)
                    {
                        fseek(fTemp, 0, SEEK_CUR);
                        fwrite(&bobj, sizeof(bobj), 1, fTemp);
                    }
                }

                fclose(fIss);
                fclose(fRet);
                fclose(fTemp);
                remove("issue.dat");
                rename("temp.dat", "issue.dat");

                if (ret == 1)
                {
                    fBook = fopen("data.dat", "rb+");
                    rewind(fBook);

                    fTemp = fopen("temp.dat", "wb+");

                    while (fread(&bobj, sizeof(bobj), 1, fBook) == 1)
                    {
                        if (bobj.bookID == bkID)
                        {
                            bobj.quantity = bobj.quantity + retQan;
                        }
                        fseek(fTemp, 0, SEEK_CUR);
                        fwrite(&bobj, sizeof(bobj), 1, fTemp);
                    }

                    fclose(fBook);
                    fclose(fTemp);
                    remove("data.dat");
                    rename("temp.dat", "data.dat");
                }

                system("cls");
                printf("\n\n\n\n\t\t\tLoading............\n");
                Sleep(1000);
                system("cls");
                printf("\n\n\n\n\n\t\t\t\tBook Returned Successfully !!!!!!\n\n");

                break;
            case 'n':
                fclose(fBook);
                fclose(fIss);
                if (ID == 1)
                {
                    adminPanel();
                }
                else if (ID == 2)
                {
                    consumerPanel();
                }
                break;
            default:
                getch();
                fclose(fBook);
                fclose(fIss);
                system("cls");
                printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
                Sleep(1000);
                returnBook(ID);
                break;
            }

            printf("\n\n\t\t\t\t-> Return another book ? (Y/N) ");

            switch (getch())
            {
            case 'y':
                returnBook(ID);
                break;

            case 'n':

                if (ID == 1)
                {
                    adminPanel();
                }
                else if (ID == 2)
                {
                    consumerPanel();
                }
                break;
            default:
                getch();
                system("cls");
                printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
                Sleep(1000);
                returnBook(ID);

                break;
            }
        }

        break;
    //*********************************************************************************
    case '2':
        //*********************************************************************************

        fIss = fopen("issue.dat", "rb+");
        rewind(fIss);
        system("cls");
        printf("\n\t\t*********************** List Of Borrowed Book's ***********************\n\n");

        while (fread(&bobj, sizeof(bobj), 1, fIss) == 1)
        {
            printf("\t\t-> Student Name      :=  %s\n", bobj.stName);
            printf("\t\t-> Book Category     :=  %s\n", bobj.Category);
            printf("\t\t-> Book ID           :=  %d\n", bobj.bookID);
            printf("\t\t-> Book Name         :=  %s\n", bobj.bookName);
            printf("\t\t-> Borrowed Quantity :=  %d\n", bobj.quantity);
            printf("\n\t\t\t*****************************\n");

            total = total + bobj.quantity;
        }

        fclose(fIss);

        printf("\t\t\tTotal quantity of borrowed books :=  %d\n", total);

        printf("\n\t\t\t Please press 'ENTER' to go back\t\n");
        if (getchar() == '\n')
        {
            returnBook(ID);
        }
        else
        {
            system("cls");

            printf("\n\n\n\t\t\t Please use 'ENTER' key !!!!\n");
            Sleep(1000);
            fflush(stdin);
            issuedBooks(ID);
        }
        break;
    //*********************************************************************************
    case '3':
        //*********************************************************************************
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
        break;
    default:
        getch();
        system("cls");
        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
        Sleep(1000);
        returnBook(ID);
        break;
    }
}

void returnedBooksList(int ID)
{
    int total = 0;
    system("cls");
    printf("\n\t\t*********************** Returned Book's ***********************");

    printf("\n\n\t\t\t\xB2 1. View list of returned book's");
    printf("\n\n\t\t\t\xB2 2. Delete list of returned book's");
    printf("\n\n\t\t\t\xB2 3. Go Back");

    printf("\n\n\n\t\t\t\tEnter your choice :=  ");

    switch (getch())
    {
    case '1':
        system("cls");
        fRet = fopen("ret.dat", "rb+");
        rewind(fRet);
        printf("\n\n\t\t\t~~~~~~~~~~~~~~ Returned Book Details ~~~~~~~~~~~~~~\n\n");
        while (fread(&bobj, sizeof(bobj), 1, fRet) == 1)
        {
            printf("\t\t\t-> Student Name  :=  %s\n", bobj.stName);
            printf("\t\t\t-> Category      :=  %s\n", bobj.Category);
            printf("\t\t\t-> Book ID       :=  %d\n", bobj.bookID);
            printf("\t\t\t-> Book Name     :=  %s\n", bobj.bookName);
            printf("\t\t\t-> Author Name   :=  %s\n", bobj.authorName);
            printf("\t\t\t-> Book Quantity :=  %d\n", bobj.quantity);
            printf("\t\t\t-> Book Price    :=  %0.2f\n", bobj.price);
            printf("\t\t\t-> Book Rack no. :=  %d\n", bobj.rackNo);
            printf("\n\t\t\t\t*****************************\n");

            total = total + bobj.quantity;
        }
        fclose(fRet);

        if (total == 0)
        {
            printf("\n\t\t\tTotal quantity of returned books :=  %d\n", total);
        }

        printf("\n\n\t\t\t Please press 'ENTER' to go back\t");
        if (getchar() == '\n')
        {
            returnedBooksList(ID);
        }
        else
        {
            system("cls");

            printf("\n\n\n\t\t\t Please use 'ENTER' key !!!!\n");
            Sleep(1000);
            fflush(stdin);
            returnedBooksList(ID);
        }
        break;

    case '2':
        system("cls");
        printf("\n\n\n\t\t\t\t\t**********\n\t\t\tIf you use this function all the data of this \n\n\t\t\tfile will be deleted permanently !!\n");

        printf("\n\n\n\t\t\t Are you sure ? (Y/N)\n");

        switch (getch())
        {
        case 'y':
            remove("ret.dat");
            system("cls");
            printf("\n\n\n\t\t\t Record deleted successfully !!\n");
            Sleep(1000);
            returnedBooksList(ID);
            break;
        case 'n':
            returnedBooksList(ID);
            break;
        default:
            while (getch() != 'y' || getch() != 'n')
            {
                system("cls");
                printf("\n\n\n\n\t\t\tPlease enter valid choice !!!\t");
                Sleep(500);
            }
            break;
        }
        break;
    case '3':
        if (ID == 1)
        {
            adminPanel();
        }
        else if (ID == 2)
        {
            consumerPanel();
        }
        break;
    default:
        getch();
        system("cls");
        printf("\n\n\n\t\t\tPlease enter valid choice !!!!!\n");
        Sleep(1000);
        returnedBooksList(ID);
        break;
    }
}

int close()
{
    printf("\n\n\t\t\t Want to exit? (Y/N) := ");

    if (getch() == 'y') /// exit
    {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\tThanks for using the application.\n\n");
        printf("\t\t\tExiting in 3 sec.\n");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t@copyright MOHASIN PATEL\n");
        Sleep(3000);
        system("cls");
        exit(0);
    }
    else
    {
        return 0; // stay on same page
    }
}
