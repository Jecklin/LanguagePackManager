#include "CLanguagePackManager.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonArray>
#include <QFile>
#include <QDebug>

CLanguagePackManager::CLanguagePackManager()
{
    
}

CLanguagePackManager::~CLanguagePackManager()
{
    
}

void CLanguagePackManager::SwitchLanguage(int LID)
{
    
}

QString CLanguagePackManager::GetValue(QString key)
{
    QString result;
    result = this->m_hash.value(key);
    return result;
}

bool CLanguagePackManager::ReadJson(int LID)
{
    bool result = false;
    do
    {
        //todo: 根据输入的LID打开JSON
        QFile loadFile("1.json");
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
            }
        }
        
        
    }while(false);

    return result;
}












