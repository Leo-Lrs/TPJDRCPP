#ifndef Hero_H
#define Hero_H
#include <QString>
#include <QDebug>

class Hero
{
public:
    static QVector<Hero *> created;

    QString type() const;
    void setType(const QString &type);

    QString name() const;
    void setName(const QString &name);

    QString resistance() const;
    void setResistance(const QString &resistance);

    void Info();
    virtual void Resistance() =0;

    void receiveDmgs(int dmg_pts);


    int resistancePts() const;
    void setResistancePts(int resistancePts);

    int getPdv() const;
    void setPdv(int value);

    ~Hero();

private:
    QString m_type;
    QString m_name;
    QString m_resistance;
    int m_resistancePts;
    int pdv = 10;
};

template <typename T>
class THero : public Hero
{
public:
    static Hero *create(){
        qDebug() << "Made by the Creator";
        return new T;
    };
    virtual void Resistance(){
        qDebug() << "Resistance template";
    }

};

class Warrior : public THero<Warrior> {
public:
    void Resistance() {
        setResistance("Physique");
        setResistancePts(4);
    }
};

class Wizzard : public THero<Wizzard> {
public:
    void Resistance() {
        setResistance("Magique");
        setResistancePts(4);
    }

};

class Rogue : public THero<Rogue> {
public:
    void Resistance() {
        setResistance("Piege");
        setResistancePts(4);
    }

};

#endif // Hero_H
