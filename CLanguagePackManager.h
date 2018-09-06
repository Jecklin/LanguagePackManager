#ifndef CLANGUAGEPACKMANAGER_H
#define CLANGUAGEPACKMANAGER_H

#include <QHash>


class CLanguagePackManager
{
public:
    CLanguagePackManager();
    ~CLanguagePackManager();
    
    void    SwitchLanguage(int LID);
    QString GetValue(QString key);
    
private:
    bool    ReadJson(int LID);
    
    
private:
    QHash<QString, QString> m_hash;
};

#endif // CLANGUAGEPACKMANAGER_H
