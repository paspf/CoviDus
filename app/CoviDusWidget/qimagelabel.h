#ifndef QIMAGELABEL_H
#define QIMAGELABEL_H

#include<QPixmap>
#include<QPaintEvent>
#include<QPainter>
#include<QWidget>

/**
 * @brief QImageLabel class, shows an scaling Image
 */
class QImageLabel : public QWidget
{
    Q_OBJECT

public:
    explicit QImageLabel(QWidget *parent = 0);
    const QPixmap* pixmap() const;

public slots:
    void setPixmap(const QPixmap& pixmap);

protected:
    /**
     * @overload
     * @brief paintEvent, get's called on every repaint
     * @details makes sure to resize image according to labelsize
     * @param event
     */
    void paintEvent(QPaintEvent *event);

private:
    QPixmap pix;
};

#endif // QIMAGELABEL_H
