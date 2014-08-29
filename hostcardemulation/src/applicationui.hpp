/*
 * Copyright (c) 2011-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include "NfcListener.hpp"

#include <QObject>
#include <errno.h>
#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <QSettings>

#define AID_SETTING_KEY "AID"
#define AID_DEFAULT_VALUE "F00012345210"

using namespace bb::cascades;

namespace bb
{
    namespace cascades
    {
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI
    : public QObject
{
    Q_OBJECT

public:
    ApplicationUI();
    virtual ~ApplicationUI();

public slots:

signals:
    void message(const QVariant &text);

private slots:
    void onSystemLanguageChanged();

private:
    QTranslator *_translator;
    bb::cascades::LocaleHandler *_pLocaleHandler;

    QmlDocument *_qml;
    AbstractPane *_root;
    QObject *_mainPage;
    const QString _orgName;
    const QString _appName;
    NfcListener *_nfcListener;

    void saveAid(QString aid);
    QString getAid();
};

#endif /* ApplicationUI_HPP_ */