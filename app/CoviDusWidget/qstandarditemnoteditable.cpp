#include "qstandarditemnoteditable.h"

/**
 * @brief QStandardItemNotEditable::QStandardItemNotEditable
 * Create a not editable standard item.
 * @param text Item Text.
 */
QStandardItemNotEditable::QStandardItemNotEditable(const QString &text)
{
    this->setText(text);
    this->setEditable(false);
}
