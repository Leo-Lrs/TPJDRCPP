#include "eventfactory.h"
#include "hero.h"
#include <QDebug>

QMap<QString, CreateEventFn> EventFactory::registeredFunctionsEvent;

EventFactory::EventFactory()
{

}

void EventFactory::Register(QString type, CreateEventFn fn)
{
    qDebug()  << "Register" << type;
    registeredFunctionsEvent[type] = fn;
}



void EventFactory::setDmg()
{
    for (auto event : qAsConst(Event::createdEvent)) {
           event->setDmg();
    }
    qDebug() << "Setting up all dmg";
}

void EventFactory::Attaque(int i)
{
    qDebug() << "Enemy attack";
    Event::createdEvent.at(i)->Info();


    for (auto hero : qAsConst(Hero::created)) {
        QString resi = hero->resistance();
        if (resi == "Physique") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_phy();
            hero->receiveDmgs(dmg);
        }
        else if (resi == "Magique") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_mag();
            hero->receiveDmgs(dmg);
        }
        else if (resi == "Piege") {
            int dmg = hero->resistancePts() - Event::createdEvent.at(i)->getDmg_pieges();
            hero->receiveDmgs(dmg);
        }
    }

}

Event *EventFactory::Create(QString type)
{
    qDebug()  << "Create" << type ;
    Event *e;
    CreateEventFn fn = registeredFunctionsEvent[type];
    if (fn != nullptr) {
        e = fn();
        e->setType(type);
        Event::createdEvent.push_back(e);
        return e;
    }
    qDebug() << "unsupported type" << type;
    return nullptr;
}
