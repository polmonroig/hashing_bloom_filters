#ifndef A_CSV_FILE_H
#define A_CSV_FILE_H

#include <list>
#include <fstream>
#include <string>

typedef std::list<std::string> CsvRow;

class CsvFile {

public:

    explicit CsvFile(std::string const& fileDir);

    void addRow(CsvRow const& row);

    void write() const;


private:

    std::string outputDir;
    std::list<CsvRow> rows;
};


#endif //A_CSV_FILE_H
