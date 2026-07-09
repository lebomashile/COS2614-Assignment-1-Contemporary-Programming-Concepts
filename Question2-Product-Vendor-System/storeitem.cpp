//10089039 Lebohang Mashile
#include "storeitem.h"
#include <QTextStream>

StoreItem::StoreItem(QString id, QString name, double price)
    :Item(id, name, price), i_Vendor(new Vendor("Unknown","Unknown","Unknown"))
{

}

void StoreItem::printItems() const
{
    QTextStream cout(stdout);

    Item::printItems();

    if(i_Vendor->getName() != "Unknown"){
        cout << i_Vendor->toString();
        cout.flush();
    }


}

void StoreItem::setVendor(Vendor *vendor)
{
    i_Vendor = vendor;
}

QString StoreItem::getVendorName() const
{
    return i_Vendor->getName();
}

QString StoreItem::toString(bool printItemsOnly) const
{

    if(printItemsOnly)
        return QString("Item_ID:%1, Item_Name:%2, Item_price:%3").arg(getId(), getName(), QString::number(getPrice()));
     else
        return QString("Item_ID:%1, Item_Name:%2, Item_price:%3 ").arg(getId(), getName(), QString::number(getPrice())) + i_Vendor->toString();

}
