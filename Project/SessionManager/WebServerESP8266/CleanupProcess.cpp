#include "CleanupProcess.h"

CleanupProcess::CleanupProcess()
{

}

void CleanupProcess::clean(Session *s)
{  
  session = s;
  if ((session->getState() == false))
  {
    session->deleteData();
  }
}

