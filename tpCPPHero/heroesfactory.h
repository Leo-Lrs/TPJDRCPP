#ifndef HEROESFACTORY_H
#define HEROESFACTORY_H
#include "hero.h"

typedef Hero *(*CreateHeroFn)();

class HeroesFactory
{
public:

    HeroesFactory();
    static QMap<QString, CreateHeroFn> registeredFunctions;

    void Register(QString type, CreateHeroFn fn);
    void Info();
    void Resistance();
    int NbHeroes();

    Hero *Create(QString type, QString name);

};

#endif // HEROESFACTORY_H
