#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About Me", "This is About Me");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer name");
    QPrintDialog dialog(&printer,this);
    ui->textEdit->textCursor().hasSelection();
    dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);
}

/*
    dialog.setWindowTitle("Print Document");
    if (ui->textEdit->textCursor().hasSelection()){
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
}
    if(dialog.exec() != QDialog::Accepted){
        return;
    }
}
*/

