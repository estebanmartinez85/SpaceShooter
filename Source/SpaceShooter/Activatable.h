#pragma once

#include "Activatable.generated.h"

/**  */
UINTERFACE()
class SPACESHOOTER_API UActivatable : public UInterface
{
	GENERATED_BODY()
};

/**  */
class SPACESHOOTER_API IActivatable
{
	GENERATED_BODY()
protected:
	bool Activated = false;
};