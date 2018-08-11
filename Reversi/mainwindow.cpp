#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "help.h"
#include "info.h"
#include <QString>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initial_chessboard();

    role = black;

    black_count = 2;
    white_count = 2;

    leftUp = QPoint(40,40);
    rightDown = QPoint(200,200);

    width = 20;
    length = 20;

    initial_chessboard();
    update();

    //play_game();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionHelp_triggered()
{
    help mhelp;
    mhelp.setModal(true);
    mhelp.exec();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_us_triggered()
{
    info minfo;
    minfo.setModal(true);
    minfo.exec();
}

 void MainWindow::initial_chessboard()
 {
     //QPainter p(this);
     //p.drawPixmap(this->rect(), QPixmap("://image.qrc/chessboard.png"));

     //QLabel mlabel;
     //QRectF target(10.0, 20.0, 80.0, 60.0);
     //QRectF source(0.0, 0.0, 70.0, 40.0);
     //QPixmap pixmap;
     //pixmap.load(":/image/chessboard.jpg");
     //mlabel.setPixmap(pixmap);
     //QPainter painter(this);

     //painter.drawPixmap(target, pixmap, source);

     for(int i=0; i<8; i++)
         for(int j=0; j<8; j++)
             reversi[i][j]= empty;

     reversi[3][3] = black;
     reversi[3][4] = white;
     reversi[4][3] = white;
     reversi[4][4] = black;

     ui->black->show();
     ui->white->show();
     ui->blackCount->display(2);
     ui->whiteCount->display(2);
 }

  void MainWindow::paintEvent(QPaintEvent *qpe)
  {
      Q_UNUSED(qpe);

      //QPixmap map;
      //qDebug()<<map.load("chessboard.png");

      QPainter painter(this);

      painter.setRenderHint(QPainter::Antialiasing, true);
          // 绘制图标
      painter.drawPixmap(rect(), QPixmap("://image/chessboard.jpg"));


      QPainter p(this);
      for(int i=0; i<8; i++)
      {
          for(int j=0; j<8; j++)
          {
              if(reversi[i][j]==black)
                  p.drawPixmap(leftUp.x()+i*length, leftUp.y()+j*width, length, width, QPixmap("://image/black.jpg"));
              else if(reversi[i][j]==white)
                  p.drawPixmap(leftUp.x()+i*length, leftUp.y()+j*width, length, width, QPixmap("://image/white.jpg"));
          }
      }
      show_count();
  }

  int MainWindow::reverse_amount(const int & i, const int & j)
  {
      int dir[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
      int tempX = i, tempY = j;
      int k = 0, dir_count = 0, count = 0;
      if(reversi[tempX][tempY]!=empty)
          return 0;
      for(k=0; k<8; k++)
      {
          tempX+=dir[k][0];
          tempY+=dir[k][1];
          while(tempX>=0 && tempX<8 && tempY>=0 && tempY<8)
          {
              if(reversi[tempX][tempY]==empty)
              {
                  break;
              }
              else
              {
                  if(reversi[tempX][tempY] == role)
                  {
                      tempX+=dir[k][0];
                      tempY+=dir[k][1];
                      if(dir_count!=0) //之前已有对方子，且第一次回到自己的子
                      {
                          count+=dir_count; //可以吃子
                          break;
                      }
                  }
                  else
                  {
                          dir_count++;
                          tempX+=dir[k][0];
                          tempY+=dir[k][1];
                  }
              }
          }
          dir_count=0;
          tempX=i;
          tempY=j;
      }
      return count;
  }

  void MainWindow::reverse(const int &i, const int &j)
  {
      int dir[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
      int tempX = i, tempY = j;
      int k = 0, dir_count = 0, count = 0;
      for(k=0; k<8; k++)
      {
          tempX+=dir[k][0];
          tempY+=dir[k][1];
          while(tempX>=0 && tempX<8 && tempY>=0 && tempY<8)
          {
              if(reversi[tempX][tempY]==empty)
                  break;
              else
              {
                  if(reversi[tempX][tempY] == role)
                  {
                      tempX+=dir[k][0];
                      tempY+=dir[k][1];
                      if(dir_count!=0) //之前已有对方子，且第一次回到自己的子
                      {
                          count+=dir_count; //可以吃子，接下来进行翻转操作
                          tempX = i+dir[k][0];
                          tempY = j+dir[k][1];
                          while(tempX>=0 && tempX<8 && tempY>=0 && tempY<8)
                          {
                              if(reversi[tempX][tempY] == role)
                                  break;
                              else
                              {
                                  reversi[tempX][tempY] = role;
                                  tempX+=dir[k][0];
                                  tempY+=dir[k][1];
                              }
                          }
                          break;
                      }
                  }
                  else
                  {
                          dir_count++;
                          tempX+=dir[k][0];
                          tempY+=dir[k][1];
                  }
              }
          }
          dir_count=0;
          tempX=i;
          tempY=j;
      }

      show_count();
  }

  int MainWindow::CanPlay_count(const int &i, const int &j)
  {
      int reversi_temp[8][8];
      int m, n;
      reversi_status role_temp;
      if(role == black)
          role_temp=white;
      else
          role_temp=black;

      for(m=0; m<8; m++)
          for(n=0; n<8; n++)
              reversi_temp[m][n]=reversi[m][n];

      int dir[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
      int tempX = i, tempY = j;
      int k = 0, dir_count = 0, count = 0;

      for(k=0; k<8; k++)
      {
          tempX+=dir[k][0];
          tempY+=dir[k][1];
          while(tempX>=0 && tempX<8 && tempY>=0 && tempY<8)
          {
              if(reversi_temp[tempX][tempY]==empty)
                  break;
              else
              {
                  if(reversi_temp[tempX][tempY] == role_temp)
                  {
                      tempX+=dir[k][0];
                      tempY+=dir[k][1];
                      if(dir_count!=0) //之前已有对方子，且第一次回到自己的子
                      {
                          count+=dir_count; //可以吃子，接下来进行翻转操作
                          tempX = i+dir[k][0];
                          tempY = j+dir[k][1];
                          while(tempX>=0 && tempX<8 && tempY>=0 && tempY<8)
                          {
                              if(reversi_temp[tempX][tempY] == role_temp)
                                  break;
                              else
                              {
                                  reversi_temp[tempX][tempY] = role_temp;
                                  tempX+=dir[k][0];
                                  tempY+=dir[k][1];
                              }
                          }
                          break;
                      }
                  }
                  else
                  {
                          dir_count++;
                          tempX+=dir[k][0];
                          tempY+=dir[k][1];
                  }
              }
          }
          dir_count=0;
          tempX=i;
          tempY=j;
      }
      int canPlayCount=0;
      for(m=0; m<8; m++)
          for(n=0; n<8; n++)
              if(reverse_amount(m,n)>0)
                  canPlayCount++;
      return canPlayCount;
  }

  void MainWindow::change_role()
  {
      if(role==black)
      {
          role=white;
          AI_play();
      }
      else
      {
          role=black;

      }

  }

  void MainWindow::AI_play()
  {
      int weight, max, m=0, n=0;
      for(int i=0; i<8; i++)
          for(int j=0; j<8; j++)
          {
              if( reverse_amount(i,j)>0 )
              {
                  weight=xy_value[i][j]+reverse_amount(i,j)*4+CanPlay_count(i,j)*10;
                  if(i==0 && j==0)
                  {
                      max=weight;
                      m=i;
                      n=j;
                  }
                  else
                  {
                      if(weight>max)
                      {
                          max=weight;
                          m=i;
                          n=j;
                      }
                  }
              }
          }
      reverse(m,n);
      update();
  }

  void MainWindow::show_count()
  {
      black_count=0;
      white_count=0;

      for(int i=0; i<8; i++)
          for(int j=0; j<8; j++)
          {
              if(reversi[i][j]==black)
                  black_count++;
              if(reversi[i][j]==white)
                  white_count++;
          }

      ui->blackCount->display(black_count);
      ui->whiteCount->display(white_count);
  }

  void MainWindow::mousePressEvent(QMouseEvent *qme)
  {
      //cout << "qme = " << qme->pos();

      int x = qme->x();
      int y = qme->y();
      int i = 0;
      int j = 0;

      if(x >= leftUp.x() && x <= (leftUp.x() + 8 * width) && y <= leftUp.y() && y >= (leftUp.y() + 8 * length))
      {
          i = (qme->x() - leftUp.x()) / width;
          j = (leftUp.y() - qme->y()) / length;

          reversi[i][j] = role;
          if(reverse_amount(i, j) > 0)
          {

              this->change_role();

              reverse(i,j);
              update();
          }
      }
  }

  bool MainWindow::end_of_game()
  {
      int i, j;
      bool flag=1;
      for(i=0; i<8; i++)
          for(j=0; j<8; j++)
              if(reverse_amount(i, j)>0)
                  flag=0;
      return flag;
  }

  void MainWindow::play_game()
  {
      while(!end_of_game())
      {
          if(role==black)
          {
              update();
              change_role();
          }
          else
          {
              AI_play();
              change_role();
          }
      }
      if(black_count>white_count)
      {
          QLabel *result=new QLabel;
          result->setText("Black wins!");
          result->show();
      }
      else if(black_count<white_count)
      {
          QLabel *result=new QLabel;
          result->setText("White wins!");
          result->show();
      }
  }
