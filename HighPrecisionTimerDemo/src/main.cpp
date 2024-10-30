#include <QtWidgets/QApplication>
#include <QDebug>
#include <TDDMUser.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TDDMUser w;
    w.show();
    
	return a.exec();
}
