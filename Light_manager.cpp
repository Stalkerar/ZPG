#include "Light_manager.h"

Light_manager::Light_manager()
{
	
}


PointLight* Light_manager::getPointLight(int idx)
{
	return this->plights[idx];
}

void Light_manager::addPointLight(PointLight* in)
{
	this->plights.push_back(in);
}

void Light_manager::setDirectLight(DirectLight* in)
{
	this->dirLight = in;
}

DirectLight* Light_manager::getDirectLight()
{
	return this->dirLight;
}

SpotLight* Light_manager::getSpotLight()
{
	return this->spotLight;
}

void Light_manager::setSpotLight(SpotLight* in)
{
	this->spotLight = in;
}