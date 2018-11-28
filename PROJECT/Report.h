//
// Created by Raylyn on 11/27/18.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>
#include "Configuration.h"
#ifndef PROJECT_REPORT_H
#define PROJECT_REPORT_H


struct Record {
    int blk_read;
    double blk_read_s;
    double kb_read_s;
    int blk_write;
    double blk_write_s;
    double kb_write_s;
};

class Report {
public:

    // constructor prototype
    Report(std::string reportFile);

    // function prototypes
    void addRecord(Record r);
    void printReport(Configuration conf);
    void writeReport(Configuration conf);
    std::vector<Record> records;
    std::string reportFile;

private:

};


#endif //PROJECT_REPORT_H
