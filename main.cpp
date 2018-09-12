#include <QCoreApplication>
#include "CLanguagePackManager.h"
#include <QDebug>

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    //Use the help
    CLanguagePackManager manger;
    
    //change language
    bool ok = manger.SwitchLanguage(CLanguagePackManager::Chinese);
    qDebug() << "SwitchLanguage" << ok;
    
    //test
    manger.Test();
    
    //get the value of key
    qDebug() << "***   GetValue():   ***";
    
    QString s1 = "1";
    QString s2 = "2";
    
    QString key1 = manger.GetValue(s1);
    QString key2 = manger.GetValue(s2);
    
    qDebug() << s1 << key1;
    qDebug() << s2 << key2;

    
    return a.exec();
}
