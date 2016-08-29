#include "mainwindow.h"
#include "ui_dlgcodingbook.h"
#include "ui_mainwindow.h"

#include "coding.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

int MainWindow::decoding() {
  QString str = ui->txCodeText->toPlainText();
  ui->txPlainText->setText("");
  if (str.length() > 0)
    ui->txPlainText->setText(decode(str.toStdString().c_str()));

  return 0;
}

int MainWindow::encoding() {
  QString str = ui->txPlainText->toPlainText();
  ui->txCodeText->setText("");
  if (str.length() > 0)
    ui->txCodeText->setText(encode(str.toStdString().c_str()));
  return 0;
}

void MainWindow::showBook() {
  QDialog dlg;
  Ui::dlgCodingBook ui_dlg;
  ui_dlg.setupUi(&dlg);
  dlg.setWindowTitle("Birth Gift For My Son!");
  dlg.exec();
}
