#include "./Headers/gamewindow.h"

/**
 * @brief GameWindow::GameWindow This is constructor of class GameWindow its prepare GUI for game.
 * @param Gameparam
 * @param parent
 */
GameWindow::GameWindow(GameData *Gameparam,QMainWindow *parent)
    : QMainWindow(parent)
{
    GameDat = Gameparam;
    testlabel= new QLabel(this);
    testlabel->setGeometry(QRect(QPoint(10,10),QSize(200,30)));

    Spacer = new QLabel(this);
    Spacer->setGeometry(QRect(QPoint(800,0),QSize(10,800)));
    Spacer->setPixmap(this->GetImage(0,8));

    Player1Frame = new QFrame(this);
    Player1Frame->setGeometry(QRect(QPoint(830,20),QSize(260,200)));

    Player2Frame = new QFrame(this);
    Player2Frame->setGeometry(QRect(QPoint(830,270),QSize(260,200)));

    HistoryButtonsFrame = new QFrame(this);
    HistoryButtonsFrame->setGeometry(QRect(QPoint(830,520),QSize(260,100)));
    HistoryButtonsFrame->setStyleSheet("background-image: url(:/Images/Others/buttons.png)");

    QuitSaveButtonsFrame = new QFrame(this);
    QuitSaveButtonsFrame->setGeometry(QRect(QPoint(830,670),QSize(260,100)));
    QuitSaveButtonsFrame->setStyleSheet("background-image: url(:/Images/Others/buttons.png)");

    QFont font;
    font.setPointSize(12);
    InfoLabel = new QLabel(this);
    InfoLabel->setGeometry(QRect(QPoint(200,750),QSize(400,30)));
    InfoLabel->setAlignment(Qt::AlignCenter);
    InfoLabel->setStyleSheet("color: red");
    InfoLabel->setFont(font);

    Player1Name = new QLabel(this);
    Player1Name->setText("tetetet");
    Player1Name->setGeometry(QRect(QPoint(860,50),QSize(200,50)));
    Player1Name->setAlignment(Qt::AlignCenter);
    Player1Name->setFont(font);

    Player2Name = new QLabel(this);
    Player2Name->setText("tetetet2");
    Player2Name->setGeometry(QRect(QPoint(860,300),QSize(200,50)));
    Player2Name->setAlignment(Qt::AlignCenter);
    Player2Name->setFont(font);

    Player1Color = new QLabel(this);
    Player1Color->setGeometry(QRect(QPoint(935,140),QSize(50,50)));
    Player1Color->setPixmap(this->GetImage(0,9));

    Player2Color = new QLabel(this);
    Player2Color->setGeometry(QRect(QPoint(935,390),QSize(50,50)));
    Player2Color->setPixmap(this->GetImage(0,10));

    Player1Score = new QLabel(this);
    Player1Score->setGeometry(QRect(QPoint(935,140),QSize(50,50)));
    Player1Score->setAlignment(Qt::AlignCenter);
    Player1Score->setFont(font);

    Player2Score = new QLabel(this);
    Player2Score->setGeometry(QRect(QPoint(935,390),QSize(50,50)));
    Player2Score->setAlignment(Qt::AlignCenter);
    Player2Score->setFont(font);
    Player2Score->setStyleSheet("color: white");

    UndoButton = new QPushButton(this);
    UndoButton->setText("Undo");
    UndoButton->setGeometry(QRect(QPoint(910,530),QSize(100,30)));

    RedoButton = new QPushButton(this);
    RedoButton->setText("Redo");
    RedoButton->setGeometry(QRect(QPoint(910,580),QSize(100,30)));

    SaveButton = new QPushButton(this);
    SaveButton->setText("Save");
    SaveButton->setGeometry(QRect(QPoint(910,680),QSize(100,30)));

    QuitButton = new QPushButton(this);
    QuitButton->setText("Quit");
    QuitButton->setGeometry(QRect(QPoint(910,730),QSize(100,30)));

    QObject::connect(UndoButton,SIGNAL(clicked(bool)),this,SLOT(UndoButtonEvent()));
    QObject::connect(RedoButton,SIGNAL(clicked(bool)),this,SLOT(RedoButtonEvent()));
    QObject::connect(SaveButton,SIGNAL(clicked(bool)),this,SLOT(SaveButtonEvent()));
    QObject::connect(QuitButton,SIGNAL(clicked(bool)),this,SLOT(QuitButtonEvent()));

    QPixmap pixelmap;
    pixelmap = GetImage(0,6);
    white.addPixmap(pixelmap);
    pixelmap = GetImage(0,5);
    empty.addPixmap(pixelmap);
    pixelmap = GetImage(0,7);
    black.addPixmap(pixelmap);
    this->InitGame();
}

GameWindow::~GameWindow()
{

}

void GameWindow::QuitButtonEvent(){
    this->close();
}

void GameWindow::SaveButtonEvent(){

}


void GameWindow::UndoButtonEvent(){
    InfoLabel->setText("");
    if(GameDat->Game.Actual>0){
        GameDat->Game.Actual--;
        this->SwitchActivePlayer();
        this->SwitchActivePlayerFrame();
        GameLogic *Logic = new GameLogic();
        GameDat = Logic->ReCountScore(GameDat);
        this->UpdateScore();
        this->RenderGrid();
        this->DissableButtonGrid();
    }else{
        InfoLabel->setText("Cannot do Undo");
    }

}

void GameWindow::RedoButtonEvent(){
    InfoLabel->setText("");
    if(GameDat->Game.Actual<GameDat->Game.Last){
        GameDat->Game.Actual++;
        this->SwitchActivePlayer();
        this->SwitchActivePlayerFrame();
        GameLogic *Logic = new GameLogic();
        GameDat = Logic->ReCountScore(GameDat);
        this->UpdateScore();
        this->RenderGrid();
        this->DissableButtonGrid();
    }else{
        InfoLabel->setText("Cannot do Redo");
    }

}

/**
 * @brief GameWindow::InitGame This method initialize GUI for game
 */
void GameWindow::InitGame(){
    this->CreateCorners();
    this->CreateGameHints();
    this->CreateGameGrid();
    this->SwitchActivePlayerFrame();
    GameLogic *Logic = new GameLogic();
    GameDat = Logic->ReCountScore(GameDat);
    this->UpdateScore();
    this->RenderGrid();
    this->DissableButtonGrid();
    Player1Name->setText(*GameDat->Game.Player1Name);
    Player2Name->setText(*GameDat->Game.Player2Name);
}

/**
 * @brief GameWindow::SwitchActivePlayer This method switch actual player to turn of next player
 */
void GameWindow::SwitchActivePlayer(){
    if(GameDat->Game.ActivePlayer==0){
        GameDat->Game.ActivePlayer=1;
    }else{
        GameDat->Game.ActivePlayer=0;
    }
}

/**
 * @brief GameWindow::SwitchActivePlayerFrame This method switch padding of active player
 */
void GameWindow::SwitchActivePlayerFrame(){
    if(GameDat->Game.ActivePlayer==0){
        Player1Frame->setStyleSheet("background-image: url(:/Images/Others/active.png)");
        Player2Frame->setStyleSheet("background-image: url(:/Images/Others/inactive.png)");
    }else{
        Player2Frame->setStyleSheet("background-image: url(:/Images/Others/active.png)");
        Player1Frame->setStyleSheet("background-image: url(:/Images/Others/inactive.png)");
    }

}

/**
 * @brief GameWindow::UpdateScore This method update sroce in information labels of both player
 */
void GameWindow::UpdateScore(){
    Player1Score->setText(QString::number(GameDat->Game.Player1Score));
    Player2Score->setText(QString::number(GameDat->Game.Player2Score));
}

/**
 * @brief GameWindow::RenderGrid This method render pictures to game grid formed as array of buttons. Data is
 * saved in game structure
 */
void GameWindow::RenderGrid(){
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            if(GameDat->Game.History[GameDat->Game.Actual].Grid[i][j]==0){
            GameGridButton[i][j]->setIcon(empty);
            }
            if(GameDat->Game.History[GameDat->Game.Actual].Grid[i][j]==1){
            GameGridButton[i][j]->setIcon(white);
            }
            if(GameDat->Game.History[GameDat->Game.Actual].Grid[i][j]==2){
            GameGridButton[i][j]->setIcon(black);
            }
        }
    }
}

/**
 * @brief GameWindow::CreateCorners This method create labels in corners of game hints
 */
void GameWindow::CreateCorners()
{
    GameCornerLabel[0] = new QLabel(this);
    GameCornerLabel[0]->setPixmap(GetImage(0,4));
    GameCornerLabel[0]->setGeometry(QRect(QPoint(50,50),QSize(30,30)));
    GameCornerLabel[1] = new QLabel(this);
    GameCornerLabel[1]->setGeometry(QRect(QPoint(50+(GameDat->Game.GridSize*50)+30,50),QSize(30,30)));
    GameCornerLabel[1]->setPixmap(GetImage(0,4));
    GameCornerLabel[2] = new QLabel(this);
    GameCornerLabel[2]->setGeometry(QRect(QPoint(50,50+(50*GameDat->Game.GridSize)+30),QSize(30,30)));
    GameCornerLabel[2]->setPixmap(GetImage(0,4));
    GameCornerLabel[3] = new QLabel(this);
    GameCornerLabel[3]->setGeometry(QRect(QPoint(50+(GameDat->Game.GridSize*50)+30,50+(GameDat->Game.GridSize*50)+30),QSize(30,30)));
    GameCornerLabel[3]->setPixmap(GetImage(0,4));
}

/**
 * @brief GameWindow::CreateGameHints This Method create label who identifi row and cow of game grid, its around of game grid
 */
void GameWindow::CreateGameHints()
{
    for(int i=0;i<GameDat->Game.GridSize;i++){
        GameTopLabel[i] = new QLabel(this);
        GameTopLabel[i]->setPixmap(GetImage(i,0));
        GameTopLabel[i]->setGeometry(QRect(QPoint(80+(50*i),50),QSize(50,30)));
    }
    for(int i=0;i<GameDat->Game.GridSize;i++){
        GameBottonLabel[i] = new QLabel(this);
        GameBottonLabel[i]->setPixmap(GetImage(i,1));
        GameBottonLabel[i]->setGeometry(QRect(QPoint(80+(50*i),80+(GameDat->Game.GridSize*50)),QSize(50,30)));
    }
    for(int i=0;i<GameDat->Game.GridSize;i++){
        GameLeftLabel[i] = new QLabel(this);
        GameLeftLabel[i]->setPixmap(GetImage(i,2));
        GameLeftLabel[i]->setGeometry(QRect(QPoint(50,80+(i*50)),QSize(30,50)));
    }
    for(int i=0;i<GameDat->Game.GridSize;i++){
        GameRightLabel[i] = new QLabel(this);
        GameRightLabel[i]->setPixmap(GetImage(i,3));
        GameRightLabel[i]->setGeometry(QRect(QPoint(80+(GameDat->Game.GridSize*50),80+(i*50)),QSize(30,50)));
    }

}

/**
 * @brief GameWindow::CreateGameGrid This method create GameGrid - array of buttons
 */
void GameWindow::CreateGameGrid()
{    
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            GameGridButton[i][j] = new QPushButton(this);
            GameGridButton[i][j]->setIcon(empty);
            GameGridButton[i][j]->setIconSize(QSize(50,50));
            GameGridButton[i][j]->setGeometry(QRect(QPoint(80+(i*50),80+(j*50)),QSize(50,50)));
            QObject::connect(GameGridButton[i][j],SIGNAL(clicked(bool)),this,SLOT(ButtonGridEvent()));
        }
    }
}
/**
 * @brief GameWindow::ButtonGridEvent
 * This method react on Button click in game grid
 *
 */
void GameWindow::ButtonGridEvent(){
    QObject* obj = sender();
    InfoLabel->setText("");
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            if( obj == GameGridButton[i][j] )
            {
                 testlabel->setText(QString::number(i)+"  sloupec   "+ QString::number(j)+" radek ");
                 GameLogic *Logic = new GameLogic();
                 if(Logic->SolveMove(GameDat->Game.History[GameDat->Game.Actual].Grid,i,j,GameDat->Game.GridSize,GameDat->Game.ActivePlayer)){
                     GameDat = Logic->Move(GameDat,i,j);
                     this->SwitchActivePlayer();
                     this->SwitchActivePlayerFrame();
                     GameDat = Logic->ReCountScore(GameDat);
                     this->UpdateScore();
                     this->RenderGrid();
                     this->DissableButtonGrid();
                 }else{
                     InfoLabel->setText("Thats not valid move...");
                 }
            }
        }
    }
}

void GameWindow::DissableButtonGrid(){
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            if(GameDat->Game.History[GameDat->Game.Actual].Grid[i][j]!=0){
                GameGridButton[i][j]->setEnabled(false);
            }else{
                GameGridButton[i][j]->setEnabled(true);
            }
        }
    }
}

/**
 * @brief GameWindow::GetImage This method return picture for defined by identifer and index
 * @param index index of picture
 * @param identyfi identifer of picture
 * @return picture in QPixmap
 */
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
    case 8:
        file = pathToFiles + "spacer.png";
        break;
    case 9:
        file = pathToFiles + "colorWhite.png";
        break;
    case 10:
        file = pathToFiles + "colorBlack.png";
        break;
    }
    QPixmap image(file);
    return image;
}

