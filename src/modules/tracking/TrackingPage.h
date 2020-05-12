/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2017, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRACKINGPAGE_H
#define TRACKINGPAGE_H

#include "TrackingType.h"

#include <QUrl>
#include <QWidget>

namespace Ui
{
class TrackingPage;
}

class Config;

class TrackingPage : public QWidget
{
    Q_OBJECT
public:
    explicit TrackingPage( Config* config, QWidget* parent = nullptr );

    /** @brief Set initial state for each option
     *
     * Enables or disables the tracking-option block for the given
     * tracking option @p t, and sets the initial state of the
     * checkbox to the @p user default.
     *
     * Call this in ascending order of tracking type.
     */
    void enableTrackingOption( TrackingType t, bool enabled );
    /** @brief Is the given tracking type enabled?
     *
     * Returns whether tracking type @p is selected by the user
     * (i.e. is the radio button for that level, or for a higher
     * tracking level, enabled).
     */
    bool getTrackingOption( TrackingType t );

    ///@brief Set URL for given level @p t
    void setTrackingPolicy( TrackingType t, QString url );
    ///@brief Select one of the four levels by name
    void setTrackingLevel( TrackingType t );

public Q_SLOTS:
    ///@brief Set URL for the global link
    void setGeneralPolicy( QString url );

    void retranslate();

private:
    Ui::TrackingPage* ui;
};

#endif  //TRACKINGPAGE_H
