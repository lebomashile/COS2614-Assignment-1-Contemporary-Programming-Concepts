//10089039 Lebohang Mashile
#include "vendor.h"

Vendor::Vendor(QString id, QString name, QString address)
    :i_Id(id), i_Name(name), i_Address(address){


}

QString Vendor::getId() const
{
    return i_Id;
}

void Vendor::setId(QString id)
{
    i_Id = id;
}

QString Vendor::getName() const
{
    return i_Name;
}

void Vendor::setName(QString name)
{
    i_Name = name;
}

QString Vendor::getAddress() const
{
    return i_Address;
}

void Vendor::setAddress(QString address)
{
    i_Address = address;
}

QString Vendor::toString() const
{
    return QString("Vendor_ID:%1, Vendor_Name:%2, Vendor_Address:%3").arg(i_Id,i_Name,i_Address);
}
