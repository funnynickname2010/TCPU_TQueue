#include "TComputationSystem.h"

void ComputationSystem::NextTic()
{
	tasks_generated_in_total++;
	bool cpu_is_occupied = (cpu.IsOccupied());
	bool flow_new_task = (flow.NewTask());

	if (!cpu.IsOccupied())
	{
		if (flow.HasTask())
		{
			cpu.ProcessTask(flow);
		}
		else
		{
			cpu_idle++;
		}
	}
	else
	{

	}
}