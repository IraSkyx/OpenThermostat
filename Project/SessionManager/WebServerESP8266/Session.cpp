#include "Session.h"

Session::Session()
{
  id = 411;
  sessionName = "Sasa27";
  timePass = 0;
  Access = false;
}

void Session::deleteData()
{
  timePass = 0;
  Access = false;
}

void Session::invalidate()
{
  Access  = false;
}


bool Session::getState()
{
  return Access;
}

void Session::setTimePass(unsigned long timerth)
{
 timePass = timerth; 
}

void Session::setState(bool v)
{
  Access = v;
}




