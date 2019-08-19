#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#define MIN(a,b) (a<b? a : b)
#define ten_thouthand 10000
#define Tweny 20
#define charcter_a 97
#define charcter_A 65
#define charcter_z 122
#define charcter_Z 90
#define binary_000001 0x01
#define binary_000010 0x02
#define binary_000100 0x04
#define binary_001000 0x08
#define binary_010000 0x10
#define binary_100000 0x20
#define binary_011000 0x18
#define binary_000000 0x00
#define FOUR_Issues 0x0F
static void print_DRAMA(union Genre drama);
static void print_THRILLER(union Genre drama);
static void print_COMEDY(union Genre drama);
static void print_NON_FICTION(union Genre drama);
static char* zones[]={"kids","highschool","adults","documentary","comics"};
char* get_zone_name(enum zone The_Book_Zone) {

    return zones[The_Book_Zone];
}
void print_book(Book * book) {
printf("book's name: %s \n book's Internal Number: %ld \n book's Promotion : %d \n book's zone: %s \n ",book->name,
       book->int_Book_Number,book->promotion,get_zone_name(book->The_zone));
       if(book->bk_GENRE==DRAMA)
       print_DRAMA(book->GENRE);
       else if(book->bk_GENRE==THRILLER)
        print_THRILLER(book->GENRE);
       else if(book->bk_GENRE==COMEDY)
        print_COMEDY(book->GENRE);
       else {
        print_NON_FICTION(book->GENRE);
       }
}
static void print_DRAMA(union Genre drama){
printf("Genre : Drama \n");
printf(" Text quality: %u \n",drama.Drama.quailty);
printf(" Plot quality: %u \n",drama.Drama.plot_quailty);
}
static void print_THRILLER(union Genre thriller){
printf("Genre : Thriller \n");
printf(" Thrilling factor: %f \n",thriller.thrilling_factor);
}
static void print_COMEDY(union Genre comedy){
printf("Genre: Comedy \n");
printf(" Quality of Humor: %u \n",comedy.COMEDY.quailty_of_humor);
printf(" Humor type: %c \n",comedy.COMEDY.humor_type);
}
static void print_NON_FICTION(union Genre non_fiction){
printf("Genre: Non Fiction \n");
printf(" Field Of the Book: %s\n",non_fiction.NON_FICTION_field);
}
int borrow_copy(BookCopy* book, int is_borrowing) {
  int book_status= book->is_borrowed;
   if (book_status == is_borrowing)
       return -1 ;  /* error value */
   book->is_borrowed=is_borrowing;
   return is_borrowing;
}

void print_copy(BookCopy * the_book) {
 Book* pointer_Book=&(the_book->Copy);
 print_book(pointer_Book);
 printf(" serial Number : %ld \n",the_book->serial_number);
 if(the_book->is_borrowed)
    printf(" is borrowed: yes \n");
 else
    printf(" is borrowed: no \n");
  printf(" it has been borrowed %d times .\n",the_book->borrowing_times);
  printf(" copy Condition of The Book : \n");
   if(is_ok(the_book)){
            printf("    the copy condition is ok!!!\n");
        }
        if(is_bookbinder_required(the_book)){
            printf("    BookBinder is required\n");
        }
        if(is_librarian_required(the_book)){
            printf("    Librarian is required\n");
        }
        if(is_repairable(the_book)){
            printf("    The copy is repairable\n");
        }
        if(is_useless(the_book)){
            printf("    The Copy is Useless\n");
        }

 }

 void init_copy(BookCopy* copy_book,long int internal_Book_Number){
 static long int serial_num=ten_thouthand;
  copy_book->int_Book_Number=internal_Book_Number;
  copy_book->serial_number=serial_num;
  copy_book->is_borrowed=0;
  copy_book->borrowing_times=0;
 serial_num++;
 return;
 }
 unsigned int is_librarian_required(BookCopy* bookcopy){
      unsigned int condiotion_of_att ;
      unsigned int check_attribute ;
  condiotion_of_att=bookcopy->cond_of_att;
  check_attribute =binary_000001 & condiotion_of_att;
  if(check_attribute==binary_000001){
    return 1;
  }
  check_attribute=binary_000010&condiotion_of_att;
  if(check_attribute==binary_000010){
    return 1;
  }
  check_attribute=binary_000100&condiotion_of_att;
  if(check_attribute==binary_000100){
    return 1;
  }
  return 0;
 }
 unsigned int is_bookbinder_required(BookCopy* bookcopy){
 unsigned int condiotion_of_att ;
 unsigned int check_attribute;
  condiotion_of_att=bookcopy->cond_of_att;
  check_attribute =binary_100000 & condiotion_of_att;
  if(check_attribute==binary_100000){
    return 1;
  }
  check_attribute=binary_010000&condiotion_of_att;
  if(check_attribute==binary_010000){
    return 1;
  }
  check_attribute=binary_001000&condiotion_of_att;
  if(check_attribute==binary_001000){
    return 1;
  }
  return 0;
 }
 unsigned int is_repairable(BookCopy* bookcopy){
 unsigned int condiotion_of_att=bookcopy->cond_of_att ;
 unsigned int check_attribute =binary_011000 & condiotion_of_att;
  if(check_attribute==binary_000000){
    return 1;
  }
  return 0;
 }

unsigned int is_ok(BookCopy* bookcopy){
 unsigned int condiotion_of_att ;
  condiotion_of_att=bookcopy->cond_of_att;
  if(condiotion_of_att==binary_000000){
    return 1;
  }
  return 0;
}

unsigned int is_useless(BookCopy* bookcopy){
    unsigned int condiotion_of_att ;
    unsigned int size ;
  condiotion_of_att=bookcopy->cond_of_att;
   size=0;
   while(condiotion_of_att!=binary_000000){
  if(condiotion_of_att %2==1){
size++;
  }
  condiotion_of_att=condiotion_of_att>>1;
   }
return (size>=4);
}

unsigned int are_in_same_condition(BookCopy* bookcopy ,BookCopy* bookcopy2){
return (bookcopy2->cond_of_att==bookcopy->cond_of_att);

}

BookCopy* create_copy( Book copy,long int internalBookNumber,unsigned int condoition_of_att){
BookCopy* ptr_Copy;
ptr_Copy= (BookCopy*)malloc(sizeof(BookCopy));
ptr_Copy->Copy=copy;
init_copy(ptr_Copy,internalBookNumber);
ptr_Copy->cond_of_att=condoition_of_att;
return ptr_Copy;
}
void get_nice_book_name( char * ds,const char* src){
int i;
unsigned char flag;
char capital;
i=0;

flag=0;
while (src[i]!='\0'){
    if(flag==0 && (src[i]>=charcter_a && src[i]<=charcter_z)){
        capital=src[i]-charcter_a;
        ds[i]=capital+charcter_A;
        flag=1;
    }
    else if (flag==0 &&src[i]>=charcter_A && src[i]<=charcter_Z){
        flag=1;
        ds[i]=src[i];
    }

    else if(flag==1 && src[i]>=charcter_A && src[i]<=charcter_Z){
        capital=src[i]-charcter_A;
        ds[i]=capital+charcter_a;
    }
    else {
        ds[i]=src[i];
    }
    if(src[i]==' '){
        flag=0;
        ds[i]=src[i];
    }
    i++;
}
ds[i]='\0';
}
void print_nicely(const Book* pbook){
char des_name [BookmaxNumber];
get_nice_book_name(des_name,pbook->name);
printf("%s \n",des_name);
}
void print_non_fiction(const  Book* pbook){
    if(pbook->bk_GENRE==NON_FICTION){
        printf("Book's name : %s \n",pbook->name);
        printf("Book's field: %s \n",pbook->GENRE.NON_FICTION_field);
    }
    else{
        printf("---\n");
    }
}
void print_most_promoted(const Book* pbook){
if(pbook->promotion>50){
    printf("Book's promotion: %d  \n",pbook->promotion);
}
else {
    printf("nothing \n");
}
}

void do_for_books(Book * books,unsigned short num,Func_name action){
int i;
i=0;
for(i=0;i<num;i++){
    (*action)(&books[i]);
}
return;
}

int get_min_promotion(Book * books){
int i=0;
int min_pro=101; /* min promotion */
for(i=0;i<Tweny;i++){

   min_pro=MIN(books[i].promotion,min_pro);

}
return min_pro;
}
float get_min_thrilling_factor(Book* books){
int i=0;
float  thriling_fac=5.01; /* minimum thrilling factor */
for(i=0;i<Tweny;i++){
   if(books[i].bk_GENRE==THRILLER){
   thriling_fac=MIN(books[i].GENRE.thrilling_factor,thriling_fac);

}
}
return thriling_fac;
}
