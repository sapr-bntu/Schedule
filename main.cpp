#include <QtCore/QCoreApplication>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream out(stdout);
    if (a.arguments().count()!= 3)
    {
        out<<"Parametry zadany neverno"<<endl;
        return a.exec();
    }

    qDebug()<<a.arguments().count();
    qDebug()<<a.arguments()[1];
    qDebug()<<a.arguments()[2];

    QFile file("README.md");
    QFile fileHtm("README.html");
    QString str;

    if(file.exists()==false)
    {
        out<<"Fail ne suschestvuet!"<<endl;
        exit(1);
    }
    file.open(QIODevice::ReadOnly);
    QTextStream fin(&file);
    fin.setCodec("ISO 8859-1");
    while(!fin.atEnd())
    {
    str = fin.readAll();
    }
    if(fileHtm.exists())
        fileHtm.remove();

fileHtm.open(QIODevice::Append | QIODevice::Text);

        QTextStream fout(&fileHtm);
         fout.setCodec("ISO 8859-1");

          fout << "<html>"<<endl;
          fout << "<head>"<<endl;
          fout << "<title> О проекте 'Расписание'.</title>\n";
          fout << "</head>\n";
          fout << "<body>\n";
          fout << "<H2> гр. 107519 </H2>\n";
          fout << "<H3 align=center>\n";
          fout << "<FONT SIZE=3 COLOR=191970>\n";
          fout << str;
          fout << "</FONT>\n";
          fout << "</H3>\n";
          fout << "</body>\n";
          fout << "</html>";

    file.close();
    fileHtm.close();

    out << "Successfully done"<<endl;
    return a.exec();
}
