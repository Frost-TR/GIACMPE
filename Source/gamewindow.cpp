/**
 * @file   gamewindow.cpp
 * @author Rys Tomáš, Tadeáš Kovář
 */

#include "./Headers/gamewindow.h"

/**
 * @brief GameWindow::GameWindow Konstruktor třídy, slouží pro inicializaci herní desky pro hru.
 * @param Gameparam Herní data.
 * @param parent
 */
GameWindow::GameWindow(GameData *Gameparam,QMainWindow *parent)
    : QMainWindow(parent)
{
    GameDat = Gameparam;

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
    isSaved=false;
    this->InitGame();
}

/**
 * @brief GameWindow::~GameWindow Destruktor této třídy.
 */
GameWindow::~GameWindow()
{

}

/**
 * @brief GameWindow::QuitButtonEvent Metoda reagující na stisk tlačítka quit.
 */
void GameWindow::QuitButtonEvent(){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Quit?", "Quit?",
                                    QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes){
     this->close();
    }
}

/**
 * @brief GameWindow::SaveGameToFile Tato metoda ukláda aktualní hru do souboru.
 */
void GameWindow::SaveGameToFile(){
    QString Filename = QFileDialog::getSaveFileName();
    QFile file(Filename);
         if (file.open(QIODevice::WriteOnly | QIODevice::Text))
             {
             QTextStream outToFile(&file);
             outToFile << "Hra2016-TTRK" << endl;
             outToFile << QString::number(GameDat->Game.GridSize) << endl;
             outToFile << QString::number(GameDat->Game.Actual) << endl;
             outToFile << QString::number(GameDat->Game.Last) << endl;
             outToFile << QString::number(GameDat->Game.Player1Score) << endl;
             outToFile << QString::number(GameDat->Game.Player2Score) << endl;
             outToFile << QString::number(GameDat->Game.RemainingStones) << endl;
             outToFile << QString::number(GameDat->Game.ActivePlayer) << endl;
             outToFile << QString::number(GameDat->Game.AIlevel) << endl;
             if(GameDat->Game.OpponentIsHuman){
                 outToFile << QString::number(1) << endl;
             }else{
                 outToFile << QString::number(0) << endl;
             }
             outToFile << *GameDat->Game.Player1Name << endl;
             outToFile << *GameDat->Game.Player2Name << endl;
             QString *outputGrid = new QString();
             outputGrid->resize(2*GameDat->Game.GridSize);
             outputGrid->clear();
             int position=0;
             for(int x=0;x<=GameDat->Game.Last;x++){
                 for(int i=0;i<GameDat->Game.GridSize;i++){
                     for(int j=0;j<GameDat->Game.GridSize;j++){
                     outputGrid->insert(position,QChar(GameDat->Game.History[x].Grid[i][j]+48));
                     position++;
                     }
                 }
                outToFile << *outputGrid << endl;
                position=0;
                outputGrid->clear();
             }
             file.close();
             isSaved=true;
         }else{
         QMessageBox::critical(this,"Error","Cannot open file","OK");
         }

    return;
}

/**
 * @brief GameWindow::SaveButtonEvent Metoda reagující na stisk tlačítka save.
 */
void GameWindow::SaveButtonEvent(){
    this->SaveGameToFile();

}

/**
 * @brief GameWindow::UndoButtonEvent Metoda reagující na stisk tlačítka undo.
 */
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

/**
 * @brief GameWindow::RedoButtonEvent Metoda reagující na stisk tlačítka redo.
 */
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
 * @brief GameWindow::InitGame Tato metoda inicializuje GUI.
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
 * @brief GameWindow::SwitchActivePlayer Tato metoda přepín aktivního hráče na protihráče.
 */
void GameWindow::SwitchActivePlayer(){
    if(GameDat->Game.ActivePlayer==0){
        GameDat->Game.ActivePlayer=1;
    }else{
        GameDat->Game.ActivePlayer=0;
    }
}

/**
 * @brief GameWindow::SwitchActivePlayerFrame Tato metoda upravuje zobrazení aktivního hráče.
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
 * @brief GameWindow::UpdateScore Tato metoda upravuje skore v informačních panelech.
 */
void GameWindow::UpdateScore(){
    Player1Score->setText(QString::number(GameDat->Game.Player1Score));
    Player2Score->setText(QString::number(GameDat->Game.Player2Score));
}

/**
 * @brief GameWindow::RenderGrid Tato metoda vykresluje obrázky do herní sítě vytvořené jako pole tlačítek.Data jsou
 * uložena v herní struktůře.
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
 * @brief GameWindow::CreateCorners Tato metoda vytváří labely v rozích herní nápovědy
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
 * @brief GameWindow::CreateGameHints Tato metoda vytvoří label, který identifikuje řádek a sloupec hrací sítě kolem celé hrací sítě.
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
 * @brief GameWindow::CreateGameGrid Tato metoda vytváří herní síť - pole tlačítek
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
 * @brief GameWindow::WinMessage Tato metoda zobrazuje zpravu pro vítěze.
 */
void GameWindow::WinMessage(){
    QString *message= new QString("");
    message->resize(2000);
    message->clear();
    message->append("Player ");
    if(GameDat->Game.Player1Score>GameDat->Game.Player2Score){
        message->append(*GameDat->Game.Player1Name);
        message->append(" Win.\n");
        message->append("Score : ");
        message->append(*GameDat->Game.Player1Name);
        message->append(" - ");
        message->append(QString::number(GameDat->Game.Player1Score));
        message->append(" : ");
        message->append(QString::number(GameDat->Game.Player2Score));
        message->append(" - ");
        message->append(*GameDat->Game.Player2Name);
    }else{
        message->append(*GameDat->Game.Player2Name);
        message->append(" Win.\n");
        message->append("Score : ");
        message->append(*GameDat->Game.Player1Name);
        message->append(" - ");
        message->append(QString::number(GameDat->Game.Player1Score));
        message->append(" : ");
        message->append(QString::number(GameDat->Game.Player2Score));
        message->append(" - ");
        message->append(*GameDat->Game.Player2Name);
    }
    QMessageBox::information(this,"Win !!!!",*message,"OK");

    this->close();
}

/**
 * @brief GameWindow::ButtonGridEvent
 * Tato metoda reáguje na stisk tlačítka v herní síti.
 *
 */
void GameWindow::ButtonGridEvent(){
    QObject* obj = sender();
    InfoLabel->setText("");
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            if( obj == GameGridButton[i][j] )
            {
                if(!DisableGrid[i][j]){
                 GameLogic *Logic = new GameLogic();

                 if(GameDat->Game.OpponentIsHuman){
                     if(Logic->SolveMove(GameDat->Game.History[GameDat->Game.Actual].Grid,i,j,GameDat->Game.GridSize,GameDat->Game.ActivePlayer)){
                         GameDat = Logic->Move(GameDat,i,j);
                         this->SwitchActivePlayer();
                         if(Logic->CanMove(GameDat)){
                             this->SwitchActivePlayerFrame();
                             GameDat = Logic->ReCountScore(GameDat);
                             this->UpdateScore();
                             this->RenderGrid();
                             this->DissableButtonGrid();
                             this->repaint();
                         }else{
                            InfoLabel->setText("You cant play. Opponent is on turn");
                            this->SwitchActivePlayer();
                            if(Logic->CanMove(GameDat)){
                                this->SwitchActivePlayerFrame();
                                GameDat = Logic->ReCountScore(GameDat);
                                this->UpdateScore();
                                this->RenderGrid();
                                this->DissableButtonGrid();
                                this->repaint();
                            }else{
                                this->WinMessage();
                            }
                         }
                         isSaved=false;
                         if(GameDat->Game.RemainingStones==0){
                            this->WinMessage();
                         }
                     }else{
                         InfoLabel->setText("Thats not valid move...");
                     }
                 }else{
                     if(Logic->SolveMove(GameDat->Game.History[GameDat->Game.Actual].Grid,i,j,GameDat->Game.GridSize,GameDat->Game.ActivePlayer)){
                         GameDat = Logic->Move(GameDat,i,j);
                         this->SwitchActivePlayer();
                         if(Logic->CanMove(GameDat)){
                             this->SwitchActivePlayerFrame();
                             GameDat = Logic->ReCountScore(GameDat);
                             this->UpdateScore();
                             this->RenderGrid();
                             this->DissableButtonGrid();
                             this->repaint();
                             QThread::msleep(300);
                             GameInteligence *AI = new GameInteligence();
                             GameDat = AI->SwitchInteligence(GameDat);
                             QThread::msleep(300);
                             this->SwitchActivePlayer();
                             this->SwitchActivePlayerFrame();
                             GameDat = Logic->ReCountScore(GameDat);
                             this->UpdateScore();
                             this->RenderGrid();
                             this->DissableButtonGrid();
                             this->repaint();
                             while(true){
                                if(Logic->CanMove(GameDat)){
                                    break;
                                }else{
                                    InfoLabel->setText("You cant play. Opponent is on turn");
                                    this->SwitchActivePlayer();
                                    this->SwitchActivePlayerFrame();
                                    this->repaint();
                                    if(Logic->CanMove(GameDat)){
                                        QThread::msleep(300);
                                        GameInteligence *AI = new GameInteligence();
                                        GameDat = AI->SwitchInteligence(GameDat);
                                        QThread::msleep(300);
                                        this->SwitchActivePlayer();
                                        this->SwitchActivePlayerFrame();
                                        GameDat = Logic->ReCountScore(GameDat);
                                        this->UpdateScore();
                                        this->RenderGrid();
                                        this->DissableButtonGrid();
                                        this->repaint();
                                    }else{
                                        //this->WinMessage();
                                        break;
                                    }

                                }
                             }
                         }else{
                            InfoLabel->setText("You cant play. Opponent is on turn");
                            this->SwitchActivePlayer();
                            if(Logic->CanMove(GameDat)){
                                this->SwitchActivePlayerFrame();
                                GameDat = Logic->ReCountScore(GameDat);
                                this->UpdateScore();
                                this->RenderGrid();
                                this->DissableButtonGrid();
                                this->repaint();
                            }else{
                              this->WinMessage();
                            }
                         }
                         isSaved=false;
                         if(GameDat->Game.RemainingStones==0){
                               this->WinMessage();
                         }

                         isSaved=false;
                     }else{
                         InfoLabel->setText("Thats not valid move...");
                     }
                 }
                }
            }
        }
    }
}

/**
 * @brief GameWindow::DissableButtonGrid Tato metoda zabranuje kliknuti na již vyplněné pole.
 */
void GameWindow::DissableButtonGrid(){
    for(int i=0;i<GameDat->Game.GridSize;i++){
        for(int j=0;j<GameDat->Game.GridSize;j++){
            if(GameDat->Game.History[GameDat->Game.Actual].Grid[i][j]!=0){
                DisableGrid[i][j]=true;
            }else{
                DisableGrid[i][j]=false;;
            }
        }
    }
}

/**
 * @brief GameWindow::GetImage Tato metoda vrací obrázek definovaný identifikátorem a indexem.
 * @param index index obrázku
 * @param identyfi identifikátor obrázku
 * @return obrázek v QPixmap
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

