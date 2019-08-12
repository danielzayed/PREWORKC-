#include <unistd.h>
#include <list>
#include<iterator>
#include "my_time.h"
char Time::day_del;
char Time::std_del;
unsigned int reverse_int(unsigned int Temp){
    unsigned int rev_integer=0;
     while(Temp >0){
        rev_integer*=10;
        rev_integer+=(Temp %10);
        Temp=Temp/10;
      }
      return rev_integer;


}

    Time::Time(unsigned int hours , unsigned char minutes ,unsigned char seconds /* 0*/) :hours(hours),minutes(minutes),seconds(seconds) {
    try {
         if(hours> One_Hunderd_Thouthand){
        throw invalid_argument("invalid variable hours.") ;
     }
     else if(minutes>Max_Sec_Min) {
       throw invalid_argument("invalid variable minutes.");
     }
     else if (seconds >Max_Sec_Min){
        throw invalid_argument ("invalid variable seconds.");
     }
    }
     catch (const invalid_argument& e) {
      cerr<<"exception caught: "<<e.what()<<'\n';
     }
     day_del='.';
     std_del=':';
}


    Time:: Time(unsigned int seconds /* 0*/){
        unsigned int temp;

        temp=seconds /60;
        if(temp >=60 ){
          this->hours=temp/60;
          this->minutes=temp-(this->hours*60);

        }
        else {
            this->hours=zero;;
            this-> minutes=temp;
        }
         this->seconds =seconds -(temp*60);
         day_del='.';
         std_del=':';

     }
string Time:: get_as_string(bool is_using_days ) const {
    string time;
    unsigned int temp=0;
    short int _hours;
    unsigned int rev_hours=zero;
     if(is_using_days){
       temp=this->hours/Full_Day;
      _hours= this->hours-(temp*Full_Day);
       // pushing back days ...
       rev_hours=reverse_int(temp);
       if(rev_hours==zero){
        time.push_back(ZeroAsChar);
       }
       while(rev_hours>zero) {
        temp=rev_hours%10;
        time.push_back(temp+ZeroAsChar);
        rev_hours=rev_hours/10;
        }
       time.push_back(day_del);

     //continue the other vars as standard ...
     }
      temp=_hours; // helper var;

     // reversing hours
      rev_hours=reverse_int(temp);
      if(rev_hours==zero){
        time.push_back(ZeroAsChar);
       }
      while(rev_hours>zero) {
        temp=rev_hours%10;
        time.push_back(temp+ZeroAsChar);
        rev_hours=rev_hours/10;
      }

     time.push_back(std_del);
      // adding the minutes
        unsigned char help=minutes/10;
        char first_dig=help%10;
        char sec_dig=minutes%10;
        //Adding the first Argument
        time.push_back(first_dig+ZeroAsChar);
        time.push_back(sec_dig+ZeroAsChar);
         time.push_back(std_del);
        // adding the seconds ;
        help=seconds/10;
        first_dig=help%10;
        sec_dig=seconds%10;
        time.push_back(first_dig+ZeroAsChar);
        time.push_back(sec_dig+ZeroAsChar);
return time ;
     }

unsigned long int Time :: get_seconds () const {
unsigned long int SumOfSeconds=zero;
SumOfSeconds=this->seconds;
SumOfSeconds+=(this->minutes*60);
return(SumOfSeconds+(this->hours*60*60));
}

Time Time:: operator + (const Time& Time_1) const  {
 Time time(zero);
  time.seconds=this->seconds+Time_1.seconds;
  time.minutes=this->minutes+Time_1.minutes;
  time.hours=this->hours+Time_1.hours;
  if(time.seconds >Max_Sec_Min){
    time.minutes+=1;
    time.seconds=time.seconds-60;
  }
  if(time.minutes>Max_Sec_Min)
  {
    time.hours+=1;
    time.minutes=time.minutes-60;
  }

return time;
}

Time Time ::operator+(const unsigned long int secs) const  {
Time Time_2(secs);
Time sum_time=this->operator+(Time_2);
return sum_time;

}

Time  operator+(const unsigned long int secs,const Time& Time_1)  {
  return( Time_1+secs);
}
ostream& operator<<(ostream& os, const Time& T1){
os <<"The Time is: " <<T1.get_as_string(true)<<"."<<endl;
return os ;
}

bool  operator==(const Time& Time_1,const Time& Time_2){
if(Time_1.hours==Time_2.hours && Time_1.minutes==Time_2.minutes && Time_1.seconds==Time_2.seconds) {
   return true;
}
return false ;
}
bool  operator!=(const Time& Time_1,const Time& Time_2){
if(Time_1.hours==Time_2.hours && Time_1.minutes==Time_2.minutes && Time_1.seconds==Time_2.seconds) {
   return false;
}
return true;
}
bool  operator< (const Time& Time_1,const Time& Time_2){
if(Time_1.hours<Time_2.hours){
    return true;
}

else if(Time_1.hours==Time_2.hours){
if(Time_1.minutes<Time_2.minutes) {
    return true;}
else if(Time_1.minutes==Time_2.minutes){
 if(Time_1.seconds<Time_2.seconds){
    return true;
 }
 // if Time_!.seconds ==Time_2.seconds
 return false;
}
 else {
    return false;
 }
}

else {
    return false;
}
}
bool operator<=(const Time& Time_1,const Time& Time_2){
    if (Time_1==Time_2 || Time_1 < Time_2) {
        return true;
    }
    return false ;
}

bool operator>(const Time& Time_1,const Time& Time_2){
return (Time_2<Time_1);

}
bool  operator>=(const Time& Time_1 ,const Time& Time_2){
return (Time_1>Time_2 || Time_1==Time_2);
}
Time&  Time::operator+=( const unsigned long int secs) {
    (*this) =  secs+(*this);
    return (*this);
}
 void Time:: set_delimiters( char day_del_1 ,char std_del_1){
     try{
if (day_del_1 >= ZeroAsChar && day_del_1 <=NineAsChar){
    throw invalid_argument(" Invalid Day Delimiter ");
}
if (std_del_1 >= ZeroAsChar && std_del_1 <= NineAsChar){
    throw invalid_argument(" Invalid Standard Delimiter ");
}
     }
     catch(const invalid_argument& e){
     cerr<< "Exception Caught: "<<e.what()<<endl;
     }
 day_del=day_del_1;
 std_del=std_del_1;
 }
   void print( const Time& The_Time) {
    string Time_in_string=The_Time.get_as_string(true);
    cout<<"The Time is :  " <<Time_in_string<<"."<<endl;
   }

   Timer::Timer(Time trg ,MsgPrinter* pptr){
    Time t(0);
    this->target=trg;
    this->pprinter=pptr;
    this->clock=t;
   }
   inline void Timer::tick()  {
    this->clock+=1; // clock+sec
    if(this->clock>=target){
        pprinter->print();
    }
    return ;
   }

   inline void Timer::tick(unsigned int secs) {
    clock=clock+secs;
    if(this->clock>=target){
        pprinter->print();
    }
    return ;
   }

inline void Timer::tick(string qty) {

    if(check_Min(qty)){
        this->clock+=one_min;
    }
    else if(check_Hour(qty)){
        this->clock+=one_hour;
    }
    else{
        try{
        throw invalid_argument("invalid String!!!");
        }
        catch (const invalid_argument& e) {
        cerr<<"Exception caught: "<<e.what()<<endl;
        }
        }
          if(this->clock>=this->target){
        pprinter->print();
    }
}

bool check_Min(string qty )  {
    if(qty=="M" || qty=="m" || qty=="Minute"|| qty=="minute" ||qty=="Min"||qty=="min"){
        return true;
    }
    return false;
}
bool check_Hour(string qty){
 if(qty=="H"|| qty=="h"|| qty=="Hour"||qty=="hour"){
        return true;
    }
 return false;
}

 inline void Timer::tick(string qty,unsigned int amount)  {
    if(check_Min(qty)){
        this->clock+=one_min*amount;
    }
   else if(check_Hour(qty)){
        this->clock+=one_hour*amount;
    }
    else{
            try{
        throw invalid_argument("invalid String!!!");
            }
        catch (const invalid_argument& e) {
        cerr<<"Exception caught: "<<e.what()<<endl;
        }
        }
    if(this->clock >=target){
        pprinter->print();
    }
}


void run_timer_1() {
Time time (60*90); //  one and ahalf hour = 90 min = 60 *90 secs
MsgPrinter* msg=new MsgPrinter("HelloWorld!");
Timer ninteyMinutes(time,msg);

int i=0;
for(i=1;i<=50;i++){
    cout<<"Iteration number : "<<i<<endl;
    ninteyMinutes.tick("Min",2);
}
delete(msg);
return;
}
void run_timer_2()  {
Time time (7); //  7 secs
MsgPrinter* msg= new MsgPrinter("Seven Seconds");
Timer Sevenseconds(time,msg);
int i=0;
for(i=1;i<=10;i++){
    usleep(1000); // sleep One second = 1000
    cout<<"Iteration number : "<<i<<endl;
    Sevenseconds.tick();
}
delete(msg);
return;
}
void run_timer_3() {
    MsgPrinter* printers[3];
    printers[0]= new MsgPrinter("This is the message");
    printers[1]= new MsgPrinterSurrounding("Surrounded","---Start---","----End----");
    MsgPrinterMultipleSurrounding* msgprinter=new MsgPrinterMultipleSurrounding("Really Surrounded",">>>>>>>","<<<<<<<");
    msgprinter->set_times(3);
    printers[2]=msgprinter;
    Time t_1(10),t_2(15),t_3(20),t_4(25),t_5(30);
    Timer t1(t_1,printers[0]);
    Timer t2(t_2,printers[1]);
    Timer t3(t_3,printers[1]);
    Timer t4(t_4,printers[2]);
    Timer t5(t_5,printers[2]);
    int i=0;
    for ( i=1;i<=40;i++){
        cout<<"Iteration number : "<<i<<endl;
        t1.tick();
        t2.tick();
        t3.tick();
        t4.tick();
        t5.tick();
    }
    for(i=0;i<3;i++){
        delete(printers[i]);
    }
    return ;
}
 void time_reset( Time* t){
 t->hours=0;
 t->minutes=0;
 t->seconds=0;
 }
 void run_timer_4(){
 list <Timer> timers_list;
  // Declaring iterator to a vector
    list<Timer>::iterator iter;
 Time t1(10),t2(15),t3(20),t4(25),t5(30);
 MsgPrinter p1("This is the message");
 MsgPrinterSurrounding p2("Surrounded","---Start---","----End----");
 MsgPrinterMultipleSurrounding p3("Really Surrounded",">>>>>>>","<<<<<<<");
 p3.set_times(3);// set times to 3 ;
 MsgPrinter* pointer1=(&p1);
 MsgPrinter*pointer2=(&p2);
 MsgPrinter *pointer3=(&p3);
 timers_list.push_back(Timer(t1,pointer1));
 timers_list.push_back(Timer(t2,pointer2));
 timers_list.push_back(Timer(t3,pointer2));
 timers_list.push_back(Timer(t4,pointer3));
 timers_list.push_back(Timer(t5,pointer3));
int i=0;
for(i=1;i<=30;i++){
 cout<<"Iteration number : "<<i<<endl;
for(iter=timers_list.begin();iter!=timers_list.end();iter++){
    iter->tick();
}
}

 }


