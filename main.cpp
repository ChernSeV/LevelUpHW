#include <QFile>
#include <QTextStream>
#include <QDebug>

class TextFile{

public:
    bool read_text (const QString &fileName){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            qDebug() << "Can not open file";
            return false;
        }

        QTextStream in(&file);
        in.setCodec("UTF-8");

        while(!in.atEnd()){
            QString line = in.readLine();
            qDebug() << line;

        }

        file.close();
        return true;
    }

    bool write_text (const QString &fileName, const QString &data){
        QFile file(fileName);
        if (!file.open(QIODevice::Append | QIODevice::Text)){
            qDebug() << "Can not file to write";
            return false;
        }

        QTextStream out(&file);
        out.setCodec("UTF-8");

        out << data;

        file.close();
        return true;
    }

    ~TextFile(){
    }
};

int main()
{
    TextFile TXT;

    TXT.read_text("../LevelUpHW/text.txt");
    TXT.write_text("../LevelUpHW/text.txt", "New data");
    TXT.read_text("../LevelUpHW/text.txt");

    return 0;
}
