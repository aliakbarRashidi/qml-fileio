#include "fileio.h"

FileIo::FileIo(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
}

FileIo::~FileIo()
{
}

void FileIo::setPath(QUrl path) {
    mPath = path;
    emit pathChanged(mPath);
}

static void writeToFile(QFile &file, const QString &text) {
    QTextStream stream(&file);
    stream << text;
}

void FileIo::write(QString text) {
    QFile file(mPath.toLocalFile());
    if (file.open(QIODevice::WriteOnly))
        writeToFile(file, text);

    file.close();
}

void FileIo::append(QString text) {
    QFile file(mPath.toLocalFile());
    if (file.open(QIODevice::Append))
        writeToFile(file, text);

    file.close();
}
