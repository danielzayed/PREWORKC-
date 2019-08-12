#include "msg_printer.h"
#include<iostream>
using namespace std;

MsgPrinter::MsgPrinter(const string& msg):message(msg){

}
MsgPrinter::MsgPrinter():message(""){
}

void MsgPrinter::print()const{
std::cout<<"Message :"<<this->message<<std::endl;
return;
}
string MsgPrinter::get_msg() const{

return message;

}


MsgPrinter::~MsgPrinter(){
std::cout<<"End of MsgPrinter: "<<this->message<<std::endl;
}


  MsgPrinterSurrounding::MsgPrinterSurrounding(const string& str):MsgPrinter(str) {
before=NULL;
after=NULL;
}
MsgPrinterSurrounding::MsgPrinterSurrounding(const string &str ,const char *before_msg,const char* after_msg):MsgPrinter(str) {
if(before_msg==NULL || after_msg==NULL) {
        try{
    throw ("One or More of the arguments are null");
        }
    catch(const invalid_argument& e){
    cerr<<"Exception caught: "<<"MsgPrinterSurrounding ctr :"<<e.what()<<endl;
    }
}
string b4_msg(before_msg);
string af_msg(after_msg);
int len_for_b4=b4_msg.length()+1;
int len_for_af=af_msg.length()+1;
int i =0;
// allocating new array for b4_msg
before=new  char[len_for_b4];
after=new  char [len_for_af];
for(i=0;i<len_for_b4;i++){
    before[i]=before_msg[i];
}
before[i]='\0';
for(i=0;i<len_for_af;i++){
    after[i]=after_msg[i];
}
after[i]='\0';
}
 void MsgPrinterSurrounding::print_before()const {
cout<<"Before : "<<this->before<<endl;
}
void MsgPrinterSurrounding:: print_after()const{
cout<<"After : "<<this->after<<endl;
}
 void MsgPrinterSurrounding:: print()const{
     // prints the string b4
 this->print_before();
 // printing the msg in sub class MsgPrinter
 MsgPrinter::print();

 //printing the string after ;
 this->print_after();
 }

  MsgPrinterSurrounding::~MsgPrinterSurrounding() {
 delete(before);
 delete(after);
 cout<<"End of MsgPrinterSorrounding: "<<MsgPrinter::get_msg()<<endl;

 }

 /* Copy constructor */ MsgPrinterSurrounding::MsgPrinterSurrounding(const MsgPrinterSurrounding& msgprinter):MsgPrinter(msgprinter.get_msg())
 {

string b4(msgprinter.before);
string af(msgprinter.after);
int len_for_b4=b4.length()+1;
int len_for_af=af.length()+1;
int i =0;
// allocating new array for b4_msg
this->before= new  char[len_for_b4];;
this->after=new  char [len_for_af];
for(i=0;i<len_for_b4;i++){
    before[i]=msgprinter.before[i];
}
before[i]='\0';
for(i=0;i<len_for_af;i++){
    after[i]=msgprinter.after[i];
}
after[i]='\0';

}

MsgPrinterSurrounding& MsgPrinterSurrounding:: operator=(const MsgPrinterSurrounding& Msg_) {
int i=0;
// sets the message of Msg
string b4 (Msg_.before);
string af (Msg_.after);

/* sets the before and after message */
this->before=new char[b4.length()+1];
this->after=new char[af.length()+1];
for(i=0;i<b4.length();i++){
    before[i]=Msg_.before[i];
}
before[i]='\0';
for(i=0;i<af.length();i++){
    after[i]=Msg_.after[i];
}
after[i]='\0';
return (*this);
}
MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding( const string& str ,const char *before_msg,const char* after_msg):MsgPrinterSurrounding(str,before_msg,after_msg){
 this->times=2;
}
MsgPrinterMultipleSurrounding::MsgPrinterMultipleSurrounding(const string& Msg_):MsgPrinterSurrounding(Msg_){
this->times=2;

}

void MsgPrinterMultipleSurrounding:: set_times(unsigned char t){
this->times=t;
}
unsigned char MsgPrinterMultipleSurrounding::get_times() const {
return (this->times);
}
void MsgPrinterMultipleSurrounding::print_before() const {
int i=0;
for (i=0;i<times;i++){
    MsgPrinterSurrounding::print_before();
}
return ;
}

void MsgPrinterMultipleSurrounding::print_after() const {

int i=0;
for (i=0;i<times;i++){
    MsgPrinterSurrounding::print_after();
}
return ;
}
 MsgPrinterMultipleSurrounding::~MsgPrinterMultipleSurrounding(){
cout<<"End of MsgPrinterMultipleSurrounding: "<<MsgPrinter::get_msg()<<endl;
}
