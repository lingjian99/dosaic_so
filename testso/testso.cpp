#include "dosaic.h"
#include <iostream>
#include "mystring.h"

CDosaic dosaic;
extern "C" void do_dosaic(wchar_t* ws)
{
       wstring wstr(ws);
       dosaic.setFile(ws2s(wstr));
       dosaic.implement(); 
       dosaic.Save();
}