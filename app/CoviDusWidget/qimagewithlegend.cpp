#include "qimagewithlegend.h"
#include "ui_qimagewithlegend.h"

QImageWithLegend::QImageWithLegend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QImageWithLegend)
{
    ui->setupUi(this);
}

QImageWithLegend::~QImageWithLegend()
{
    delete ui;
}

void QImageWithLegend::setPixmap(const QPixmap &pixmap)
{
    ui->imageLabel->setPixmap(pixmap);
}

void QImageWithLegend::setLegend(const QList<LegendInfo> &legend)
{
    leg = legend;

    clearLayout(ui->legendLayout);
    ui->legendLayout->setHorizontalSpacing(0);
    ui->legendLayout->setVerticalSpacing(0);
    int rowSize = (int)sqrt(legend.size());
    int elemCounter = 0;
    int legendWidth = 0;

    for(auto &legendItem: legend){
        legendWidth = legendItem.incidenceRange.count() > legendWidth ?
                    legendItem.incidenceRange.count() :
                    legendWidth;
    }

    for(auto &legendItem: legend)
    {
        QLabel* legendLabel = new QLabel(legendItem.incidenceRange);
        QLabel* legendPicture = new QLabel();
        QHBoxLayout* legendCellLayout = new QHBoxLayout();
        QPixmap legendColor = QPixmap(10,10);
        QColor legColor;

        legendCellLayout->setSpacing(0);
        legColor.setNamedColor(legendItem.color);
        legendColor.fill(legColor);
        legendPicture->setPixmap(legendColor);
        legendPicture->setAlignment(Qt::AlignCenter);
        legendPicture->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
        legendPicture->setMargin(0);
        legendPicture->setFixedHeight(10);
        legendPicture->setFixedWidth(10);
        legendLabel->setAlignment(Qt::AlignCenter);
        legendLabel->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
        legendLabel->setMargin(0);
        legendLabel->setFixedHeight(legendLabel->fontMetrics().height());
        legendLabel->setFixedWidth(legendLabel->fontMetrics().averageCharWidth() * legendWidth);
        legendCellLayout->addWidget(legendPicture);
        legendCellLayout->addWidget(legendLabel);
        ui->legendLayout->addLayout(legendCellLayout, elemCounter / rowSize, elemCounter % rowSize);
        elemCounter++;
    }
}

void QImageWithLegend::clearLayout(QLayout* layout, bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
}
