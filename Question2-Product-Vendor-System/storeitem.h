//10089039 Lebohang Mashile
#ifndef STOREITEM_H
#define STOREITEM_H

#include "item.h"
#include "vendor.h"

class StoreItem : public Item
{
public:
    StoreItem(QString id, QString name, double price);
    void printItems()const;
    void setVendor(Vendor *vendor);
    QString getVendorName()const;
    QString toString(bool printItemsOnly) const;
private:
    Vendor *i_Vendor;

};

#endif // STOREITEM_H
