#include "./Headers/gamewindow.h"

GameWindow::GameWindow(int Size,QMainWindow *parent)
    : QMainWindow(parent)
{
    arraySize=Size;
    testlabel= new QLabel(this);
    testlabel->setGeometry(QRect(QPoint(0,0),QSize(200,30)));
    this->CreateCorners(arraySize);
    this->CreateGameHints(arraySize);
    QPixmap pixelmap = GetImage(0,6);
    white.addPixmap(pixelmap);
    pixelmap = GetImage(0,5);
    empty.addPixmap(pixelmap);
    pixelmap = GetImage(0,7);
    black.addPixmap(pixelmap);
    this->CreateGameGrid(arraySize);
}

GameWindow::~GameWindow()
{

}

void GameWindow::CreateCorners(int size)
{
    GameCornerLabel[0] = new QLabel(this);
    GameCornerLabel[0]->setPixmap(GetImage(0,4));
    GameCornerLabel[0]->setGeometry(QRect(QPoint(50,50),QSize(30,30)));
    GameCornerLabel[1] = new QLabel(this);
    GameCornerLabel[1]->setGeometry(QRect(QPoint(50+(size*50)+30,50),QSize(30,30)));
    GameCornerLabel[1]->setPixmap(GetImage(0,4));
    GameCornerLabel[2] = new QLabel(this);
    GameCornerLabel[2]->setGeometry(QRect(QPoint(50,50+(size*50)+30),QSize(30,30)));
    GameCornerLabel[2]->setPixmap(GetImage(0,4));
    GameCornerLabel[3] = new QLabel(this);
    GameCornerLabel[3]->setGeometry(QRect(QPoint(50+(size*50)+30,50+(size*50)+30),QSize(30,30)));
    GameCornerLabel[3]->setPixmap(GetImage(0,4));
}

void GameWindow::CreateGameHints(int size)
{
    for(int i=0;i<size;i++){
        GameTopLabel[i] = new QLabel(this);
        GameTopLabel[i]->setPixmap(GetImage(i,0));
        GameTopLabel[i]->setGeometry(QRect(QPoint(80+(50*i),50),QSize(50,30)));
    }
    for(int i=0;i<size;i++){
        GameBottonLabel[i] = new QLabel(this);
        GameBottonLabel[i]->setPixmap(GetImage(i,1));
        GameBottonLabel[i]->setGeometry(QRect(QPoint(80+(50*i),80+(size*50)),QSize(50,30)));
    }
    for(int i=0;i<size;i++){
        GameLeftLabel[i] = new QLabel(this);
        GameLeftLabel[i]->setPixmap(GetImage(i,2));
        GameLeftLabel[i]->setGeometry(QRect(QPoint(50,80+(i*50)),QSize(30,50)));
    }
    for(int i=0;i<size;i++){
        GameRightLabel[i] = new QLabel(this);
        GameRightLabel[i]->setPixmap(GetImage(i,3));
        GameRightLabel[i]->setGeometry(QRect(QPoint(80+(size*50),80+(i*50)),QSize(30,50)));
    }

}

void GameWindow::CreateGameGrid(int size)
{    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            GameGridButton[i][j] = new QPushButton(this);
            GameGridButton[i][j]->setIcon(empty);
            GameGridButton[i][j]->setIconSize(QSize(50,50));
            GameGridButton[i][j]->setGeometry(QRect(QPoint(80+(i*50),80+(j*50)),QSize(50,50)));
            QObject::connect(GameGridButton[i][j],SIGNAL(clicked(bool)),this,SLOT(TestChange()));
        }
    }
}

void GameWindow::TestChange(){
    QObject* obj = sender();

    for(int i=0;i<arraySize;i++){
        for(int j=0;j<arraySize;j++){
            if( obj == GameGridButton[i][j] )
            {
                 testlabel->setText(QString::number(i)+" kurvaaaa "+ QString::number(j));
            }
        }
    }
}

QPixmap GameWindow::GetImage(int index,int identyfi){
    QString file;
    char znak;
    switch(identyfi){
    case 0:
        znak = index+65;
        file = pathToFiles + znak + ".png";
        break;
    case 2:
        file = pathToFiles + QString::number(index+1) + ".png";
        break;
    case 3:
        file = pathToFiles + QString::number(index+1) + ".png";
        break;
    case 1:
        znak = index+65;
        file = pathToFiles + znak + ".png";
        break;
    case 6:
        file = pathToFiles + "white.png";
        break;
    case 7:
        file = pathToFiles + "black.png";
        break;
    case 5:
        file = pathToFiles + "empty.png";
        break;
    case 4:
        file = pathToFiles + "corner.png";
        break;
    }
    QPixmap image(file);
    return image;
}

