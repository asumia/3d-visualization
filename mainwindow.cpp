#include "mainwindow.h"
#include "ui_mainwindow.h"

#define MOVE_KOEF 30
#define SCALE_FOEF 1.1
#define ANGEL 0.17

Facade facade;
int model_count = 0;
int print_check = 0;

void error_message(const char* error);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->butUp, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->butDown, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->butLeft, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->butRight, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->spinOxLeft, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->spinOyLeft, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->spinOzLeft, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->spinOxRight, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->spinOyRight, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->spinOzRight, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->sizePlus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->sizeMinus, SIGNAL(clicked()), this, SLOT(operations()));

    ui->butUp->setCheckable(true);
    ui->butRight->setCheckable(true);
    ui->butLeft->setCheckable(true);
    ui->butDown->setCheckable(true);
    ui->spinOxLeft->setCheckable(true);
    ui->spinOyLeft->setCheckable(true);
    ui->spinOzLeft->setCheckable(true);
    ui->spinOxRight->setCheckable(true);
    ui->spinOyRight->setCheckable(true);
    ui->spinOzRight->setCheckable(true);
    ui->sizePlus->setCheckable(true);
    ui->sizeMinus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_file_search_button_clicked()
{
    string filepath = QFileDialog::getOpenFileName(0, "Open", "*.csv").toStdString();
    if (!filepath.empty())
    {
        FacadeOperationResult result(true);
        result = facade.LoadScene(filepath);
        if(!result.IsSuccess())
            error_message(result.GetErrorMessage().c_str());
        else
        {
            print_filename(filepath);
            model_count++;
            ui->figure_number->setRange(1, model_count);
            facade.EditSettings();
            if(facade.previous_scene_loaded())
            {
                print_check = model_count;
                facade.DrawScene(ui->graph, model_count);
            }
        }
    }
}

void MainWindow::on_draw_button_clicked()
{
    if (facade.is_empty())
    {
        error_message("Модель не была загружена!");
    }
    else
    {
        float min = ui->range_start->text().toFloat();
        float max = ui->range_end->text().toFloat();
        float DxStep = ui->stepOx->text().toFloat();
        float DyStep = ui->stepOy->text().toFloat();
        if (max <= min)
            error_message("Неверно введены поля нормировки значений");
        else if (DxStep < 0 || DyStep < 0)
            error_message("Неверно введены поля шагов");
        else
        {
            print_check = model_count;
            NormalizationParameters param;
            param.SetParameters(min, max, DxStep, DyStep);
            facade.Normalize(param);
            facade.DrawScene(ui->graph, model_count);
        }
    }
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    FacadeOperationResult result(true);
    size_t number = ui->figure_number->value();
    if (model_count == print_check)
    {
        if (ui->butUp->isChecked())
            result = facade.MoveScene(0, -MOVE_KOEF, 0, number);
        else if (ui->butDown->isChecked())
            result = facade.MoveScene(0, MOVE_KOEF, 0, number);
        else if (ui->butLeft->isChecked())
            result = facade.MoveScene(-MOVE_KOEF, 0, 0, number);
        else if (ui->butRight->isChecked())
            result = facade.MoveScene(MOVE_KOEF, 0, 0, number);
        else if (ui->spinOxLeft->isChecked())
            result = facade.RotateScene(-ANGEL, 0, 0, number);
        else if (ui->spinOyLeft->isChecked())
            result = facade.RotateScene(0, -ANGEL, 0, number);
        else if (ui->spinOzLeft->isChecked())
            result = facade.RotateScene(0, 0, -ANGEL, number);
        else if (ui->spinOxRight->isChecked())
            result = facade.RotateScene(ANGEL, 0, 0, number);
        else if (ui->spinOyRight->isChecked())
            result = facade.RotateScene(0, ANGEL, 0, number);
        else if (ui->spinOzRight->isChecked())
            result = facade.RotateScene(0, 0, ANGEL, number);
        else if (ui->sizePlus->isChecked())
            result = facade.ScaleScene(SCALE_FOEF, number);
        else
            result = facade.ScaleScene(1/SCALE_FOEF, number);

        if (result.IsSuccess())
            facade.DrawScene(ui->graph, model_count);
        else
            error_message(result.GetErrorMessage().c_str());
    }
    else
    {
        error_message("Для начала отрисуйте все модели!\nНажмите на кнопку \"Нарисовать модели\"");
    }
    button->setChecked(false);
}

void error_message(const char* error)
{
    QMessageBox::warning(0, "Ошибка!", error);
}

void MainWindow::print_filename(string& path)
{
    QTextEdit* names = ui->filenames;
    vector<string> parts = Split(path, '/');
    string filename = parts[parts.size() - 1];
    if (model_count == 0)
    {
        names->clear();
        names->setText(filename.c_str());
    }
    else
    {
        names->append(filename.c_str());
    }
}
