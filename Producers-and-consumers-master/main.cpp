#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "����ģ��ʵ��" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;

    w.setWindowTitle(QString::fromLocal8Bit("�����ߺ�������ģ��ʵ��"));
    w.show();
    return a.exec();
}
