#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define SIZE_INPUT_BTNS 11

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

    double firstNum =0;
    char operationChar = ' ';
    bool newChar = true;
private slots:
    void addDigital();

    void cleanInputLabel();

    void asign();

    void operation();
    void equal();
    void percent();

    void addPoint();
};
#endif // MAINWINDOW_H
