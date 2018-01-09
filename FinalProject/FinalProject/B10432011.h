#pragma once
#include"model.h"
#include"view.h"

class B10432011 : public view
{
	// change the block into cyan color
	virtual void changeView(Model::State myState);
};
