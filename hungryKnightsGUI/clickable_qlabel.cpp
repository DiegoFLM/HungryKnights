#include "clickable_qlabel.h"

Clickable_QLabel::Clickable_QLabel(QWidget *parent):
    QLabel(parent)
{

}

void Clickable_QLabel::mousePressEvent(QMouseEvent *ev)
{
    emit Mouse_Pressed();
}

