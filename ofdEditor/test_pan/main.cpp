#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QXmlStreamReader reader;
    QFile file("F:\\test_xml.xml");
    file.open(QFile::ReadOnly | QFile::Text);
    reader.setDevice(&file);
    reader.readNext();
    if (reader.isStartDocument()) {
        qDebug() << "I've got it.\n";
        reader.readNext();
        qDebug() << reader.name();
        qDebug() << reader.readElementText();
        //readNext();
        qDebug() << reader.name();
        qDebug() << "Is End Element ? " << reader.isEndElement();
        reader.readNext();
        qDebug() << reader.name();
        qDebug() << "Is End Element ? " << reader.isEndElement();
    }
    else qDebug() << "Nothing happened." << reader.name();
    file.close();
}