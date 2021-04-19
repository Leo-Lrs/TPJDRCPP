#include "heroesfactory.h"
#include <QDebug>

QMap<QString, CreateHeroFn> HeroesFactory::registeredFunctions;

HeroesFactory::HeroesFactory()
{

}

void HeroesFactory::Register(QString type, CreateHeroFn fn)
{
    qDebug()  << "Register" << type;
    registeredFunctions[type] = fn;
}

void HeroesFactory::Info()
{
    for (auto hero : qAsConst(Hero::created)) {
       hero->Info();
    }
    qDebug() << "There are" << QString::number(Hero::created.size()) << "heroes left.";
}

void HeroesFactory::Resistance()
{
    for (auto hero : qAsConst(Hero::created)) {
       hero->Resistance();
    }
}

int HeroesFactory::NbHeroes()
{
    return Hero::created.size();
}

Hero *HeroesFactory::Create(QString type, QString name)
{
    qDebug()  << "Create" << type << name;
    Hero *h;
    CreateHeroFn fn = registeredFunctions[type];
    if (fn != nullptr) {
        h = fn();
        h->setType(type);
        h->setName(name);
        Hero::created.push_back(h);
        return h;
    }
    qDebug() << "unsupported type" << type;
    return nullptr;
}


