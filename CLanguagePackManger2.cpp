#include "CLanguagePackManger2.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include <QStringList>

CLanguagePackManager::CLanguagePackManager()
{
    //The default language pack is English
    this->ReadJson(ELanguage::English);
    
}

CLanguagePackManager::~CLanguagePackManager()
{
    ;
}

void CLanguagePackManager::SwitchLanguage(ELanguage language)
{
    bool flag = this->ReadJson(language);
    qDebug() << "123123123:" << flag;
}

QStringList CLanguagePackManager::GetValue(QString key)
{
    QStringList valueList;

    QHash<QString, QStringList>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        QString hashKey = iter.key();
        if (hashKey == key)
        {
            valueList = iter.value();
        }

        ++iter;
    }
    
    return valueList;
}

void CLanguagePackManager::Test()
{
    QHash<QString,QStringList>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        
        QString     key       = iter.key();
        QStringList valueList = iter.value();
        
        qDebug() << "key:" << key << ": ";
        
        QStringList::const_iterator listIter = valueList.begin();
        while (listIter != valueList.end())
        {
            qDebug() << "value:" << *listIter;
            ++listIter;
        }
          
        ++iter;
    }
}

bool CLanguagePackManager::ReadJson(ELanguage language)
{
    bool result = false;
    do
    {
        //Open the file according to the language you entered
        QString dir = "../LanguagePackManager/";
        QString fileName;
        
        switch (language)
        {
        case    ELanguage::English:
        {
            fileName = "English.json";
        }break;
        case    ELanguage::Chinese:
        {
            fileName = "Chinese.json";
        }break;
        case    ELanguage::Japanese:
        {
            fileName = "Japanese.json";
        }break;
        case    ELanguage::Spanish:
        {
            fileName = "Spanish.json";
        }
        }
        qDebug() << fileName;
        
        dir += fileName;
            
        
        QFile loadFile(dir);
        if (!loadFile.open(QIODevice::ReadOnly))
        {
            qDebug() << "could't open projects json";
            break;
        }
        
        QByteArray allData = loadFile.readAll();
        loadFile.close();
        
        QJsonParseError jsonError;
        QJsonDocument   document    = QJsonDocument::fromJson(allData, &jsonError);
        QStringList     keys        = document.object().keys();
        QStringList     indexList;
        QHash<QString, QStringList> indexHash;
        
        if (document.isNull() || (jsonError.error != QJsonParseError::NoError))
        {
            qDebug() << "document error";
            break;
        }
        
        if (!document.isObject())
        {
            qDebug() << "document is not object";
            break;
        }
        
        QJsonObject object      = document.object();
        int         keySize     = keys.size();
        qDebug() << "keySize: " << keySize;
        
        for (int i = 0; i < keySize; ++i)
        {
            QString strKey = keys.at(i);
            indexList.clear();
            
            if (object.contains(strKey))
            {
                QJsonValue value = object.value(strKey);
                if (value.isArray())
                {
                    QJsonArray array = value.toArray();
                    int arrSize = array.size();
                    for (int i = 0; i < arrSize; ++i)
                    {
                        QJsonValue  arrValue = array.at(i);
                        if (arrValue.isString())
                        {
                            QString  strValue = arrValue.toString();
                            indexList.push_back(strValue);
                        }
                        
                    }
                    
                }
                
                indexHash.insert(strKey, indexList);
            }
            
            
        }

        this->m_hash = indexHash;
        result = true;
        
        //test
        this->Test();
        
        
    }while(false);
    
    return result;
}


