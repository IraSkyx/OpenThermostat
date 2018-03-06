#ifndef CleanupProcess_h
#define CleanupProcess_h

#include "Session.h"


class CleanupProcess
{
  private:
    Session *session;


  public:
    CleanupProcess();
    void clean(Session *s);

};

#endif
