#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <chrono>
#include <thread>

// opencv
#include <opencv2/opencv.hpp>
#include "cv_to_qt.h"

// lcm
#include <lcm/lcm-cpp.hpp>
#include "lcm_types/command.hpp"
#include "lcm_types/map_data_t.hpp"
#include "lcm_types/robot_status.hpp"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double get_time();

    //joystick
    bool flag_x = false;
    bool flag_y = false;
    bool flag_th = false;
    bool flag_mx = false;
    bool flag_my = false;
    bool flag_mth = false;
    float robot_x;
    float robot_y;
    float robot_th;
    int robot_state;

    // lcm
    lcm::LCM lcm;
    void cmd_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const command *msg);
    void robot_status_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_status *msg);
    void map_data_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const map_data_t *msg);

    // lcm message loop
    std::atomic<bool> bFlag;
    std::thread* bThread = NULL;
    void bLoop();
    QTimer *timer;

private slots:
    void onTimer();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_th_pressed();
    void on_btn_mth_pressed();
    void on_btn_x_pressed();
    void on_btn_mx_pressed();
    void on_btn_y_pressed();
    void on_btn_my_pressed();
    void on_btn_th_released();
    void on_btn_mth_released();
    void on_btn_x_released();
    void on_btn_mx_released();
    void on_btn_y_released();
    void on_btn_my_released();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_btn_Ready_clicked();

    void on_btn_Moving_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
