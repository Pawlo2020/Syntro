#ifndef TEST_H
#define TEST_H

#include <QObject>


class test: public QObject
{
    Q_OBJECT
public:
    explicit test(QObject* parent=0);
    Q_INVOKABLE void printMessage(QString txt);




   public:

};

#endif // TEST_H
