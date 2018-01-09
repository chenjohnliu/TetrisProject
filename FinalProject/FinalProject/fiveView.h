#pragma once
#include"view.h"
#include"model.h"

class B10432040 : public view
{
	//friend class Model;
public:

	virtual void changeView(Model::State myState);
};

class B10432014 : public view
{
	//friend class Model;
public:

	virtual void changeView(Model::State myState);
};

class B10432007 : public view
{
    //friend class Model;
public:

    virtual void changeView(Model::State myState);
};