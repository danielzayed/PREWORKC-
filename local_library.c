#include "local_library.h"
#include <string.h>
#include <stddef.h>

Book books[] = {
 {1001, "Sun Don't Shine", 40, ADULT,DRAMA},
 {1002, "Irma la dos", -25, DOCUMENTARY,THRILLER},
 {1003, "Starship Troopers: Invasion", -68, KIDS,COMEDY},
 {1004, "Year of the Jellyfish", 5, ADULT,NON_FICTION},
 {1005, "After Life", -95, DOCUMENTARY,NON_FICTION},
 {1006, "Rest Stop", 20, HIGHSCHOOL,DRAMA},
 {1007, "Wuthering Heights", 56, KIDS,THRILLER},
 {1008, "New Adventures of Pippi Longstocking", 11, HIGHSCHOOL,NON_FICTION},
 {1009, "She Does Not Drink, Smoke or Flirt", 23, KIDS,DRAMA},
 {1010, "F.I.S.T.", 97, HIGHSCHOOL,NON_FICTION},
 {1011, "Cruise", -97, HIGHSCHOOL,NON_FICTION},
 {1012, "Letter to Elia, A", 54, KIDS,DRAMA},
 {1013, "To Be and to Have", -57, ADULT,THRILLER},
 {1014, "Get Hard", -66, HIGHSCHOOL,THRILLER},
 {1015, "A Nation's Battle for Life", 51, ADULT,NON_FICTION},
 {1016, "Place Called Chiapas", 76, COMICS,THRILLER},
 {1017, "A Drama of the Wilderness", 55, COMICS,COMEDY},
 {1018, "Ladies Man", 46, ADULT,COMEDY},
 {1019, "Film Geek", -60, COMICS,COMEDY},
 {1020, "Raining Stones", -83, DOCUMENTARY,NON_FICTION}
};



 const Book * get_pointer() {
    return (&books[0]);
}

void specify_Genre_vars(Book * books) {
    char Non_fic_hist[]="HIST";
books[0].GENRE.Drama.plot_quailty=33;
books[0].GENRE.Drama.quailty=2;
books[1].GENRE.thrilling_factor=3.5;
books[2].GENRE.COMEDY.humor_type='N';
books[2].GENRE.COMEDY.quailty_of_humor=556;
strncpy(books[3].GENRE.NON_FICTION_field,Non_fic_hist,5);
strncpy(books[4].GENRE.NON_FICTION_field,Non_fic_hist,5);
books[5].GENRE.Drama.quailty=12;
books[5].GENRE.Drama.plot_quailty=56;
books[6].GENRE.thrilling_factor=2.5;
strncpy(books[7].GENRE.NON_FICTION_field,Non_fic_hist,5);
books[8].GENRE.Drama.quailty=12;
books[8].GENRE.Drama.plot_quailty=80;
strncpy(books[9].GENRE.NON_FICTION_field,Non_fic_hist,5);
strncpy(books[10].GENRE.NON_FICTION_field,Non_fic_hist,5);
books[11].GENRE.Drama.quailty=25;
books[11].GENRE.Drama.plot_quailty=80;
books[12].GENRE.thrilling_factor=5;
books[13].GENRE.thrilling_factor=1.2;
strncpy(books[14].GENRE.NON_FICTION_field,Non_fic_hist,5);
books[15].GENRE.thrilling_factor=1.6;
books[16].GENRE.COMEDY.humor_type='N';
books[16].GENRE.COMEDY.quailty_of_humor=546;
books[17].GENRE.COMEDY.humor_type='N';
books[17].GENRE.COMEDY.quailty_of_humor=12;
books[18].GENRE.COMEDY.humor_type='N';
books[18].GENRE.COMEDY.quailty_of_humor=269;
strncpy(books[19].GENRE.NON_FICTION_field,Non_fic_hist,5);
return ;
}
int get_num_Of_Books(){
return sizeof(books)/(sizeof(books[0]));
}

char* get_name (long int _int_Book_Number) {
 int len=get_num_Of_Books();
int  i=0;
 while (i< len ){
    if(books[i].int_Book_Number==_int_Book_Number) {
        return books[i].name;
    }
    i++;
 }
return NULL;
}

int get_Index(long int int_Book_Num) {
    int len=get_num_Of_Books();
    int i=0;
    while (i<len) {
        if(books[i].int_Book_Number==int_Book_Num) {
            return i;
        }
        i++;
    }

return -1 ;

}
