#include "QTableWidgetItem"
#include "QDate"

class MyDateTableWidgetItem : public QTableWidgetItem {
    public:
        MyDateTableWidgetItem(const QString txt = QString("0")) : QTableWidgetItem(txt) {}

        //For Date comparison
        bool operator <(const QTableWidgetItem &other) const
        {
            QDate date1 = QDate::fromString(text(), "dd-MMM-yyyy");
            QDate date2 = QDate::fromString(other.text(), "dd-MMM-yyyy");

            return date1 < date2;
        }
};
