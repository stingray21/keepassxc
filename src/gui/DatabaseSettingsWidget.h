/*
 *  Copyright (C) 2012 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_DATABASESETTINGSWIDGET_H
#define KEEPASSX_DATABASESETTINGSWIDGET_H

#include <QtCore/QScopedPointer>

#include "gui/DialogyWidget.h"

class QAbstractButton;

namespace Ui {
    class DatabaseSettingsWidget;
}

class DatabaseSettingsWidget : public DialogyWidget
{
    Q_OBJECT

public:
    explicit DatabaseSettingsWidget(QWidget* parent = 0);
    ~DatabaseSettingsWidget();

    void setForms(QString dbName, QString dbDescription,
                  QString defaultUsername, bool recylceBinEnabled,
                  int transformRounds, int historyMaxItems,
                  int historyMaxSize);
    quint64 transformRounds();
    QString dbName();
    QString dbDescription();
    QString defaultUsername();
    bool recylceBinEnabled();
    int historyMaxItems();
    int historyMaxSize();

Q_SIGNALS:
    void editFinished(bool accepted);

private Q_SLOTS:
    void changeSettings();
    void reject();
    void toggleHistoryMaxItemsSpinBox(int state);
    void toggleHistoryMaxSizeSpinBox(int state);

private:
    const QScopedPointer<Ui::DatabaseSettingsWidget> m_ui;

    QString m_dbName;
    QString m_dbDescription;
    QString m_defaultUsername;
    bool m_recylceBinEnabled;
    quint64 m_transformRounds;
    int m_historyMaxItems;
    int m_historyMaxSize;

    Q_DISABLE_COPY(DatabaseSettingsWidget)
};

#endif // KEEPASSX_DATABASESETTINGSWIDGET_H
