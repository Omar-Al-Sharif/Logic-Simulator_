#pragma once
#include "action.h"
#include "../XNOR.h"
#include "../Components/Component.h"

class AddXNOR : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddXNOR(ApplicationManager* pApp);
	virtual ~AddXNOR(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

