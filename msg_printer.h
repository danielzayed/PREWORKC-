#include <string>
class MsgPrinter {
private:
const std::string message;
public:
MsgPrinter(const std::string& msg);
MsgPrinter();
virtual void print() const;
~MsgPrinter();
std::string get_msg()const;
};

class MsgPrinterSurrounding:public MsgPrinter {
private:
    char* before;
    char* after;
protected:
    virtual void print_before()const ;
    void print_after()const;
public :
    MsgPrinterSurrounding(const std::string& str);
    MsgPrinterSurrounding(const MsgPrinterSurrounding& msgprinter);
    MsgPrinterSurrounding( const std::string& str ,const char *before_msg,const char* after_msg);
    MsgPrinterSurrounding& operator=(const MsgPrinterSurrounding& Msg_);
    void print()const;
    ~MsgPrinterSurrounding();
};

class MsgPrinterMultipleSurrounding : public MsgPrinterSurrounding {
 unsigned char times ;
 public:

     MsgPrinterMultipleSurrounding(const std::string& Msg_);
     MsgPrinterMultipleSurrounding(const std::string & str,const char *before_msg,const char* after_msg) ;
     void set_times(unsigned char t);
     unsigned char get_times()const;
     void print_before()const ;
     void print_after() const;
     ~MsgPrinterMultipleSurrounding();


};
