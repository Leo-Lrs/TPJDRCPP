#include "hero.h"
#include <QVector>

QVector<Hero *> Hero::created;

QString Hero::type() const
{
    return m_type;
}

void Hero::setType(const QString &type)
{
    m_type = type;
}

QString Hero::name() const
{
    return m_name;
}

void Hero::setName(const QString &name)
{
    m_name = name;
}

void Hero::Info()
{
    qDebug() << type() << name() << getPdv();
}

void Hero::receiveDmgs(int dmg_pts)
{

    if ( (getPdv() - dmg_pts ) <= 0){
        qDebug()<< "A hero just die";
        delete this;
    }else{
        setPdv(getPdv() - dmg_pts);
    }

}

int Hero::resistancePts() const
{
    return m_resistancePts;
}

void Hero::setResistancePts(int resistancePts)
{
    m_resistancePts = resistancePts;
}

int Hero::getPdv() const
{
    return pdv;
}

void Hero::setPdv(int value)
{
    pdv = value;
}

Hero::~Hero()
{
    qDebug() << type() << "drops dead";
    Hero::created.erase(std::remove(Hero::created.begin(), Hero::created.end(), this), Hero::created.end());
}

QString Hero::resistance() const
{
    return m_resistance;
}

void Hero::setResistance(const QString &resistance)
{
    m_resistance = resistance;
}

