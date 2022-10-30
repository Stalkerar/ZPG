#include "Object_manager.h"



Object_manager::Object_manager()
{
	this->modelArr = new Object_model*();


}


void Object_manager::addModel(int in)
{
	Object_model* buffer = new Object_model(in);
	this->modelArr[this->objectCount] = buffer;
	this->objectCount++;
}

int Object_manager::getmodelCount()
{
	return this->objectCount;
}


Object_model* Object_manager::getModel(int idx)
{
	return this->modelArr[idx];
}