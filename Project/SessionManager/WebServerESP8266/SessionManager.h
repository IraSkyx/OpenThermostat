#ifndef SessionManager_h
#define SessionManager_h

#include "Session.h"
#include "CleanupProcess.h"

class SessionManager
{
  private:
    Session *session;
    unsigned long timeoutValue;

  public:

    SessionManager(Session *s);
    void flagInvalidSessions();
    Session* getSession(){return session;};


};

#endif
