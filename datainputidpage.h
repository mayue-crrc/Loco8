#ifndef DATAINPUTIDPAGE_H
#define DATAINPUTIDPAGE_H

#include <QWidget>

namespace Ui {
class DataInputIDPage;
}

class DataInputIDPage : public QWidget
{
    Q_OBJECT
    
public:
    explicit DataInputIDPage(QWidget *parent = 0);
    ~DataInputIDPage();
    
private:
    Ui::DataInputIDPage *ui;
};

#endif // DATAINPUTIDPAGE_H
