#ifndef Session_h
#define Session_h

#include <WString.h>

class Session
{
  private:
    String sessionName;
    long id;
    unsigned long timePass;
    bool Access;

  public:
    String  getSessionName() {return sessionName;};
    bool getState();
    unsigned long getTimePass(){return timePass;};
    void setTimePass(unsigned long timerth);
    Session();
    void deleteData();
    void invalidate();
    void setState(bool v);
};

#endif
