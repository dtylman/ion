/*
 * File:   ModelSubsystem.h
 * Author: danny
 *
 * Created on January 24, 2015, 6:42 PM
 */

#ifndef MODELSUBSYSTEM_H
#define	MODELSUBSYSTEM_H

#include <Poco/Util/Subsystem.h>
#include "Model.h"

class ModelSubsystem : public Poco::Util::Subsystem
{
public:
    ModelSubsystem();
protected:
    virtual ~ModelSubsystem();
    virtual const char* name() const;
    virtual void initialize(Poco::Util::Application& app);
    virtual void uninitialize();
private:
    void addModel(Model* model);
    Model::Container _models;
};

#endif	/* MODELSUBSYSTEM_H */

