//10089039 Lebohang Mashile
#ifndef VENDOR_H
#define VENDOR_H

#include <QString>
class Vendor
{
public:
    Vendor(QString id, QString name, QString address);
    void setId(QString id);
    void setName(QString name);
    void setAddress(QString address);
    QString getId() const;
    QString getName() const;
    QString getAddress() const;
    QString toString()const;
private:
    QString i_Id;
    QString i_Name;
    QString i_Address;
};

#endif // VENDOR_H
