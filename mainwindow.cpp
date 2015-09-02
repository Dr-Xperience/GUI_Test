#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QCalendarWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    //    connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),ui->dateEdit->calendarWidget(),SLOT(setSelectedDate(QDate)));
    //    ui->dateEdit->calendarWidget()->setVisible(true);
    //        ui->dateEdit->activateWindow();
    //    ui->calendarWidget->setVisible(false);
    //    ui->calendarWidget->hide();
    QCompleter *com=ui->comboBox->completer();
    com->setCompletionMode(QCompleter::PopupCompletion);
    //ui->calendarWidget->setWindowFlags(Qt::Popup);



    widget=new QCalendarWidget();

    ui->verticalLayout->addWidget(widget);
    widget->setWindowFlags(Qt::Popup);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //    ui->calendarWidget->move(ui->pushButton->mapToGlobal(QPoint(0,ui->pushButton->height())));

    //    ui->calendarWidget->show();

    widget->move(ui->pushButton->mapToGlobal(QPoint(0,ui->pushButton->height())));
    widget->show();

//    widget->deleteLater();
}
