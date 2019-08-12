#include "my_time.h"
#include "testPhases.h"

 void test_phase_1() {
Time  T1_Test(80,20,20);
Time  T2_Test(100,24,24);
print(T1_Test);
T1_Test.set_delimiters(';','$');
print(T1_Test);
cout<<"This time seconds :" <<T1_Test.get_seconds()<<endl;
cout<<"B4 Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
T2_Test=T2_Test+T1_Test ;
cout<<" After Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
T2_Test+=10;
cout<<"Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
bool check_Test= (T2_Test>=T1_Test);
bool check_eq= (T2_Test==T1_Test);
cout<<"Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
}
void test_phase_2() {
run_timer_1();
run_timer_2();

}
void test_phase_3(){
//run_timer_3();
run_timer_4();


}
  /*
Time  T1_Test(1,20,50);
Time  T2_Test(100,24,24);
print(T1_Test);
T1_Test.set_delimiters(';','$');
print(T1_Test);
cout<<"This time in seconds :" <<T1_Test.get_seconds()<<endl;
cout<<"Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
T2_Test=T2_Test+T1_Test ;
T2_Test=T1_Test+20;
bool check_Test= (T2_Test>=T1_Test);
bool check_eq= (T2_Test==T1_Test);
cout<<check_eq<<"  "<<check_Test<<endl;
cout<<"Printing Time : " <<"TIME 1 : "<<T1_Test<<"Time 2:"<<T2_Test<<endl;
    return 0;*/
