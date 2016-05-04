/**
 * @file   mainwindow.cpp
 * @author Rys Tomáš, Tadeáš Kovář
 */
#include "./Headers/mainwindow.h"

/**
 * @brief MainWindow::MainWindow Konstruktor třídy MainWindow pro vytvořeni herního menu.
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    actualLayout=0;

    QFont font;
    font.setPointSize(16);
    /** Vygenerovani objektu  QLabel QPushButton QLineEdit a jejich inicializace,
     *  Pro toto generování nebyl využit žádný tookil, vše je řeseno dynamicky.
     **/
    MenuLabel = new QLabel("MenuLabel",this);
    MenuLabel->setText("Hra 2016 - Reversi");
    MenuLabel->setFont(font);
    MenuLabel->setAlignment(Qt::AlignCenter);
    MenuLabel->setGeometry(QRect(QPoint(100,50),QSize(300,70)));

    NewGameLabel = new QLabel("NewGameLabel",this);
    NewGameLabel->setText("New Game");
    NewGameLabel->setFont(font);
    NewGameLabel->setAlignment(Qt::AlignCenter);
    NewGameLabel->setVisible(false);
    NewGameLabel->setGeometry(QRect(QPoint(100,20),QSize(300,70)));

    LoadGameLabel = new QLabel("LoadGameLabel",this);
    LoadGameLabel->setText("Load Game");
    LoadGameLabel->setFont(font);
    LoadGameLabel->setAlignment(Qt::AlignCenter);
    LoadGameLabel->setVisible(false);
    LoadGameLabel->setGeometry(QRect(QPoint(100,20),QSize(300,70)));

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

    NewGameInfoLabel = new QLabel("NewGameInfoLabel",this);
    NewGameInfoLabel->setText("");
    NewGameInfoLabel->setFont(font);
    NewGameInfoLabel->setStyleSheet("color: red");
    NewGameInfoLabel->setVisible(false);
    NewGameInfoLabel->setAlignment(Qt::AlignCenter);
    NewGameInfoLabel->setGeometry(QRect(QPoint(100,400),QSize(300,30)));

    AuthorsLabel = new QLabel("AuthorsLabel",this);
    AuthorsLabel->setText("Authors:");
    AuthorsLabel->setFont(font);
    AuthorsLabel->setVisible(false);
    AuthorsLabel->setGeometry(QRect(QPoint(20,20),QSize(80,30)));

    Author1NameLabel = new QLabel("Author1NameLabel",this);
    Author1NameLabel->setText("Tomas Rys (xrysto00)");
    Author1NameLabel->setVisible(false);
    Author1NameLabel->setFont(font);
    Author1NameLabel->setGeometry(QRect(QPoint(110,20),QSize(350,30)));

    Author2NameLabel = new QLabel("Author2NameLabel",this);
    Author2NameLabel->setText("Tadeas Kovar (xkovar69)");
    Author2NameLabel->setVisible(false);
    Author2NameLabel->setFont(font);
    Author2NameLabel->setGeometry(QRect(QPoint(110,60),QSize(350,30)));

    DescriptionLabel = new QLabel("DescriptionLabel",this);
    DescriptionLabel->setText("Board game Reversi. This application was developed as project to ICP(Seminář C++) in FIT VUT Brno by Tomáš Rys and Tadeáš Kovář.");
    DescriptionLabel->setVisible(false);
    DescriptionLabel->setFont(font);
    DescriptionLabel->setGeometry(QRect(QPoint(20,100),QSize(360,500)));
    DescriptionLabel->setWordWrap(true);

    PlayerNameEdit = new QLineEdit(this);
    PlayerNameEdit->setVisible(false);
    PlayerNameEdit->setGeometry(QRect(QPoint(220,190),QSize(150,20)));

    PlayerNameEdit2 = new QLineEdit(this);
    PlayerNameEdit2->setVisible(false);
    PlayerNameEdit2->setGeometry(QRect(QPoint(220,220),QSize(150,20)));

    LoadGameInfoLabel = new QLabel("LoadGameInfoLabel",this);
    LoadGameInfoLabel->setText("File:");
    LoadGameInfoLabel->setVisible(false);
    LoadGameInfoLabel->setFont(font);
    LoadGameInfoLabel->setAlignment(Qt::AlignCenter);
    LoadGameInfoLabel->setGeometry(QRect(QPoint(200,200),QSize(100,30)));

    LoadFileEdit = new QLineEdit(this);
    LoadFileEdit->setVisible(false);
    LoadFileEdit->setGeometry(QRect(QPoint(50,250),QSize(400,20)));

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
    OpponentDifficultComboBox->addItem("Hard");
    OpponentDifficultComboBox->addItem("Medium");
    OpponentDifficultComboBox->addItem("Stupid");
    OpponentDifficultComboBox->setCurrentIndex(1);

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

    ChooseGameButton= new QPushButton("ChooseGameButton",this);
    ChooseGameButton->setText("Choose file");
    ChooseGameButton->setVisible(false);
    ChooseGameButton->setFont(font);
    ChooseGameButton->setGeometry(QRect(QPoint(100, 440),
                                 QSize(300, 70)));


    /**
     * @brief QObject::connect Propojení signálu se sloty.
     */
    QObject::connect(ExitGameButton,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(NewGameButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToNewGame()));
    QObject::connect(LoadButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToLoadGame()));
    QObject::connect(AboutGameButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutToAboutGame()));
    QObject::connect(BackButton,SIGNAL(clicked(bool)),this,SLOT(setLayoutToMenu()));
    QObject::connect(HumanRadioButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutForOpponent()));
    QObject::connect(AIRadioButton,SIGNAL(clicked(bool)),this,SLOT(SetLayoutForOpponent()));
    QObject::connect(PlayGameButton,SIGNAL(clicked(bool)),this,SLOT(showGameWindow()));
    QObject::connect(ChooseGameButton,SIGNAL(clicked(bool)),this,SLOT(GetFileName()));
    QObject::connect(LoadGameButton,SIGNAL(clicked(bool)),this,SLOT(LoadGame()));

}
/**
 * @brief MainWindow::~MainWindow Destruktor třídy MainWindow
 */
MainWindow::~MainWindow()
{

}

/**
 * @brief MainWindow::LoadGame Načtení hry po stisknutí požadovaného tlačítka
 */
void MainWindow::LoadGame(){
    QFile file(LoadFileEdit->text());
    QTextStream in(&file);
    GameData *loadGame = new GameData();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString line = in.readLine();
        if((QString::compare(line,"Hra2016-TTRK",Qt::CaseSensitive))!=0){
           QMessageBox::critical(this,"Error","It isnt file with saved game...","OK");
           return ;
        }
        line = in.readLine();
        loadGame->Game.GridSize=line.toInt();
        line = in.readLine();
        loadGame->Game.Actual=line.toInt();
        line = in.readLine();
        loadGame->Game.Last=line.toInt();
        line = in.readLine();
        loadGame->Game.Player1Score=line.toInt();
        line = in.readLine();
        loadGame->Game.Player2Score=line.toInt();
        line = in.readLine();
        loadGame->Game.RemainingStones=line.toInt();
        line = in.readLine();
        loadGame->Game.ActivePlayer=line.toInt();
        line = in.readLine();
        loadGame->Game.AIlevel=line.toInt();
        line = in.readLine();
        if(line.toInt()==0){
           loadGame->Game.OpponentIsHuman=false;
        }else{
           loadGame->Game.OpponentIsHuman=true;
        }
        line = in.readLine();
        loadGame->Game.Player1Name= new QString(line);
        line = in.readLine();
        loadGame->Game.Player2Name= new QString(line);
        int position=0;
        for(int x=0;x<=loadGame->Game.Last;x++){
           line = in.readLine();
           for(int i=0;i<loadGame->Game.GridSize;i++){
               for(int j=0;j<loadGame->Game.GridSize;j++){
                   QChar key=line.at(position);
                   loadGame->Game.History[x].Grid[i][j]=key.toLatin1()-48;
                   position++;
               }
           }
           position=0;
        }
    NewGameWindow = new GameWindow(loadGame);
    NewGameWindow->setFixedSize(1100,800);
    NewGameWindow->setWindowTitle("Loaded Game");
    NewGameWindow->show();
    this->setLayoutToMenu();
    }else{
        QMessageBox::critical(this,"Error","Cannot open file","OK");
    }
    file.close();

}

/**
 * @brief MainWindow::GetFileName Metoda získávajíci nazev souboru z FileDialogu
 */
void MainWindow::GetFileName(){
    QString FileName = QFileDialog::getOpenFileName();
    LoadFileEdit->setText(FileName);
}

/**
 * @brief MainWindow::showGameWindow Metoda pro inicializaci nové hry a vytvoření okna pro hru
 */
void MainWindow::showGameWindow(){
    if(!PlayerNameEdit->text().isEmpty()){
        if(HumanRadioButton->isChecked()){
            if(!PlayerNameEdit2->text().isEmpty()){
                NewGameWindow = new GameWindow(this->createNewGame());
                NewGameWindow->setFixedSize(1100,800);
                NewGameWindow->setWindowTitle("New Game");
                NewGameWindow->show();
                this->setLayoutToMenu();
            }else{
                NewGameInfoLabel->setText("Fill player 2 name!!");
            }
        }else{
            NewGameWindow = new GameWindow(this->createNewGame());
            NewGameWindow->setFixedSize(1100,800);
            NewGameWindow->setWindowTitle("New Game");
            NewGameWindow->show();
            this->setLayoutToMenu();
        }
    }else{
        NewGameInfoLabel->setText("Fill player 1 name!!");
    }
}

/**
 * @brief MainWindow::createNewGame Tato metoda inicializuje nouvou hru.
 * @return Vrací herní strukturu
 */
GameData* MainWindow::createNewGame(){
    GameData *newGame = new GameData();
    switch(BoardSizeComboBox->currentIndex()){
    case 0:
        newGame->Game.GridSize=6;
        break;
    case 1:
        newGame->Game.GridSize=8;
        break;
    case 2:
        newGame->Game.GridSize=10;
        break;
    case 3:
        newGame->Game.GridSize=12;
        break;
    }
    newGame->Game.Player1Name = new QString(PlayerNameEdit->text());
    if(AIRadioButton->isChecked()){
    newGame->Game.OpponentIsHuman = false;
    switch(OpponentDifficultComboBox->currentIndex()){
    case 0:
        newGame->Game.Player2Name = new QString("AI (Hard)");
        break;
    case 1:
        newGame->Game.Player2Name = new QString("AI (Medium)");
        break;
    case 2:
        newGame->Game.Player2Name = new QString("AI (Stupid)");
        break;

    }
    newGame->Game.AIlevel = OpponentDifficultComboBox->currentIndex();
    }else{
    newGame->Game.OpponentIsHuman = true;
    newGame->Game.Player2Name= new QString(PlayerNameEdit2->text());
    newGame->Game.AIlevel = 10;
    }
    newGame->Game.Actual=0;
    newGame->Game.Last=0;
    newGame->Game.ActivePlayer=0;
    newGame->Game.Player1Score=2;
    newGame->Game.Player2Score=2;

    for(int i=0;i<newGame->Game.GridSize;i++){
        for(int j=0;j<newGame->Game.GridSize;j++){
            newGame->Game.History[0].Grid[i][j]=0;
        }
    }
    newGame->Game.History[0].whoMove=1;
    int halfsize=newGame->Game.GridSize/2;

    newGame->Game.History[0].Grid[halfsize-1][halfsize-1]=1;
    newGame->Game.History[0].Grid[halfsize][halfsize]=1;

    newGame->Game.History[0].Grid[halfsize-1][halfsize]=2;
    newGame->Game.History[0].Grid[halfsize][halfsize-1]=2;
    newGame->Game.RemainingStones=(newGame->Game.GridSize*newGame->Game.GridSize)-4;
    return newGame;

}

/**
 * @brief MainWindow::SetLayoutForOpponent Metoda upravuje UI podle zaškrknutého checkboxu
 */
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

/**
 * @brief MainWindow::SetLayoutToNewGame Metoda přepínajíci laynout pro vytvoření nové hry.
 */
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
    NewGameInfoLabel->setVisible(true);

    BoardSizeComboBox->setCurrentIndex(1);
    OpponentDifficultComboBox->setCurrentIndex(1);

    HumanRadioButton->setChecked(false);
    AIRadioButton->setChecked(true);

    this->SetLayoutForOpponent();
}

/**
 * @brief MainWindow::SetLayoutToLoadGame Metoda přepínající layout pro načtení hry ze souboru.
 */
void MainWindow::SetLayoutToLoadGame(){
    actualLayout=2;
    NewGameButton->setVisible(false);
    LoadButton->setVisible(false);
    AboutGameButton->setVisible(false);
    ExitGameButton->setVisible(false);
    ChooseGameButton->setVisible(true);
    LoadGameButton->setVisible(true);
    BackButton->setVisible(true);
    MenuLabel->setVisible(false);
    LoadGameLabel->setVisible(true);
    LoadGameInfoLabel->setVisible(true);
    LoadFileEdit->setVisible(true);

}
/**
 * @brief MainWindow::SetLayoutToAboutGame Metoda přepínajíci layout zobrazující informace o hře.
 */
void MainWindow::SetLayoutToAboutGame(){
    actualLayout=3;
    NewGameButton->setVisible(false);
    LoadButton->setVisible(false);
    AboutGameButton->setVisible(false);
    ExitGameButton->setVisible(false);
    BackButton->setVisible(true);
    MenuLabel->setVisible(false);
    AuthorsLabel->setVisible(true);
    Author1NameLabel->setVisible(true);
    Author2NameLabel->setVisible(true);
    DescriptionLabel->setVisible(true);

}

/**
 * @brief MainWindow::setLayoutToMenu Metoda přepínajíci layout na menu.
 */
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
        PlayerNameLabel2->setVisible(false);
        PlayerNameEdit2->setVisible(false);
        OpponentDifficultLabel->setVisible(false);
        OpponentDifficultComboBox->setVisible(false);
        PlayerNameEdit->setText("");
        PlayerNameEdit2->setText("");
        NewGameInfoLabel->setText("");
        NewGameInfoLabel->setVisible(false);

        actualLayout=0;
        break;
    case 2:
        LoadGameButton->setVisible(false);
        ChooseGameButton->setVisible(false);
        LoadGameLabel->setVisible(false);
        LoadGameInfoLabel->setVisible(false);
        LoadFileEdit->setVisible(false);
        actualLayout=0;
        break;
    case 3:
        AuthorsLabel->setVisible(false);
        Author1NameLabel->setVisible(false);
        Author2NameLabel->setVisible(false);
        DescriptionLabel->setVisible(false);
        actualLayout=0;
        break;
    }
}

