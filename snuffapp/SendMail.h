/*
 * File:   SendMail.h
 * Author: danny
 *
 * Created on February 4, 2015, 11:10 AM
 */

#ifndef SENDMAIL_H
#define	SENDMAIL_H

#include "EventData.h"

class SendMail
{
public:
    SendMail();
    void send(const EventData& event);
    virtual ~SendMail();
private:

};

#endif	/* SENDMAIL_H */

