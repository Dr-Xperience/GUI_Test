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

    //    ui->comboBox->installEventFilter(this);
    ui->dateEdit->installEventFilter(this);
    //connecting widget with dateedit
    ui->dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    ui->dateEdit->setCalendarPopup(false);
    connect(widget,SIGNAL(clicked(QDate)),ui->dateEdit,SLOT(setDate(QDate)));

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

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::FocusIn)
        //        if (event->type() != QEvent::Paint && event->type() != QEvent::HoverEnter && event->type() != QEvent::HoverLeave && event->type() != QEvent::HoverMove&& event->type() != QEvent::Enter && event->type() != QEvent::Leave)
    {
        if (object == ui->dateEdit)
        {

            eventCounter++;
            qWarning(QString().number(event->type()).toStdString().c_str());
            qWarning(object->objectName().toLatin1().data());
                        qWarning(QString().number(eventCounter).toStdString().c_str());
//            ui->dateEdit->calendarWidget()->setVisible(true);
//            ui->dateEdit->calendarWidget()->show();
            if(eventCounter >= 0)
            widget->move(ui->dateEdit->mapToGlobal(QPoint(0,ui->dateEdit->height())));
            widget->show();
        }
//    widget->hide();
    }

    return false;
}
