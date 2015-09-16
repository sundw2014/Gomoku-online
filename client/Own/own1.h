#ifndef OWN1_H
#define OWN1_H

#include <QDialog>
#include <QSound>

namespace Ui {
class Own1;
}

class Own1 : public QDialog
{
    Q_OBJECT

public:
    explicit Own1(QWidget *parent = 0);
    ~Own1();
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Own1 *ui;
    int a[16][16];
    int review = 0;
    int Win(int, int);
    int win1(int, int);
    int win2(int, int);
    int win3(int, int);
    int win4(int, int);
    int player;
    int users;
    bool check = true;
};

class save
{
public:
    int _x;
    int _y;
    save ()
    {
        _x = 0;
        _y = 0;
    }
    void inisave(int a,int b)
    {
        this->_x = a;
        this->_y = b;
    }

};

#endif // OWN1_H