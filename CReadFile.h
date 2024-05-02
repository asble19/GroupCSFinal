#ifndef CREADFILE_H
#define CREADFILE_H

#include <QObject>
#include <QAbstractItemModel>
#include <QStack>
#include <QVector>

class CReadFile : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit CReadFile(QObject *parent = nullptr);

    QString getMovie(int index) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QString getRandomMovie(bool isOdd);

private:
    QStack<QString> stack_odd;
    QStack<QString> stack_even;
    QVector<QString> titles;
    QStack<QString> stack_temp;

    int generateRandomNumber(int max) const; // Declaration of random number generator method

};

#endif // CREADFILE_H
