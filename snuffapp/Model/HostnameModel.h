/*
 * File:   HostnameModel.h
 * Author: danny
 *
 * Created on January 24, 2015, 8:51 PM
 */

#ifndef HOSTNAMEMODEL_H
#define	HOSTNAMEMODEL_H

#include "Model.h"
//MAC - hostname, nbname

class HostnameModel : public Model
{
public:
    HostnameModel();

    virtual void initialize();

protected:
    virtual ~HostnameModel();
private:

};

#endif	/* HOSTNAMEMODEL_H */

