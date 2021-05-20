#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QGraphicsScene>
#include <business/FacadeOperationResult.h>
#include <business/Facade.h>
#include <business/NormalizationParameters.h>
#include <business/FileReader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_file_search_button_clicked();

    void on_draw_button_clicked();

    void operations();

    void print_filename(string& path);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
