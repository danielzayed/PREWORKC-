#define BookmaxNumber 50
#define Five 5
#define Six_Bits 6
enum zone {KIDS,HIGHSCHOOL,ADULT,DOCUMENTARY,COMICS};
enum genere {DRAMA,THRILLER,COMEDY,NON_FICTION};


/*static void print_DRAMA(GENRE drama);
static void print_THRILLER(GENRE thriller);
static void print_COMEDY(GENRE comedy);
static void print_NON_FICTION(GENRE non_fiction);
*/
typedef struct Book {
 long int int_Book_Number;
 char name [BookmaxNumber];
 int promotion ;
 enum zone The_zone;
 enum genere bk_GENRE;/* book Genre */
 union Genre {
struct DRAMA {
unsigned int quailty;
unsigned int plot_quailty;}Drama;
float thrilling_factor;
struct comedy {
unsigned int quailty_of_humor;
char humor_type;
}COMEDY;
char NON_FICTION_field[Five];
}GENRE;

}Book;
typedef struct BookCopy {
 Book Copy;
 long int int_Book_Number;
 long int serial_number;
 int is_borrowed;
 int borrowing_times;
 unsigned int cond_of_att :Six_Bits;
 /* Cover ,Indexing ,Bar Code , Missing pages , Stained pages ,Spine*/
}BookCopy;
void print_book(Book * book);
char* get_zone_name(enum zone The_Book_Zone) ;
int borrow_copy(BookCopy* book, int is_borrowing);
void print_copy(BookCopy * the_book);
void init_copy(BookCopy* copy_book,long int internal_Book_Number);
unsigned int is_librarian_required(BookCopy* bookcopy);
unsigned int is_bookbinder_required(BookCopy* bookcopy);
unsigned int is_repairable(BookCopy* bookcopy);
unsigned int is_ok(BookCopy* bookcopy);
unsigned int is_useless(BookCopy* bookcopy);
unsigned int are_in_same_condition(BookCopy* bookcopy ,BookCopy* bookcopy2);
BookCopy* create_copy( Book copy,long int internalBookNumber,unsigned int condoition_of_att);
void get_nice_book_name( char * ds, const char* src);
void print_nicely(const Book* pbook);
void print_non_fiction(const  Book* pbook);
void print_most_promoted(const Book* pbook);
typedef void (*Func_name)(const Book* pbook) ;
void do_for_books(Book * books,unsigned short num,Func_name action);
int get_min_promotion(Book * books);
float get_min_thrilling_factor(Book* books);
