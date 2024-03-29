#include "../Components/NAND2.h"
#include "../Components/Gate.h"
NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

//Ziad 
void NAND2::Operate()
{
	//caclulate the output status as the ORing of the two input pins

	//Add you code here
	if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}



}


// Function Draw
// Draws 2-input OR gate
void NAND2::Draw(Output* pOut, bool Selected)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND(m_GfxInfo, Selected);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}