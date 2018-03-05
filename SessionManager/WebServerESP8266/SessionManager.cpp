#include "SessionManager.h"


SessionManager::SessionManager(Session *s)
{
  session = s;
  timeoutValue = 300000;  
}

void SessionManager::flagInvalidSessions()
{
  if ((session->getState())&& session->getTimePass()> timeoutValue )
  {
    session->invalidate();
  }
}

