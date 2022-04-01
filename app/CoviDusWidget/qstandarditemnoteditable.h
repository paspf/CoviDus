#ifndef QSTANDARDITEMNOTEDITABLE_H
#define QSTANDARDITEMNOTEDITABLE_H

#include <QStandardItem>

class QStandardItemNotEditable : public QStandardItem
{
public:
    explicit QStandardItemNotEditable(const QString &text);
};

#endif // QSTANDARDITEMNOTEDITABLE_H
