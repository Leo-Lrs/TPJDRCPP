#ifndef EVENT_H
#define EVENT_H
#include <QString>
#include <QVector>
#include <QDebug>

class Event
{
public:
    static QVector<Event *> createdEvent;

    QString type() const;
    void setType(const QString &type);

    int getDmg_phy() const;
    void setDmg_phy(int value);

    int getDmg_mag() const;
    void setDmg_mag(int value);

    int getDmg_pieges() const;
    void setDmg_pieges(int value);

    void Info();
    virtual void setDmg() =0;

private:
    QString m_type;
    int dmg_phy;
    int dmg_mag;
    int dmg_pieges;
};

template <typename T>
class TEvent : public Event
{
public:
    static Event *create(){
        qDebug() << "Provided by the heroes guild!";
        return new T;
    };
};

class PoisonedArrows : public TEvent<PoisonedArrows> {
public:

    void setDmg() {
        setDmg_phy(2);
        setDmg_mag(1);
        setDmg_pieges(4);
    }
};

class Sword : public TEvent<Sword> {
public:

    void setDmg() {
        setDmg_phy(3);
        setDmg_mag(0);
        setDmg_pieges(1);
    }
};

class Fireball : public TEvent<Fireball> {
public:

    void setDmg() {
        setDmg_phy(1);
        setDmg_mag(4);
        setDmg_pieges(1);
    }
};

class FireSword : public TEvent<FireSword> {
public:

    void setDmg() {
        setDmg_phy(4);
        setDmg_mag(4);
        setDmg_pieges(0);
    }
};




#endif // EVENT_H
