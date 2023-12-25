#include "TTaskFlow.h"

bool TTaskFlow::HasTask()
{
	return (!queue.Empty());
}

bool TTaskFlow::NewTask()
{
	return (random());
}