#include "CReadFile.h"
#include <QFile>
#include <QTextStream>
#include <random>

CReadFile::CReadFile(QObject *parent)
    : QAbstractItemModel(parent)
{
    QFile file("input.txt");

    // Check if file can be opened
    if (!file.exists())
    {
        qDebug() << "File does not exist.";
        return;
    }

    // Open file
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        int lineCount = 1;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            titles.push_back(line);

            if (lineCount % 2 == 1)
            {
                stack_odd.push(line);
            }
            else
            {
                stack_even.push(line);
            }

            lineCount++;
        }

        file.close();
    }
    else
    {
        qDebug() << "Unable to open the file.";
        return;
    }
}



QString CReadFile::getMovie(int index) const
{
    index--;

    if (index >= 0 && index < titles.size())
    {
        return titles.at(index);
    }
    else
    {
        return "No more available movies";
    }
}



QVariant CReadFile::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(section);

    if(role!= Qt::DisplayRole)
    {
        return QVariant();
    }
    if(orientation ==Qt::Horizontal)
    {
        return QString("Title");
    }
    return QString();
}

QModelIndex CReadFile::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid() && row >= 0 && row < titles.size() && column == 0)
    {
        return createIndex(row, column);
    }
    return QModelIndex();
}

QModelIndex CReadFile::parent(const QModelIndex &index) const
{
    Q_UNUSED(index);

    return QModelIndex();
}

int CReadFile::rowCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
    {
        return titles.size();
    }
    return 0;
}

int CReadFile::columnCount(const QModelIndex &parent) const
{
    if(!parent.isValid())
    {
        return 1;
    }
    return 0;
}

QVariant CReadFile::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole && !index.parent().isValid() && index.row() < titles.size())
    {
        return titles.at(index.row());
    }
    return QVariant();
}


QString CReadFile::getRandomMovie(bool isOdd)
{
    QStack<QString>* selectedStack = isOdd ? &stack_odd : &stack_even;

    if (selectedStack->isEmpty())
    {
        return "No more available movies";
    }

    // Seed the random number generator with current time
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, selectedStack->size() - 1);
    int randomIndex = distribution(gen);

    QString selectedMovie = selectedStack->at(randomIndex);

    // Remove the selected movie from the original stack
    selectedStack->remove(randomIndex);

    return selectedMovie;
}

