//10089039 Lebohang Mashile

#include <QApplication>
#include <QString>
#include <QInputDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTime>

QString createUserID(QString FirstName, QString MiddleName, QString LastName){
    QString UniqueID;
    int count;

    if(MiddleName.size() !=0 ){
    UniqueID.append(FirstName.at(0).toUpper());
    UniqueID.append(MiddleName.at(0).toUpper());
    }
    else{
        UniqueID.append(FirstName.at(0).toUpper());
        UniqueID.append(LastName.at(0).toUpper());
    }

    count = FirstName.size() + MiddleName.size() + LastName.size();

    if(count > 4){

        for(int i = 0 ; i < 4 ; i++)
            UniqueID.append(QString::number(count));
    }
    else{
        for(int i = 0 ; i < 4 ; i++)
            UniqueID.append("0");
    }

    UniqueID.resize(6);


    return UniqueID;
}

QString createKey(QString FirstName, QString MiddleName, QString LastName){
    QString FullName;
    QString InitialKey;
    int count;
    int timeout = 0;

    bool isVowel = false, isConsonant = false;

    qsrand(QTime::currentTime().msec());

    if(MiddleName.size() > 0){
        FullName = FirstName.toLower() + MiddleName.toLower() + LastName.toLower();

    }
    else{

        FullName = FirstName.toLower() + LastName.toLower();
    }

    count = FullName.size();
    while(isVowel == false || isConsonant == false){
        timeout++;

        if(timeout >= 1000){
            QMessageBox::information(0,"Error","Could not generate key. Make sure vowels and consonant is present");
            exit(1);

        }
        for(int i = 0; i < 6; i++){
            int randomNumber;
            randomNumber = qrand()%(count - 1);
            InitialKey.append(FullName.at(randomNumber));

            if(InitialKey.at(i) == 'a' || InitialKey.at(i) == 'e' ||
                InitialKey.at(i) == 'i' || InitialKey.at(i) == 'o' ||
                InitialKey.at(i) == 'u'){
                isVowel = true;
            }
            else{
                isConsonant = true;

            }
        }
    }
    qDebug() << InitialKey;
    return InitialKey;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString fullName, userID, initialKey;
    QString firstName, lastName, middleName;
    QStringList stringList;

    fullName = QInputDialog::getText(0,"Details","Enter Your Name(First Middle Last)");
    stringList = fullName.split(" ",QString::SkipEmptyParts);

    if(stringList.size() == 3){

        firstName = stringList.at(0);
        middleName = stringList.at(1);
        lastName = stringList.at(2);

    }
    else if(stringList.size() == 2){
        firstName = stringList.at(0);
        lastName = stringList.at(1);

    }
    else{

        QMessageBox::critical(0,"Invalid Input","Enter your details in this sequence 'First, Middle and Last Name'");
        exit(0);
    }

        userID = createUserID(firstName, middleName, lastName);
        initialKey = createKey(firstName, middleName, lastName);
        QMessageBox::information(0,"User ID and Key",QString("Your userID is %1 and initial key is %2").arg(userID,initialKey));

        return a.exec();
    }



