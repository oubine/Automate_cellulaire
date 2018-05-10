#ifndef DOCUMENT_XML_H
#define DOCUMENT_XML_H

#include <QObject>
#include <QWidget>

class Document_XML : public QWidget
{
public:
    Document_XML(QString &path);
    ~Document_XML();
};

#endif // DOCUMENT_XML_H
