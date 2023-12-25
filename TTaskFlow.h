#pragma once
#include "TQueue.h"
#include <random>

class TTaskFlow
{
public:

	TQueue<int> queue;
	unsigned int flow_intensity_critical;

	bool HasTask();
	bool NewTask();
};
