#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCompleter>
#include <QCalendarWidget>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());

    QCompleter *com=ui->comboBox->completer();
    com->setCompletionMode(QCompleter::PopupCompletion);


    //    widget= new QCalendarWidget();

    widget = ui->dateEdit->calendarWidget();

    //    ui->verticalLayout->addWidget(widget);
    widget->setWindowFlags(Qt::Popup);

    ui->dateEdit->installEventFilter(this);


    //connecting widget with dateedit
    connect(widget,SIGNAL(clicked(QDate)),ui->dateEdit,SLOT(setDate(QDate)));

    ui->dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
    //    ui->dateEdit->setCalendarPopup(false);
    ui->dateEdit->calendarWidget()->setDateEditEnabled(true);
    ui->dateEdit->calendarWidget()->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
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
    if (object == ui->dateEdit)
    {
        //        if (event->type() != QEvent::Paint && event->type() != QEvent::HoverEnter && event->type() != QEvent::HoverLeave && event->type() != QEvent::HoverMove&& event->type() != QEvent::Enter && event->type() != QEvent::Leave)
        if (event->type() == QEvent::FocusIn || event->type() == QEvent::MouseButtonPress)
        {
            //            eventCounter++;
            //            qWarning(QString().number(event->type()).toStdString().c_str());
            //            qWarning(object->objectName().toLatin1().data());
            //                        qWarning(QString().number(eventCounter).toStdString().c_str());

            if(widget->isVisible()==false && ( ((QMouseEvent* )event)->x()< (ui->dateEdit->width()-10)))
            {
                widget->move(ui->dateEdit->mapToGlobal(QPoint(0,ui->dateEdit->height())));
                widget->show();
                //                ui->dateEdit->clearFocus();
            }

        }
    }
    return false;
}
