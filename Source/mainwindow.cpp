#include "./Headers/mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    actualLayout=0;

    QFont font;
    font.setPointSize(16);

    MenuLabel = new QLabel("MenuLabel",this);
    MenuLabel->setText("Hra 2016 - Reversi");
    MenuLabel->setFont(font);
    MenuLabel->setGeometry(QRect(QPoint(100,50),QSize(300,70)));

    NewGameLabel = new QLabel("NewGameLabel",this);
    NewGameLabel->setText("New Game");
    NewGameLabel->setFont(font);
    NewGameLabel->setVisible(false);
    NewGameLabel->setGeometry(QRect(QPoint(100,50),QSize(300,70)));

    BoardSizeLabel = new QLabel("BoardSizeLabel",this);
    BoardSizeLabel->setText("Playing board size:");
    BoardSizeLabel->setVisible(false);
    BoardSizeLabel->setGeometry(QRect(QPoint(100,100),QSize(100,20)));

    OpponentLabel = new QLabel("OpponentLabel",this);
    OpponentLabel->setText("Opponent :");
    OpponentLabel->setVisible(false);
    OpponentLabel->setGeometry(QRect(QPoint(100,130),QSize(100,20)));

    PlayerNameLabel = new QLabel("PlayerNameLabel",this);
    PlayerNameLabel->setText("Player name: ");
    PlayerNameLabel->setVisible(false);
    PlayerNameLabel->setGeometry(QRect(QPoint(100,190),QSize(100,20)));

    PlayerNameLabel2 = new QLabel("PlayerNameLabel2",this);
    PlayerNameLabel2->setText("Player 2 name: ");
    PlayerNameLabel2->setVisible(false);
    PlayerNameLabel2->setGeometry(QRect(QPoint(100,220),QSize(100,20)));

    OpponentDifficultLabel = new QLabel("OpponentDifficultLabel",this);
    OpponentDifficultLabel->setText("Game inteligence: ");
    OpponentDifficultLabel->setVisible(false);
    OpponentDifficultLabel->setGeometry(QRect(QPoint(100,220),QSize(100,20)));

    PlayerNameEdit = new QLineEdit(this);
    PlayerNameEdit->setVisible(false);
    PlayerNameEdit->setGeometry(QRect(QPoint(220,190),QSize(150,20)));

    PlayerNameEdit2 = new QLineEdit(this);
    PlayerNameEdit2->setVisible(false);
    PlayerNameEdit2->setGeometry(QRect(QPoint(220,220),QSize(150,20)));

    BoardSizeComboBox = new QComboBox(this);
    BoardSizeComboBox->setVisible(false);
    BoardSizeComboBox->setGeometry(QRect(QPoint(220,100),QSize(100,20)));
    BoardSizeComboBox->addItem("6x6");
    BoardSizeComboBox->addItem("8x8");
    BoardSizeComboBox->addItem("10x10");
    BoardSizeComboBox->addItem("12x12");
    BoardSizeComboBox->setCurrentIndex(1);

    OpponentDifficultComboBox = new QComboBox(this);
    OpponentDifficultComboBox->setVisible(false);
    OpponentDifficultComboBox->setGeometry(QRect(QPoint(220,220),QSize(100,20)));
    OpponentDifficultComboBox->addItem("Stupid");
    OpponentDifficultComboBox->addItem("Very Stupid");
    OpponentDifficultComboBox->setCurrentIndex(0);

    HumanRadioButton = new QRadioButton("HumanRadioButton",this);
    HumanRadioButton->setVisible(false);
    HumanRadioButton->setGeometry(QRect(QPoint(220,130),QSize(150,20)));
    HumanRadioButton->setText("Human");

    AIRadioButton = new QRadioButton("AIRadioButton",this);
    AIRadioButton->setVisible(false);
    AIRadioButton->setGeometry(QRect(QPoint(220,160),QSize(150,20)));
    AIRadioButton->setText("Artificial Inteligence");

    NewGameButton= new QPushButton("NewGameButton",this);
    NewGameButton->setText("New Game");
    NewGameButton->setFont(font);
    NewGameButton->setGeometry(QRect(QPoint(100, 280),
                                 QSize(300, 70)));

    LoadButton= new QPushButton("LoadButton",this);
    LoadButton->setText("Load Game");
    LoadButton->setFont(font);
    LoadButton->setGeometry(QRect(QPoint(100, 360),
                                 QSize(300, 70)));

    AboutGameButton= new QPushButton("AboutGameButton",this);
    AboutGameButton->setText("About");
    AboutGameButton->setFont(font);
    AboutGameButton->setGeometry(QRect(QPoint(100, 440),
                                 QSize(300, 70)));

    ExitGameButton= new QPushButton("ExitGameButton",this);
    ExitGameButton->setText("Exit Game");
    ExitGameButton->setFont(font);
    ExitGameButton->setGeometry(QRect(QPoint(100, 520),
                                 QSize(300, 70)));

    BackButton = new QPushButton("BackButton",this);
    BackButton->setText("Back");
    BackButton->setVisible(false);
    BackButton->setFont(font);
    BackButton->setGeometry(QRect(QPoint(100, 520),
                                 QSize(300, 70)));

    PlayGameButton= new QPushButton("PlayGameButton",this);
    PlayGameButton->setText("Play");
    PlayGameButton->setVisible(false);
    PlayGameButton->setFont(font);
    PlayGameButton->setGeometry(QRect(QPoint(100, 440),
                                 QSize(300, 70)));

    LoadGameButton= new QPushButton("LoadGameButton",this);
    LoadGameButton->setText("Load");
    LoadGameButton->setVisible(false);
    LoadGameButton->setFont(font);
    LoadGameButton->setGeometry(QRect(QPoint(100, 360),
                                 QSize(300, 70)));

    DeleteGameButton= new QPushButton("DeleteGameButton",this);
    DeleteGameButton->setText("Delete");
    DeleteGameButton->setVisible(false);
    DeleteGameButton->setFont(font);
    DeleteGameButton->setGeometry(QRect(QPoint(100, 440),
                                 QSize(300, 70)));

    QObject::connect(ExitGameButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(NewGameButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToNewGame()));
    QObject::connect(LoadButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToLoadGame()));
    QObject::connect(AboutGameButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToAboutGame()));
    QObject::connect(BackButton,SIGNAL(clicked(bool)),this,SLOT(setLayoutToMenu()));
    QObject::connect(HumanRadioButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutForOpponent()));
    QObject::connect(AIRadioButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutForOpponent()));
    QObject::connect(PlayGameButton,SIGNAL(clicked(bool)),this,SLOT(showGameWindow()));
}

MainWindow::~MainWindow()
{

}


void MainWindow::showGameWindow(){
    int size = 0;
    switch(BoardSizeComboBox->currentIndex()){
    case 0:
        size = 6;
        break;
    case 1:
        size = 8;
        break;
    case 2:
        size = 10;
        break;
    case 3:
        size = 12;
        break;
    }
    NewGameWindow = new GameWindow(size);
    NewGameWindow->setFixedSize(1200,800);
    NewGameWindow->show();
}

void MainWindow::SetLayoutForOpponent(){
    if(AIRadioButton->isChecked()){
        OpponentDifficultLabel->setVisible(true);
        OpponentDifficultComboBox->setVisible(true);
        PlayerNameLabel2->setVisible(false);
        PlayerNameEdit2->setVisible(false);
    }else{
        OpponentDifficultLabel->setVisible(false);
        OpponentDifficultComboBox->setVisible(false);
        PlayerNameLabel2->setVisible(true);
        PlayerNameEdit2->setVisible(true);
    }

}

void MainWindow::SetLayoutToNewGame(){
    actualLayout=1;
    NewGameButton->setVisible(false);
    LoadButton->setVisible(false);
    AboutGameButton->setVisible(false);
    ExitGameButton->setVisible(false);
    BackButton->setVisible(true);
    PlayGameButton->setVisible(true);
    MenuLabel->setVisible(false);
    NewGameLabel->setVisible(true);
    BoardSizeLabel->setVisible(true);
    BoardSizeComboBox->setVisible(true);
    OpponentLabel->setVisible(true);
    HumanRadioButton->setVisible(true);
    AIRadioButton->setVisible(true);
    PlayerNameLabel->setVisible(true);
    PlayerNameEdit->setVisible(true);

    BoardSizeComboBox->setCurrentIndex(1);
    OpponentDifficultComboBox->setCurrentIndex(0);

    HumanRadioButton->setChecked(false);
    AIRadioButton->setChecked(true);
    this->SetLayoutForOpponent();
}

void MainWindow::SetLayoutToLoadGame(){
    actualLayout=2;
    NewGameButton->setVisible(false);
    LoadButton->setVisible(false);
    AboutGameButton->setVisible(false);
    ExitGameButton->setVisible(false);
    DeleteGameButton->setVisible(true);
    LoadGameButton->setVisible(true);
    BackButton->setVisible(true);
    MenuLabel->setVisible(false);

}

void MainWindow::SetLayoutToAboutGame(){
    actualLayout=3;
    NewGameButton->setVisible(false);
    LoadButton->setVisible(false);
    AboutGameButton->setVisible(false);
    ExitGameButton->setVisible(false);
    BackButton->setVisible(true);
    MenuLabel->setVisible(false);

}

void MainWindow::setLayoutToMenu(){
    NewGameButton->setVisible(true);
    LoadButton->setVisible(true);
    AboutGameButton->setVisible(true);
    ExitGameButton->setVisible(true);
    BackButton->setVisible(false);
    MenuLabel->setVisible(true);
    switch(actualLayout){
    case 1:
        PlayGameButton->setVisible(false);
        NewGameLabel->setVisible(false);
        BoardSizeLabel->setVisible(false);
        BoardSizeComboBox->setVisible(false);
        OpponentLabel->setVisible(false);
        HumanRadioButton->setVisible(false);
        AIRadioButton->setVisible(false);
        PlayerNameLabel->setVisible(false);
        PlayerNameEdit->setVisible(false);
        OpponentDifficultLabel->setVisible(false);
        OpponentDifficultComboBox->setVisible(false);

        actualLayout=0;
        break;
    case 2:
        LoadGameButton->setVisible(false);
        DeleteGameButton->setVisible(false);

        actualLayout=0;
        break;
    case 3:
        actualLayout=0;
        break;
    }
}

