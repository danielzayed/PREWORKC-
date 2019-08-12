#include <string>
#include <stdexcept>
#include <string>
#include <iostream>
#include "msg_printer.h"
#define fifty_Nine 59
#define One_Hunderd_Thouthand 100000
#define ZeroAsChar 48
#define NineAsChar 57

using namespace std ;
class Time
{
    private :
    static const unsigned char zero=0;
    static const unsigned char Max_Sec_Min=59;
    static const unsigned char Full_Day=24;
    static const unsigned char sixty=60;
    static  char day_del;
    static  char std_del;
    unsigned int hours; // 0-100000
    unsigned char minutes; // 0-59
    unsigned char seconds;  // 0-59
    public:
     static void set_delimiters( char day_del_1 ,char std_del_1);
     Time(unsigned int hours , unsigned char minutes ,unsigned char seconds=0);
     Time(unsigned int seconds=0);
     string get_as_string(bool is_using_days )const ;
     unsigned long int get_seconds () const;
     Time operator + (const Time& Time_1 ) const;
     Time operator + (const unsigned long int secs)const;
     Time friend operator+(const unsigned long  int secs,const Time& Time_1);
     bool friend operator==(const Time& Time_1,const Time& Time_2);
     bool friend operator!=(const Time& Time_1,const Time& Time_2);
     bool friend operator<(const Time& Time_1,const Time& Time_2);
     bool friend operator<=(const Time& Time_1,const Time& Time_2);
     bool friend operator >(const Time& Time_1,const Time& Time_2);
     bool friend operator >=(const Time& Time_1,const Time& Time_2);
     friend ostream&  operator<<(ostream& os, const Time& T1);
     void friend time_reset( Time* t);
     Time& operator+= (const unsigned long int secs);
     ~Time (){};
};
class Timer {
Time target;
Time clock;
MsgPrinter* pprinter;
static const char zero=0;
static const char one_sec=1;
static const char one_min=60;
static const unsigned int one_hour=3600;
public:
Timer(Time trg ,MsgPrinter* pptr) ;
inline void tick();
inline void tick(unsigned int secs) ;
inline void tick(string qty) ;
inline void tick(string qty,unsigned int amount) ;
};
bool check_Min(string qty);
bool check_Hour(string qty);
void print( const Time& The_Time);
void time_reset( Time* t);
unsigned int reverse_int(unsigned int Temp);
Time operator+(const int secs,const Time& Time_1);
bool  operator==(const Time& Time_1,const Time& Time_2);
bool  operator!=(const Time& Time_1,const Time& Time_2);
bool  operator<(const Time& Time_1,const Time& Time_2);
bool  operator<=(const Time& Time_1,const Time& Time_2);
bool  operator >(const Time& Time_1,const Time& Time_2);
bool  operator >=(const Time& Time_1,const Time& Time_2);
ostream& operator<<(ostream& os, const Time& T1);
void run_timer_1() ;
void run_timer_2()  ;
void run_timer_3();
void run_timer_4();

