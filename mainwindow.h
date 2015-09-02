#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QCalendarWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *object, QEvent *event);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    int eventCounter=0;
    Ui::MainWindow *ui;
    QCalendarWidget *widget;
};

#endif // MAINWINDOW_H
