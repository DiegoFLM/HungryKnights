#ifndef CLICKABLE_QLABEL_H
#define CLICKABLE_QLABEL_H

#include <QLabel>
//#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class Clickable_QLabel : public QLabel
{
    Q_OBJECT
public:
    explicit Clickable_QLabel(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void Mouse_Pressed();
public slots:

};

#endif // CLICKABLE_QLABEL_H

