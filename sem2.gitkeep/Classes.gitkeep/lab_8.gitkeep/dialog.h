#pragma once
#include "tree.h"
#include "event.h"

using namespace std;

class Dialog :
    public Tree {
protected:
    int EndState;
public:
    Dialog(void);
    virtual ~Dialog(void);
    virtual void GetEvent(TEvent&);
    virtual int Execute();
    virtual void HandleEvent(TEvent&);
    virtual void ClearEvent(TEvent&);
    int Valid();
    void EndExec();
};
