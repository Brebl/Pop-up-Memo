#ifndef MANPAGE_H
#define MANPAGE_H

#include <QDialog>

namespace Ui {
class manpage;
}

class manpage : public QDialog
{
    Q_OBJECT

public:
    explicit manpage(QWidget *parent = nullptr);
    ~manpage();

private:
    Ui::manpage *ui;
};

#endif // MANPAGE_H
