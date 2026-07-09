//10089039 Lebohang Mashile
#ifndef ITEM_H
#define ITEM_H
#include <QString>


class Item
{
public:
    Item(QString id, QString name, double price);
    void setId(QString id);
    void setName(QString name);
    void setPrice(double price);
    QString getId()const;
    QString getName()const;
    double getPrice()const;
    void printItems()const;
private:
    QString i_Id;
    QString i_Name;
    double i_Price;
};

#endif // ITEM_H
