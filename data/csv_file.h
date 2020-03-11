#ifndef A_CSV_FILE_H
#define A_CSV_FILE_H

#include <list>
#include <fstream>
#include <string>

/**
 * @typedef Defines a csv row as a list of strings
 * */
typedef std::list<std::string> CsvRow;


/**
 * @class CsvFile
 * @brief The CsvFile class saves a list of rows and writes them in
 *        a csv format in a specified directory
 * */
class CsvFile {

public:

    /**
     * @brief Basic constructor
     * @param fileDir is the output directory
     * */
    explicit CsvFile(std::string const& fileDir);

    /**
     * @brief appends a row to the file
     * @param row contains the contents of the row to add
     * */
    void addRow(CsvRow const& row);

    /**
     * @brief writes the file in the specified directory
     * */
    void write() const;


private:

    /**
     * @brief the parent directory of the file
     * */
    std::string outputDir;

    /**
     * @brief saves the csv rows
     * */
    std::list<CsvRow> rows;

    const std::string CSV_EXTENSION = ".csv";
};


#endif //A_CSV_FILE_H
