#ifndef B10432001_H
#define B10432001_H
#include"view.h"
#include"model.h"

class B10432001 : public view
{
//friend class Model;
public:

virtual void changeView(Model::State myState);
};

#endif
