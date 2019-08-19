#include <stdio.h>
#include <stdlib.h>
#include "local_library.h"
#define True 1
#define Ten 10
#define Tweny 20
#define binary_000000 0x00
#define binary_010101 0x15
#define binary_010100 0x14
#define binary_110111 0x37
BookCopy* searching_Serial_num(long int ser_num,BookCopy** Lib_Books,int size);
BookCopy* searching_Serial_num(long int ser_num,BookCopy** Lib_Books,int size){
    int i;
for (i=0;i<size;i++){
    if(Lib_Books[i]->serial_number==ser_num){
        return Lib_Books[i];
    }
}
return NULL;

}
int main()
{
  extern Book books[Tweny];
   BookCopy* Search_Copy;
   BookCopy** Lib_Books;
   BookCopy* pointer_Copy;
   BookCopy* Search_Copy2;
   int size=0;
   int num=0;
   int   i;
  int len =sizeof(books)/sizeof(books[0]);
  int  j;
int Book_Index=-1;
long int serial_number;
long int int_Book_Num;
long int seri_num;

/* specifying Genre details for eac book in books array */
 specify_Genre_vars(&books[0]);

 /****************************************************** /
  /* printing the Books in The Library */
printf("The Books in the Library are: \n\n");
 for (i=0;i<len;i++){
print_book( &books[i]) ;
 }
 printf("\nPrinting the names of the books in the Library in a nice Format :\n");
 do_for_books(books,Tweny,&print_nicely);
 printf("\nPrinting Only NON FICTION book's name and it's field  : \n");
 do_for_books(books,Tweny,&print_non_fiction);
 printf("\nPrinting book's Promotion if its Higher than 50 else its prints nothing... \n");
 do_for_books(books,Tweny,&print_most_promoted);
 /* printing the result of func min_promotion and min_thrilling_factor */
 printf("\nMinimum Promotion in  books is : %d",get_min_promotion(books));
 printf("\nMinimum Thrilling factor in  books is : %.2f",get_min_thrilling_factor(books));
 /* getting from the user the use of the array of pointers oF  BookCopy struct */
 printf("\n\nPlease Enter the size of  Copy Books you want to add !!!:  ");
 scanf("%d",&size);
 pointer_Copy= (BookCopy*) malloc(sizeof(BookCopy));
 if(pointer_Copy==NULL){
    printf("Error! memory not allocated.");
        exit(0);
 }

 Lib_Books=  (BookCopy**)malloc(size* sizeof(pointer_Copy));
 if(Lib_Books==NULL){
     printf("Error! memory not allocated.");
        exit(0);
 }
 free(pointer_Copy);
  i=0;

 /* check if there is a space */
  if(Lib_Books == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }

 /* Adding  Copy Of Books to the Lib_Books */
 for (j=0;j<size;j++) {
     do {
        printf("   ---   \n");
        printf("Please Add abook-copy to the Library!\n");
        printf("Enter Internal Book Number : ");
        scanf("%ld",&int_Book_Num);
        /* check if there is this int_Book_Num */
        Book_Index=get_Index(int_Book_Num);
        if(Book_Index!=-1) {
        Lib_Books[j]=create_copy(books[Book_Index],int_Book_Num, binary_010100);
        print_copy(Lib_Books[j]);
        }
        else {
            printf ("The Value You Have Entered is Incorrect!\n");
            printf("Please Enter  Again!!!, Thank you ;)\n");
        }
     }
        while(Book_Index==-1);
 }

 while (True){
 printf ("\nThe menu : \n");
 printf("Please Choose Number: \n");
 printf("1.Borrow a book-copy.\n");
 printf("2.Return a book-copy.\n");
 printf("9.Exit\n");
 scanf("%d",&num);
 switch (num) {
     case 1: printf("Please Enter The Serial Number of the Book: ") ;

     scanf("%ld",&serial_number);
      Search_Copy =searching_Serial_num( serial_number,Lib_Books,size);
      if(Search_Copy==NULL){
         printf(" Sorry!! Incorrect Serial Number \n");
         printf(" Please Try Again!!!\n");
         break;
      }
      if(borrow_copy(Search_Copy, 1)==-1 ){
         printf(" Sorry!! The Book has been Borrowed  already!!\n");
         break;
      }
     printf(" Amazing !!! the book copy has been borrowed successfully ;)\n");
     Search_Copy->borrowing_times+=1;
     break;
     case 2:printf("Please Enter The Serial Number of the Book: ") ;
     scanf("%ld",&seri_num);
     Search_Copy2 =searching_Serial_num(seri_num,Lib_Books,size);
     if(Search_Copy2==NULL){
         printf(" Sorry!! Incorrect Serial Number \n");
         printf(" Please Try Again!!!\n");
         break;
      }
      if(borrow_copy(Search_Copy2, 0)==-1 ){
         printf(" Sorry!! The Book has not been Borrowed yet in order to return it!!\n");
         break;
      }
     printf(" Amazing !!! the book copy has been returned successfully ;)\n");
     break;
     case 9: printf("Good Bye!!!");
      /* free the dynamic array */
     for (i=0;i<size;i++){
     free(Lib_Books[i]);
      }
       free(Lib_Books);
     return 1;

     default : printf("The number you have entered is not in the menu!!!,Try again!");
 }
 }

}
