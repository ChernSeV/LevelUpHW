#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    double calcValue = 0.0f;
    bool divide = false;
    bool multip = false;
    bool subtrc = false;
    bool additn = false;


private slots:
    void NumPressed();
    void MathPressed();
    void ResultPressed();
    void ChangeSignPressed();
    void ClearPressed();
    void DotPressed();
};
#endif // MAINWINDOW_H
