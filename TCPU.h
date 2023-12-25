#pragma once
#include "TTaskFlow.h"

class TCPU
{
public:

	unsigned int cpu_power_critical;
	bool state;

	void ProcessTask(TTaskFlow& myflow);
	bool IsOccupied();
};
