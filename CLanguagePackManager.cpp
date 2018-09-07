﻿#include "CLanguagePackManager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

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
    this->ReadJson(language);
}

QString CLanguagePackManager::GetValue(QString key)
{
    QString result = "";
    QHash<QString, QString>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        if (iter.key() == key)
        {
            result = iter.value();
        }
    }
    
    return result;
}

void CLanguagePackManager::Test()
{
    QHash<QString,QString>::const_iterator iter = this->m_hash.constBegin();
    while (iter != this->m_hash.constEnd())
    {
        qDebug() << "key:" << iter.key() << ": "
                 << "value:" << iter.value();
        ++iter;
    }
}

bool CLanguagePackManager::ReadJson(ELanguage language)
{
    bool result = false;
    do
    {
        //Open the file according to the language you entered
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
        
        
        QFile loadFile(language);
        if (!loadFile.open(QIODevice::ReadOnly))
        {
            qDebug() << "could't open projects json";
            break;
        }
        
        QByteArray allData = loadFile.readAll();
        loadFile.close();
        
        QJsonParseError jsonError;
        QJsonDocument   document = QJsonDocument::fromJson(allData, &json_error);
        QStringList     keys     = document.object().keys();
        
        if (!document.isNull() && (jsonError.error == QJsonParseError::NoError))
        {
            if (document.isArray())
            { 
                QJsonArray array = document.array();
                int size = array.size();
                for (int i = 0; i < size; ++i)
                {
                    QJsonValue key = keys.at(i);
                    QJsonValue value = array.at(i);
                    if (key.type() == QJsonValue::String && value.type() == QJsonValue::String)
                    {
                        this->m_hash.insert(key, value);
                    }

                }
                
                result = true;
            }
        }
        
        //test
        this->Test();
        
        
    }while(false);

    return result;
}












