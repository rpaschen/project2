//
// Created by raylyn on 11/20/18.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "CommandLine.h"
#include "Report.h"

CommandLine::CommandLine() {

}

bool getData(Report &r) {
    system("grep 'sda2' /proc/diskstats > data.txt");

    std::ifstream inFile;
    inFile.open("data.txt");

    if(!inFile) {
        std::cout << "Error opening file.\n" << std::endl;
        return false;
    }

    std::string a;
    std::string  b;
    std::string c;
    int blk_read; // included in report
    std::string d;
    int secsRead;
    int msReading;
    int blk_write; // included in report
    std::string e;
    int secsWritten;
    int msWriting;
    std::string f;
    std::string g;
    std::string h;

    inFile >> a >> b >> c >> blk_read >> d >> secsRead >> msReading >> blk_write >> e >> secsWritten >> msWriting >> f >> g >> h;

    inFile.close();

    // conversion of milliseconds to seconds
    double sReading = (double) msReading / 1000.0;
    double sWriting = (double) msWriting / 1000.0;

    // throughput calculations (included in report)

    double blk_read_s = (double) blk_read / sReading;
    double kb_read_s = (double) secsRead / (2.0 * sReading);

    double blk_write_s = (double) blk_write / sWriting;
    double kb_write_s = (double) secsWritten / (2.0 * sWriting);

    Record rec;
    rec.blk_read_s = blk_read_s;
    rec.kb_read_s = kb_read_s;
    rec.blk_write_s = blk_write_s;
    rec.kb_write_s = kb_write_s;
    rec.blk_read = blk_read;
    rec.blk_write = blk_write;
    r.addRecord(rec);


    return true;
}