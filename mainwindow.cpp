#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <qrandom.h>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QMessageBox welcome;
    welcome.setText("Welcome to Drinkopoly!!! Press OK to start!");
    welcome.exec();


    // play background music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("D:/QT PROJECTS/Drinkopoly/Piece/MonopolySounds.mp3"));
    music->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct Node
{
    int data;
    struct Node *next;
};

//insert a new node in an empty list
struct Node *insertInEmpty(struct Node *last, int new_data)
{
   // if last is not null then list is not empty, so return
   if (last != nullptr)
   return last;

   // allocate memory for node
   struct Node *temp = new Node;

   // Assign the data.
   temp -> data = new_data;
   last = temp;

   // Create the link.
   last->next = last;

   return last;
}

//insert new node at the beginning of the list
struct Node *insertAtBegin(struct Node *last, int new_data)
{
   //if list is empty then add the node by calling insertInEmpty
   if (last == nullptr)
   return insertInEmpty(last, new_data);

   //else create a new node
   struct Node *temp = new Node;

   //set new data to node
   temp -> data = new_data;
   temp -> next = last -> next;
   last -> next = temp;

   return last;
}

//traverse the circular linked list
void MainWindow::pointTO(struct Node *last)
{
    struct Node *p;
    p = last -> next;
    int x = 0;
    int y = 0;

    QMediaPlayer * piecesounds = new QMediaPlayer();
    piecesounds->setMedia(QUrl("D:/QT PROJECTS/Drinkopoly/Piece/Piece_sound.wav"));

    QPixmap dice1("D:/QT PROJECTS/Drinkopoly/Dice/1.jpg");
    QPixmap dice2("D:/QT PROJECTS/Drinkopoly/Dice/2.jpg");
    QPixmap dice3("D:/QT PROJECTS/Drinkopoly/Dice/3.jpg");
    QPixmap dice4("D:/QT PROJECTS/Drinkopoly/Dice/4.jpg");
    QPixmap dice5("D:/QT PROJECTS/Drinkopoly/Dice/5.jpg");
    QPixmap dice6("D:/QT PROJECTS/Drinkopoly/Dice/6.jpg");
    QPixmap piece("D:/QT PROJECTS/Drinkopoly/Piece/Piece_1.png");
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5
    // 0 = free
    // 1 = truth or dare
    // 2 = double shot
    // 3 = do jumping jacks
    // 4 = person to your right takes the shot
    // 5 = take the next 3 penalties

    do
    {
        //roll dice
        x+=1;
        int roll = qrand() % 6 + 1;
        QMessageBox rollMessage;
        rollMessage.setText(QString("You rolled %1!").arg(roll));
        rollMessage.exec();

        //display dice in GUI
        if (roll == 1)
        {
            p = p -> next;
            ui->label_3->setPixmap(dice1);
        }
        else if (roll == 2)
        {
            p = p -> next;
            p = p -> next;
            ui->label_3->setPixmap(dice2);

        }
        else if (roll == 3)
        {
            p = p -> next;
            p = p -> next;
            p = p -> next;
            ui->label_3->setPixmap(dice3);

        }
        else if (roll == 4)
        {
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            ui->label_3->setPixmap(dice4);

        }
        else if (roll == 5)
        {
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            ui->label_3->setPixmap(dice5);

        }
        else if (roll == 6)
        {
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            p = p -> next;
            ui->label_3->setPixmap(dice6);

        }

        animation = new QPropertyAnimation(ui->label_8,"geometry");
        animation->setDuration(1000);
        animation->setStartValue(ui->label_8->geometry());
        y = y + roll;

        //set beer position
        if (y == 0)
        {
            animation->setEndValue(QRect(40,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 1)
        {
            animation->setEndValue(QRect(180,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 2)
        {
            animation->setEndValue(QRect(320,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 3)
        {
            animation->setEndValue(QRect(450,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 4)
        {
            animation->setEndValue(QRect(590,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 5)
        {
            animation->setEndValue(QRect(720,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 6)
        {
            animation->setEndValue(QRect(860,890,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 7)
        {
            animation->setEndValue(QRect(860,740,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 8)
        {
            animation->setEndValue(QRect(860,600,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 9)
        {
            animation->setEndValue(QRect(860,470,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 10)
        {
            animation->setEndValue(QRect(860,330,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 11)
        {
            animation->setEndValue(QRect(860,200,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 12)
        {
            animation->setEndValue(QRect(860,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 13)
        {
            animation->setEndValue(QRect(710,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 14)
        {
            animation->setEndValue(QRect(580,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 15)
        {
            animation->setEndValue(QRect(450,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 16)
        {
            animation->setEndValue(QRect(310,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 17)
        {
            animation->setEndValue(QRect(180,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 18)
        {
            animation->setEndValue(QRect(40,60,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 19)
        {
            animation->setEndValue(QRect(40,200,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 20)
        {
            animation->setEndValue(QRect(40,330,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 21)
        {
            animation->setEndValue(QRect(40,460,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 22)
        {
            animation->setEndValue(QRect(40,600,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 23)
        {
            animation->setEndValue(QRect(40,730,51,61));
            animation->start();
            piecesounds->play();
        }
        if (y == 24)
        {
            //0
            animation->setEndValue(QRect(40,890,51,61));
            animation->start();
            piecesounds->play();
            y = 0;
        }
        if (y == 25)
        {
            //1
            animation->setEndValue(QRect(180,890,51,61));
            animation->start();
            piecesounds->play();
            y = 1;
        }
        if (y == 26)
        {
            //2
            animation->setEndValue(QRect(320,890,51,61));
            animation->start();
            piecesounds->play();
            y = 2;
        }
        if (y == 27)
        {
            //3
             animation->setEndValue(QRect(450,890,51,61));
             animation->start();
             piecesounds->play();
            y = 3;
        }
        if (y == 28)
        {
            //4
            animation->setEndValue(QRect(590,890,51,61));
            animation->start();
            piecesounds->play();
            y = 4;
        }
        if (y == 29)
        {
            //5
            animation->setEndValue(QRect(720,890,51,61));
            animation->start();
            piecesounds->play();
            y = 5;
        }


        //output tile information
        if(p->data==0)
        {
            //free tile
            QMessageBox free;
            free.setText("FREE PASS!!");
            free.exec();

        }
        if(p->data==1)
        {
            //go on a dare
            QMessageBox dare;
            dare.setText("Truth or Dare!!!");
            dare.exec();

        }
        if(p->data==2)
        {
            //take 1 shot
            QMessageBox shot;
            shot.setText("Double shot!!");
            shot.exec();

        }
        if(p->data==3)
        {
            //go on a dare
            QMessageBox dare;
            dare.setText("Do 10 times jumping jacks.");
            dare.exec();

        }
        if(p->data==4)
        {
            //take 1 shot
            QMessageBox shot;
            shot.setText("Person to your right takes the shot.");
            shot.exec();

        }
        if(p->data==5)
        {
            //go on a dare
            QMessageBox dare;
            dare.setText("Take the next 3 penalties.");
            dare.exec();
        }

        QMessageBox msgBox;
        msgBox.setText("Next player ready to roll?");
        msgBox.addButton("Yeah!",QMessageBox::YesRole);
        QAbstractButton* pButtonNo = msgBox.addButton("Exit", QMessageBox::NoRole);

        msgBox.exec();

        if (msgBox.clickedButton()==pButtonNo)
        {
            ui->label_8->setGeometry(40,890,51,61);
            QMessageBox tryagain;
            tryagain.setText("Thank you for playing! Press ROLL to play again!");
            tryagain.exec();
            break;
        }


    } while(x!=999);

}

//start button
void MainWindow::on_pushButton_clicked()
{

    QMessageBox start;
    start.setText("Hello! Welcome to Drinkopoly!.");
    start.exec();
}


//EXIT
void MainWindow::on_pushButton_2_clicked()
{
    close();
}

//ROLL DICE
void MainWindow::on_pushButton_4_clicked()
{
    struct Node *last = nullptr;

    last = insertInEmpty(last, 5);
    last = insertAtBegin(last, 4);
    last = insertAtBegin(last, 3);
    last = insertAtBegin(last, 2);
    last = insertAtBegin(last, 1);
    last = insertAtBegin(last, 0);

    MainWindow::pointTO(last);

}

//HELP
void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox start;
    start.setText("Once you roll, you will stop in a certain tile depending on your roll, and then the next person who will roll will start from where you've stopped.");
    start.exec();
}
