//
// Created by Raylyn on 11/27/18.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <unistd.h>
#include "Report.h"
#include "Configuration.h"

Report::Report(std::string _reportFile) {
    reportFile = _reportFile;
}

void Report::addRecord(Record r) {
    records.push_back(r);
}

void Report::printReport(Configuration conf) {
    std::cout << "\n" << records.size() << " records found in '" << conf.getReportFile() << "'" << std::endl;
    std::cout << "blk_read blk_read/s kb_read/s blk_write blk_write/s kb_write/s\n";
    for(int i = 0; i < records.size(); i++) {
        if (conf.getBlk_read() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].blk_read;
        }

        if (conf.getBlk_read_s() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].blk_read_s;
        }

        if (conf.getKb_read_s() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].kb_read_s;
        }

        if (conf.getBlk_write() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].blk_write;
        }

        if (conf.getBlk_write_s() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].blk_write_s;
        }

        if(conf.getKb_write() == 0) {
            std::cout << std::left << std::setw(10) << "N/A";
        }
        else {
            std::cout << std::left << std::setw(10) << records[i].kb_write_s;
        }
    }
}

void Report::writeReport(Configuration conf) {

    std::ofstream outStream;
    outStream.open(conf.getReportFile(), std::ios::app);


    outStream << "\n" << records.size() << " records found in '" << conf.getReportFile() << "'" << std::endl;
    outStream << "blk_read blk_read/s kb_read/s blk_write blk_write/s kb_write/s\n";
    for(int i = 0; i < records.size(); i++) {
        if (conf.getBlk_read() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].blk_read;
        }

        if (conf.getBlk_read_s() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].blk_read_s;
        }

        if (conf.getKb_read_s() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].kb_read_s;
        }

        if (conf.getBlk_write() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].blk_write;
        }

        if (conf.getBlk_write_s() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].blk_write_s;
        }

        if(conf.getKb_write() == 0) {
            outStream << std::left << std::setw(10) << "N/A";
        }
        else {
            outStream << std::left << std::setw(10) << records[i].kb_write_s;
        }
    }
}

// std::left << std::setw(10) <<

// std::cout << records[i].

// left << setw(10)