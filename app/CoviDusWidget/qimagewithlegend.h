#ifndef QIMAGEWITHLEGEND_H
#define QIMAGEWITHLEGEND_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QBoxLayout>
#include <QSizePolicy>
#include <math.h>
#include "./endpoints/legendinfo.h"

namespace Ui {
class QImageWithLegend;
}

/**
 * @brief The QImageWithLegend class
 * Shows an Images and Generates a Grid of Legends
 */
class QImageWithLegend : public QWidget
{
    Q_OBJECT

public:
    explicit QImageWithLegend(QWidget *parent = nullptr);
    ~QImageWithLegend();
    /**
     * @brief QImageWithLegend::clearLayout
     * clears the current Layout of all elements (All LegendWidgets + childLayouts)
     * @param layout
     * @param deleteWidgets
     */
    void clearLayout(QLayout* layout, bool deleteWidgets = true);
public slots:
    /**
     * @brief QImageWithLegend::setPixmap
     * Sets the Pixmap of the child ImageLabel
     * @param pixmap - a QPixmap
     */
    void setPixmap(const QPixmap& pixmap);   
    /**
     * @brief QImageWithLegend::setLegend
     * Sets the Legend, Creates a Grid of Labels and adds to the UI
     * @param legend - a List of the LegendInfo (Incidencerange and Color)
     */
    void setLegend(const QVector<LegendInfo>& legend);

private:
    Ui::QImageWithLegend *ui;
    QVector<LegendInfo> leg;
    QVector<QLabel> legLabels;
};

#endif // QIMAGEWITHLEGEND_H
