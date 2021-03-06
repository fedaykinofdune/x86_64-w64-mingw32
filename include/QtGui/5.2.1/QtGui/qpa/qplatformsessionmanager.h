/****************************************************************************
**
** Copyright (C) 2013 Samuel Gaist <samuel.gaist@edeltech.ch>
** Copyright (C) 2013 Teo Mrnjavac <teo@kde.org>
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QPLATFORMSESSIONMANAGER_H
#define QPLATFORMSESSIONMANAGER_H

//
//  W A R N I N G
//  -------------
//
// This file is part of the QPA API and is not meant to be used
// in applications. Usage of this API may make your code
// source and binary incompatible with future versions of Qt.
//

#include <QtCore/qmetatype.h>
#include <QtCore/qnamespace.h>

#include <QtGui/qsessionmanager.h>

#ifndef __QT_NO_SESSIONMANAGER

QT_BEGIN_NAMESPACE

class Q_GUI_EXPORT QPlatformSessionManager
{
public:
    explicit QPlatformSessionManager(const QString &id, const QString &key);
    virtual ~QPlatformSessionManager();

    virtual QString sessionId() const;
    virtual QString sessionKey() const;

    virtual bool allowsInteraction();
    virtual bool allowsErrorInteraction();
    virtual void release();

    virtual void cancel();

    virtual void setRestartHint(QSessionManager::RestartHint restartHint);
    virtual QSessionManager::RestartHint restartHint() const;

    virtual void setRestartCommand(const QStringList &command);
    virtual QStringList restartCommand() const;
    virtual void setDiscardCommand(const QStringList &command);
    virtual QStringList discardCommand() const;

    virtual void setManagerProperty(const QString &name, const QString &value);
    virtual void setManagerProperty(const QString &name, const QStringList &value);

    virtual bool isPhase2() const;
    virtual void requestPhase2();

protected:
    virtual void appCommitData();
    virtual void appSaveState();

    QString m_sessionId;
    QString m_sessionKey;

private:
    QStringList m_restartCommand;
    QStringList m_discardCommand;
    QSessionManager::RestartHint m_restartHint;

    Q_DISABLE_COPY(QPlatformSessionManager)
};

QT_END_NAMESPACE

#endif // __QT_NO_SESSIONMANAGER

#endif // QPLATFORMSESSIONMANAGER_H
