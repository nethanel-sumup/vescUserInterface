#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0), level(36), speed(0)
{

}

void Model::tick()
{
	level += 0.1;
	if (level > 43)
	{
		level = 36;
	}
	if (modelListener)
	{
		modelListener->NotifyBatteryLevelChanged(level);
	}

	if (++speed > 99)
	{
		speed = 0;
	}
	if (modelListener)
	{
		modelListener->NotifySpeedChanged(speed);
	}

}
