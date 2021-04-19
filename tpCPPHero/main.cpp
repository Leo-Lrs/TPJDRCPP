#include <QCoreApplication>
#include "hero.h"
#include "heroesfactory.h"
#include "event.h"
#include "eventfactory.h"
#include <QDebug>

void testFactory() {

    HeroesFactory herosFactory;
    herosFactory.Register("Warrior", &Warrior::create);
    herosFactory.Register("Wizzard", &Wizzard::create);
    herosFactory.Register("Rogue", &Rogue::create);
    Hero *John = herosFactory.Create("Warrior", "John");
    Hero *Jean = herosFactory.Create("Rogue", "Jean");
    Hero *Ali = herosFactory.Create("Wizzard", "Ali");
    qDebug() << "\n";
    herosFactory.Info();
    herosFactory.Resistance();
    qDebug() << "\n";

    EventFactory eventFactory;
    eventFactory.Register("Poisoned Arrows", &PoisonedArrows::create);
    eventFactory.Register("Sword", &Sword::create);
    eventFactory.Register("Fireball", &Fireball::create);
    eventFactory.Register("Fire Sword", &FireSword::create);
    qDebug() << "\n";
    Event *PoisonedArrows = eventFactory.Create("Poisoned Arrows");
    Event *Sword = eventFactory.Create("Sword");
    Event *Fireball = eventFactory.Create("Fireball");
    Event *FireSword = eventFactory.Create("Fire Sword");
    qDebug() << "\n";
    eventFactory.setDmg();
    int randomNumber;

    while (herosFactory.NbHeroes()>1) {

        randomNumber = (rand() % Event::createdEvent.size());
        qDebug() << "\n";
        eventFactory.Attaque(randomNumber);
        herosFactory.Info();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testFactory();

    return a.exec();
}



