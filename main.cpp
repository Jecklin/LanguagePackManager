#include <QCoreApplication>
#include "CLanguagePackManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    CLanguagePackManager manger;
    manger.SwitchLanguage(CLanguagePackManager::Chinese);
    manger.Test();
    
    return a.exec();
}
