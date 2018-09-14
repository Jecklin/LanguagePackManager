#include "CLanguagePackManager3.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

CLanguagePackManager CLanguagePackManager::m_manager;

CLanguagePackManager::CLanguagePackManager()
    :m_hash()
{
    //The default language pack is English
    this->InitLanguage();   
}

CLanguagePackManager::~CLanguagePackManager()
{
    ;
}

CLanguagePackManager* CLanguagePackManager::getInstance()
{
    return &m_manager;
}

bool CLanguagePackManager::SwitchLanguage(ELanguage language)
{
    bool flag = this->ReadJson(language);
    qDebug() << "ReadJson:" << flag;
    return flag;
}

QString CLanguagePackManager::GetValue(QString key)
{
    QString value;

    QHash<QString, QString>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        QString hashKey = iter.key();
        if (hashKey == key)
        {
            value = iter.value();
        }

        ++iter;
    }
    
    return value;
}

void CLanguagePackManager::Test()
{
    QHash<QString,QString>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        QString     key       = iter.key();
        QString     value     = iter.value();
        
        qDebug() << "key:" << key << ": " << "value: " << value;
        
        ++iter;
    }   
}

bool CLanguagePackManager::ReadJson(ELanguage language)
{
    bool result = false;
    do
    {
        //Open the file according to the language you entered
        QString dir = "../";
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
        QJsonDocument   document    = QJsonDocument::fromJson(allData, &jsonError); //函数说明：解析UTF-8编码的JSON文档并从中创建QJsonDocument。
        QStringList     keys        = document.object().keys();
        QHash<QString, QString> indexHash;
        
        if (document.isNull() || (jsonError.error != QJsonParseError::NoError))
        {
            qDebug() << "document error";
            break;
        }
        if (jsonError.error == QJsonParseError::IllegalUTF8String)                  //输入中出现非法UTF8序列
        {
            qDebug() << "An illegal UTF8 sequence occurred in the input";
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
            if (object.contains(strKey))
            {
                QJsonValue value = object.value(strKey);
                if (value.isString())
                {
                    QString strValue = value.toString();
                    indexHash.insert(strKey, strValue);  
                }
 
            }

        }

        this->m_hash = indexHash;
        result = true;
        
        
        
    }while(false);
    
    return result;
}

void CLanguagePackManager::InitLanguage()
{
    this->ReadJson(ELanguage::English);
}



