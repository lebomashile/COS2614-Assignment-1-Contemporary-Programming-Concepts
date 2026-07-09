//10089039 Lebohang Mashile
#include "item.h"
#include <QTextStream>


Item::Item(QString id, QString name, double price)
    :i_Id(id), i_Name(name), i_Price(price){

}

void Item::setId(QString id)
{
    i_Id = id;
}

void Item::setName(QString name)
{
    i_Name = name;
}

void Item::setPrice(double price)
{
     i_Price = price;
}

QString Item::getId() const
{
    return i_Id;
}

QString Item::getName() const
{
    return i_Name;
}

double Item::getPrice() const
{
    return i_Price;
}

void Item::printItems() const
{
    QTextStream cout(stdout);
    cout << "Item_ID:" << i_Id << ", Item_Name:"<<i_Name << ", Item_Price: R" << QString::number(i_Price)<<endl;
    cout.flush();
}
