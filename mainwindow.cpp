#include "mainwindow.h"
#include <QListView>
#include <QStandardItemModel>
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , lcm("udpm://239.255.76.67:7667?ttl=1")
{
    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(onTimer()));
    timer->start(100);
    if (bThread == NULL)
    {
        bFlag = true;
        bThread = new std::thread(&MainWindow::bLoop, this);
    }
    flag_x = false;
    flag_y = false;
    flag_th = false;

    flag_mx = false;
    flag_my = false;
    flag_mth = false;
    robot_x = 0;
    robot_y = 0;
    robot_th = 0;

    robot_state = 1;
    on_pushButton_2_clicked();

}

inline void SetBTNColor(QPushButton *btn, QString color){
    btn->setStyleSheet("QPushButton{background-color:"+color+"}");
}

void MainWindow::onTimer(){
    if(robot_state == 1){
        SetBTNColor(ui->btn_Ready, "blue");
        SetBTNColor(ui->btn_Moving, "white");
    }else{
        SetBTNColor(ui->btn_Moving, "blue");
        SetBTNColor(ui->btn_Ready, "white");
    }

    if(flag_x){
        robot_x += 0.03;
    }
    if(flag_mx){
        robot_x -= 0.03;
    }
    if(flag_y){
        robot_y += 0.03;
    }
    if(flag_my){
        robot_y -= 0.03;
    }
    if(flag_th){
        robot_th += M_PI/30;
    }
    if(flag_mth){
        robot_th -= M_PI/30;
    }

    ui->robotx->setText(QString().sprintf("%f",robot_x));
    ui->roboty->setText(QString().sprintf("%f",robot_y));
    ui->robotth->setText(QString().sprintf("%f",robot_th));

    robot_status send_msg;
    send_msg.bat = ui->le_bat->text().toFloat();
    send_msg.state = robot_state;
    send_msg.err_code = ui->le_err->text().toInt();
    send_msg.robot_pose[0] = robot_x;
    send_msg.robot_pose[1] = robot_y;
    send_msg.robot_pose[2] = robot_th;
    lcm.publish("ROBOT_STATUS",&send_msg);

}
MainWindow::~MainWindow()
{
    if(bThread != NULL)
    {
        bFlag = false;
        bThread->join();
    }

    delete ui;
}

double MainWindow::get_time()
{
    std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::nanoseconds>(t.time_since_epoch()).count();
    return timestamp*1.0e-9; // nano to sec
}

void MainWindow::cmd_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const command *msg)
{
    ui->lineEdit->setText(QString::number(msg->cmd));

    if(msg->cmd == 1 || msg->cmd == 2 || msg->cmd == 3 || msg->cmd == 4){
        robot_state = 2;
    }else if(msg->cmd == 5){
        robot_state = 1;
    }else if(msg->cmd == 6){
        robot_state = 4;
    }else if(msg->cmd == 7){
        robot_state = 2;
    }else if(msg->cmd == 9){
        on_pushButton_2_clicked();
    }
//    QStandardItemModel *model = new QStandardItemModel();
//    for(int i=0; i<255; i++){
//       model->appendRow(new QStandardItem(QString::number(msg->params[i])));
//    }
//    ui->listView->setModel(model);


}
void MainWindow::robot_status_callback(const lcm::ReceiveBuffer *rbuf, const std::string &chan, const robot_status *msg)
{
//    qDebug() << "HERE";
}

void MainWindow::bLoop()
{
    /*
    sudo ifconfig lo multicast
    sudo route add -net 224.0.0.0 netmask 240.0.0.0 dev lo
    */

    // lcm init
    if(lcm.good())
    {
        lcm.subscribe("COMMAND", &MainWindow::cmd_callback, this);
        lcm.subscribe("ROBOT_STATUS", &MainWindow::robot_status_callback, this);

    }
    else
    {
        printf("lcm init failed\n");
    }

    while(bFlag)
    {
        lcm.handleTimeout(1);
    }

}

void MainWindow::on_pushButton_clicked()
{
//    robot_status send_msg;
//    send_msg.bat = ui->le_bat->text().toFloat();
//    send_msg.state = ui->le_state->text().toInt();
//    send_msg.err_code = ui->le_err->text().toInt();
//    lcm.publish("STATUS",&send_msg);
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::Mat map = cv::imread("raw_map.png", cv::IMREAD_GRAYSCALE);
    printf("loaded map w:%d, h:%d\n", map.cols, map.rows);

    // send structure
    map_data_t send_msg;

    // map metadata
    send_msg.map_name = "test_map";
    send_msg.map_grid_w = 0.025; // 2.5cm
    send_msg.map_w = map.cols;
    send_msg.map_h = map.rows;
    send_msg.map_origin[0] = map.cols/2;
    send_msg.map_origin[1] = map.rows/2;

    // map data
    send_msg.len = send_msg.map_w*send_msg.map_h;
    send_msg.data.resize(send_msg.len, 0);
    memcpy(send_msg.data.data(), map.data, map.rows*map.cols);

    // set via points for test
    send_msg.via_num = 4;
    send_msg.via_pos.resize(send_msg.via_num);
    for(int p = 0; p < send_msg.via_num; p++)
    {
        send_msg.via_pos[p].resize(3, 0);
    }

    send_msg.via_pos[0][0] = 0;
    send_msg.via_pos[0][1] = 0;
    send_msg.via_pos[0][2] = 0;

    send_msg.via_pos[1][0] = 1.0;
    send_msg.via_pos[1][1] = 0;
    send_msg.via_pos[1][2] = 0;

    send_msg.via_pos[2][0] = 1.0;
    send_msg.via_pos[2][1] = 0;
    send_msg.via_pos[2][2] = M_PI/2;

    send_msg.via_pos[3][0] = 1.0;
    send_msg.via_pos[3][1] = 1.0;
    send_msg.via_pos[3][2] = 0;


    // set loc points for test
    send_msg.loc_num = 3;
    send_msg.loc_name.resize(send_msg.loc_num);
    send_msg.loc_pos.resize(send_msg.loc_num);
    send_msg.loc_name[0] = "table_1";
    send_msg.loc_name[1] = "wait";
    send_msg.loc_name[2] = "charge";

    send_msg.loc_pos[0].resize(3);
    send_msg.loc_pos[0][0] = -1.0;
    send_msg.loc_pos[0][1] = 0.0;
    send_msg.loc_pos[0][2] = M_PI/4;
    send_msg.loc_pos[1].resize(3);
    send_msg.loc_pos[1][0] = 0.0;
    send_msg.loc_pos[1][1] = 0.0;
    send_msg.loc_pos[1][2] = 0;
    send_msg.loc_pos[2].resize(3);
    send_msg.loc_pos[2][0] = 0.0;
    send_msg.loc_pos[2][1] = 1.0;
    send_msg.loc_pos[2][2] = M_PI/2;

    lcm.publish("MAP_DATA", &send_msg);
    printf("PUB(MAP_DATA): %s, %d, %d\n", send_msg.map_name.data(), send_msg.data[send_msg.len-2], send_msg.data[send_msg.len-1]);

}

void MainWindow::on_btn_x_pressed()
{
    flag_x = true;
}

void MainWindow::on_btn_mx_pressed()
{
    flag_mx = true;
}

void MainWindow::on_btn_y_pressed()
{
    flag_y = true;
}

void MainWindow::on_btn_my_pressed()
{
    flag_my = true;
}

void MainWindow::on_btn_th_pressed()
{
    flag_th = true;
}

void MainWindow::on_btn_mth_pressed()
{
    flag_mth = true;
}

void MainWindow::on_btn_x_released()
{
    flag_x = false;
}

void MainWindow::on_btn_mx_released()
{
    flag_mx= false;
}

void MainWindow::on_btn_y_released()
{
    flag_y = false;
}

void MainWindow::on_btn_my_released()
{
    flag_my = false;
}

void MainWindow::on_btn_th_released()
{
    flag_th = false;
}

void MainWindow::on_btn_mth_released()
{
    flag_mth = false;
}


void MainWindow::on_pushButton_3_clicked()
{
    robot_state = 1;
}

void MainWindow::on_pushButton_4_clicked()
{
    robot_state = 2;
}

void MainWindow::on_btn_Ready_clicked()
{
    robot_state = 1;
}

void MainWindow::on_btn_Moving_clicked()
{
    robot_state = 2;
}
