#include "qimagelabel.h"

QImageLabel::QImageLabel(QWidget *parent) : QWidget(parent)
{

}

/**
 * @brief QImageLabel::paintEvent paints the Image and dynamically scales with the available size
 * @param event
 */
void QImageLabel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    if (pix.isNull())
        return;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QSize pixSize = pix.size();
    pixSize.scale(event->rect().size(), Qt::KeepAspectRatio);

    QPixmap scaledPix = pix.scaled(pixSize,
                                   Qt::KeepAspectRatio,
                                   Qt::SmoothTransformation
                                   );

    painter.drawPixmap(QPoint(), scaledPix);
}

const QPixmap* QImageLabel::pixmap() const
{
    return &pix;
}

void QImageLabel::setPixmap(const QPixmap &pixmap)
{
    pix = pixmap;
}
