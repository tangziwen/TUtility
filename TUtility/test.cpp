#include <iostream>

using namespace std;
#include "TUtility.h"
using namespace tzw;

void func_a()
{
    T_ENTER;
    T_TRACE_STATCK;
    T_RETURN;
}

void func_b()
{
    T_ENTER;
    func_a();
    T_RETURN;
}


void func_c()
{
    T_ENTER;
    func_b();
    T_RETURN;
}
int main()
{
    T_ENTER;
    Tstring heheda = "wo ri ni ma";
    heheda += "haha";
    Tlog()<<TlogBegin<<"haha"<<TlogEnd;
    T_Log_AT("shall trigger a log");
    func_c ();
    return 0;
}
