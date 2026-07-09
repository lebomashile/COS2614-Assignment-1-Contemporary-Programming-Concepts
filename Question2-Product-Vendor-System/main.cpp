//10089039 Lebbohang Mashile
#include <QCoreApplication>
#include <QTextStream>
#include "storeitem.h"
#include "vendor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    QString ID, name, address;
    double price;
    char c;

    do{
        cout << "Enter Item ID:";
        cout.flush();
        cin >> ID;

        cout << "Enter Item name:";
        cout.flush();
        cin.read(1);
        name = cin.readLine();

        cout << "Enter Item price:";
        cout.flush();
        cin >> price;

        StoreItem item(ID, name, price);

        cout << "Enter Vendor ID:";
        cout.flush();
        cin >> ID;

        cout << "Enter Vendor name:";
        cout.flush();
        cin.read(1);
        name = cin.readLine();

        cout << "Enter Vendor address:";
        cout.flush();
        address = cin.readLine();

        Vendor *v = new Vendor(ID, name, address);

        item.setVendor(v);
        item.printItems();
        cout << endl << "Do you want to continue(Y/N):";
        cout.flush();
        cin >> c;
    }
    while(c == 'y' || c == 'Y' );



    return a.exec();
}





