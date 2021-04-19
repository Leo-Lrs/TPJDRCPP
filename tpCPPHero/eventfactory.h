#ifndef EVENTFACTORY_H
#define EVENTFACTORY_H
#include "event.h"
#include <QString>
#include <QMap>

typedef Event *(*CreateEventFn)();

class EventFactory
{
public:

    EventFactory();
    static QMap<QString, CreateEventFn> registeredFunctionsEvent;

    void Register(QString type, CreateEventFn fn);
    void setDmg();

    void Attaque(int i);

    Event *Create(QString type);

};

#endif // EVENTFACTORY_H
